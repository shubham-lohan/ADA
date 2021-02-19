#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
// no of ways
int ways(int n)
{
    if (n == 0)
        return 1;
    if (n < 0)
        return 0;
    return ways(n - 1) + ways(n - 3) + ways(n - 4);
}
int recurDP_ways(int n, vector<int> memo)
{
    if (n == 0)
        return 1;
    if (n < 0)
        return 0;
    if (memo[n] != -1)
        return memo[n];
    // cout << n << endl;
    // memo[n - 1] = recurDP_ways(n - 1, memo);
    // memo[n - 3] = recurDP_ways(n - 3, memo);
    // memo[n - 4] = recurDP_ways(n - 4, memo);
    // memo[n] = memo[n - 1] + memo[n - 3] + memo[n - 4];
    memo[n] = recurDP_ways(n - 1, memo) + recurDP_ways(n - 3, memo) + recurDP_ways(n - 4, memo);
    return memo[n];
    // return ways(n - 1) + ways(n - 3) + ways(n - 4);
}
int main()
{
    int n;
    cin >> n;
    // vector<int> arr(n);
    // for (auto &x : arr)
    //     cin >> x;
    // for (auto x : arr)
    //     cout << x;
    vector<int> memo(n + 1, -1);
    // int memo[n + 1];
    // // memset(memo, -1, n + 1);
    // fill(memo, memo + n + 1, -1);
    // cout << ways(n) << endl;
    cout << recurDP_ways(n, memo) << endl;
    return 0;
}