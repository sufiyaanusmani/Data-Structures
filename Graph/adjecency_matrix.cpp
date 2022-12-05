// Sufiyaan Usmani

#include <iostream>
#define SIZE 5
using namespace std;

class Graph{
    private:
        int matrix[SIZE][SIZE];
    public:
        Graph(){
            for(int i=0;i<SIZE;i++){
                for(int j=0;j<SIZE;j++){
                    matrix[i][j] = 0;
                }
            }
        }

        void addEdge(int u, int v){
            matrix[u][v] = 1;
            matrix[v][u] = 1;
        }

        void displayMatrix(int v){
            for(int i=0;i<v;i++){
                for(int j=0;j<v;j++){
                    cout << matrix[i][j] << "  ";
                }
                cout << endl;
            }
        }
};

int main(){
    int v = 4;
    Graph graph;
    graph.addEdge(0, 3);
    graph.addEdge(0, 2);
    graph.addEdge(1, 2);
    graph.displayMatrix(v);
    return 0;
}