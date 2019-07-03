

def fun(num):
    count = 0
    for a in range(1, num + 1):
        # print(a)
        for b in range(1, a + 1):
            for c in range(1, b + 1):
                for d in range(1, c + 1):
                    if a * a + b * b + c * c + d * d == num:
                        count+=1
                        print(a.__str__() + " " + b.__str__() + " " + c.__str__() + " " + d.__str__())
    print(count)


if __name__ == '__main__':
    input_num = eval(input('num is :'))
    fun(input_num)