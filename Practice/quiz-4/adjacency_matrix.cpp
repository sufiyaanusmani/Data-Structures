// Sufiyaan Usmani

#include <iostream>
#define N 5
using namespace std;

class Graph{
    private:
        int matrix[N][N];
    public:
        Graph(){
            for(int i=0;i<N;i++){
                for(int j=0;j<N;j++){
                    matrix[i][j] = 0;
                }
            }
        }

        void addEdge(int u, int v){
            matrix[u][v] = 1;
            matrix[v][u] = 1;
        }

        void removeEdge(int u, int v){
            matrix[u][v] = 0;
            matrix[v][u] = 0;
        }

        void printMatrix(){
            for(int i=0;i<N;i++){
                for(int j=0;j<N;j++){
                    cout << matrix[i][j] << "  ";
                }
                cout << endl;
            }
            cout << endl;
        }
};

int main(){
    Graph graph;
    graph.addEdge(1, 4);
    graph.addEdge(1, 3);
    graph.addEdge(3, 2);
    graph.addEdge(2, 4);
    graph.addEdge(4, 3);
    graph.addEdge(0, 4);
    graph.printMatrix();
    graph.removeEdge(2, 3);
    graph.printMatrix();
    return 0;
}