#include<bits/stdc++.h>
using namespace std;

map<int, vector<int>>adj;
map<int, bool>visited;

void addedge(int u ,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);

}

void DFSSS(int node){
    visited[node] = true;
    cout<<node<< " " ;

    for(auto it: adj[node]){
        if(!visited[it]){
            DFSSS(it);

        }
    }
}

void BFSS(int node){
    queue<int>q;
    q.push(node);
    visited[node] = true;
    
    while(!q.empty()){
        int headd = q.front();
        q.pop();
        cout<< headd << " " ;

        for(auto it : adj[headd]){
            if(!visited[it]){
                visited[it] = true;
                q.push(it);
            }
        }
    }

}

bool DLSS(int node, int target, int limit){
    if(limit == 0 && node == target){
        return true;
    }
    else if(limit> 0){
        //for neighbours
       for(auto it : adj[node]){
        if(DLSS(it, target, limit-1)){
            return true;
        }
       } 
    }
    return false;
}

int main(){
    int head = 0;

    int n;int m;
    cout<<"Enter the number of nodes: " ;
    cin>> n;
    cout<< " Enter the number of edges: " ;
    cin>> m; 

    cout<< " Enter "<< m << " edges(source->destination)"<< endl ;
    for(int i =0; i<m; i++){
        int u, v;
        cin>>u>>v;
        addedge(u,v);
    }

    int ch =0;
    cout<<"Enter 1 for DFS, 2 for BFS, 3 for DLS: " ;
    cin>> ch;

    if(ch == 1){
        cout<< "DFS of the given graph will be: " ;
        DFSSS(head);
    }
    else if(ch ==2){
        cout<< "BFS of thr given graph will be: ";
        BFSS(head);
    }

    else if(ch == 3){

        int limit;
        cout<< "Enter the limit: " ;
        cin>> limit;
        
        int target;
        cout<< "Enter the target: " ;
        cin>> target ;

        // cout<< " DLS will be" ;
        if(DLSS(head, target, limit))
            cout << "Target found within limit ";
        else
            cout << "Target not found within limit limit.";
        

    }
    return 0;

}