import numpy as np
import matplotlib.pyplot as plt # 数据可视化
from model import Linear, Multinomial

def load_data():
    # path = "./data/linear_data.txt"
    path = "./data/temperature.txt"
    raw_data = open(path).read().split("，")
    int_data = np.array(raw_data, dtype=int)
    return int_data

def draw(X):
    plt.scatter(range(len(X)), X)
    plt.show()

def linear(X, y):
    model = Linear()
    model.train(X, y, 1e-4)
    model.draw(X, y)

def multinomial(X, y):
    model = Multinomial()
    model.train(X, y, 5000, 1e-7, 5)
    model.draw(X, y)


if __name__ == '__main__':
    int_data = load_data()
    # draw(int_data)
    # linear(range(len(int_data)), int_data)
    multinomial(range(len(int_data)), int_data)