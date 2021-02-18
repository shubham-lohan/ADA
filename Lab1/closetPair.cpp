

#include <bits/stdc++.h>
using namespace std;
#define vpii vector<pair<int, int>>
#define float long double
void print(vpii P)
{
    for (auto x : P)
    {
        cout << x.first << " " << x.second << endl;
    }
}
vpii points;
int compareX(pair<int, int> a, pair<int, int> b)
{
    return a.first < b.first;
}
int compareY(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}
float distance(pair<int, int> a, pair<int, int> b)
{
    return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
}
float bruteForce(vpii P, int n)
{
    float min = FLT_MAX;
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
            if (distance(P[i], P[j]) < min)
                min = distance(P[i], P[j]);
    }
    return min;
}
float stripClosest(vpii strip, int size, float d)
{
    float min = d;
    sort(strip.begin(), strip.end(), compareY);
    
    for (int i = 0; i < size; ++i)
        for (int j = i + 1; j < size && (strip[j].second - strip[i].second) < min; ++j)
            if (distance(strip[i], strip[j]) < min)
                min = distance(strip[i], strip[j]);

    return min;
}
float closestUtil(vpii P, int n)
{
    if (n <= 3)
        return bruteForce(P, n);
    int mid = n / 2;
    pair<int, int> midPoint = P[mid];
    vpii Left;
    vpii Right;
    for (int i = 0; i < mid; i++)
    {
        Left.push_back(P[i]);
    }
    for (int i = mid; i < n; i++)
    {
        Right.push_back(P[i]);
    }
    // print(Left);
    float dl = closestUtil(Left, Left.size());

    float dr = closestUtil(Right, Right.size());
    float d = min(dl, dr);
    vpii strip;
    strip.reserve(n);
    for (int i = 0; i < n; i++)
    {
        if (abs(P[i].first - midPoint.first) < d)
        {
            strip.push_back(P[i]);
        }
    }
    return min(d, stripClosest(strip, strip.size(), d));
}
float closest(vpii P, int n)
{
    sort(P.begin(), P.end(), compareX);
    return closestUtil(P, n);
}

int main()
{
    points = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
    cout << "The smallest distance is " << closest(points, points.size());
    return 0;
}