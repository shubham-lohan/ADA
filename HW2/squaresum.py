# arr = [1, 4, 2, 3, 5]
n = int(input())
arr = list(map(int, input().split()))
n = len(arr)
dp = [[[0, 0]for i in range(n)]for i in range(n)]
for i in range(n):
    dp[i][i][0] = arr[i]
for i in range(1, n):
    l = 0
    r = i
    for j in range(n - i):
        dp[l][r][0] = dp[l][l][0] + dp[l + 1][r][0]
        a = dp[l][l][0] ** 2 + dp[l + 1][r][0] ** 2
        b = dp[l][l][1] + dp[l + 1][r][1]
        c = dp[r][r][0] ** 2 + dp[l][r - 1][0] ** 2 + \
            dp[r][r][1] + dp[l][r - 1][1]
        dp[l][r][1] = max(a+b, c)
        l += 1
        r += 1

for i in dp:
    print(*i)
