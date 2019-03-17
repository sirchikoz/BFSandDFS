
/* 
 * File:   Vertex.h
 * Author: sirch
 *
 * Created on March 7, 2019, 9:58 PM
 */

#ifndef VERTEX_H
#define VERTEX_H
#include <vector>
#include <limits>
using namespace std;
namespace algorithms{
      enum color{White = 1, Gray , Black };
    class Vertex{
         int distance = 0, id=0;
         int discoveryTime = 0;
         int finishTime = 0;
        color col;
        Vertex* ancestor = nullptr;
       
        vector<Vertex*> adjacents;
    public:
        Vertex(int identity){
            id=identity;
            col = color::White;
            distance = numeric_limits<int>::max();
        }
        void setDistance(int dst){
            distance = dst;
        }
        int getDistance(){
            return distance;
        }
        void setColor(color c){
                col = c;
        }
        color getColor(){
            return col;
        }
        void add(Vertex* ver){
            adjacents.push_back(ver);
        }
        vector<Vertex*> getAdjacents(){
            return adjacents;
        }
        void setID(int d){
            id = d;
        }
        int getID(){
            return id;
        }
        void setDiscoveryTime(int d){
            discoveryTime = d;
        }
        int getDiscoveryTime(){
            return discoveryTime;
        }
        void setFinishTime(int d){
            finishTime = d;
        }
        int getFinishTime(){
            return finishTime;
        }
        void setAncestor(Vertex* v){
            ancestor = v;
        }
        Vertex* getAncestor(){
           return ancestor;
        }
    };
}


#endif /* VERTEX_H */

