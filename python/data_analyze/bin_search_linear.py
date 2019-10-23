def f(x):
    return x ** 5 - 3 * x + 1


def calcu_pos(a: float, b: float, limit: float):
    mid = (a + b) / 2
    while f(mid) != 0 and abs(a - b) >= limit:
        if f(a) * f(mid) < 0:
            a = mid
        else:
            b = mid
        mid = (a + b) / 2
    return mid


if __name__ == '__main__':
    strs = input().split()
    print(strs)
    ans = calcu_pos(float(strs[0]), float(strs[1]), float(strs[2]))
    print(str(ans))
