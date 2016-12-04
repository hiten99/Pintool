#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include "Vertex.h"
#include "Graph.h"



    Graph::Graph() {}

    void Graph::insert(Vertex *v)
    {
        vertices.push_back(v);
    }

    void Graph::printGraph()
    {
		std::ofstream file("h.gv");
		

		std::string cnt="start";
		for (int i = 0; i < vertices.size(); i++)
        {   
			vertices[i]->printEdges(cnt,file);
			cnt="n";
		}
		file<<"}";
		file.close();
	}
