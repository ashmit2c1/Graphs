#include<bits/stdc++.h>
using namespace std;
// NODE CLASS HOLDING THE CITY NAME AND IT'S LIST OF NEIGHBORS
class Node{
    public:
    string name;
    list<string>neighbors;
    Node(string name){
        this->name=name;
    }
};
// GRAPH CLASS 
class Graph{
    private:
    unordered_map<string,Node*>mp;
    public:
    Graph(vector<string>&cities){
        for(auto city:cities){
            mp[city]=new Node(city);
        }
    }
    void addEdge(string src,string dest,bool undir=false){
        mp[src]->neighbors.push_back(dest);
        if(undir==true){
            mp[dest]->neighbors.push_back(src);
        }
    }
    void printList(){
        for(auto it=mp.begin();it!=mp.end();it++){
            string city = it->first;
            list<string>nbrs=it->second->neighbors;
            cout << city << "--> ";
            for(auto nbr : nbrs){
                cout << nbr << "  ";
            }
            cout << "\n";
        }
    }

};

int main(){
    vector<string>cities={"Delhi","London","New York","Paris"};
    Graph g(cities);
    g.addEdge("Delhi","London");
    g.addEdge("London","New York");
    g.addEdge("Delhi","Paris");
    g.addEdge("Paris","London");
    g.printList();
}