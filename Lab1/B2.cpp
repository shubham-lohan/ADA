#include <bits/stdc++.h>
using namespace std;
using namespace chrono;
#define int long long
#define float long double
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define vi vector<int>
#define vpii vector<pii>
#define mii map<int, int>
#define maxheap(type) priority_queue<type>
#define minheap(type) priority_queue<type, vector<type>, greater<int>>
#define setbits(x) __builtin_popcountint(x)
#define zrobits(x) __builtin_ctzint(x)
#define mod 1000000007
#define inf 1e9
#define sp(x, y) fixed << setprecision(y) << x
#define endl '\n'
#define deb(x) cout << #x << ": " << x << endl
#define all(x) x.begin(), x.end()
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
bool compareX(pii a, pii b)
{
    if (a.first != b.first)
        return a.first < b.first;
    return a.second < b.second;
}
bool compareY(pii a, pii &b)
{
    if (a.second != b.second)
        return a.second < b.second;
    return a.first < b.first;
}
float dist(pii &a, pii &b)
{
    return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
}

float perimeter(pii &a, pii &b, pii &c)
{
    return dist(a, b) + dist(b, c) + dist(c, a);
}

float solve(vpii &points, vpii &points_Y, int n)
{
    if (n < 3)
        return inf;
    int left = n / 2;
    int right = n - left;
    pii midPoint = points[left];
    vpii L_y, R_Y, L, R;
    for (int i = 0; i < left; i++)
    {
        L.pb(points[i]);
    }
    for (int i = left; i < n; i++)
    {
        R.pb(points[i]);
    }
    For1(i, n)
    {
        if (compareX(points_Y[i], midPoint))
        {
            L_y.pb(points_Y[i]);
        }
        else
        {
            R_Y.pb(points_Y[i]);
        }
    }
    float res = solve(L, L_y, left);
    res = min(res, solve(R, R_Y, right));
    vpii strip;
    int margin = res;
    int start = 0;
    for (int i = 0; i < n; ++i)
    {
        pii p = points_Y[i];
        if (abs(p.first - midPoint.first) > margin)
            continue;
        while (start < strip.size() && p.second - strip[start].second > margin)
            ++start;
        for (int i = start; i < strip.size(); ++i)
        {
            for (int j = i + 1; j < strip.size(); ++j)
            {
                res = min(res, perimeter(p, strip[i], strip[j]));
            }
        }
        strip.pb(p);
    }
    return res;
}
void fastio()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
int32_t main()
{
    fastio();
    auto start1 = high_resolution_clock::now();
    // ! program starts from here!
    int n;
    cin >> n;
    vpii points(n);
    points.reserve(n);
    For(n)
    {
        int x, y;
        cin >> x >> y;
        points[i].first = x;
        points[i].second = y;
    }
    sort(all(points), compareX);
    vpii points_Y = points;
    sort(all(points_Y), compareY);
    float res = solve(points, points_Y, points.size());
    cout << sp(res, 10) << endl;
    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop1 - start1);
#ifndef ONLINE_JUDGE
    cerr << "Time elapsed: " << duration.count() << " ms." << endl;
#endif
}