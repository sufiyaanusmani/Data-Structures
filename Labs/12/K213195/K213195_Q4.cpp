// Sufiyaan Usmani

#include <iostream>
#define V 5
using namespace std;

int getMinDistance(int distance[V], bool visited[V]){
    int minIndex;
    int minValue = INT_MAX;
    for(int i=0;i<V;i++){
        if(visited[i] == false && distance[i] < minValue){
            minValue = distance[i];
            minIndex = i;
        }
    }
    return minIndex;
}

void prim(int graph[V][V]){
    int distance[V];
    bool visited[V];
    int parent[V];
    for(int i=0;i<V;i++){
        distance[i] = INT_MAX;
        visited[i] = false;
    }

    // selecting 0
    distance[0] = 0;
    parent[0] = -1;

    for(int i=0;i<V-1;i++){
        int u = getMinDistance(distance, visited);
        visited[u] = true;
        for(int v=0;v<V;v++){
            if(visited[v] == false && graph[u][v] != 0 && graph[u][v] < distance[v]){
                distance[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    cout << "Edge       Weight" << endl;
    for(int i=1;i<V;i++){
        cout << parent[i] << " -> " << i << "  :  " << graph[i][parent[i]] << endl;
    }
}

int main(){
    int graph[V][V] = { { 0, 2, 0, 6, 0 },
                        { 2, 0, 3, 8, 5 },
                        { 0, 3, 0, 0, 7 },
                        { 6, 8, 0, 0, 9 },
                        { 0, 5, 7, 9, 0 } };

    prim(graph);
    return 0;
}