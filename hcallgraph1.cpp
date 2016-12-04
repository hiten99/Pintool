#include "pin++/Callback.h"
#include "pin++/Routine_Instrument.h"
#include "pin++/Routine.h"
#include "pin++/Pintool.h"
#include "pin++/Symbol.h"
#include "Graph.h"
#include "Vertex.h"
#include "Edge.h"
#include <fstream>
#include <stack> 
#include <string>

/**
* @class h_Before
*/
class h_Before :
	public OASIS::Pin::Callback <h_Before (OASIS::Pin::ARG_FUNCARG_ENTRYPOINT_VALUE)>
{
public:
	h_Before (std::ofstream & file, std::stack<std::string> & hstack,Graph &hgraph)
		: hfile (file),
		hstack(hstack),
		hgraph_(hgraph)
	{

	}

	void setname(std::string name)
	{
		std::string fname= name;
	}

	void handle_analyze (ADDRINT ip)
	{
		std::string fpush_Name = this->f_name;
		if(hstack.empty()){
		hstack.push(fpush_Name);
		this->hfile  << fpush_Name << std::endl;
		Vertex *v=new Vertex(fpush_Name); 
		hgraph_.insert(v);
		}
		else if(!hstack.empty()){
			Vertex *v2=new Vertex(fpush_Name);
			std::string stacktop=hstack.top();
			Vertex *v1=new Vertex(stacktop);
			v1->addEdge(v2);
			hgraph_.insert(v1);
			hgraph_.insert(v2);
		}

	}


	void setRoutineName(std::string name)
	{
		this->f_name = name;
	}

private:
	std::ofstream & hfile;
	std::string f_name;
	std::stack<std::string> & hstack;
	Graph &hgraph_;
};

/**
* @class h_After
*/
class h_After :
	public OASIS::Pin::Callback <h_After (OASIS::Pin::ARG_FUNCRET_EXITPOINT_VALUE)>
{
public:
	h_After (std::ofstream & file, std::stack<std::string> & hstack)
		: hfile (file),
		hstack(hstack)
	{
	}

	void setname(std::string name)
	{
		std::string fname= name;
	}

	void handle_analyze (ADDRINT ip)
	{
		if(!hstack.empty()){
			std::string fpop_Name  = hstack.top();
			hstack.pop();
			this->hfile << fpop_Name << std::endl;
		}
	}

	void setRoutineName(std::string name)
	{
		this->f_name = name;
	}

private:
	std::ofstream & hfile;
	std::string f_name;
	std::stack<std::string> & hstack;
};

class Instruction : public OASIS::Pin::Routine_Instrument <Instruction>
{
public:

	Instruction (std::ofstream & file, std::stack<std::string> & hstack, Graph &f)
		: hfile (file),
		hstack (hstack),
		g(f)
	{

	}

	void handle_instrument (const OASIS::Pin::Routine & rtn)
	{

			std::string myRtnName = rtn.name ();
			std::string newMyRtnName= OASIS::Pin::Symbol::undecorate (myRtnName, UNDECORATION_NAME_ONLY);
			OASIS::Pin::Routine_Guard guard (rtn);
			h_Before * h1_Before=new h_Before(hfile,  hstack,g);
			h1_Before->setname(newMyRtnName);
			h1_Before->setRoutineName(newMyRtnName);
			h1_Before->insert (IPOINT_BEFORE,rtn,0);
			
			h_After * h1_After=new h_After(hfile, hstack);
			h1_After->setname(newMyRtnName);
			h1_After->insert (IPOINT_AFTER,rtn);
			
  }

private:
	std::ofstream & hfile;
	std::stack<std::string> & hstack;
	Graph &g;
};

class hcallgraph1 : public OASIS::Pin::Tool <hcallgraph1>
{
public:
	hcallgraph1 (void)
		: hfile ("hcallgraph1.out"),
		hinst (hfile, hstack,g)
	{
		this->init_symbols ();
		this->enable_fini_callback ();
	}

	void handle_fini (INT32)
	{
		g.printGraph();
		this->hfile.close ();
	}

private:
	std::ofstream hfile;
	std::stack<std::string> hstack;
	Instruction hinst;
	Graph g;

};

DECLARE_PINTOOL (hcallgraph1);