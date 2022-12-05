#include "graph.hh"

int main() {
    Node n1(-3);
	Node n2(2);

	std::vector<Node> n;
	n.push_back(n1);
	n.push_back(n2);


	Edge e(n1,n2,5);

	Graph g;
	std::cout << "Nodes" << g.getNodes().size() << std::endl;
	g.addNode(n1);
	std::cout << "Nodes" << g.getNodes().size() << std::endl;
	g.addNode(n2);
	std::cout << "Nodes" << g.getNodes().size() << std::endl;
	g.addEdge(e);
	std::cout << "Nodes" << g.getNodes().size() << std::endl;

	g.print();


	return 0; 
}
