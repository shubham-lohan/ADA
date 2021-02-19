dp = []
n = int(input())
arr = list(map(int, input().split()))
for i in range(n+1):
    dp.append([0, 0, 0])
mycandy = [0, 1, 2]
for i in range(1, n+1):
    for j in range(3):
        if mycandy[j] == arr[i-1]:
            dp[i][j] = 1+dp[i-1][j]
        else:
            dp[i][j] = max(-1+dp[i-1][arr[i-1]], dp[i-1][j])
print(dp[n][2])
