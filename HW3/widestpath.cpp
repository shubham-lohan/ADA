// Note: 1-based indexing
#include <bits/stdc++.h>
using namespace std;
#define Graph map<int, vector<pair<int, int>>>

struct Compare
{
    bool operator()(const pair<int, int> &a, const pair<int, int> &b)
    {
        return a.first > b.first;
    }
};
void path(int parent[], int vertex, int target)
{
    if (vertex == 0)
        return;

    path(parent, parent[vertex], target);
    cout << vertex << " ";
}
int bottleneck_distance(Graph &graph, int src, int target)
{
    int n = graph.size();
    vector<int> widest(n, INT_MIN);
    int parent[n];
    fill(parent, parent + n, 0);
    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;

    pq.push(make_pair(0, src));

    widest[src] = INT_MAX;

    while (!pq.empty())
    {
        auto temp = pq.top();
        pq.pop();
        int current_src = temp.second;
        for (int i = 0; i < graph[current_src].size(); i++)
        {
            int u = graph[current_src][i].first;
            int v = graph[current_src][i].second;
            int distance = max(widest[v], min(widest[current_src], u));
            if (distance > widest[v])
            {
                widest[v] = distance;
                parent[v] = current_src;
                pq.push(make_pair(distance, v));
            }
        }
    }
    cout << "Path: ";
    path(parent, target, target);
    cout << '\n';
    return widest[target];
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
        graph[u].push_back(make_pair(w, v));
        graph[v].push_back(make_pair(w, u));
    }
    int x, y;
    // x , y denotes the node from which we want to find bottleneck distance between them.
    cin >> x >> y;
    
    /* testcase
    7 12
    1 2 1
    2 3 5
    3 4 8
    4 5 2
    5 6 9
    6 1 11
    6 7 3
    7 3 10
    2 6 6
    2 7 4
    7 4 7
    7 5 12
    1 3
    */
    // ans=9

    cout << bottleneck_distance(graph, x, y) << endl;

    return 0;
}
