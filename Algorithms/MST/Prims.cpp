#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;

int prim(vector < pair<int,int> > adj[], int seen[], int src)
{
	int i,j,u,w,ans = 0;

	pair <int,int> p;
	priority_queue<PII, vector<PII>, greater<PII> > Q;
	vector < pair<int,int> > :: iterator it;

	Q.push(make_pair(0,src));

	while(!Q.empty())
	{
		p = Q.top();
		Q.pop();

		w = p.first;
		u = p.second;

		if(seen[u] == 1)
			continue;
		
		ans += w;
		seen[u] = 1;

		for(i=0;i<adj[u].size();++i)
		{
			j = adj[u][i].second;
			if(seen[j] == 0)
				Q.push(adj[u][i]);
		}
		
	}

	cout << ans << "\n";
	return ans;
} 

int main()
{	
	int v,e;

	cin >> v >> e;
	vector < pair<int,int> > adj[v];

	int x,y,w,i;
	
	for(i=0;i<e;i++)
	{
		cin >> x >> y >> w;
		adj[x-1].push_back(make_pair(w,y-1));
		adj[y-1].push_back(make_pair(w,x-1));
	}

	int seen[v] = {0};

	int ans = prim(adj,seen,1);
}