#include <bits/stdc++.h> 
using namespace std; 


void selectionSort() 
{ 
	int n;
	cout<<"Enter no of elements :";
	cin>>n;
	vector<int> arr(n);
	cout<<"Enter the elements :";
	for(int i=0; i<n; i++)  cin>>arr[i];
	int i, j, min_idx; 
	for (i = 0; i < n - 1; i++) { 
		min_idx = i; 
		for (j = i + 1; j < n; j++) { 
			if (arr[j] < arr[min_idx]) 				min_idx = j; 
		} 
		if (min_idx != i) 			swap(arr[min_idx], arr[i]); 
	} 
	cout<<"Sorted array :";
	for (i = 0; i < n; i++) 		cout << arr[i] << " "; 
	cout<<endl;
} 

int minKey(int key[], bool mstSet[], int n)
{
    int min = INT_MAX, min_index;
 
    for (int i = 0; i < n; i++)
        if (mstSet[i] == false && key[i] < min)            min = key[i], min_index = i;
    return min_index;
}

void Prims(){
	

    int n,m,x,y,wt;
    cout<<"Enter no of nodes, Edges: ";
    cin>>n>>m;
    cout<<"Enter edge,weight: ";
    vector<vector<int>> graph(n,vector<int>(n,0));
    int parent[n];
    int key[n];
    bool mstSet[n];
    for(int i=0;i<m;i++){
        cin>>x>>y>>wt;
        graph[x][y]=wt;
        graph[y][x]=wt;
    }
 
    for (int i = 0; i < n; i++)        key[i] = INT_MAX, mstSet[i] = false;
    key[0] = 0;
    parent[0] = -1;
 
    for (int count = 0; count < n - 1; count++) {
        int u = minKey(key, mstSet, n);
        mstSet[u] = true;
		

        for (int i = 0; i < n; i++){
			if (graph[u][i] && mstSet[i] == false && graph[u][i] < key[i])
                parent[i] = u, key[i] = graph[u][i];
		}
            
    }
	
	cout<<endl;
	int cost=0;

    cout << "Edge \tWeight\n";
    for (int i = 1; i < n; i++){
		cout << parent[i] << " - " << i << " \t"<< graph[i][parent[i]] << " \n";
		cost+=graph[i][parent[i]];
	}
	cout<<"Min_cost = "<<cost<<endl;
        
}

const int MAX = 1e6-1;
int root[MAX];
pair <long long, pair<int, int> > p[MAX];

const int N=100000;
int parent[N];
int size[N];

void make(int v){
    parent[v]=v;
    size[v]=1;
}

int find(int v){
    if(parent[v]==v) return v;
    //Path compression
    return parent[v]=find(parent[v]);
}

void Union(int a,int b){
    a=find(a);
    b=find(b);
    // Union by Size/Rank
    if(a!=b && size[a]<size[b]){
        swap(a,b);
    }
    parent[b]=a;
    size[b]+=size[a];
}

void Kruskal(){
    int v,e;cin>>v>>e;
    vector<pair<int ,pair<int,int> > >vec;
    for(int i=0;i<e;i++){
        int src,dest,weight;
        cin>>src>>dest>>weight;
        vec.push_back({weight,{src,dest}});
    }
    sort(vec.begin(),vec.end());
    for(int i=1;i<=v;i++){
        make(i);
    }
    int total_cost=0;
    for(auto edge:vec){
        int wt=edge.first;
        int x=edge.second.first;
        int y=edge.second.second;
        if(find(x)==find(y)){
            continue;
        }
        total_cost+=wt;
        Union(x,y);
        cout<<x<<" "<<y<<endl;
    }
    cout<<"Cost of minimum spanning tree is: ";
    cout<<total_cost<<endl;
}


vector<pair<int,int>>g[N];
int ar[N];
int mod=1000000007;
const int INF=1e9+10;

void Dijkstra(){
	int n,m;
	cout<<"No of nodes, edges: ";
    cin>>n>>m;
	cout<<"Enter edge, weight :";
    for(int i=0;i<m;i++){
        int x,y,wt;
        cin>>x>>y>>wt;
        g[x].push_back({y,wt});
        g[y].push_back({x,wt});
    }
	int s=1;

	vector<int>vis(N,0);
    vector<int>dist(N,INF);
    multiset<pair<int,int>>st;
    st.insert({0,s});
    dist[s]=0;
 
    while(st.size()>0){
        auto it=*(st.begin());
        int v=it.second;
        int d=it.first;
        st.erase(st.begin());
        if(vis[v]) continue;
        vis[v]=1;
        for(auto c : g[v]){
            int c_v=c.first;
            int wt=c.second;
            if(dist[v]+wt<dist[c_v]){
                dist[c_v]=dist[v]+wt;
                st.insert({dist[c_v],c_v});  
            }
        }
        
    }
    for(int i =1;i<=n;i++){
        cout<<"distance between "<<s<<" and "<<i<<" is "<<dist[i]<<endl;
    }
}


int main() 
{
	int choice;
	while(1){

		cout<<"\n1.selection sort\n2.Prims\n3.Kruskal\n4.Dijkstra\n\nEnter choice :";
		cin>>choice;
		switch(choice){
			case 1:		
				selectionSort();  
				break;
			case 2:
				Prims();
				break;
			case 3:
				Kruskal();
				break;
			case 4:
				Dijkstra();
				break;
			default: 
				break;
		}
	}
	return 0; 
} 

