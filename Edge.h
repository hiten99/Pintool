#ifndef _EDGE_H_
#define _EDGE_H_
#include "Vertex.h"
class Edge
{
public:
    Edge(Vertex *org, Vertex *dest, int dist);
    Vertex* getOrigin();
    Vertex* getDestination();
    int getDistance();
	void incrementDistance();
	int getedgecount(Vertex *org, Vertex *dest);
private:
    Vertex* origin;
    Vertex* destination;
    int distance;
};
#endif   // !defined _EDGE_H_