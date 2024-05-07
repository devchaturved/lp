#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>

vector<int> DJJJ(int source, vector<vector<pii>> &graph, int V)
{
    vector<int> dist(V, INT_MAX);
    vector<bool> visited(V, false);
dist[source] = 0;

    priority_queue<pii, vector<pii>, greater<pii>> pq;  //wv
    pq.push({0, source});
    

    while (!pq.empty())
    { // w--> v
        int u = pq.top().second;

        if (visited[u] == true)
        {
            pq.pop();
            continue;
        }
        visited[u] = true;
        int w = pq.top().first;

        for (auto it : graph[u])
        {
            int v = it.first;
            int edge_weight = it.second;

            if (!visited[v] && dist[u] + edge_weight < dist[v])
            {
                dist[v] = dist[u] + edge_weight;  
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

int main()
{
    int u;
    cout << "enter the no of edges: ";
    cin >> u;
    int v;
    cout << "enter the no of vertices: ";
    cin >> v;

    cout << "enter the edges src->dest->weight: " << endl;

    vector<vector<pii>> graph(v);
    for (int i = 0; i < u; i++)
    {
        int n, m, w;
        cin >> n >> m >> w;
        graph[n].push_back({m, w});
        graph[m].push_back({n, w});
    }

    vector<int> distance(v);

    distance = DJJJ(0, graph, v);

    for (int i = 0; i < v; i++)
    {
        cout << i << "\t" << distance[i] << endl;
    }
    return 0;
}