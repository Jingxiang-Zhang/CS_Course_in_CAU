import numpy as np
import tensorflow as tf
import os
import tools
import reader
import cv2

class alexnet:
    def __init__(self, path):
        self.batch_size = 64
        self.dwindle_rage = 2
        self.learnning_rate = 0.001
        self.epoch = 301
        self._layer_1_convs = int(64 / self.dwindle_rage)
        self._layer_2_convs = int(192 / self.dwindle_rage)
        self._layer_3_convs = int(384 / self.dwindle_rage)
        self._layer_4_convs = int(256 / self.dwindle_rage)
        self._layer_5_convs = int(256 / self.dwindle_rage)
        self._layer_6_full = int(4096 / self.dwindle_rage)
        self._layer_7_full = int(4096 / self.dwindle_rage)
        self._layer_8_full = 10
        self._outsum = 11

        self.img_w = 224
        self.img_h = 224  #223
        self._net_save_loc = os.path.join(path, "netsave")
        self._log_save_loc = os.path.join(path, "log.txt")
        self._net_meta_loc=os.path.join(path, "netsave.meta")
        res = self._readpath(path)
        pass

    def train(self, datapath):
        self._net_init()

        read = reader.reader()
        readt = read.reader(path=datapath, imgshape=(self.img_w, self.img_h),
                            groupsize=self.batch_size, shuffle=True, img_arg=True, std=True)

        self._savelog()

        with tf.Session() as sess:
            writer = tf.summary.FileWriter("./tensorboard/test/", sess.graph)
            if self._new_train == True:
                sess.run(tf.global_variables_initializer())
            else:
                tf.train.Saver().restore(sess, save_path=self._net_save_loc)

            while self._current_epoch < self.epoch:
                nowtimeloss, nowaccuracy = 0,0
                for imgs, labels in readt:
                    label = self._transfer_label(labels)
                    _, nowtimeloss, nowaccuracy = sess.run(
                                                            [self.train_op,
                                                             self.loss_function,
                                                             self.accuracy],
                                                           feed_dict={self.x_images: imgs,
                                                                      self.y_labels: label})

                    print("\nepoch: {}  loss: {}  accuracy: {}".
                        format(self._current_epoch, nowtimeloss, nowaccuracy))
                        #print(imgs)

                read = reader.reader()
                readt = read.reader(path=datapath, imgshape=(self.img_w, self.img_h),
                                    groupsize=self.batch_size, shuffle=True, img_arg=True, std=True)

                if self._getstop() == True:
                    self._current_epoch += 1
                    tf.train.Saver().save(sess, save_path=self._net_save_loc)
                    self._savelog()
                    break
                self._current_epoch += 1
                tf.train.Saver().save(sess, save_path=self._net_save_loc)
                self._savelog()


    def test(self, data):
        tf.reset_default_graph()
        self._net_init()
        with tf.Session() as sess:
            tf.train.Saver().restore(sess, save_path=self._net_save_loc)
            predict = sess.run([self.net], feed_dict={self.x_images: data})
        return predict[0]


    def testall(self,datapath):
        read = reader.reader()
        readt = read.reader(path=datapath, imgshape=(self.img_w, self.img_h),
                    groupsize=self.batch_size, shuffle=True, img_arg=False, std=True)

        result=[]

        first=True

        tf.reset_default_graph()
        self._net_init()
        maxl = tf.arg_max(self.net, 1)
        with tf.Session() as sess:
            tf.train.Saver().restore(sess, save_path=self._net_save_loc)
            for imgs, labels in readt:
                if first==True:
                    for i, _ in read.type.items():
                        result.append([i,0,0])
                    first=False

                label = self._transfer_label(labels)
                res = sess.run([maxl],feed_dict={self.x_images: imgs, self.y_labels: label})
                res=res[0].tolist()
                for i in range(len(res)):
                    result[labels[i]][1]+=1
                    if labels[i]==res[i]:
                        result[labels[i]][2] += 1
        return result


    def _net_init(self):
        self.x_images = tf.placeholder(tf.float32, shape=[self.batch_size, self.img_w, self.img_h, 3])
        self.y_labels = tf.placeholder(tf.int16, shape=[self.batch_size, self._outsum])
        self.net = self._network(self.x_images)
        self.loss_function = self._loss(self.net, self.y_labels)
        self.accuracy = self._accuracy(self.net, self.y_labels)
        self.my_global_step = tf.Variable(0, name="global_step", trainable=False)
        self.train_op = self._optimizer(self.loss_function, self.learnning_rate, self.my_global_step)

    def _transfer_label(self, labels):
        res = np.zeros(shape=(self.batch_size, self._outsum), dtype=np.int16)
        for i in range(self.batch_size):
            res[i][labels[i]] = 1
        return res

    @staticmethod
    def setstop(path):
        path = path.join(path, "log.txt")
        info = tools.getFileInfo(path)
        times = int(info.get("times", 0))
        it = {
            "times": times,
            "stop:": "true"
        }
        tools.saveFileInfo(path, it)

    def _getstop(self):
        info = tools.getFileInfo(self._log_save_loc)
        res = info.get("stop", 0)
        if res == "true":
            return True
        else:
            return False

    def _readpath(self, path):
        if os.path.exists(self._log_save_loc) and os.path.exists(self._net_meta_loc):
            info = tools.getFileInfo(self._log_save_loc)
            self._current_epoch = int(info.get("times", 0))
            self._new_train = False
        else:
            self._current_epoch = 0
            self._new_train = True

    def _savelog(self):
        it = {
            "times": self._current_epoch,
            "stop": "false"
        }
        tools.saveFileInfo(self._log_save_loc, it)

    def _network(self, x, is_pretrain=True):
        with tf.name_scope("AlexNet"):
            #224*224*3
            x = self._conv("conv1", x, self._layer_1_convs, kernel_size=[11, 11], stride=[1, 4, 4, 1], is_pretrain=is_pretrain)
            x = tf.nn.lrn(x, 4, bias=1, alpha=1e-3 / 9, beta=0.75, name="lrn1")
            x= self._pool("pool1", x, kernel=[1, 3, 3, 1], stride=[1, 2, 2, 1], is_max_pool=True)

            x = self._conv("conv2", x, self._layer_2_convs, kernel_size=[5, 5], stride=[1, 1, 1, 1], is_pretrain=is_pretrain)
            x = tf.nn.lrn(x, 4, 1.0, alpha=1e-3 / 9, beta=0.75, name="lrn2")
            x= self._pool("pool2", x, kernel=[1, 3, 3, 1], stride=[1, 2, 2, 1], is_max_pool=True)

            x = self._conv("conv3", x, self._layer_3_convs, kernel_size=[3, 3], stride=[1, 1, 1, 1],
                           is_pretrain=is_pretrain)
            x = self._conv("conv4", x, self._layer_4_convs, kernel_size=[3, 3], stride=[1, 1, 1, 1],
                           is_pretrain=is_pretrain)
            x = self._conv("conv5", x, self._layer_5_convs, kernel_size=[3, 3], stride=[1, 1, 1, 1],
                           is_pretrain=is_pretrain)
            x= self._pool("pool1", x, kernel=[1, 3, 3, 1], stride=[1, 2, 2, 1], is_max_pool=True)

            x = self._FC_layer("fc6", x, out_nodes=self._layer_6_full)
            x = self._batch_norm(x)
            x = self._FC_layer("fc7", x, out_nodes=self._layer_6_full)
            x = self._batch_norm(x)
            x = self._FC_layer("fc8", x, out_nodes=self._outsum,withrelu=False)
        return x


    def _optimizer(self, loss, learning_rate, global_step):
        with tf.name_scope("optimizer"):
            optimizer = tf.train.AdamOptimizer(learning_rate=learning_rate)
            #train_op = optimizer.minimize(loss, global_step=global_step)

            grads, variables = zip(*optimizer.compute_gradients(loss))
            grads, global_norm = tf.clip_by_global_norm(grads, 5)
            train_op = optimizer.apply_gradients(zip(grads, variables))
            return train_op

    def _loss(self, logits, labels):
        with tf.name_scope("loss") as scope:
            cross_entropy = tf.nn.softmax_cross_entropy_with_logits(logits=logits, labels=labels, name="cross_entropy")
            loss = tf.reduce_mean(cross_entropy, name="loss")
            tf.summary.scalar(scope + "/loss", loss)
            return loss

    def _accuracy(self, logits, labels):
        with tf.name_scope("accuracy") as scope:
            correct = tf.equal(tf.arg_max(logits, 1), tf.arg_max(labels, 1))
            correct = tf.cast(correct, tf.float32)
            accuracy = tf.reduce_mean(correct) * 100
            tf.summary.scalar(scope + "/accuracy", accuracy)
        return accuracy



    def _pool(self,layer_name, x, kernel=(1, 2, 2, 1), stride=(1, 2, 2, 1), is_max_pool=True):
        if is_max_pool:
            x = tf.nn.max_pool(x, kernel, strides=stride, padding="SAME", name=layer_name)
        else:
            x = tf.nn.avg_pool(x, kernel, strides=stride, padding="SAME", name=layer_name)
        return x

    def _conv(self,layer_name, x, out_channels, kernel_size=(3, 3), stride=(1, 1, 1, 1), is_pretrain=True):
        in_channels = x.get_shape()[-1]
        with tf.variable_scope(layer_name):
            w = tf.get_variable(name='weights',
                                trainable=is_pretrain,
                                shape=[kernel_size[0], kernel_size[1], in_channels, out_channels],
                                initializer=tf.contrib.layers.xavier_initializer())
            b = tf.get_variable(name='biases',
                                trainable=is_pretrain,
                                shape=[out_channels],
                                initializer=tf.constant_initializer(0.0))
            x = tf.nn.conv2d(x, w, stride, padding="SAME", name="conv")
            x = tf.nn.bias_add(x, b, name="bias_add")
            x = tf.nn.relu(x, name="relu")
            return x

    def _batch_norm(self,x):
        epsilon = 1e-3
        batch_mean, batch_var = tf.nn.moments(x, [0])
        x = tf.nn.batch_normalization(x,
                                      mean=batch_mean,
                                      variance=batch_var,
                                      offset=None,
                                      scale=None,
                                      variance_epsilon=epsilon)
        return x

    def _FC_layer(self,layer_name, x, out_nodes,withrelu=True):
        shape = x.get_shape()
        if len(shape) == 4:
            size = shape[1].value * shape[2].value * shape[3].value
        else:
            size = shape[-1].value
        with tf.variable_scope(layer_name):
            w = tf.get_variable(name='weights',
                                shape=[size, out_nodes],
                                initializer=tf.contrib.layers.xavier_initializer())
            b = tf.get_variable(name='biases',
                                shape=[out_nodes],
                                initializer=tf.constant_initializer(0.0))
            flat_x = tf.reshape(x, [-1, size])

            x = tf.nn.bias_add(tf.matmul(flat_x, w), b)
            if withrelu:
                x = tf.nn.relu(x)
            return x


