n = input()
ans = ""
for i in n:
    if i >= 'a':
        ans += i.upper()
    else:
        ans += i.lower()
print(ans)
