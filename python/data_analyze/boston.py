from sklearn.datasets import load_boston
import matplotlib.pyplot as plt

# 读取数据集
dataset = load_boston()

# 获取数据与标签
x_data = dataset.data
y_data = dataset.target
name_data = dataset.feature_names

# 绘图
for i in range(13):
    plt.subplot(7, 2, i + 1)
    plt.scatter(x_data[:, i], y_data, s=20)
    plt.title(name_data[i])
    plt.show

# 数据处理
x_data = dataset.data
y_data = dataset.target
i_ = []
for i in range(len(y_data)):
    if y_data[i] == 50:
        i_.append(i)
name_data = dataset.feature_names
j_ = []

# 获取所有数据集
for i in range(13):
    if name_data[i] == 'RM' or name_data[i] == 'PTRATIO' or name_data[i] == 'LSTAT':
        continue
    j_.append(i)

# 删除测试数据集
x_data = delete(x_data, j_, axis=1)

from sklearn.cross_validation import train_test_split

# 切分数据集并赋值
X_train, X_test, y_train, y_test = train_test_split(x_data, y_data, random_state=0, test_size=0.20)
print(len(X_train))
print(len(X_test))
print(len(y_train))
print(len(y_test))

# 调库人
from sklearn import preprocessing

# 这里直接调库了
min_max_scaler = preprocessing.MinMaxScaler()

# 转换为库队应的数据类型
X_train = min_max_scaler.fit_transform(X_train)
X_test = min_max_scaler.fit_transform(X_test)
y_train = min_max_scaler.fit_transform(y_train.reshape(-1, 1))
y_test = min_max_scaler.fit_transform(y_test.reshape(-1, 1))

from sklearn.linear_model import LinearRegression

# 这里新建一个线性回归器
lr = LinearRegression()

# 训练
lr.fit(X_train, y_train)

# 预测
lr_y_predict = lr.predict(X_test)
from sklearn.metrics import r2_score

# 检测r2数值
score = r2_score(y_test, lr_y_predict)
print(score)
