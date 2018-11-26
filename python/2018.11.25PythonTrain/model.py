import numpy as np
import matplotlib.pyplot as plt

class Linear:
    def __init__(self):
        # 0初始化极其不好！
        # 一般使用正态分布初始化！
        self.alpha = 0.0 # 通道
        self.bias = 0.0

    def predict(self, x, flag = False):
        x = np.array(x)
        return self.alpha * x + self.bias

    def draw(self, X, y):
        X = np.array(X)
        y = np.array(y)
        plt.scatter(X, y, color="R")
        y_temp = self.predict(X)
        plt.plot(X, y_temp)
        plt.show()

    def train(self, X, label, learning_rate = 1e-3, step = 5000, batch_size = 5):
        # 转换成np的标准格式
        X = np.array(X)
        label = np.array(label)
        for i in range(step):
            # X 训练集 learning_rate 学习率 step总长 batch_size 传参大小
            random_index = np.random.randint(low = 0, high = len(X), size = batch_size) # low, high中选取size个数
            # 获取训练数据
            X_train = X[random_index] # 随机获取点的横轴
            y_train = label[random_index] # 随机获取点的纵轴

            # 关键点
            y_pre = self.predict(X_train) # 此时y_pre : (1, 5)
            loss = (y_train - y_pre) ** 2 # 方差
            print("loss:",np.sum(loss))
            dloss_pre = -2 * (y_train - y_pre) # 方差求导
            df_alpha = X_train
            dloss_alpha = dloss_pre * df_alpha * learning_rate # alpha变化（导数

            # 优化
            self.alpha -= np.mean(dloss_alpha)
            self.bias -= np.mean(dloss_pre) * learning_rate



class Multinomial:

    def __init__(self):
        self.alpha = 0.0
        self.beta = 0.0
        self.bias = 0.0
        self.gama = 1.0

        self.sin_a = 0.0
        self.sin_b = 0.0
        self.sin_bias = 0.0

        self.losses = []

    def predict(self, x):
        """
        y = a * x^2 + b * x + bias + gama * sin( sin_a * x^2 + sin_b * x + sin_bias)
        :param x:
        :return:
        """
        x = (x - np.mean(x)) / np.std(x)
        return self.alpha * x ** 2 + self.beta * x + self.bias + self.gama * np.sin(
            self.sin_a * x ** 2 + self.beta * x + self.sin_bias)

    def calculateLoss(self, y, y_pre):
        """
        计算误差
        :param y:
        :param y_pre:
        :return:
        """
        loss = np.mean((y - y_pre) ** 2)
        print("loss:%0.5f" % loss)
        self.losses.append(loss)

    def train(self, X, label, step, learning_rate = 10000, batch=1):
        """
        训练
        :param X:
        :param label:
        :param step:
        :param learning_rate:
        :param batch:
        :return:
        """
        X = np.array(X)
        X = (X - np.mean(X)) / np.std(X)
        label = np.array(label)

        for i in range(step):
            random_index = np.random.randint(low=0, high=len(X), size=batch)

            X_train = X[random_index]
            y = label[random_index]

            y_pre = self.predict(X_train)
            self.calculateLoss(y, y_pre)

            lossdf = -2 * (y - y_pre)

            dalpha = np.mean(lossdf * (X_train ** 2) * learning_rate)
            dbeta = np.mean(lossdf * X_train * learning_rate)
            dbias = np.mean(lossdf * learning_rate)

            dgama = np.mean(lossdf * np.sin(self.sin_a * X_train ** 2 + self.beta * X_train + self.sin_bias))
            dsin_a = np.mean(lossdf * self.gama * np.cos(
                self.sin_a * X_train ** 2 + self.beta * X_train + self.sin_bias) * X_train ** 2)
            dsin_b = np.mean(lossdf * self.gama * np.cos(
                self.sin_a * X_train ** 2 + self.beta * X_train + self.sin_bias) * X_train)
            dsin_bias = np.mean(lossdf * self.gama * np.cos(
                self.sin_a * X_train ** 2 + self.beta * X_train + self.sin_bias))

            self.alpha -= dalpha
            self.bias -= dbias
            self.beta -= dbeta
            self.gama -= dgama
            self.sin_a -= dsin_a
            self.sin_b -= dsin_b
            self.sin_bias -= dsin_bias

            # print(dalpha, dbeta, dbias, dgama, dsin_a, dsin_b, dsin_bias)

    def draw(self, X, y):
        plt.subplot(2, 1, 1)
        plt.scatter(X, y)
        x_temp = np.arange(start=-1, stop=len(y) + 5, step=0.1)
        y_pre = self.predict(x_temp)
        plt.plot(x_temp, y_pre)

        plt.subplot(2, 1, 2)
        plt.plot(range(len(self.losses)), self.losses)
        plt.show()