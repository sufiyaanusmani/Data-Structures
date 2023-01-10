// Sufiyaan Usmani

#include <iostream>
#include <list>
#include <vector>
using namespace std;

class Edge{
    public:
        int destinationVertexID;
        int weight;

        Edge(){}

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
        int data;
    public:
        list<Edge> edgeList;

        Vertex(){}

        Vertex(int vertexID, int data){
            this->vertexID = vertexID;
            this->data = data;
        }

        void setData(int data){
            this->data = data;
        }

        int getVertexID(){
            return vertexID;
        }

        int getData(){
            return data;
        }

        list<Edge> getEdgeList(){
            return edgeList;
        }

        void printEdgeList(){
            cout << "[";
            for(auto it=edgeList.begin();it!=edgeList.end();it++){
                cout << it->getDestinationVertexID() << "(" << it->getWeight() << "), "; 
            }
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

        void addVertex(int ID, int data){
            if(vertexExists(ID)){
                cout << "vertex already exists" << endl;
            }else{
                Vertex v(ID, data);
                vertices.push_back(v);
            }
        }

        Vertex getVertex(int ID){
            if(vertexExists(ID)){
                Vertex temp;
                for(int i=0;i<vertices.size();i++){
                    temp = vertices[i];
                    if(temp.getVertexID() == ID){
                        return temp;
                    }
                }
            }
        }

        bool edgeExists(int from, int to){
            if(vertexExists(from) && vertexExists(to)){
                Vertex v = getVertex(from);
                list<Edge> e = v.getEdgeList();
                for(auto it=e.begin();it!=e.end();it++){
                    if(it->getDestinationVertexID() == to){
                        return true;
                    }
                }
            }
            return false;
        }

        void updateVertex(int ID, int data){
            if(vertexExists(ID)){
                for(int i=0;i<vertices.size();i++){
                    if(vertices[i].getVertexID() == ID){
                        vertices[i].setData(data);
                        break;
                    }
                }
            }else{
                cout << "Not found" << endl;
            }
        }

        void addEdge(int from, int to, int weight){
            if(edgeExists(from, to)){
                cout << "already exists"<< endl;
            }else{
                for(int i=0;i<vertices.size();i++){
                    if(vertices[i].getVertexID() == from){
                        Edge e(to, weight);
                        vertices[i].edgeList.push_back(e);
                    }else if(vertices[i].getVertexID() == to){
                        Edge e(from, weight);
                        vertices[i].edgeList.push_back(e);
                    }
                }
            }
        }

        void updateEdge(int from, int to, int weight){
            if(edgeExists(from, to)){
                for(int i=0;i<vertices.size();i++){
                    if(vertices[i].getVertexID() == from){
                        for(auto it=vertices[i].edgeList.begin();it!=vertices[i].edgeList.end();it++){
                            if(it->getDestinationVertexID() == to){
                                it->setWeight(weight);
                                break;
                            }
                        }
                    }else if(vertices[i].getVertexID() == to){
                        for(auto it=vertices[i].edgeList.begin();it!=vertices[i].edgeList.end();it++){
                            if(it->getDestinationVertexID() == from){
                                it->setWeight(weight);
                                break;
                            }
                        }
                    }
                }
            }else{
                cout << "Edge does not exists" << endl;
            }
        }

        void deleteEdge(int from, int to){
            if(edgeExists(from, to)){
                for(int i=0;i<vertices.size();i++){
                    if(vertices[i].getVertexID() == from){
                        for(auto it=vertices[i].edgeList.begin();it!=vertices[i].edgeList.end();it++){
                            if(it->getDestinationVertexID() == to){
                                vertices[i].edgeList.erase(it);
                                break;
                            }
                        }
                    }else if(vertices[i].getVertexID() == to){
                        for(auto it=vertices[i].edgeList.begin();it!=vertices[i].edgeList.end();it++){
                            if(it->getDestinationVertexID() == from){
                                vertices[i].edgeList.erase(it);
                                break;
                            }
                        }
                    }
                }
            }
        }

        void deleteVertex(int ID){
            int vIndex;
            if(vertexExists(ID)){
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
        }else{
            cout << "Not found" << endl;
        }
        }

        void printGraph(){
            if(vertices.size() == 0){
                cout << "Empty" << endl;
                return;
            }
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
    graph.addVertex(1, 3195);
    graph.addVertex(2, 3158);
    graph.addEdge(1, 2, 10);
    graph.printGraph();
    graph.updateEdge(1, 2, 50);
    graph.printGraph();
    graph.deleteEdge(1, 2);
    graph.printGraph();
    graph.deleteVertex(2);
    graph.printGraph();
    return 0;
}