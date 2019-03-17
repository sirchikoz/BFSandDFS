/* 
 * File:   Graph.h
 * Author: sirch
 *
 * Created on March 11, 2019, 8:34 PM
 */

#ifndef GRAPH_H
#define GRAPH_H
#include "Vertex.h"
using namespace std;
namespace algorithms{
class Graph{
    vector<Vertex*> vertices;
    Vertex* temp=nullptr;
public:
    Graph(){ }
    void addVertex(Vertex* v){
        vertices.push_back(v);
    }
    vector<Vertex*> getVertices(){
        return vertices;
    }
    vector<Vertex*> getAdjacents(Vertex* ver){
        return ver->getAdjacents();
    }
   /* vector* getVertex(int i){
        
    }*/
};
}
#endif /* GRAPH_H */
