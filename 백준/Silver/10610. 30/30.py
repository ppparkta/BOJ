a = list(input())
a.sort(reverse=True)
b = False
c = 0
for i in a:
    if i == '0':
        b = True
    c += int(i)
if not b or c % 3 != 0:
    print(-1)
else:
    print(''.join(a))
