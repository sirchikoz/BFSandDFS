
/* 
 * File:   DepthFirstSearch.h
 * Author: sirch
 *
 * Created on March 16, 2019, 12:02 PM
 */

#ifndef DEPTHFIRSTSEARCH_H
#define DEPTHFIRSTSEARCH_H

#include "Graph.h"

namespace algorithms{
class DepthFirstSearch{
    int time = 0;
    Graph graph;
    void DFS_Visit(Vertex* u);
public:
    DepthFirstSearch(Vertex vertices[], int count){
        for(int i=0; i<count; i++){
            graph.addVertex(&vertices[i]);
        }
    }
    void explore(){
        for(Vertex* u : graph.getVertices()){
            if(u->getColor()==White){
                DFS_Visit(u);
            }
        }
    }
};

void DepthFirstSearch::DFS_Visit(Vertex* u){
    time+=1;
    u->setDiscoveryTime(time);
    u->setColor(Gray);
    for(Vertex* v : u->getAdjacents()){
        if(v->getColor()==White){
            v->setAncestor(u);
            DFS_Visit(v);
        }
    }
    u->setColor(Black);
    time+=1;
    u->setFinishTime(time);
}
}
#endif /* DEPTHFIRSTSEARCH_H */

