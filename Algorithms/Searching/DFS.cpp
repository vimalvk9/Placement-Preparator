#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int>adj[],int seen[],int src)
{
	seen[src] = 1;
	vector <int> :: iterator it;

	cout << src << " ";

	for(it=adj[src].begin();it!=adj[src].end();it++)
		if(!seen[*it]) dfs(adj,seen,*it);
}

int main()
{
	int v,e;
	cout << "Enter number of vertices and edges\n";
	cin >> v >> e;

	vector <int> graph[v];
	int i,j,a,b;

	for(i=0;i<e;i++)
	{
		cin >> a >> b;
		graph[a-1].push_back(b-1);
		graph[b-1].push_back(a-1);
	}

	int seen[v] = {0};

	dfs(graph,seen,v-1);
}