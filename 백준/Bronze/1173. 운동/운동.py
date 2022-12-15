N, m, M, T, R = map(int, input().split())
ans = 0
health = 0
now = m
while health < N:
    if m+T > M:
        break
    if now+T <= M:
        health += 1
        now += T
    else:
        if now-R < m:
            now = m
        else:
            now -= R
    ans += 1
if health == N:
    print(ans)
else:
    print(-1)
