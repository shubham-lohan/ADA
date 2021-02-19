#include <iostream>
#include <vector>
using namespace std;
int solve(int arr[], int n, int k, int index = 0, int ans = 0)
{
    if (index >= n || k == 0)
        return ans;
    return max(solve(arr, n, k - 1, index + 2, ans + arr[index]), solve(arr, n, k, index + 1, ans));
}
int main()
{
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << solve(arr, n, k) << endl;
}