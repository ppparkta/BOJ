s = input().split('-')
ans = []
for i in s:
    cnt = 0
    n = i.split('+')
    for j in n:
        cnt += int(j)
    ans.append(cnt)
a = ans[0]
for i in range(1, len(ans)):
    a -= ans[i]
print(a)
