// Sufiyaan Usmani

#include <iostream>
#include <list>
#include <vector>
#include <stack>
using namespace std;

class Graph{
    private:
        int v;
        vector<list<int>> adj;
        vector<bool> visited;
    public:
        Graph(int v){
            this->v = v;
            adj.resize(this->v);
            visited.resize(v, false);
        }

        void addEdge(int u, int v){
            adj[u].push_back(v);
        }

        void DFS(int s){
            visited[s] = true;
            cout << s << "  ";

            for(auto it=adj[s].begin();it!=adj[s].end();it++){
                if(visited[*it] == false){
                    DFS(*it);
                }
            }
        }
};

int main(){
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    cout << "DFS: ";
    g.DFS(2);
    return 0;
}