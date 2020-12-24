L = [1, 2, 3]

it = iter(L)


def generate_ints(N):
    for i in range(N):
        yield i


gen = generate_ints(3)
