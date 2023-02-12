import sys
input = sys.stdin.readline

n = int(input())
arr1 = [0]*3
arr2 = [0]*3
for _ in range(n):
    a, b, c = map(int, input().split())
    arr1[0] += a
    arr1[1] += b
    arr1[2] += c
    arr2[0] += a*a
    arr2[1] += b*b
    arr2[2] += c*c
max_sum = max(arr1)
if arr1.count(max_sum) == 1:
    for i in range(3):
        if arr1[i] == max_sum:
            print(i+1, max_sum)
else:
    real_max_sum = max(arr2)
    elected = 0
    for i in range(3):
        if arr2[i]==real_max_sum:
            elected=i
    if arr2.count(real_max_sum) == 1:
        print(elected+1, arr1[elected])
    else:
        print(0, arr1[elected])
