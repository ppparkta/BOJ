arr = []
ans = 0
for i in range(8):
    arr.append(list(map(str, input())))
for i in range(8):
    for j in range(8):
        if (i+j) % 2 == 0 and arr[i][j] == 'F':
            ans += 1
print(ans)
