import tensorflow as tf
m1 = tf.constant([[3.,3.]])
m2 = tf.constant([[2.,2.]])
p1 = tf.matmul(m1, m2)
with tf.Session() as sess:
    print(sess.run(m1))
    print(sess.run(m2))
    print(sess.run(p1))

sess.close()

