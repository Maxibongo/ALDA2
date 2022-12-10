#include "Node.hh"

Node::Node(){
	this->weight = 0;
	this->ID = ++NodeID;
}

Node::Node(int weight_){
	this->weight = weight_;
	this->ID = ++NodeID;
}

int Node::getWeight() const {
	return this->weight;
}

void Node::setWeight(int weight_){
	this->weight = weight_;
}

int Node::getID() const {
	return this->ID;
}

void Node::print(){
	std::cout << "-------------------------------" << std::endl;
	std::cout << "NodeID:" << this->ID << std::endl;
	if(this->weight != 0)
		std::cout << "Node weight:" <<this->weight << std::endl;
	std::cout << "-------------------------------" << std::endl;
}

bool Node::operator==(const Node& other) const {
	if(this->getID() == other.getID()){
		return true;
	}
	return false;
}

bool Node::operator!=(const Node& other) const{
	if(*this == other){
		return false;
	}
	return true;
}

bool Node::operator<(const Node& other) const {
	if(this->getID() < other.getID()){
		return true;
	}
	return false;
}

