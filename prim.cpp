// Sufiyaan Usmani

#include <iostream>
#include <vector>
#define V 5
using namespace std;

int getMinDistance(vector<int> dist, vector<bool> visited){
    int minValue = INT_MAX;
    int minIndex;
    for(int i=0;i<V;i++){
        if(visited[i] == false && dist[i] < minValue){
            minValue = dist[i];
            minIndex = i;
        }
    }
    return minIndex;
}

void prim(int graph[V][V]){
    vector<int> dist;
    vector<bool> visited;
    vector<int> parent;
    dist.resize(V, INT_MAX);
    visited.resize(V, false);
    parent.resize(V);

    dist[0] = 0;
    parent[0] = -1;

    for(int i=0;i<V-1;i++){
        int u = getMinDistance(dist, visited);
        visited[u] = true;
        for(int v=0;v<V;v++){
            if(visited[v] == false && graph[u][v] != 0 && graph[u][v] < dist[v]){
                dist[v] = graph[u][v];
                parent[v] = u;
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