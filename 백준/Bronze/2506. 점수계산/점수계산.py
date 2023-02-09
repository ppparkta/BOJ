n = int(input())
ans = 0
switch = 1
arr = list(map(int, input().split()))
for i in arr:
    if i == 1:
        ans += switch
        switch += 1
    elif i == 0:
        switch = 1
print(ans)
