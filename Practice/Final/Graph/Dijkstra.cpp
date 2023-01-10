// C program for Dijkstra's single source shortest path
// algorithm. The program is for adjacency matrix
// representation of the graph

#include <iostream>
using namespace std;
#define V 9

int getMinDistance(int distance[V], bool visited[V]){
    int minIndex, minValue;
    minValue = INT_MAX;
    for(int i=0;i<V;i++){
        if(visited[i] == false && distance[i] <= minValue){
            minValue = distance[i];
            minIndex = i;
        }
    }
    return minIndex;
}

void dijkstra(int graph[V][V], int src){
    bool visited[V];
    int distance[V];
    for(int i=0;i<V;i++){
        visited[i] = false;
        distance[i] = INT_MAX;
    }

    distance[src] = 0;

    for(int i=0;i<V-1;i++){
        int u = getMinDistance(distance, visited);
        visited[u] = true;
        for(int v=0;v<V;v++){
            if(visited[v] == false && graph[u][v] != 0 && distance[u] + graph[u][v] < distance[v]){
                distance[v] = distance[u] + graph[u][v];
            }
        }
    }

    for(int i=0;i<V;i++){
        if(i != src){
            cout << src << " -> " << i << " : " << distance[i] << endl;
        }
    }
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