// Sufiyaan Usmani

#include <iostream>
#include <vector>
#include <list>
using namespace std;

// Directed Graph
class Edge{
    private:
        int destinationVertexID;
        int weight;
    public:
        Edge(int destinationVertexID, int weight){
            this->destinationVertexID = destinationVertexID;
            this->weight = weight;
        }

        int getDestinationVertexID(){
            return destinationVertexID;
        }

        int getWeight(){
            return weight;
        }
};

class Vertex{
    private:
        int vertexID;
        char data;
    public:
        list<Edge> edgeList;
        Vertex(){

        }

        Vertex(int vertexID, char data){
            this->vertexID = vertexID;
            this->data = data;
        }

        void setData(char data){
            this->data = data;
        }

        int getVertexID(){
            return vertexID;
        }

        char getData(){
            return data;
        }

        list<Edge> getEdgeList(){
            return edgeList;
        }

        void printEdgeList(){
            cout << "[";
            for(auto it=edgeList.begin();it!=edgeList.end();it++){
                cout << it->getDestinationVertexID() << "(" << it->getWeight() << ") -> ";
            }
            cout << "]" << endl;
        }

};

class Graph{
    private:
        vector<Vertex> vertices;
    public:
        bool vertexExists(int ID){
            for(int i=0;i<vertices.size();i++){
                if(vertices[i].getVertexID() == ID){
                    return true;
                }
            }
            return false;
        }

        void addVertex(int ID, char data){
            if(vertexExists(ID)){
                cout << "Vertex with this ID already exists" << endl;
            }else{
                Vertex v(ID, data);
                vertices.push_back(v);
                cout << "Vertex added successfully" << endl;
            }
        }

        Vertex getVertex(int ID){
            Vertex temp;
            for(int i=0;i<vertices.size();i++){
                temp = vertices[i];
                if(temp.getVertexID() == ID){
                    return temp;
                }
            }
        }

        bool edgeExists(int fromVertex, int toVertex){
            if(vertexExists(fromVertex) && vertexExists(toVertex)){
                Vertex v = getVertex(fromVertex);
                list<Edge> e = v.getEdgeList();
                for(auto it=e.begin();it!=e.end();it++){
                    if(it->getDestinationVertexID() == toVertex){
                        return true;
                    }
                }
            }else{
                cout << "Error: One or both vertex does not exists" << endl;
            }
            return false;
        }

        void addEdge(int fromVertex, int toVertex, int weight){
            if(vertexExists(fromVertex) && vertexExists(toVertex)){
                if(edgeExists(fromVertex, toVertex)){
                    cout << "Edge already exists" << endl;
                }else{
                    Edge e(toVertex, weight);
                    for(int i=0;i<vertices.size();i++){
                        if(vertices[i].getVertexID() == fromVertex){
                            vertices[i].edgeList.push_back(e);
                            break;
                        }
                    }
                    cout << "Edge added successfully" << endl;
                }
            }else{
                cout << "Error: One or both vertex does not exists" << endl;
            }
        }

        void searchVertex(int ID){
            if(vertexExists(ID)){
                cout << "VERTEX FOUND" << endl;
                Vertex v = getVertex(ID);
                cout << "ID: " << v.getVertexID() << endl;
                cout << "Data: " << v.getData() << endl;
                cout << "Edges: ";
                v.printEdgeList();
                cout << endl;
            }else{
                cout << "VERTEX NOT FOUND" << endl;
            }
        }

        void deleteVertex(int ID){
            if(vertexExists(ID)){
                int vIndex;
                for(int i=0;i<vertices.size();i++){
                    if(vertices[i].getVertexID() == ID){
                        vIndex = i;
                    }
                }
                for(int i=0;i<vertices.size();i++){
                    for(auto it=vertices[i].edgeList.begin();it!=vertices[i].edgeList.end();it++){
                        if(it->getDestinationVertexID() == ID){
                            vertices[i].edgeList.erase(it);
                            break;
                        }
                    }
                }
                vertices.erase(vertices.begin() + vIndex);
                cout << "Vertex deleted successfully" << endl;
            }else{
                cout << "Vertex does not exists" << endl;
            }
        }

        void deleteEdge(int fromVertex, int toVertex){
            if(vertexExists(fromVertex) && vertexExists(toVertex)){
                if(edgeExists(fromVertex, toVertex)){
                    for(int i=0;i<vertices.size();i++){
                        if(vertices[i].getVertexID() == fromVertex){
                            for(auto it=vertices[i].edgeList.begin();it!=vertices[i].edgeList.end();it++){
                                if(it->getDestinationVertexID() == toVertex){
                                    vertices[i].edgeList.erase(it);
                                    break;
                                }
                            }
                        }
                    }
                    cout << "Edge deleted successfully" << endl;
                }else{
                    cout << "Edge does not exists" << endl;
                }
            }else{
                cout << "One or both vertices does not exists" << endl;
            }
        }

        void printGraph(){
            for(int i=0;i<vertices.size();i++){
                cout << "ID: " << vertices[i].getVertexID() << endl;
                cout << "Data: " << vertices[i].getData() << endl;
                cout << "Edges: ";
                vertices[i].printEdgeList();
                cout << endl;
            }
            cout << endl;
        }
};

int main(){
    int m, n, w;
    char data;
    Graph graph;

    while(1){
        cout << "1. Add Vertex" << endl;
        cout << "2. Add Edge" << endl;
        cout << "3. Search Vertex" << endl;
        cout << "4. Delete Vertex" << endl;
        cout << "5. Delete Edge" << endl;
        cout << "6. Print Graph" << endl;
        cout << "7. Exit" << endl;
        cout << "\nEnter your choice: ";
        cin >> n;
        
        if(n == 1){
            cout << "Enter vertex ID: ";
            cin >> n;
            cout << "Enter data: ";
            cin >>data;
            graph.addVertex(n, data);
        }else if(n == 2){
            cout << "Enter source vertex: ";
            cin >> m;
            cout << "Enter destination vertex: ";
            cin >> n;
            cout << "Enter weight: ";
            cin >> w;
            graph.addEdge(m, n, w);
        }else if(n == 3){
            cout << "Enter vertex ID: ";
            cin >> n;
            graph.searchVertex(n);
        }else if(n == 4){
            cout << "Enter vertex ID: ";
            cin >> n;
            graph.deleteVertex(n);
        }else if(n == 5){
            cout << "Enter source vertex: ";
            cin >> m;
            cout << "Enter destination vertex: ";
            cin >> n;
            graph.deleteEdge(m, n);
        }else if(n == 6){
            graph.printGraph();
        }else if(n == 7){
            break;
        }else{
            cout << "Please enter a valid choice" << endl;
        }
    }
    return 0;
}