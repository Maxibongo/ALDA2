#include "graph.hh"

int main() {

	// Test all Node functionality constructors, getter and setter methods, print
	std::cout << "Test Node functionality:" << std::endl;

	Node n1;
	Node n2(2);

	std::cout << (n1.getWeight() == 0) << std::endl;
	std::cout << (n2.getWeight() == 2) << std::endl;

	std::cout << (n1.getID() == 1) << std::endl;
	std::cout << (n2.getID() == 2) << std::endl;

	n1.setWeight(-5);

	std::cout << (n1.getWeight() == -5) << std::endl;
	std::cout << (n1.getID() == 1) << std::endl;

	n1.print();
	n2.print();


	std::cout << ((n1<n2)) << std::endl;

	std::cout << "============================================" << std::endl;

	// Test all Edge functionality constructors, getter and setter methods, print
	std::cout << std::endl << "Test Edge functionality:" << std::endl;

	Edge e1;
	Edge e2(n1, n2);
	Edge e3(n2, n1, 10);

	e1.print();
	e2.print();
	e3.print();

	e3.getStart().print();
	e3.getEnd().print();
	std::cout << e3.getWeight() << std::endl;

	Node nTemp = e3.getStart();
	e3.setStart(e3.getEnd());
	e3.setEnd(nTemp);
	e3.print();

	e3.setWeight(-25);
	e3.print();

	// Test all Graph functionality constructors, addEdge, addNode, print, getter methods
	std::cout << std::endl << "Test Graph functionality:" << std::endl;

	Graph g1;
	Graph g2(n1);
	Graph g3(e1); 
	Graph g4(n1,e1);
	Graph g5(n1,e1, true);
	Graph g6(n1,e1, false);

	std::vector<Node> N = {n1,n2};
	std::vector<Edge> E = {e1,e2};
	Graph g7(N,E);

	std::cout << "Test constructors" << std::endl;

	g1.print();
	g2.print();
	g3.print();
	g4.print();
	g5.print();
	g6.print();
	g7.print();

	std::cout << "Test addNode and addEdge" << std::endl;
	Graph g8;
	g1.print();
	g1.addNode(n1);
	g1.print();
	g1.addEdge(e1);
	g1.print();

	std::cout << "Test removeNode and removeEdge" << std::endl;
	g1.print();
	g1.removeEdge(e1);
	g1.print();
	g1.removeNode(n1);
	g1.print();

	std::cout << "Test Graph comparing" << std::endl;
	g8.addNode(n1);
	g8.addEdge(e1);
	g8.removeEdge(e1);
	g8.removeNode(n1);

	std::cout << (g1 == g8) << std::endl;
	

	std::cout << std::endl << "Test overall functionality with example of ALDA sheet 7 \"Haus des Nikolaus-Graph\"" << std::endl;
	
	std::vector<Node> Nodes;
	for(int i = 0; i < 7; i++){
		Nodes.push_back(Node(0));
	}
	std::vector<Edge> Edges = {Edge(Nodes[0], Nodes[1],10),
		Edge(Nodes[1], Nodes[2],2),Edge(Nodes[1], Nodes[3],4),Edge(Nodes[1], Nodes[4],3),
		Edge(Nodes[2], Nodes[6],9),
		Edge(Nodes[3], Nodes[2],5),Edge(Nodes[3], Nodes[4],2),Edge(Nodes[3], Nodes[5],2),
		Edge(Nodes[4], Nodes[2],2),
		Edge(Nodes[5], Nodes[4],3),};
	
	Graph HdN(Nodes, Edges, true);
	HdN.print();


	return 0; 
}
