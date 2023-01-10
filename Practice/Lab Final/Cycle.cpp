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
            adj.resize(v);
            visited.resize(v, false);
        }

        void addEdge(int from, int to){
            adj[from].push_back(to);
        }

        void DFS(int s, bool &flag){
            visited[s] = true;
            for(auto it=adj[s].begin();it!=adj[s].end();it++){
                if(visited[*it] == false){
                    DFS(*it, flag);
                }else{
                    flag = true;
                    return;
                }
            }
        }

        bool isCyclic(){
            int s = 0;
            
            bool flag = false;
            DFS(s, flag);
            return flag;
        }
};

int main(){
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 0);
 
    if(g.isCyclic())
        cout << "Graph contains cycle";
    else
        cout << "Graph doesn't contain cycle";
    return 0;
}