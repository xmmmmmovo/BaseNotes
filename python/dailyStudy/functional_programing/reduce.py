from functools import reduce
from operator import mul

if __name__ == '__main__':
    print(reduce(mul, range(1, 11)))
