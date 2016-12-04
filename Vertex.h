#ifndef _VERTEX_H_
#define _VERTEX_H_

#include <string>
#include <vector>

class Edge;

class Vertex
{
public:
    Vertex::Vertex(std::string id);

    void Vertex::addEdge(Vertex *v);

    void Vertex::printEdges(std::string &cnt,std::ofstream &file);
    
	std::string Vertex::getName(); 
    
	std::vector<Edge> Vertex::getEdges() ;

private:
    std::string name;
    std::vector<Edge> edges;
	
};
#endif   // !defined _VERTEX_H_