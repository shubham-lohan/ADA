#include <bits/stdc++.h>
using namespace std;
using namespace chrono;
#define int long long
#define float long double
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
vector<pair<int, int>> points;
float distance(pair<int, int> a, pair<int, int> b)
{
    return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
}
float perimeter(pii A, pii B, pii C)
{
    return distance(A, B) + distance(B, C) + distance(A, C);
}
float bruteForce()
{
    float min_dis = DBL_MAX;
    int n = points.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                float p = perimeter(points[i], points[j], points[k]);
                min_dis = min(min_dis, p);
            }
        }
    }
    return min_dis;
}
int32_t main()
{
    fastio();
    auto start1 = high_resolution_clock::now();
    // ! program starts from here!
    int n;
    cin >> n;

    points.resize(n);
    For(n)
    {

        int x, y;
        cin >> x >> y;
        points[i].first = x;
        points[i].second = y;
    }
    cout << sp(bruteForce(), 9) << endl;
    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop1 - start1);
#ifndef ONLINE_JUDGE
    cerr << "Time elapsed: " << duration.count() << " ms." << endl;
#endif
    return 0;
}