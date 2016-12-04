#include <vector>
#include <iostream>
#include <string>

#include "Edge.h"
#include "Vertex.h"


    Edge::Edge(Vertex *org, Vertex *dest, int ecount)
    {
        origin = org;
        destination = dest;
        distance = ecount;
		getedgecount(origin,destination);
		
    }

    Vertex* Edge:: getOrigin() {return origin;}
    Vertex* Edge::getDestination() {return destination;}
    int Edge:: getDistance() {return distance;}
	void Edge:: incrementDistance() { distance++;}
	int Edge::getedgecount(Vertex *origin, Vertex *destination){return this->distance;}