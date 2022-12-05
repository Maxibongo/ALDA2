#include "graph.hh"

int main() {

	// Test all Node functionality constructors, getter and setter methods, print
	std::cout << "Test Node functionality:" << std::endl;

	Node n;
	Node n_(2);

	std::cout << (n.getWeight() == 0) << std::endl;
	std::cout << (n_.getWeight() == 2) << std::endl;

	std::cout << (n.getID() == 1) << std::endl;
	std::cout << (n_.getID() == 2) << std::endl;

	n.setWeight(-5);

	std::cout << (n.getWeight() == -5) << std::endl;
	std::cout << (n.getID() == 1) << std::endl;

	n.print();
	n_.print();

	NodeComparator nComp;

	std::cout << (nComp(n,n_)) << std::endl;

	std::cout << "============================================" << std::endl;

	// Test all Edge functionality constructors, getter and setter methods, print
	std::cout << std::endl << "Test Edge functionality:" << std::endl;

	Edge e;
	Edge e_(n, n_);
	Edge e__(n_, n, 10);

	e.print();
	e_.print();
	e__.print();

	e__.getStart().print();
	e__.getEnd().print();
	std::cout << e__.getWeight() << std::endl;

	Node nTemp = e__.getStart();
	e__.setStart(e__.getEnd());
	e__.setEnd(nTemp);
	e__.print();

	e__.setWeight(-25);
	e__.print();

	// Test all Graph functionality constructors, addEdge, addNode, print, getter methods
	std::cout << std::endl << "Test Edge functionality:" << std::endl;

	


	return 0; 
}
