from sys import stdin

# sys.stdin.readline()이 input()보다 입력 속도 빠름
for _ in range(3):
    num = int(stdin.readline())
    list = []
    for _ in range(0, num):
        list.append(int(stdin.readline()))
    if sum(list) > 0:
        print("+")
    elif sum(list) < 0:
        print("-")
    else:
        print("0")
