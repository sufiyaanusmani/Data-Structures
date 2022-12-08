// Sufiyaan Usmani

#include <iostream>
#define V 9
using namespace std;

int minDist(int dist[V], bool visited[V]){
    int minIndex;
    int minValue = INT_MAX;
    for(int i=0;i<V;i++){
        if(visited[i] == false && dist[i] <= minValue){
            minValue = dist[i];
            minIndex = i;
        }
    }
    return minIndex;
}

void dijkstra(int graph[V][V], int src){
    int dist[V];
    bool visited[V];
    for(int i=0;i<V;i++){
        dist[i] = INT_MAX;
        visited[i] = false;
    }
    dist[src] = 0;

    for(int i=0;i<V-1;i++){
        int u = minDist(dist, visited);
        visited[u] = true;

        for(int v=0;v<V;v++){
            if(visited[v] == false && graph[u][v] != 0 && dist[u] + graph[u][v] < dist[v]){
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    for (int i = 0; i < V; i++)
		printf("%d \t\t\t\t %d\n", i, dist[i]);
}

int main(){
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