#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
int recur_candy(vector<int> &arr, int my_candy, int index = 0)
{
    if (index == arr.size())
        return 0;
    if (arr[index] == my_candy)
        return 1 + recur_candy(arr, my_candy, index + 1);
    int a = recur_candy(arr, my_candy, index + 1);
    int b = recur_candy(arr, arr[index], index + 1) - 1;
    return max(a, b);
}
int recurDP_candy(vector<int> &arr, int my_candy, vector<vector<int>> &memo, int index = 0)
{
    if (index == arr.size())
        return 0;

    if (memo[index][my_candy] != INT_MIN)
        return memo[index][my_candy];
    if (arr[index] == my_candy)
        memo[index][my_candy] = 1 + recurDP_candy(arr, my_candy, memo, index + 1);
    else
        memo[index][my_candy] = max(recurDP_candy(arr, my_candy, memo, index + 1), recurDP_candy(arr, arr[index], memo, index + 1) - 1);

    return memo[index][my_candy];
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<vector<int>> memo(n, vector<int>(4, INT_MIN));
    cout << recurDP_candy(arr, 1, memo) << endl;
}