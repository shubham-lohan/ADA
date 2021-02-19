#include <iostream>
#include <climits>
#include <vector>
using namespace std;
#define vi vector<int>
#define V_SUM_MAX 1000
#define N_MAX 100
#define W_MAX 10000000
int dp[V_SUM_MAX + 1][N_MAX];
bool v[V_SUM_MAX + 1][N_MAX];

int knapsuck(int r, int i, vi &weight, vi value, int n)
{
    if (r <= 0)
        return 0;
    if (i == n)
        return W_MAX;
    if (v[r][i])
        return dp[r][i];
    v[r][i] = 1;
    dp[r][i] = min(knapsuck(r, i + 1, weight, value, n), weight[i] + knapsuck(r - value[i], i + 1, weight, value, n));
    return dp[r][i];
}
int solve(vi weight, vi &value, int n, int w)
{
    for (int i = V_SUM_MAX; i >= 0; i--)
    {
        if (knapsuck(i, 0, weight, value, n) <= w)
            return i;
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, w;
    cin >> n >> w;
    vi weight(n);
    vi value(n);
    for (int i = 0; i < n; i++)
    {
        cin >> value[i] >> weight[i];
    }
    cout << solve(weight, value, n, w) << '\n';

    return 0;
}
