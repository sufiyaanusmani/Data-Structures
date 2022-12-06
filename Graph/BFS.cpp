// Sufiyaan Usmani

#include <iostream>
#include <vector>
#include <list>
using namespace std;

class Graph{
    private:
        int v;
        vector<list<int>> adj;
    public:
        Graph(int v){
            this->v = v;
            adj.resize(this->v);
        }

        void addEdge(int from, int to){
            adj[from].push_back(to);
        }

        void BFS(int s){
            vector<bool> visited;
            visited.resize(v, false);

            list<int> queue;
            visited[s] = true;
            queue.push_back(s);

            while(!queue.empty()){
                s = queue.front();
                cout << s << "  ";
                queue.pop_front();

                for(auto it=adj[s].begin();it!=adj[s].end();it++){
                    if(visited[*it] == false){
                        visited[*it] = true;
                        queue.push_back(*it);
                    }
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
 
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";
    g.BFS(2);
    return 0;
}