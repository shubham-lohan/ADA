def calc_median(presum, i, j):
    m1, m2 = (i + j) // 2, (i + j + 1) // 2
    return (presum[j + 1] - presum[m2]) - (presum[m1 + 1] - presum[i])


k = int(input())
arr = sorted(list(map(int, input().split(" "))))
n = len(arr)
print(arr)
presum = [0]
for i in range(len(arr)):
    presum.append(presum[i] + arr[i])
print(presum)
dp = [calc_median(presum, 0, j) for j in range(n)]
print('intial dp ', dp)
for _ in range(2, k + 1):
    for j in range(n - 1, k - 2, -1):
        for i in range(k - 2, j):
            dp[j] = min(dp[j], dp[i]+calc_median(presum, i+1, j))
print(dp)
