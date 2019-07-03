
def fun(num):
    import math

    for i in range(2, num):
        factors = []  # 因子列表，i 每次循环都清空
        for j in range(1, math.floor(i / 2) + 1):
            if i % j == 0:
                factors.append(j)
        if sum(factors) == i:
            print(i, end=',')

if __name__ == '__main__':
    input_num = eval(input('input num :'))
    fun(input_num)
