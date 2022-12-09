#include "Edge.hh"

Edge::Edge(){
	this->weight = 0;
}

Edge::Edge(Node start_, Node end_, int weight_){
	this->start = start_;
	this->end = end_;
	this->weight = weight_;
}

Node Edge::getStart() const{
	return this->start;
}

Node Edge::getEnd() const{
	return this->end;
}

int Edge::getWeight() const{
	return this->weight;
}

void Edge::setStart(Node start_){
	this->start = start_;
}

void Edge::setEnd(Node end_){
	this->end = end_;
}

void Edge::setWeight(int weight_){
	this->weight = weight_;
}

void Edge::print(){
	std::cout << "-------------------------------" << std::endl;
	std::cout << "Start NodeID:" << this->start.getID() << std::endl;
	if(this->start.getWeight() != 0)
	    std::cout << "Start Node Weight:" << this->start.getWeight() << std::endl;
	std::cout << "End NodeID:" << this->end.getID() << std::endl;
	if(this->end.getWeight() != 0)
	    std::cout << "End Node Weight:" << this->end.getWeight() << std::endl;
	std::cout << "Node weight:" <<this->weight << std::endl;
	std::cout << "-------------------------------" << std::endl;
}

bool Edge::operator==(const Edge& other){
	if(this->start == other.getStart() && this->end == other.getEnd() && this->weight == other.getWeight()){
		return true;
	}
	return false;
}

