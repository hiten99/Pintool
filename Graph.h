#ifndef _GRAPH_H_
#define _GRAPH_H_
#include "Edge.h"
#include "Vertex.h"

#include <vector>

class Graph
{
public:
    Graph() ;

    void insert(Vertex *v);


    void printGraph();

private:
    std::vector <Vertex*> vertices;
};
#endif   // !defined _GRAPH_H_