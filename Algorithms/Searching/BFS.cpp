#include <bits/stdc++.h>
using namespace std;

void bfs(vector<int> adj[],int seen[],int src)
{
	vector <int> :: iterator it;
	queue <int> q;

	q.push(src);

	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		
		cout << u << " ";

		for(it=adj[u].begin();it!=adj[u].end();it++)
		{
			if(!seen[*it])
			{
				seen[*it] = 1;
				q.push(*it);
			}
		}
	}

	cout << "\n";

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

	int seen[v]={0};
	seen[v-1]=1;

	bfs(graph,seen,v-1);
	
	return 0;
}