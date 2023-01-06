t = int(input())
ans = []
for _ in range(t):
    a = int(input())
    b = int(input())
    ans = [i for i in range(1, b+1)]
    for i in range(a):
        for j in range(1, b):
            ans[j] += ans[j-1]
    print(ans[-1])