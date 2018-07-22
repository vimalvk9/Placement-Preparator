#include <bits/stdc++.h>
#include <limits.h>

using namespace std;

#define V 4
#define INF INT_MAX

void printSolution(int dist[][V])
{
    cout << "Following matrix shows the shortest distances"
            " between every pair of vertices \n";

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (dist[i][j] == INT_MAX)
                printf("%7s", "INF");
            else
                printf ("%7d", dist[i][j]);
        }
        printf("\n");
    }
}

void floyd_warshall(int graph[][V])
{
	int dist[V][V],i,j,k;

	for(i=0;i<V;i++)
		for(j=0;j<V;j++)
			dist[i][j] = graph[i][j];

	for(k=0;k<V;k++)	
		for(i=0;i<V;i++)
			for(j=0;j<V;j++)			
				if ( dist[i][k] != INF &&  dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j])
 					dist[i][j] = dist[i][k] + dist[k][j];

			
	printSolution(dist);
}

int main()
{
   
    int graph[V][V] = { {0,   5,  INT_MAX, 10},
                        {INT_MAX, 0,   3, INT_MAX},
                        {INT_MAX, INT_MAX, 0,   1},
                        {INT_MAX, INT_MAX, INT_MAX, 0}
                      };
 
    floyd_warshall(graph);
    return 0;
}