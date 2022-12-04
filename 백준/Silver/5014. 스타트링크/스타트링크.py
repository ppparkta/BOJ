from collections import deque


def bfs(s):
    q = deque()
    q.append(s)
    visits[s] = 1
    ans[s] += 1
    while q:
        y = q.popleft()
        for i in range(2):
            ny = y+ud[i]
            if f > ny >= 0 and visits[ny] == 0:
                q.append(ny)
                ans[ny] = ans[y]+1
                visits[ny] = 1


if __name__ == "__main__":
    f, s, g, u, d = map(int, input().split())
    ud = [u, -d]
    ans = [-1 for i in range(f)]
    visits = [0 for i in range(f)]
    bfs(s-1)
    if ans[g-1] == -1:
        print("use the stairs")
    else:
        print(ans[g-1])
