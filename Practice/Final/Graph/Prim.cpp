// A C++ program for Prim's Minimum
// Spanning Tree (MST) algorithm. The program is
// for adjacency matrix representation of the graph
#include <iostream>
#define V 5
using namespace std;

int getMinDistance(int distance[V], bool visited[V]){
    int minValue = INT_MAX;
    int minIndex;
    for(int i=0;i<V;i++){
        if(visited[i] == false && distance[i] < minValue){
            minIndex = i;
            minValue = distance[i];
        }
    }
    return minIndex;
}

void prim(int graph[V][V]){
    bool visited[V];
    int parent[V];
    int distance[V];

    for(int i=0;i<V;i++){
        visited[i] = false;
        distance[i] = INT_MAX;
    }

    distance[0] = 0;
    parent[0] = -1;

    for(int i=0;i<V-1;i++){
        int u = getMinDistance(distance, visited);
        visited[u] = true;
        for(int v=0;v<V;v++){
            if(visited[v] == false && graph[u][v] != 0 && graph[u][v] < distance[v]){
                parent[v] = u;
                distance[v] = graph[u][v];
            }
        }
    }

    cout << "Edge \tWeight\n";
	for (int i = 1; i < V; i++)
		cout << parent[i] << " - " << i << " \t"
			<< graph[i][parent[i]] << " \n";
}

// Driver's code
int main()
{
	/* Let us create the following graph
		2 3
	(0)--(1)--(2)
	| / \ |
	6| 8/ \5 |7
	| / \ |
	(3)-------(4)
			9	 */
	int graph[V][V] = { { 0, 2, 0, 6, 0 },
						{ 2, 0, 3, 8, 5 },
						{ 0, 3, 0, 0, 7 },
						{ 6, 8, 0, 0, 9 },
						{ 0, 5, 7, 9, 0 } };

	// Print the solution
	prim(graph);

	return 0;
}

// This code is contributed by rathbhupendra
