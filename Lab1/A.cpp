#include <bits/stdc++.h>
using namespace std;
using namespace chrono;
#define int long long
#define double long double
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define vi vector<int>
#define mii map<int, int>
#define maxheap(type) priority_queue<type>
#define minheap(type) priority_queue<type, vector<type>, greater<int>>
#define setbits(x) __builtin_popcountint(x)
#define zrobits(x) __builtin_ctzint(x)
#define mod 1000000007
#define inf 1e18
#define sp(x, y) fixed << setprecision(y) << x
#define endl '\n'
#define deb(x) cout << #x << ": " << x << endl
#define aint(x) x.begin(), x.end()
#define rall(x) (x).rbegin(), (x).rend()
#define yes cout << "YES" << endl
#define no cout << "NO" << endl

#define w(x)  \
    int x;    \
    cin >> x; \
    while (x--)

#define For(n) for (int i = 0; i < n; i++)
#define For1(i, n) for (int i = 0; i < n; i++)
#define RFor(n) for (int i = n - 1; i >= 0; i--)
#define RFor1(i, n) for (int i = n - 1; i >= 0; i--)
template <typename T>
void printList(T *arr, int n)
{
    For(n)
    {
        cout << arr[i] << " ";
    }
    cout << '\n';
}
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int lcm(int a, int b)
{
    return (a * b) / gcd(a, b);
}

vector<bool> generatePrimeNo(int n)
{
    //! time complexity O(N log log N)
    // * to generates prime no prime 1 to N
    vector<bool> prime(n + 1, true);
    prime[0] = false;
    prime[1] = false;
    for (int i = 2; i * i <= n; i++)
    {
        if (prime[i] == true)
        {

            for (int j = 2 * i; j <= n; j += i)
                prime[j] = false;
        }
    }
    return prime;
}
bool isPrime(int n)
{
    //! time complexity O(sqrt(N))
    if (n <= 1)
        return false;
    if (n == 2 || n == 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (int i = 5; i * i <= n; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}
bool compare(int a, int b)
{
    return a > b; // ? for decreasing order
}

void fastio()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
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
int32_t main()
{
    fastio();
    auto start1 = high_resolution_clock::now();
    // ! program starts from here!
    w(t)
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
        // printList<int>(P, n);
        // printList<int>(Q, n);
        cout << MergeSort(Q, 0, n - 1) << endl;
    }
    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop1 - start1);
#ifndef ONLINE_JUDGE
    cerr << "Time elapsed: " << duration.count() << " ms." << endl;
#endif
    return 0;
}