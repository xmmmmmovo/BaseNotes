import json

def loadLaws():
    file = open("D:\\download\download from server\\cail2018_big\\cail2018_big.json",
                encoding='utf-8')
    law_line = json.load(file)
    for law in law_line:
        print(law)



if __name__ == '__main__':
    loadLaws()