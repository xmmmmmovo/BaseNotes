#!/usr/bin/env python3
if __name__ == '__main__':
    a, b = input().split(' ')
    a = int(a)
    b = int(b)
    r = 1

    while(r):
        r = a % b
        a = b
        b = r

    print(a)