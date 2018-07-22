#include <bits/stdc++.h>
using namespace std;

#define MAX 999999
typedef pair<int, int> PII;


vector< pair<int,int> > adj[MAX];
int dist[MAX];
int seen[MAX];

void init() 
{
	int i;
	for(i=0;i<MAX;i++) dist[i]=MAX;
}

void dijkstra(int src)
{
	int u,v,w,i,j;

	dist[src] = 0;
	
	pair <int,int> p;
	pair <int,int> q;
	priority_queue<PII, vector<PII>, greater<PII> > Q;

	Q.push(make_pair(0,src));

	while(!Q.empty())
	{
		p = Q.top();
		Q.pop();

		u = p.second;

		if(seen[u] == 1)
			continue;

		seen[u] = 1;

		for(i=0;i<adj[u].size();i++)
		{
			q = adj[u][i];
			// cout << q.first << "\n";
			v = q.first;
			w = q.second;

			if(dist[u] + w < dist[v])
			{
				dist[v] = dist[u] + w;
				Q.push(make_pair(dist[v],v));
			}
			
		} 
	}
}

int main()
{
	init();
	int v,e,x,y,w,i;

	cin >> v >> e;
	for(i=0;i<e;i++)
	{
		cin >> x >> y >> w;
		adj[x-1].push_back(make_pair(y-1,w));
		adj[y-1].push_back(make_pair(x-1,w));
	}

	dijkstra(0);

	for(i=0;i<v;i++)
	cout << i+1 << ":" <<  dist[i] << "\n";
}
