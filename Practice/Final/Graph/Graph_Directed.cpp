// Sufiyaan Usmani

#include <iostream>
#include <vector>
#include <list>
using namespace std;

class Edge{
    private:
        int destinationVertexID;
        int weight;
    public:

        Edge(int destinationVertexID, int weight){
            this->destinationVertexID = destinationVertexID;
            this->weight = weight;
        }

        void setWeight(int weight){
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
            vertexID = 0;
            data = '-';
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
            cout << "[ ";
            for(auto it=edgeList.begin();it!=edgeList.end();it++){
                cout << it->getDestinationVertexID() << "(" << it->getWeight() << "), ";
            }
            cout << "] " << endl;
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
                cout << "Vertex already exists with this ID" << endl;
            }else{
                Vertex v(ID, data);
                vertices.push_back(v);
                cout << "Added successfully" << endl;
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
            return temp;
        }

        bool edgeExists(int fromVertex, int toVertex){
            if(vertexExists(fromVertex) && vertexExists(toVertex)){
                Vertex temp = getVertex(fromVertex);
                list<Edge> e= temp.getEdgeList();
                for(auto it=e.begin();it!=e.end();it++){
                    if(it->getDestinationVertexID() == toVertex){
                        return true;
                    }
                }
            }else{
                return false;
            }
            return false;
        }

        void updateVertex(int ID, char newData){
            if(vertexExists(ID)){
                for(int i=0;i<vertices.size();i++){
                    if(vertices[i].getVertexID() == ID){
                        vertices[i].setData(newData);
                        break;
                    }
                }
            }else{
                cout << "Vertex does not exists" << endl;
            }
        }

        void addEdge(int fromVertex, int toVertex, int weight){
            if(vertexExists(fromVertex) && vertexExists(toVertex)){
                if(edgeExists(fromVertex, toVertex)){
                    cout << "Edge already exists" << endl;
                }else{
                    for(int i=0;i<vertices.size();i++){
                        if(vertices[i].getVertexID() == fromVertex){
                            Edge e(toVertex, weight);
                            vertices[i].edgeList.push_back(e);
                            break;
                        }
                    }
                }
            }else{
                cout << "Vertex does not exists" << endl;
            }
        }

        void updateEdge(int fromVertex, int toVertex, int newWeight){
            if(edgeExists(fromVertex, toVertex)){
                for(int i=0;i<vertices.size();i++){
                    if(vertices[i].getVertexID() == fromVertex){
                        for(auto it=vertices[i].edgeList.begin();it!=vertices[i].edgeList.end();it++){
                            if(it->getDestinationVertexID() == toVertex){
                                it->setWeight(newWeight);
                                break;
                            }
                        }
                        break;
                    }
                }
            }else{
                cout << "Edge does not exists" << endl;
            }
        }

        void deleteEdge(int fromVertex, int toVertex){
            if(edgeExists(fromVertex, toVertex)){
                for(int i=0;i<vertices.size();i++){
                    if(vertices[i].getVertexID() == fromVertex){
                        for(auto it=vertices[i].edgeList.begin();it!=vertices[i].edgeList.end();it++){
                            if(it->getDestinationVertexID() == toVertex){
                                vertices[i].edgeList.erase(it);
                                break;
                            }
                        }
                        break;
                    }
                }
            }else{
                cout << "Edge does not exists" << endl;
            }
        }

        void deleteVertex(int ID){
            if(vertexExists(ID)){
                int vIndex;
                for(int i=0;i<vertices.size();i++){
                    if(vertices[i].getVertexID() == ID){
                        vIndex = i;
                        break;
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
                cout << "Deleted" << endl;
            }else{
                cout << "Vertex does not exists" << endl;
            }
        }

        void printGraph(){
            for(int i=0;i<vertices.size();i++){
                cout << "ID: " << vertices[i].getVertexID() << endl;
                cout << "Data: " << vertices[i].getData() << endl;
                vertices[i].printEdgeList();
                cout << endl;
            }
            cout << endl;
        }
};

int main(){
    Graph graph;
    graph.addVertex(1, 'A');
    graph.addVertex(2, 'B');
    graph.addVertex(3, 'C');
    graph.addVertex(4, 'D');
    graph.addEdge(2, 4, 100);
    graph.printGraph();
    return 0;
}