#include<bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    list<int>* l;
    bool unDire;
public:
    Graph(int V,bool unDire=true){
        this->V=V;
        l=new list<int>[V];
        this->unDire=unDire;
    }

    void addEdge(int u,int v){
        l[u].push_back(v);
        if(unDire)
        l[v].push_back(u);
    }

    void topological(int src,vector<bool>&vis,stack<int>&s){//0(V+E)
        vis[src]=true;

        list<int>neighbour=l[src];
        for(int v:neighbour){
            if(!vis[v]){
                topological(v,vis,s);
            }
        }
        s.push(src);
    }

    void TopologicalSorting(){
        vector<bool>vis(7,false);
        stack<int> s;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                topological(i,vis,s);
            }
        }
        while(!s.empty()){
            cout<<s.top()<<" ";
            s.pop();
        }
    }
};
int main(){
    Graph graph(6,false);

    graph.addEdge(5,0);
    graph.addEdge(4,0);
    graph.addEdge(4,1);
    graph.addEdge(3,1);
    graph.addEdge(2,3);
    graph.addEdge(5,2);

    graph.TopologicalSorting();
    return 0;
}