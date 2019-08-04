import tensorflow as tf
sess = tf.Session()
x = tf.Variable([1.,2.])    # Variable은 초기화initializer가 꼭 필요
a = tf.constant([3.,3.])    
sess.run(x.initializer)
sub = tf.subtract(x,a)
# print(sess.run(sub))
print(sub.eval())
sess.close()

# 오리 타이핑? 덕 타이핑? duck typing 