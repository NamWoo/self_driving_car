import os
import pandas as pd
from PIL import Image, ImageDraw
import matplotlib.pyplot as plt
import numpy as np
from pathlib import Path

IMAGE_WIDTH, IMAGE_HEIGHT = (299, 299)

# root_path = 'gdrive/My Drive/'
# path = root_path + '!DataSets/2019-3rd-ml-month-with-kakr/'
path = 'D://2019-3rd-ml-month-with-kakr//'

DATA_PATH = path
CROPPED_DATA_PATH = path + "cropped"
MODEL_PATH = path +"models"

# TRAIN_IMG_PATH = os.path.join(path, 'train')
# TEST_IMG_PATH = os.path.join(path, 'test')

df_train = pd.read_csv(os.path.join(path, 'train.csv'))
df_test = pd.read_csv(os.path.join(path, 'test.csv'))
df_class = pd.read_csv(os.path.join(path, 'class.csv'))

image_width, image_height = IMAGE_WIDTH, IMAGE_HEIGHT

# crop해서 만들 이미지의 W/H 비율을 1:1로 한다.
# 모델의 이미지 입력은 width,height가 동일하므로 1:1만이 가능함.
default_ratio = 1.0

def get_fixed_img(filename, area, ratio, output_size):
    debug = False
    im = Image.open(filename)
    cropIm = im.crop(area)
    
    if debug:
        print("crop w/h=", cropIm.width, cropIm.height)
    
    w, h = cropIm.width, cropIm.height
    # w : h = w/h ratio : 1
    fixedW, fixedH = w, h
    if w/h >= ratio:
        fixedH = w / ratio
    else:
        fixedW = h * ratio
    fixedW, fixedH = int(fixedW), int(fixedH)

    if debug:
        print("fixed w/h=", fixedW, fixedH, "ratio=", fixedW/fixedH)
    
    newIm = Image.new("RGB", (fixedW, fixedH))
    newIm.paste(cropIm, ((fixedW - w)//2, (fixedH - h)//2))
    
    #newIm = newIm.resize(output_size, resample=Image.NEAREST)
    return newIm

def img_from_row(row, path, ratio, w, h):
    filepath = os.path.join(path, row['img_file'])
    area = (row['bbox_x1'], row['bbox_y1'], row['bbox_x2'], row['bbox_y2'])
    return get_fixed_img(filepath, area, ratio, (w, h))    

def make_crop_img(df, dirname):
    # 저장될 디렉토리부터 생성
    dirpath_crop = os.path.join(CROPPED_DATA_PATH, dirname)
    if os.path.exists(dirpath_crop) == False:
        Path(dirpath_crop).mkdir(parents=True, exist_ok=True)

    for idx, row in df.iterrows():
        src_path = os.path.join(DATA_PATH, dirname)
        target_img_path = os.path.join(dirpath_crop, row['img_file'])
        
        # 파일이 없거나, 사이즈가 0이면 새로 만든다.
        isvalid = os.path.exists(target_img_path)
        isvalid = (isvalid and (os.path.getsize(target_img_path) > 0))
        if isvalid == False:
            im = img_from_row(row, src_path, default_ratio, image_width, image_height)
            im.save(target_img_path)

def make_cropped_imgs():
    dirpath_crop = os.path.join(CROPPED_DATA_PATH, "train")
    print(dirpath_crop)
    make_crop_img(df_train, "train")
    
    dirpath_crop = os.path.join(CROPPED_DATA_PATH, "test")
    print(dirpath_crop)
    make_crop_img(df_test, "test")

make_cropped_imgs()