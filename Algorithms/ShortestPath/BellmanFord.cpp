#include <bits/stdc++.h>
using namespace std;

#define MAX 100005

vector <int> adj[MAX];
int dist[MAX]; 

void init()
{
	int i;
	for(i=0;i<MAX;i++) dist[i] = 99999;
}

void relax(int u,int v, int w)
{

	// cout <<"----" << "\n" <<  u << " " << v << " " << w << "\n";
	// cout << dist[v] << "\n";

	// cout << "Distance of 1 " << dist[u] << "\n";
	// cout << "Distance of 2 " << dist[v] << "\n";
	// cout << "Weight" << w << "\n"; 

	if(dist[u] + w < dist[v]){
		dist[v] = dist[u] + w;
		cout << dist[v];
	}
}

int main()
{
	int v,e,x,y,w;
	int i,j;

	init();

	cin >> v >> e;

	for(i=0;i<e;i++){
		cin >> x >> y >> w;

		adj[i].push_back(x);
		adj[i].push_back(y);
		adj[i].push_back(w);
	} 

	dist[1] = 0;

	// Bellman starts !

	for(i=0;i<v-1;i++){
		for(j=0;j<e;j++){
			relax(adj[j][0],adj[j][1],adj[j][2]);	
		}
	}
	
	cout << "\n";
	for(i=1;i<=v;i++)
		cout << dist[i] << " ";
	cout << "\n";

}