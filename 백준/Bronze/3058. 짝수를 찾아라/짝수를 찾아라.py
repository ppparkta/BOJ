t = int(input())
for _ in range(t):
    a = []
    temp = list(map(int, input().split()))
    for i in temp:
        if i % 2 == 0:
            a.append(i)
    print(sum(a), min(a))
