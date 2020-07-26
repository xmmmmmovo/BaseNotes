# !/usr/bin/env python3

class Stack:
    def __init__(self):
        self.s = []

    def push(self, v):
        self.s.append(v)

    def pop(self):
        return self.s.pop()

    def __bool__(self):
        return not not self.s

    def __len__(self):
        return len(self.s)

    def __str__(self):
        return str(self.s)


class Queue:
    def __init__(self):
        self.H = Stack()
        self.T = Stack()
        self.H1 = Stack()
        self.HR = Stack()
        self.T1 = Stack()
        self.h = Stack()
        self.h1 = Stack()
        self.deleted = 0

    def enqueue(self, v):
        if self._copy():
            self.T1.push(v)
        else:
            self.T.push(v)

    def dequeue(self):
        if self._copy():
            self.deleted += 1
            return self.h.pop()
        else:
            self.h.pop()
            return self.H.pop()

    def debug(self):
        print('---inner status---')
        print(f'self.T: {self.T}')
        print(f'self.H: {self.H}')
        print(f'self.T1: {self.T1}')
        print(f'self.H1: {self.H1}')
        print(f'self.HR: {self.HR}')
        print(f'self.h: {self.h}')
        print(f'self.h1: {self.h1}')
        print(f'self.deleted: {self.deleted}')
        print('---inner status end---')

    def _copy(self):
        if len(self.T) < len(self.H) + 1 and not self.HR:
            return False

        # self._copy_step()
        status = self._copy_step()
        if status == False:
            self.T = self.T1
            self.T1 = Stack()
            self.H = self.H1
            self.H1 = Stack()
            self.HR = Stack()
            self.h = self.h1
            self.h1 = Stack()
            self.deleted = 0
        return status

    def _copy_step(self):
        '''copy finished return False else True'''
        if self.T:
            v = self.T.pop()
            self.H1.push(v)
            self.h1.push(v)
        if self.H:
            self.HR.push(self.H.pop())
        if not self.T and not self.H:
            if len(self.HR) <= self.deleted:
                return False
            else:
                v = self.HR.pop()
                self.H1.push(v)
                self.h1.push(v)
                if len(self.HR) <= self.deleted:
                    return False
                else:
                    return True
        else:
            return True


if __name__ == '__main__':
    q = Queue()
    for i in range(20):
        q.enqueue(i)
        q.debug()
        if i in [5, 8, 14, 15, 19]:
            for _ in range(2):
                print(q.dequeue())
    for _ in range(10):
        print(q.dequeue())