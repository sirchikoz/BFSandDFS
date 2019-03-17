/* 
 * File:   BreadthFirstSearch.h
 * Author: sirch
 *
 * Created on March 11, 2019, 9:25 PM
 */

#ifndef BREADTHFIRSTSEARCH_H
#define BREADTHFIRSTSEARCH_H

#include <queue>
#include "Graph.h"
using namespace std;
namespace algorithms{
class BreadthFirstSearch{ 

    Graph graph;
    Vertex* source;
public:
    BreadthFirstSearch( Vertex& s){
        // = &g;
        source = &s;//vertices;
    }
    void explore(){
        source->setColor(Gray);
        queue<Vertex*>q;

        q.push(source);
                 //cout<<q.size()<<" ooo 1121 "<<endl;

        source->setDistance(0);
        
        while(q.size()>0){
            Vertex* u = q.front();
             // cout<<u.getColor() <<" 1121 "<<endl;
              q.pop();  
            for(Vertex* v: graph.getAdjacents(u)){
                if(v->getColor()==White){
                    v->setColor(Gray);
                    v->setDistance(u->getDistance()+1);
                    v->setAncestor(u);
                    q.push(v);
                   //cout<<v->getID() <<" Level "<<v->getDistance()<<endl;

                }
            }
                      
          //cout<<q.size()<<" ooo 1121 "<<endl;
            u->setColor(Black);
        }
    }
};
}

#endif /* BREADTHFIRSTSEARCH_H */

