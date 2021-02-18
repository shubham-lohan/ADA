#include "countinversion.cpp"
#include <algorithm>
int main()
{
    int n;
    cin >> n;
    int x;
    int P[n], Q[n];
    For(n)
    {
        cin >> x;
        P[x - 1] = i;
    }
    For(n)
    {
        cin >> x;
        Q[i] = P[x - 1];
    }
    cout << MergeSort(Q, 0, n - 1);

    return 0;
}