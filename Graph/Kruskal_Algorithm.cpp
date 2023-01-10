#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//max posssible groups
const int MAX = 1e6-1;
// array for groups
int root[MAX];
// nodes and edges 
const int nodes = 4, edges = 5;
// graph declaration
pair <long long, pair<int, int> > p[MAX];
//find the parent of the given node
int parent(int a)  
{
    while(root[a] != a)
    {
        root[a] = root[root[a]];
        a = root[a];
    }
    return a;
}
//check if the given two vertices are in the same “union” or not
void union_find(int a, int b)                                         
{
    int d = parent(a);
    int e = parent(b);
    root[d] = root[e];
}

long long kruskal()
{
    int a, b;
    long long cost, minCost = 0;
    for(int i = 0 ; i < edges ; ++i)
    {
        a = p[i].second.first;
        cout<<"sourse "<< a<<" ";
        b = p[i].second.second;
        cout<<"to destination "<< b<<" with weight " <<p[i].first<<endl ;
        cost = p[i].first;
        //only select edge if it does not create a cycle (ie the two nodes forming it have different root nodes)
        if(parent(a) != parent(b))                                  
        {
            minCost += cost;
            union_find(a, b);
        }
    }
    return minCost;
}

int main()
{
    int x, y;
    long long weight, cost, minCost;
    //initialize the array groups
    for(int i = 0;i < MAX;++i)                                       
    {
        root[i] = i;
        //cout<<root[i]<<endl;
    }
    p[0] = make_pair(10, make_pair(0, 1));
    p[1] = make_pair(18, make_pair(1, 2));
    p[2] = make_pair(13, make_pair(2, 3));
    p[3] = make_pair(21, make_pair(0, 2));
    p[4] = make_pair(22, make_pair(1, 3));
    //sort the array of edges giving the inital value or set and final value or set.
    sort(p, p + edges);                                             
    minCost = kruskal();
    cout << "Minimum cost is: "<< minCost << endl;
    return 0;
}
