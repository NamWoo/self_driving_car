import os
import pandas as pd
import numpy as np
from keras import backend as K
from sklearn.model_selection import StratifiedKFold, KFold
from keras.models import Sequential, Model, model_from_json
from keras.layers import Dense, Dropout, Flatten, Activation, Conv2D, GlobalAveragePooling2D
from keras import optimizers
from sklearn.metrics import f1_score
from keras.callbacks import ModelCheckpoint, EarlyStopping, ReduceLROnPlateau, LambdaCallback
import ssl
# from keras.applications.resnet50 import ResNet50, preprocess_input
from keras.preprocessing.image import ImageDataGenerator
from keras.applications.xception import Xception, preprocess_input
from sklearn.model_selection import train_test_split


BATCH_SIZE = 32
EPOCHS = 100
TTA_STEPS = 5
PATIENCE = 6
SEED = 4569
# BASE_MODEL = Xception
# IMAGE_SIZE = 299
IMAGE_WIDTH, IMAGE_HEIGHT = (299, 299)
# EPOCHS = 30
K_FOLDS = 5

# 전체적으로 문제없이 돌아가는지만 확인할 때 사용.
TESTFLIGHT = False

epochs = EPOCHS
batch_size = BATCH_SIZE


DATA_PATH = path
CROPPED_DATA_PATH = path + 'cropped/'
MODEL_PATH = path + 'models/'

_m = 0
fold_index = 0
model_save_filename = ("%s_%d.h5" % (_m , fold_index))
model_save_filepath = os.path.join(MODEL_PATH, model_save_filename)



df_train = pd.read_csv(os.path.join(DATA_PATH, "train.csv"))
df_test = pd.read_csv(os.path.join(DATA_PATH, "test.csv"))
df_class = pd.read_csv(os.path.join(DATA_PATH, "class.csv"))

df_train['class'] = df_train['class'].astype('str')

classes = df_class['id'].values.astype('str').tolist()
num_classes_out = len(classes)


def get_total_batch(num_samples, batch_size):    
    if (num_samples % batch_size) > 0 :
        return (num_samples // batch_size) + 1
    else :
        return num_samples // batch_size

def recall(y_target, y_pred):
    # clip(t, clip_value_min, clip_value_max) : clip_value_min~clip_value_max 이외 가장자리를 깎아 낸다
    # round : 반올림한다
    y_target_yn = K.round(K.clip(y_target, 0, 1)) # 실제값을 0(Negative) 또는 1(Positive)로 설정한다
    y_pred_yn = K.round(K.clip(y_pred, 0, 1)) # 예측값을 0(Negative) 또는 1(Positive)로 설정한다

    # True Positive는 실제 값과 예측 값이 모두 1(Positive)인 경우이다
    count_true_positive = K.sum(y_target_yn * y_pred_yn) 

    # (True Positive + False Negative) = 실제 값이 1(Positive) 전체
    count_true_positive_false_negative = K.sum(y_target_yn)

    # Recall =  (True Positive) / (True Positive + False Negative)
    # K.epsilon()는 'divide by zero error' 예방차원에서 작은 수를 더한다
    recall = count_true_positive / (count_true_positive_false_negative + K.epsilon())

    # return a single tensor value
    return recall

def precision(y_target, y_pred):
    # clip(t, clip_value_min, clip_value_max) : clip_value_min~clip_value_max 이외 가장자리를 깎아 낸다
    # round : 반올림한다
    y_pred_yn = K.round(K.clip(y_pred, 0, 1)) # 예측값을 0(Negative) 또는 1(Positive)로 설정한다
    y_target_yn = K.round(K.clip(y_target, 0, 1)) # 실제값을 0(Negative) 또는 1(Positive)로 설정한다

    # True Positive는 실제 값과 예측 값이 모두 1(Positive)인 경우이다
    count_true_positive = K.sum(y_target_yn * y_pred_yn) 

    # (True Positive + False Positive) = 예측 값이 1(Positive) 전체
    count_true_positive_false_positive = K.sum(y_pred_yn)

    # Precision = (True Positive) / (True Positive + False Positive)
    # K.epsilon()는 'divide by zero error' 예방차원에서 작은 수를 더한다
    precision = count_true_positive / (count_true_positive_false_positive + K.epsilon())

    # return a single tensor value
    return precision

def f1score_1(y_target, y_pred):
    _recall = recall(y_target, y_pred)
    _precision = precision(y_target, y_pred)
    # K.epsilon()는 'divide by zero error' 예방차원에서 작은 수를 더한다
    _f1score = ( 2 * _recall * _precision) / (_recall + _precision+ K.epsilon())
    # return a single tensor value
    return _f1score

def f1score_2(y_target, y_pred):
    return f1_score(y_target, y_pred, average='micro')

def get_model(base_model):
    base_model = base_model(weights='imagenet', include_top=False, input_shape = (IMAGE_WIDTH,IMAGE_HEIGHT,3))

    model = Sequential()
    model.add(base_model)
    model.add(GlobalAveragePooling2D())
    model.add(Dense(1024, activation='relu'))
    model.add(Dropout(0.5))
    model.add(Dense(1024, activation='relu'))
    model.add(Dropout(0.5))
    # model.add(layers.Dense(512, activation='relu'))
    # model.add(layers.Dropout(0.5))
    model.add(Dense(256, activation='relu'))
    model.add(Dropout(0.5))
    model.add(Dense(num_classes_out, activation='softmax', kernel_initializer='he_normal'))
    optimizer = optimizers.RMSprop(lr=0.0001)  
    model.compile(optimizer=optimizer, loss='categorical_crossentropy', metrics=['acc', f1score_1])
    return model

def get_callbacks(model_save_filename, patience):
    es = EarlyStopping(monitor='val_f1score', min_delta=0, patience=patience, verbose=1, mode='max')

    rr = ReduceLROnPlateau(monitor = 'val_f1score', factor = 0.5, patience = patience / 2,
                           min_lr=0.000001,
                           verbose=1,
                           mode='max')

    mc = ModelCheckpoint(filepath=model_save_filename, monitor='val_f1score', verbose=1,
                           save_best_only=True, mode='max')

    return [es, rr, mc]


datagen_train = ImageDataGenerator(
    featurewise_center=False,  # set input mean to 0 over the dataset
    samplewise_center=False,  # set each sample mean to 0
    featurewise_std_normalization=False,  # divide inputs by std of the dataset
    samplewise_std_normalization=False,  # divide each input by its std
    zca_whitening=False,  # apply ZCA whitening
    rotation_range=15,  # randomly rotate images in the range (degrees, 0 to 180)
    zoom_range = 0.1, # Randomly zoom image 
    width_shift_range=0.1,  # randomly shift images horizontally (fraction of total width)
    height_shift_range=0.1,  # randomly shift images vertically (fraction of total height)
    horizontal_flip=True,  # randomly flip images
    vertical_flip=False,  # randomly flip images
    preprocessing_function = preprocess_input)

datagen_val = ImageDataGenerator(
    featurewise_center=False,  # set input mean to 0 over the dataset
    samplewise_center=False,  # set each sample mean to 0
    featurewise_std_normalization=False,  # divide inputs by std of the dataset
    samplewise_std_normalization=False,  # divide each input by its std
    zca_whitening=False,  # apply ZCA whitening
    rotation_range=15,  # randomly rotate images in the range (degrees, 0 to 180)
    zoom_range = 0.1, # Randomly zoom image 
    width_shift_range=0.1,  # randomly shift images horizontally (fraction of total width)
    height_shift_range=0.1,  # randomly shift images vertically (fraction of total height)
    horizontal_flip=True,  # randomly flip images
    vertical_flip=False,  # randomly flip images
    preprocessing_function = preprocess_input)




its = np.arange(df_train.shape[0])
train_idx, val_idx = train_test_split(its, train_size = 0.8, random_state=167)

X_train = df_train.iloc[train_idx, :]
dataframe_train = X_train

X_val = df_train.iloc[val_idx, :]
dataframe_val = X_val

# skfold = StratifiedKFold(n_splits=K_FOLDS, random_state=314)

__models = {}
__models = {"Xception" : Xception}
model = get_model(__models[0])

ssl._create_default_https_context = ssl._create_unverified_context
history_list = {}


# ImageDataGenerator 생성(train/val)
datagen_train_flow = datagen_train.flow_from_dataframe(dataframe=dataframe_train,
                                            directory=os.path.join(CROPPED_DATA_PATH, "train"),
                                            x_col='img_file',
                                            y_col="class",
                                            classes = classes,
                                            target_size=(IMAGE_WIDTH, IMAGE_HEIGHT),
                                            color_mode='rgb',
                                            class_mode='categorical',
                                            batch_size=batch_size,
                                            seed=314)

datagen_val_flow = datagen_val.flow_from_dataframe(dataframe=dataframe_val,
                                            directory=os.path.join(CROPPED_DATA_PATH, "train"),
                                            x_col='img_file',
                                            y_col="class",
                                            classes = classes,
                                            target_size=(IMAGE_WIDTH, IMAGE_HEIGHT),
                                            color_mode='rgb',
                                            class_mode='categorical',
                                            batch_size=batch_size,
                                            seed=214)


train_steps = get_total_batch(dataframe_train.shape[0], batch_size)
val_steps = get_total_batch(dataframe_val.shape[0], batch_size)

history = model.fit_generator(datagen_train_flow,
    epochs=epochs,
    steps_per_epoch = train_steps,
    validation_data = datagen_val_flow,
    validation_steps = val_steps,
    callbacks = get_callbacks(model_save_filepath, PATIENCE),
    verbose=1)

history_list[model_save_filename] = history




datagen_metalearner_flow = datagen_submit.flow_from_dataframe(
            dataframe=df,
            directory=os.path.join(CROPPED_DATA_PATH, imgdirname),
            x_col='img_file',
            y_col=None,
            target_size= (IMAGE_WIDTH, IMAGE_HEIGHT),
            color_mode='rgb',
            class_mode=None,
            batch_size=batch_size,
            shuffle=False)

datagen_metalearner_flow.reset()
pred = model.predict_generator(generator = datagen_metalearner_flow,
                                steps = get_total_batch(df.shape[0], batch_size),
                                verbose=1)