#include <bits/stdc++.h>
using namespace std;
#define Graph map<int, vector<pair<int, int>>>
struct Compare
{
    bool operator()(const pair<int, int> &a, const pair<int, int> &b)
    {
        return -1 * a.second > -1 * b.second;
    }
};
int MST(Graph &graph, int n)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
    int src = 0;
    int key[n];
    int ans = 0;
    pair<int, int> parent[n];
    bool inMST[n];
    fill(key, key + n, INT_MAX);
    fill(inMST, inMST + n, false);
    pq.push(make_pair(src, 0));
    key[src] = 0;
    while (!pq.empty())
    {
        auto temp = pq.top();
        pq.pop();
        int u = temp.first;
        inMST[u] = true;
        for (int i = 0; i < graph[u].size(); i++)
        {
            pair<int, int> y = graph[u][i];
            int v = y.first;
            int weight = y.second;
            if (!inMST[v] && key[v] > weight)
            {
                key[v] = weight;
                parent[v].first = u;
                parent[v].second = weight;
                pq.push(make_pair(v, key[v]));
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        ans += parent[i].second;
    }
    for (int i = 1; i < n; i++)
    {
        cout << parent[i].first + 1 << "---(" << parent[i].second << ")--->" << i + 1 << endl;
    }
    return ans;
}
int main()
{
    int n, m;
    // n is the no of vertices and m is no of edges in the graph
    cin >> n >> m;
    Graph graph;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        graph[u].push_back(make_pair(v, w));
        graph[v].push_back(make_pair(u, w));
    }
    int ans = MST(graph, n);
    cout << "Weight of Maximum spanning tree " << ans << endl;
    //  output : first n-1 lines contain two space separated u and v such that u and v are connected in obtained MST.
    // last line shows total weight of required Max.ST.

    return 0;
}
