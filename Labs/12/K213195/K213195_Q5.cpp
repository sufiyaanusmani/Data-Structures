// Sufiyaan Usmani

#include <iostream>
#define n 9
using namespace std;

int getMinDistance(int distance[n], bool visited[n]){
    int minValue = INT_MAX;
    int minIndex;

    for(int i=0;i<n;i++){
        if(visited[i] == false && distance[i] < minValue){
            minValue = distance[i];
            minIndex = i;
        }
    }
    return minIndex;
}

void dijkstra(int graph[n][n], int source){
    int distance[n];
    bool visited[n];
    for(int i=0;i<n;i++){
        distance[i] = INT_MAX;
        visited[i] = false;
    }

    distance[source] = 0;

    for(int i=0;i<n-1;i++){
        int u = getMinDistance(distance, visited);
        visited[u] = true;

        for(int v=0;v<n;v++){
            if(visited[v] == false && graph[u][v] != 0 && distance[u] + graph[u][v] <= distance[v]){
                distance[v] = distance[u] + graph[u][v];
            }
        }
    }

    for(int i=0;i<n;i++){
        if(i != source){
            cout << source << " --> " << i << ": " << distance[i] << endl;
        }
    }
}

int main(){
    int graph[n][n] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } 
    };

    dijkstra(graph, 0);
    return 0;
}