using namespace std;
#include <iostream>
#include <fstream>
#include <algorithm>
#include <array>
#include <chrono>
#include <bitset>
#include <cmath>
#include <iterator>
#include <functional>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>
// #include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
//!-------------------------------------------Macros-------------------------------------------------------
#define int long long int
#define float long double
#define fbo find_by_order
#define ook order_of_key
#define pii pair<int, int>
#define vpii vector<pair<int, int>>
#define vi vector<int>
#define mii map<int, int>
#define maxheap(type) priority_queue<type>
#define minheap(type) priority_queue<type, vector<type>, greater<int>>
#define setbits(x) __builtin_popcountll(x) // to count no of 1's
#define zrobits(x) __builtin_ctzint(x)
#define mod (int)1e10 + 7
#define inf 1e18
#define sp(x, y) fixed << setprecision(y) << x
#define flush fflush(stdout)
#define mid(a, b) (a + (b - a) / 2)
#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define fastio() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define w(x)  \
    int x;    \
    cin >> x; \
    while (x--)
//?------------------------------For-loop Macro----------------------------------------------
#define GET3(a, b, c, n, ...) n
#define F_OR3(i, n, s) for (int i = 0; i < n; i += (s))
#define F_OR2(i, n) F_OR3(i, n, 1)
#define F_OR1(n) F_OR2(i, n)
#define F_ORC(...) GET3(__VA_ARGS__, F_OR3, F_OR2, F_OR1)
#define For(...)       \
    F_ORC(__VA_ARGS__) \
    (__VA_ARGS__)
#define rF_OR3(i, n, s) for (int i = n - 1; i >= 0; i -= (s))
#define rF_OR2(i, n) rF_OR3(i, n, 1)
#define rF_OR1(n) rF_OR2(i, n)
#define rF_ORC(...) GET3(__VA_ARGS__, rF_OR3, rF_OR2, rF_OR1)
#define rFor(...) rF_ORC(__VA_ARGS__)(__VA_ARGS__)
//!-------------------------------------------Debugger--------------------------------------------------------
void __print(const int &x) { cerr << x; }
void __print(const float &x) { cerr << x; }
void __print(const double &x) { cerr << x; }
void __print(const char &x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(const bool &x) { cerr << (x ? "true" : "false"); }

template <typename T, typename V>
void __print(const pair<T, V> &x) { cerr << '(', __print(x.first), cerr << ',', __print(x.second), cerr << ')'; }
template <typename T>
void __print(const T &x)
{
    int f = 0;
    cerr << "{ ";
    for (auto i : x)
        cerr << (f++ ? "," : ""), __print(i);
    cerr << " } ";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v)
{
    __print(t);
    if (sizeof...(v))
        cerr << ", ";
    _print(v...);
}
#ifndef ONLINE_JUDGE
#define deb(x...)               \
    cerr << "[" << #x << ":  "; \
    _print(x)
#else
#define deb(x...)
#endif

template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v)
{
    for (int i = 0; i < v.size(); ++i)
    {
        os << v[i];
        if (i != v.size() - 1)
            os << " ";
    }
    os << "\n";
    return os;
}
template <typename T, int n>
void print(T const (&arr)[n])
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
    cout << '\n';
}
//!----------------------------------------------------Algorithms-------------------------------------------------------
vector<bool> sieve(int n)
{
    //! time complexity O(N log(log N) )
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
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int lcm(int a, int b) { return (a * b) / gcd(a, b); }
template <typename T, typename V>
double divide(T a, V b) { return (double)a / b; }
//!-------------------------------------------------------------------------------------------------------------
void fileIO()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout), freopen("error.txt", "w", stderr);
#endif
}
//?--------------------------------------------------------------------------------------------------------------
void solve()
{
    int n, B;
    cin >> n >> B;
    int ans = INT64_MIN;
    For(n)
    {
        int a, b;
        cin >> a >> b;
        ans = max(a * B * B + b*B, ans);
    }
    cout << ans << endl;
}
//!-----------------------------------------------------------------------------------------------------
int32_t main()
{
    fastio();
    // fileIO();
    auto start = std::chrono::high_resolution_clock::now();
    solve();
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
#ifndef ONLINE_JUDGE
    cerr << "\nTime elapsed: " << duration.count() << " ms." << endl;
#endif
    return 0;
}