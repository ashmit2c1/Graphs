#include<bits/stdc++.h>
using namespace std;
// CREATING A GRAPH CLASS
class Graph {
    private:
        int V;
        list<int>*l;
    public:
        Graph(int v){
            V=v;
            l = new list<int>[V];
        }
        void addEdge(int i,int j,bool undir=true){
            l[i].push_back(j);
            if(undir==true){
                l[j].push_back(i);
            }
        }
        void printList(){
            for(int i=0;i<V;i++){
                cout << i << "-->";
                for (auto node:l[i]){
                    cout << node << ",";
                }
                cout << "\n";
            }
        }
};
// CREATING AN ADJACENCY LIST 
void createList(){
    int n;
    int m;
    cin >> n >> m;
    bool undir;
    cin >> undir;
    vector<vector<int>>adj(n);
    for(int i=0;i<m;i++){
        int u;
        int v;
        cin >> u >> v;
        adj[u].push_back(v);
        if(undir==true){
            adj[v].push_back(u);
        }
    }
}
// CREATING AN ADJACENCY MATRIX
void createMatrix(){
    int n;
    int m;
    cin >> n >> m;
    bool undir;
    cin >> undir;
    vector<vector<int>>adj(n,vector<int>(n,false));
    for(int i = 0; i<m ; i++){
        int u;
        int v;
        cin >> u >> v;
        adj[u][v]=true;
        if(undir==true){
            adj[v][u]=true;
        }
    }
    for(int i = 0; i<n ; i++){
        for(int j = 0; j<n ; j++){
            cout << adj[i][j] << " ";
        }
        cout <<  "\n";
    }
}
int main(){
    Graph g(6);
    g.addEdge(0,1);
    g.addEdge(0,4);
    g.addEdge(2,1);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.addEdge(2,3);
    g.addEdge(3,5);
    g.printList();
    createMatrix();
}