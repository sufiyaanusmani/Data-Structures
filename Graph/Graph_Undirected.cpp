// Sufiyaan Usmani

#include <iostream>
#include <vector>
#include <list>
#include <iterator>
using namespace std;

class Edge{
    private:
        int destinationVertexID;
        int weight;
    public:

        Edge(){}

        Edge(int destinationVertexID, int weight){
            this->destinationVertexID = destinationVertexID;
            this->weight = weight;
        }

        void setEdge(int destinationVertexID, int weight){
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
    public:
        int vertexID;
        char data;
        list<Edge> edgeList;

        Vertex(){
            vertexID = 0;
            data = '-';
        }

        Vertex(int vertexID, char data){
            this->vertexID = vertexID;
            this->data = data;
        }

        int getVertexID(){
            return vertexID;
        }

        char getData(){
            return data;
        }

        void setVertexID(int vertexID){
            this->vertexID = vertexID;
        }

        void setData(char data){
            this->data = data;
        }

        list<Edge> getEdgeList(){
            return edgeList;
        }

        void printEdgeList(){
            cout << "[";
            for (auto it = edgeList.begin(); it != edgeList.end(); it++) {
            cout << it -> getDestinationVertexID() << "(" << it -> getWeight() << ") --> ";
            }
            cout << "]";
            cout << endl;
        }

        void updateVertexData(char data){
            this->data = data;
        }
};

class Graph{
    private:
        vector<Vertex> vertices;
    public:
        bool vertexExists(int ID){
            for(int i=0;i<vertices.size();i++){
                if(vertices.at(i).getVertexID() == ID){
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
                temp = vertices.at(i);
                if(temp.getVertexID() == ID){
                    return temp;
                }
            }
            return temp;
        }

        bool edgeExists(int fromVertex, int toVertex){
            Vertex v = getVertex(fromVertex);
            list<Edge> e;
            e = v.getEdgeList();
            for(auto it=e.begin();it!=e.end();it++){
                if(it->getDestinationVertexID() == toVertex){
                    return true;
                }
            }
            return false;
        }

        void updateVertex(int ID, char data){
            if(vertexExists(ID)){
                for(int i=0;i<vertices.size();i++){
                    if(vertices.at(i).getVertexID() == ID){
                        vertices.at(i).setData(data);
                        cout << "Data updated successfully" << endl;
                        break;
                    }
                }
            }else{
                cout << "This vertex does not exists" << endl;
            }
        }

        void addEdge(int fromVertex, int toVertex, int weight){
            if(vertexExists(fromVertex) && vertexExists(toVertex)){
                if(edgeExists(fromVertex, toVertex)){
                    cout << "Edge between these two vertices already exists" << endl;
                }else{
                    for(int i=0;i<vertices.size();i++){
                        if(vertices.at(i).getVertexID() == fromVertex){
                            Edge e(toVertex, weight);
                            vertices.at(i).edgeList.push_back(e);
                        }else if(vertices.at(i).getVertexID() == toVertex){
                            Edge e(fromVertex, weight);
                            vertices.at(i).edgeList.push_back(e);
                        }
                    }
                    cout << "Edge added successfully" << endl;
                }
            }else{
                cout << "One or both vertex does not exists" << endl;
            }
        }

        void updateEdge(int fromVertex, int toVertex, int newWeight){
            if(vertexExists(fromVertex) && vertexExists(toVertex)){
                if(edgeExists(fromVertex, toVertex)){
                    for(int i=0;i<vertices.size();i++){
                        if(vertices.at(i).getVertexID() == fromVertex){
                            for(auto it=vertices.at(i).edgeList.begin();it!=vertices.at(i).edgeList.end();it++){
                                if(it->getDestinationVertexID() == toVertex){
                                    it->setWeight(newWeight);
                                    break;
                                }                                
                            }
                        }else if(vertices.at(i).getVertexID() == toVertex){
                            for(auto it=vertices.at(i).edgeList.begin();it!=vertices.at(i).edgeList.end();it++){
                                if(it->getDestinationVertexID() == fromVertex){
                                    it->setWeight(newWeight);
                                    break;
                                }
                            }
                        }
                    }
                    cout << "Edge updated successfully" << endl;
                }else{
                    cout << "Edge does not exists" << endl;
                }
            }else{
                cout << "One or two vertex does not exists" << endl;
            }
        }

        void deleteEdge(int fromVertex, int toVertex){
            if(edgeExists(fromVertex, toVertex)){
                for(int i=0;i<vertices.size();i++){
                    if(vertices.at(i).getVertexID() == fromVertex){
                        for(auto it=vertices.at(i).edgeList.begin();it!=vertices.at(i).edgeList.end();it++){
                            if(it->getDestinationVertexID() == toVertex){
                                vertices.at(i).edgeList.erase(it);
                                break;
                            }
                        }
                    }else if(vertices.at(i).getVertexID() == toVertex){
                        for(auto it=vertices.at(i).edgeList.begin();it!=vertices.at(i).edgeList.end();i++){
                            if(it->getDestinationVertexID() == fromVertex){
                                vertices.at(i).edgeList.erase(it);
                                break;
                            }
                        }
                    }
                }
                cout << "Edge deleted successfully" << endl;
            }else{
                cout << "Edge does not exists" << endl;
            }
        }

        void deleteVertex(int ID){
            int vIndex;
            if(vertexExists(ID)){
                for(int i=0;i<vertices.size();i++){
                    if(vertices.at(i).getVertexID() == ID){
                        vIndex = i;
                        break;
                    }
                }
                for(int i=0;i<vertices.size();i++){
                    for(auto it=vertices.at(i).edgeList.begin();it!=vertices.at(i).edgeList.end();it++){
                        if(it->getDestinationVertexID() == ID){
                            vertices.at(i).edgeList.erase(it);
                            break;
                        }
                    }
                }
                vertices.erase(vertices.begin() + vIndex);
                cout << "Vertex deleted successfully" << endl;
            }else{
                cout <<"Vertex does not exists" << endl;
            }
        }

        void printGraph(){
            for(int i=0;i<vertices.size();i++){
                Vertex temp;
                temp = vertices.at(i);
                cout << "ID: " << temp.getVertexID() << endl;
                cout << "Data: " << temp.getData() << endl;
                temp.printEdgeList();
                cout << endl;
            }
        }
};

int main(){
    Graph graph;
    graph.addVertex(1, 'A');
    graph.addVertex(2, 'B');
    graph.addEdge(1, 2, 10);
    graph.printGraph();
    graph.updateEdge(1, 2, 50);
    graph.printGraph();
    // graph.deleteEdge(1, 2);
    graph.printGraph();
    graph.deleteVertex(2);
    graph.printGraph();
    return 0;
}