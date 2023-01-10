// A C++ program to print topological
// sorting of a DAG
#include <iostream>
#include <vector>
#include <list>
#include <stack>
using namespace std;

class Graph{
    private:
        int v;
        vector<list<int>> adj;
    public:
        Graph(int v){
            this->v = v;
            adj.resize(v);
        }

        void addEdge(int from, int to){
            adj[from].push_back(to);
        }

        void sortUtil(int v, stack<int> &st, vector<bool> &visited){
            visited[v] = true;
            for(auto it=adj[v].begin();it!=adj[v].end();it++){
                if(visited[*it] == false){
                    sortUtil(*it, st, visited);
                }
            }
            st.push(v);
        }

        void topologicalSort(){
            vector<bool> visited;
            visited.resize(v, false);
            stack<int> st;
            for(int i=0;i<v;i++){
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

// Driver Code
int main()
{
	// Create a graph given in the above diagram
	Graph g(6);
	g.addEdge(5, 2);
	g.addEdge(5, 0);
	g.addEdge(4, 0);
	g.addEdge(4, 1);
	g.addEdge(2, 3);
	g.addEdge(3, 1);

	cout << "Following is a Topological Sort of the given "
			"graph \n";

	// Function Call
	g.topologicalSort();

	return 0;
}
