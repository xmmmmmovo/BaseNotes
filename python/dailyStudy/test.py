import os
import shutil

if __name__ == "__main__":
    # os.listdir("/Users/xmmmmmovo/Library/Rime")
    base = "/Users/xmmmmmovo/Downloads/rime-dict-master"
    dirs = os.listdir(base)
    for d in dirs:
        if not os.path.isdir(f"{base}/{d}"):
            # for dd in os.listdir(f"{base}/{d}"):
            #     shutil.copyfile(f"{base}/{d}/{dd}", f"{base}/{dd}")
            print(d[:-10])

