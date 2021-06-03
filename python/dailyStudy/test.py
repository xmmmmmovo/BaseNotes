from random import randint, choice

if __name__ == "__main__":
    with open('./file.txt', 'r', encoding='utf-8') as f:
        points = 0
        lines = list(map(lambda it: it.replace('\n', '').split(','), f.readlines()))
        while True:
            sentence = choice(lines)
            res = randint(0, 1)
            print(sentence[int(not res)])
            inp = input("input sentences:")
            if sentence[res] == inp:
                print("congratulations! point add 10!")
                points += 10
            else:
                if input("wrong! please input y/n to choose your next turn") == 'n':
                    break
        print(f"final summary points:{points}")
        f.close()
