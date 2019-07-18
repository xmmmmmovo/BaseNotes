import numpy as np

if __name__ == '__main__':
    s = np.array([i for i in range(10)])
    s = np.resize(s, (2, 5))
    print(s)
    s = (s - s.mean())/s.std()
    print(s)