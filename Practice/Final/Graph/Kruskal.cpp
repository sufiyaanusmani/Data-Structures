#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 1e6 - 1;
int root[MAX];
int nodes = 4;
int edges = 5;
pair<long long, pair<int, int>> p[MAX];

int parent(int a){
    while(a != root[a]){
        root[a] = root[root[a]];
        a = root[a];
    }
    return a;
}

void unionSet(int a, int b){
    int c = parent(a);
    int d = parent(b);
    root[c] = root[d];
}

int kruskal(){
    for(int i=0;i<MAX;i++){
        root[i] = i;
    }
    sort(p, p + edges);
    int cost, mstCost, a, b;
    mstCost = 0;
    for(int i=0;i<edges;i++){
        a = p[i].second.first;
        cout<<"sourse "<< a<<" ";
        b = p[i].second.second;
        cout<<"to destination "<< b<<" with weight " <<p[i].first<<endl ;
        cost = p[i].first;
        if(parent(a) != parent(b)){
            unionSet(a, b);
            mstCost += cost;
        }
    }
    return mstCost;
}

int main()
{
    
    
    
    p[0] = make_pair(10, make_pair(0, 1));
    p[1] = make_pair(18, make_pair(1, 2));
    p[2] = make_pair(13, make_pair(2, 3));
    p[3] = make_pair(21, make_pair(0, 2));
    p[4] = make_pair(22, make_pair(1, 3));
    //sort the array of edges giving the inital value or set and final value or set.
    cout << "MST Cost: " << kruskal() << endl;
    return 0;
}
