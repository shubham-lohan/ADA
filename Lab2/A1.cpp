// #include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
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
#define int long long int
#define float long double
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define fbo find_by_order
#define ook order_of_key
#define pii pair<int, int>
#define vpii vector<pair<int, int>>
#define vi vector<int>
#define mii map<int, int>
#define maxheap(type) priority_queue<type>
#define minheap(type) priority_queue<type, vector<type>, greater<int>>
#define setbits(x) __builtin_popcountint(x)
#define zrobits(x) __builtin_ctzint(x)
#define mod 1e10 + 7
#define inf 1e18
#define sp(x, y) fixed << setprecision(y) << x
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define w(x)  \
    int x;    \
    cin >> x; \
    while (x--)
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
void __print(int x)
{
    cerr << x;
}
void __print(float x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }

template <typename T, typename V>
void __print(const pair<T, V> &x)
{
    cerr << '(';
    __print(x.first);
    cerr << ',';
    __print(x.second);
    cerr << ')';
}
template <typename T>
void __print(const T &x)
{
    int f = 0;
    cerr << "{ ";
    for (auto i : x)
        cerr << (f++ ? "," : ""), __print(i);
    cerr << " } ";
}
void _print() { cerr << "]\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"; }
template <typename T, typename... V>
void _print(T t, V... v)
{
    __print(t);
    if (sizeof...(v))
        cerr << ", ";
    _print(v...);
}
#ifndef ONLINE_JUDGE
#define deb(x...)                 \
    cerr << "[" << #x << ":->  "; \
    _print(x)
#else
#define deb(x...)
#endif
//!----------------------------------------------------Algorithms-------------------------------------------------------
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
bool compare(int a, int b)
{
    return a > b;
}
//?--------------------------------------------------------------------------------------------------------------
void solve()
{
    vi dp(101, __LONG_LONG_MAX__);
    vi visited(101, 0);
    int i = 0, diff = 1;
    for (int i = 1, dif = 1; i + dif <= 100; ++i)
    {
        if (!visited[i])
        {
            visited[i] = 1;
            int j = i + diff;
            visited[j] = 1;
            dp[i] = j;
            diff++;
        }
    }
    // w(t)
    // {
    int a, b;
    cin >> a >> b;

    if (a == 0 && b == 0)
    {
        no;
        return;
        // continue;
    }
    if (dp[min(a, b)] == max(a, b))
        no;
    else
        yes;
    // }
}
void fileIO()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
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