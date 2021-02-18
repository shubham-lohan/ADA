#include <iostream>
using namespace std;
#define For(n) for (int i = 0; i < n; i++)
// #define int long long
int merge(int arr[], int low, int mid, int high)
{
    int s1 = mid - low + 1; // [1 2 3 4 5 6 7] low= 2 high=6 mid=4
    int s2 = high - mid;
    int L[s1], R[s2];
    int count_inv = 0;
    for (int i = 0; i < s1; i++)
    {
        L[i] = arr[low + i];
    }
    for (int i = 0; i < s2; i++)
    {
        R[i] = arr[mid + 1 + i];
    }
    int i = 0, j = 0, k = low;
    while (i < s1 && j < s2)
    {
        if (L[i] <= R[j])
        {
            arr[k++] = L[i++];
        }
        else // L[i]>R[j]
        {
            arr[k++] = R[j++];
            // count_inv += mid - i + 1;
            count_inv += s1 - i;
        }
    }
    while (i < s1)
    {
        arr[k++] = L[i++];
    }
    while (j < s2)
    {
        arr[k++] = R[j++];
    }
    return count_inv;
}
int MergeSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int mid = low + (high - low) / 2;
        int left_inv = MergeSort(arr, low, mid);
        int right_inv = MergeSort(arr, mid + 1, high);
        int split_inv = merge(arr, low, mid, high);
        return left_inv + right_inv + split_inv;
    }
    return 0;
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << MergeSort(arr, 0, n - 1) << endl;
    //     // for (int i = 0; i < n; i++)
    //     // {
    //     //     cout << arr[i] << " ";
    //     // }
}