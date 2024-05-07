#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>

int MSTTT(vector<vector<pii>>& graph, int v){
    vector<int>dist(v,INT_MAX);
    vector<int>ans(v,-1);
    vector<bool>visited(v,false);

    priority_queue<pii, vector<pii>,greater<pii>>pq;
    pq.push({0,0});
    dist[0]=0;
    int mincost = 0;  // w---> v

    while(!pq.empty()){
        int u = pq.top().second;

        if(visited[u] == true){
            pq.pop();
            continue;
        }
        visited[u] =  true;
        int w = pq.top().first;
        mincost = mincost+w;


        for(auto it: graph[u]){
            int v = it.first;
            int edge_weight = it.second;

            if(!visited[v] && edge_weight< dist[v]){
                dist[v] = edge_weight;
                pq.push({dist[v], v});
                ans[v] = u;
            }
        }
    }
    for(int i =1; i<v; i++){
        cout<< ans[i] << "->"<< i << endl;
    }
    return mincost ;
}

int main()
{
    int n,  m;
    cout<< " enter the edges: ";
    cin>>n;
    cout<< " Enter the vertices: " ;
    cin>>m;
    vector<vector<pii>>graph(m) ;
    cout<<" Enter the vertices as edge->vertex->weight" << endl;
    

    for(int i =0; i<n; i++){
        int u,v,w;
        cin>>u>>v>>w;
        graph[u].push_back({v,w});
        graph[v].push_back({u,w});
    }

    cout<< MSTTT(graph,m);

    return 0;

}