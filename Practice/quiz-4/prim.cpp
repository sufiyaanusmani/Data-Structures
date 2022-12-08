// Sufiyaan Usmani

#include <iostream>
#define V 5
using namespace std;

int minDist(int dist[V], bool visited[V]){
    int minIndex;
    int minValue = INT_MAX;
    for(int i=0;i<V;i++){
        if(visited[i]==false && dist[i]<minValue){
            minValue = dist[i];
            minIndex = i;
        }
    }
    return minIndex;
}

void prim(int graph[V][V]){
    int dist[V];
    bool visited[V];
    int parent[V];

    for(int i=0;i<V;i++){
        dist[i] = INT_MAX;
        visited[i] = false;
    }

    dist[0] = 0;
    parent[0] = -1;

    for(int i=0;i<V-1;i++){
        int u = minDist(dist, visited);
        visited[u] = true;
        for(int v=0;v<V;v++){
            if(visited[i] == false && graph[u][v]!=0&&graph[u][v]<dist[v]){
                parent[v] = u;
                dist[v] = graph[u][v];
            }
        }
    }
    cout << "Edge \tWeight\n";
	for (int i = 1; i < V; i++)
		cout << parent[i] << " - " << i << " \t"
			<< graph[i][parent[i]] << " \n";
}

int main(){
    int graph[V][V] = { { 0, 2, 0, 6, 0 },
						{ 2, 0, 3, 8, 5 },
						{ 0, 3, 0, 0, 7 },
						{ 6, 8, 0, 0, 9 },
						{ 0, 5, 7, 9, 0 } };

	// Print the solution
	prim(graph);
    return 0;
}