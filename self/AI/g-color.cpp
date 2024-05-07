#include <bits/stdc++.h>
using namespace std;

const int N = 2e5;
vector<int> graph[N];

void coloring(int V)
{
	vector<int> result(V, -1);
	vector<bool> used(V, false);

	result[0] = 0;

	set<int> st;

	for (int u = 1; u < V; u++)
	{

		for (auto it : graph[u])
			if (result[it] != -1)
				used[result[it]] = true;
		// If an adjacent vertex it already has a color assigned
		//(result[it] != -1), we mark that color as used in the used vector.

		int color;
		for (color = 0; color < V; color++)
			if (used[color] == false)
				break;
		// Next, we iterate through the used vector to find the smallest unused color
		//

		result[u] = color;
		// that unused color is given to the current vertex

		st.insert(color);

		for (auto it : graph[u])
			if (result[it] != -1)
				used[result[it]] = false;
	}

	cout << "Vertex\tColour\n"
		 << endl;
	for (int u = 0; u < V; u++)
	{
		cout << u << "\t" << result[u] << endl;
	}

	cout << "\n Minimum colors used: " << st.size() << "\n";
}

int main()
{
	cout << "Enter the number of vertex and edges ";
	int n, m;
	cin >> n >> m;

	cout << "Enter the edges: \n";

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	coloring(n);

	return 0;
}
