#ifndef GRAPH_hh
#define GRAPH_hh

#include "graph.hh"
#include <iostream>
#include <vector>

int main(){
	Vertex v1;
	std::cout << v1.pot << std::endl;
	Vertex v2(9.0);
	std::cout << v2.pot << std::endl;

	Edge e1;
	std::cout << e1.weight << std::endl;
	Edge e2(v1,v2);
	std::cout << e2.weight << std::endl;
	Edge e3(v1,v2,5.0);
	std::cout << e3.weight << std::endl;

	std::vector<Vertex> vs;
	vs.push_back(v1);
	vs.push_back(v2);

	std::vector<Edge> es;
	es.push_back(e1);
	es.push_back(e2);
	es.push_back(e3);

	Graph g(vs, es);
	std::vector<Edge> e = g.getEdges();

	for(int i = 0; i < e.size(); i++){
		std::cout << &e[i].start << " " << &e[i].end << std::endl;
	}

	std::cout << v1 == v2 << std::endl;
	std::cout << v1 == v1 << std::endl;
	
}


#endif