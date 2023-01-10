// Sufiyaan Usmani

#include <iostream>
#include <vector>
#include <list>
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
            adj.resize(v);
            visited.resize(v, false);
        }

        void addEdge(int from, int to){
            adj[from].push_back(to);
        }

        void BFS(int s){
            vector<bool> visited;
            visited.resize(v, false);
            list<int> queue;
            queue.push_back(s);
            visited[s] = true;
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

        void DFS(int s){
            visited[s] = true;
            cout << s << "  ";
            for(auto it=adj[s].begin();it!=adj[s].end();it++){
                if(visited[*it] == false){
                    DFS(*it);
                }
            }
        }

        void sortUtil(int i, stack<int> &st, vector<bool> &visited){
            visited[i] = true;
            for(auto it=adj[i].begin();it!=adj[i].end();it++){
                if(visited[*it] == false){
                    sortUtil(*it, st, visited);
                }
            }
            st.push(i);
        }

        void topologicalSort(){
            stack<int> st;
            vector<bool> visited;
            visited.resize(v, false);

            for(int i=0;i<adj.size();i++){
                if(visited[i] == false){
                    sortUtil(i, st, visited);
                }
            }

            while(!st.empty()){
                cout << st.top() << "  ";
                st.pop();
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
    g.BFS(2);
    cout << endl;
    g.DFS(2);
    cout << endl;
    g.topologicalSort();
    return 0;
}