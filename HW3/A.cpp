#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> arr, int k, int ans)
{
    int prev = arr[0];
    k--;
    for (int i = 1; i < arr.size(); i++)
    {
        if (abs(arr[i] - prev) >= ans)
        {
            k--, prev = arr[i];
        }
        if (k == 0)
            return true;
    }
    return false;
}
int k_rain(vector<int> arr, int k)
{
    int n = arr.size();
    int low = 0, high = arr[n - 1] - arr[0];
    int ans = 0;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (!check(arr, k, mid))
            high = mid - 1;
        else
        {
            ans = mid;
            low = mid + 1;
        }
    }
    return ans;
}
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << k_rain(arr, k) << endl;
    return 0;
}