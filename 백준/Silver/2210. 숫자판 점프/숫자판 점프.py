arr = [list(map(int, input().split())) for _ in range(5)]
ans = set()
d = [(0, 1), (0, -1), (1, 0), (-1, 0)]


def dfs(y, x, s):
    s += str(arr[y][x])
    if len(s) == 6:
        ans.add(s)
        return
    for dx, dy in d:
        ny = dy+y
        nx = dx+x
        if 0 <= ny < 5 and 0 <= nx < 5:
            dfs(ny, nx, s)


for i in range(5):
    for j in range(5):
        dfs(i, j, "")

print(len(ans))
