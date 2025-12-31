/**
 * This code demonstrates basic graph function with simple data structure representation
 * Here we are going to adjancencyList. AL representation is better in terms of time and space 
 * complexity compared adj.Matrix.
 */

#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Graph{
private:
    unordered_map<string, unordered_set<string>> adjList;

public:

    bool addVertex(string);
    bool addEdge(string, string);
    bool removeEdge(string, string);
    bool removeVertex(string);
    void printGraph();


};

bool Graph::addVertex(string v){
    if (adjList.count(v) == 0){
        adjList[v];
        return true;
    }
    return false;
}

bool Graph::addEdge(string v1, string v2){
    if(adjList.count(v1) != 0 && adjList.count(v2) != 0){
        adjList[v1].insert(v2);
        adjList[v2].insert(v1);
        return true;
    }
    return false;
}

bool Graph::removeEdge(string v1, string v2){
    if(adjList.count(v1) != 0 && adjList.count(v2) != 0){
        adjList[v1].erase(v2);
        adjList[v2].erase(v1);
        return true;
    }
    return false;
}

bool Graph::removeVertex(string v){
    if(adjList.count(v) == 0)
        return 0;
    for (auto vertexList: adjList[v]){
        adjList[vertexList].erase(v); //try to use iterator to remove the corresponding vertex.
    }
    adjList.erase(v);
    return true;
}

void Graph::printGraph(){
    unordered_map<string, unordered_set<string>>::iterator graphIter = adjList.begin();

    while(graphIter != adjList.end()){
        cout<<graphIter->first<<"::"<<" {";
        unordered_set<string>::iterator edgeList = graphIter->second.begin();
        while(edgeList != graphIter->second.end()){
            cout<<edgeList->data()<<" ";
            edgeList++;
        }
        cout<<" }"<<endl;
        graphIter++;
        
    }
}

int main(){
    Graph graph;
    graph.addVertex("A");
    graph.addVertex("B");

    graph.printGraph();
}