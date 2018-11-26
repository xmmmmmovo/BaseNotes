import numpy as np # 矩阵操作

list_test = [1, 2, 3, 4, 5]
list_test.append(1)
print(list_test)

# dict
dict_test = {
    1: "bao",
    2: "歉",
    3: "月"
}
print(dict_test)

# range
for i in range(10):
    print(i)

for i in list_test:
    print(i)

temp = [i + 1 for i in list_test]
print(temp)

# 文件操作
path = "./data/linear_data.txt"
file = open(path)
str = file.read()
print(str)

str_list = str.split("，")
print(str_list)

def function(test = 1):
    return 1, 2
a, b = function()
print(a, b)

class Test:

    def show(self):
        print()
test = Test()
test.show()

x = np.ones(shape=(1,5))
print(x)

x = [[1, 2, 3], [4, 5, 6]]
y = [[1], [2], [3]]
x = np.array(x)
y = np.array(y)
print(x)
print(y)
print((x == 1).astype(int))