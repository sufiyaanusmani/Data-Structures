// Sufiyaan Usmani

#include <iostream>
#include <vector>
#define V 9
using namespace std;

int getMinDistance(vector<int> dist, vector<bool> visited){
    int minValue = INT_MAX;
    int minIndex;
    for(int i=0;i<V;i++){
        if(visited[i] == false && dist[i] <= minValue){
            minValue = dist[i];
            minIndex = i;
        }
    }
    return minIndex;
}

void dijkstra(int graph[V][V], int src){
    vector<int> dist;
    dist.resize(V, INT_MAX);
    vector<bool> visited;
    visited.resize(V, false);
    dist[src] = 0;
    for(int i=0;i<V-1;i++){
        int u = getMinDistance(dist, visited);
        visited[u] = true;
        for(int v=0;v<V;v++){
            if(visited[v]==false && graph[u][v]!=0 && dist[u] + graph[u][v] < dist[v]){
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printf("Vertex \t\t Distance from Source\n");
	for (int i = 0; i < V; i++)
		printf("%d \t\t\t\t %d\n", i, dist[i]);
}

// driver's code
int main()
{
	/* Let us create the example graph discussed above */
	int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
						{ 4, 0, 8, 0, 0, 0, 0, 11, 0 },
						{ 0, 8, 0, 7, 0, 4, 0, 0, 2 },
						{ 0, 0, 7, 0, 9, 14, 0, 0, 0 },
						{ 0, 0, 0, 9, 0, 10, 0, 0, 0 },
						{ 0, 0, 4, 14, 10, 0, 2, 0, 0 },
						{ 0, 0, 0, 0, 0, 2, 0, 1, 6 },
						{ 8, 11, 0, 0, 0, 0, 1, 0, 7 },
						{ 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

	// Function call
	dijkstra(graph, 0);

	return 0;
}