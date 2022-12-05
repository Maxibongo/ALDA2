#include "graph.hh"

int main() {
    Node n1(-3);
	Node n2(2);
	n1.print();
	n2.print();

	std::vector<Node> n;
	n.push_back(n1);
	n.push_back(n2);

	std::cout << inVector(n, n1) << std::endl;

	Edge e(n1,n2,5);
	e.print(); 

	Graph g;
	g.addNode(n1);
	g.addNode(n2);

	std::vector<Node> nodes = g.getNodes();
	std::vector<Edge> edges = g.getEdges();

	std::cout << "Nodes: " << nodes[0].getID();
	for(int i = 1; i < nodes.size(); i++){
		std::cout << " , " << nodes[i].getID();
	}
	std::cout << std::endl;

	std::cout << "Edges: " << "(" << edges[0].getStart().getID() << "," << edges[0].getEnd().getID() << ")";
	for(int i = 1; i < nodes.size(); i++){
		std::cout << " , " << "(" << edges[i].getStart().getID() << "," << edges[i].getEnd().getID() << ")";
	}
	std::cout << std::endl;

	g.print();


	return 0; 
}
