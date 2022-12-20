n = int(input())
dp = list()
dp.append(4)
dp.append(6)
for i in range(2, n):
    dp.append(dp[i-2]+dp[i-1])
print(dp[n-1])
