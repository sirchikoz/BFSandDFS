
/* 
 * File:   main.cpp
 * Author: sirch
 *
 * Created on March 7, 2019, 9:35 PM
 */
#include "Vertex.h"
#include "Graph.h"
#include <cstdlib>
#include <iostream>
#include "BreadthFirstSearch.h"
#include "DepthFirstSearch.h"
using namespace std;
using namespace algorithms;
/*
 * 
 */
void print_path(Vertex* s, Vertex* v);
int main(int argc, char** argv) {
    //First graph
    Vertex v1(1);
    Vertex v2(2);
    Vertex v3(3);
    Vertex v4(4);
    Vertex v5(5);
    Vertex v6(6);
    Vertex v7(7);
    Vertex v8(8);
    Vertex vertices[]={v1,v2,v3,v4,v5,v6,v7,v8} ;
    vertices[0].add(&vertices[1]);
    vertices[0].add(&vertices[4]);
            
    vertices[1].add(&vertices[0]);
    vertices[1].add(&vertices[5]);
            
    vertices[2].add(&vertices[5]);
    vertices[2].add(&vertices[6]);
    vertices[2].add(&vertices[3]);
     
    vertices[3].add(&vertices[2]);
    vertices[3].add(&vertices[6]);
    vertices[3].add(&vertices[7]);
     
    vertices[4].add(&vertices[0]);
            
    vertices[5].add(&vertices[1]);
    vertices[5].add(&vertices[2]);
    vertices[5].add(&vertices[6]);
                
    vertices[6].add(&vertices[5]);
    vertices[6].add(&vertices[2]);
    vertices[6].add(&vertices[3]);
    vertices[6].add(&vertices[7]);
            
    vertices[7].add(&vertices[3]);
    vertices[7].add(&vertices[6]);
    //Second graph
    Vertex vv1(1);
    Vertex vv2(2);
    Vertex vv3(3);
    Vertex vv4(4);
    Vertex vv5(5);
    Vertex vv6(6);
    
    Vertex vertices2[]={vv1,vv2,vv3,vv4,vv5,vv6} ;
    vertices2[0].add(&vertices2[1]); 
    vertices2[0].add(&vertices2[3]);
    vertices2[1].add(&vertices2[4]);
    vertices2[2].add(&vertices2[4]);
    vertices2[2].add(&vertices2[5]);
    vertices2[4].add(&vertices2[3]);
    vertices2[5].add(&vertices2[5]);
    
    Vertex source = vertices2[5];
    //Graph g;
    BreadthFirstSearch bfs(source);
    bfs.explore();
    print_path(&vertices2[5],&vertices2[5]);
    
    
    DepthFirstSearch dfs(vertices2,8);
    dfs.explore();
    print_path(&vertices2[5],&vertices2[5]);
//cout<<"We have to be sure "<<numeric_limits<int>::max()<<endl;
    return 0;
}
void print_path(Vertex* s, Vertex* v){
    //cout<<" |-----------| ";
    if(s->getID()==v->getID())
        cout<<s->getID()<<endl;
    else if(v->getAncestor()==nullptr)
        cout<<"No path from "<<s->getID()<<" to "<<v->getID()<<" exists";
    else print_path(s,v->getAncestor());
    cout<<" "<<v->getID()<<" ";
}

