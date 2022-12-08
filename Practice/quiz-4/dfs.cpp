// Sufiyaan Usmani

#include <iostream>
#include <vector>
#include <list>
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
            visited.resize(this->v, false);
        }

        void addEdge(int from, int to){
            adj[from].push_back(to);
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

int main()
{
    // Create a graph given in the above diagram
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";
    g.DFS(2);
 
    return 0;
}