
def fun(num):
    n = [[0 for i in range(num)] for i in range(num)]
    k = 1
    for i in range(0, int(num/2) + 1):
        for j in range(i, num - 1 - i):
            n[j][i] = k
            k +=1
        for j in range(i, num - 1 - i):
            n[num - 1 - i][j] = k
            k+=1
        for j in range(num - 1 - i, i, -1):
            n[j][num - 1 - i] = k
            k += 1
        for j in range(num-1-i, i, -1):
            n[i][j] = k
            k += 1

    if num%2 == 1:
        i = int(num/2)
        n[i][i] = int(num * num)

    for i in range(0, num):
        for j in range(0, num):
            print(str(n[i][j]) + "\t", end='')
        print()

if __name__ == '__main__':
    input_num = eval(input('input num:'))
    fun(input_num)