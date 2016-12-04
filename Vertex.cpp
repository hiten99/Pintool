#include <vector>
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include "Edge.h"
#include "Vertex.h"


	Vertex::Vertex(std::string id)
    {
        name = id;
    }

    void Vertex::addEdge(Vertex *v)
    {
		int ecount=0;
		for (int i = 0; i < edges.size(); i++){
			std::string vsource=edges[i].getOrigin()->getName();
			std::string vcurrentsource=this->getName();
			std::string vdestination=edges[i].getDestination()->getName();
			std::string vcurrentdestination=v->getName();

			if(vsource==vcurrentsource && vdestination==vcurrentdestination){
				edges[i].incrementDistance();
				ecount++;
				break;
			}
		}
	
		if(ecount==0){
		Edge newEdge(this, v, 1);
		edges.push_back(newEdge);
		}
		
    }

    void Vertex::printEdges(std::string &cnt,std::ofstream &file)
    {
		if(cnt=="start"){
        file<<"digraph G {"<<"\n";
		}
		else if(cnt=="n"){
			
			for (int i = 0; i < edges.size(); i++)
			{
			file << "\""<<name <<"\"->";
			Edge e = edges[i];
			file << "\""<<e.getDestination()->getName() <<"\" [label=\"" << e.getDistance() <<"\"];"<< std::endl;
			}
		}
	}

    std::string Vertex:: getName() {return name;} 
    std::vector<Edge> Vertex::getEdges() {return edges;}

