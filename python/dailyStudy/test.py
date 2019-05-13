import random
import matplotlib.pyplot as p

input = int(input('输入生成点的数量：'))
arr = [[0] * 3 for i in range(input)]
x = [[0] * 2 for a in range(int(input * (input - 1) / 2))]
y = [[0] * 2 for b in range(int(input * (input - 1) / 2))]
fg = p.figure()
cn = fg.add_subplot(1, 1, 1)
cn.set_xlim(0, 1000)
cn.set_ylim(0, 1000)
p.ion()
for i in range(input):
    arr[i][0] = random.randrange(1000)
    arr[i][1] = random.randrange(1000)
    arr[i][2] = 0


def judge(inp):
    n = 0
    for i in range(inp):
        for j in range(i + 1, inp):
            a = arr[j][1] - arr[i][1]
            b = arr[i][0] - arr[j][0]
            c = (arr[i][0] * arr[j][1]) - (arr[i][1] * arr[j][0])
            sign1 = 0
            sign2 = 0
            x[n][0] = arr[i][0]
            x[n][1] = arr[j][0]
            y[n][0] = arr[i][1]
            y[n][1] = arr[j][1]
            n += 1
            for k in range(inp):
                if k == j or k == i:
                    continue
                if a * arr[k][0] + b * arr[k][1] == c:
                    sign1 += 1
                    sign2 += 1
                if a * arr[k][0] + b * arr[k][1] > c:
                    sign1 += 1
                if a * arr[k][0] + b * arr[k][1] < c:
                    sign2 += 1
                if (sign1 == (inp - 2)) or (sign2 == (inp - 2)):
                    arr[i][2] = 1
                    arr[j][2] = 1
                    cn.scatter(arr[i][0], arr[i][1], color='g', marker='.')
                    cn.scatter(arr[j][0], arr[j][1], color='g', marker='.')
                    cn.plot(x[n - 1], y[n - 1], color='b')
            cn.scatter(arr[i][0], arr[i][1], color='g', marker='.')
            cn.scatter(arr[j][0], arr[j][1], color='g', marker='.')
            cn.plot(x[n - 1], y[n - 1], color='r')
            p.pause(0.1)
            cn.lines.pop()


judge(input)
print("凸包坐标点：")
for i in range(input):
    if arr[i][2] == 1:
        print((arr[i][0], arr[i][1]))