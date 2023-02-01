while True:
    n=int(input())
    if n == 0:
        break
    a = []
    for i in range(n):
        a.append(input())
        a.sort(key=str.lower)
    print(a[0])