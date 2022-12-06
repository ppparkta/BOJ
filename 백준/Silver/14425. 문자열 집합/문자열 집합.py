import sys

input=sys.stdin.readline
n, m = map(int, input().split())
arr = {}
for i in range(n):
    s = input()
    arr[s] = 1
for i in range(m):
    s = input()
    if s not in arr:
        continue
    else:
        arr[s] += 1
ans = 0
for i in arr:
    if arr[i] > 1:
        ans += arr[i]-1
print(ans)
