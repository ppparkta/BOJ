n = int(input())
k = 0
while k < n:
    ans = []
    tmp = []
    s = input()
    for i in s:
        if i == '>':
            if tmp:
                ans.append(tmp.pop())
        elif i == '<':
            if ans:
                tmp.append(ans.pop())
        elif i == '-':
            if ans:
                ans.pop()
        else:
            ans.append(i)
    print("".join(ans)+"".join(reversed(tmp)))
    k += 1