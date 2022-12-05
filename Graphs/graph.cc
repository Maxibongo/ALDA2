#include "graph.hh"


template<class T=Node>
bool inVector(std::vector<T>& con, T element){
	for(int i = 0; i < con.size(); i++){
		if(con[i].getID() == element.getID()){
			return true;
		}
	}
	return false;
}



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










Edge::Edge(){
	this->weight = 0;
}

Edge::Edge(int weight_){
	this->weight = weight_;
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









Graph::Graph(bool dir){
	this->directional = dir;
}

Graph::Graph(Node n,bool dir){
	this->nodes.push_back(n);
	this->directional = dir;
	this->adjacencyList[n] = {};
}

Graph::Graph(Edge e,bool dir){
	this->nodes.push_back(e.getStart());
	this->nodes.push_back(e.getEnd());
	this->edges.push_back(e);
	if(!dir){
		this->edges.push_back(Edge(e.getEnd(),e.getStart(),e.getWeight()));
		return;
	}

	for(int i = 0; i < this->nodes.size(); i++){
		this->adjacencyList[this->nodes[i]] = {};
	}
	for(int j = 0; j < edges.size(); j++){
		this->adjacencyList[this->edges[j].getStart()].push_back(this->edges[j].getEnd());
	}
}

Graph::Graph(Node n, Edge e, bool dir){
	this->nodes.push_back(n);
	this->edges.push_back(e);
	if(!inVector(this->nodes, e.getStart())){
		this->nodes.push_back(e.getStart());
	}
	if(!inVector(this->nodes, e.getEnd())){
		this->nodes.push_back(e.getEnd());
	}
	if(!dir){
		this->edges.push_back(Edge(e.getEnd(), e.getStart(), e.getWeight()));
	}

	for(int i = 0; i < this->nodes.size(); i++){
		this->adjacencyList[this->nodes[i]] = {};
	}
	for(int j = 0; j < edges.size(); j++){
		this->adjacencyList[this->edges[j].getStart()].push_back(this->edges[j].getEnd());
	}
}

Graph::Graph(std::vector<Node>& nodes_, std::vector<Edge>& edges_,bool dir){
	this->nodes = nodes_;
	this->edges = edges_;
	if(!dir){
		for(int i = 0; i < edges_.size(); i++){
			this->edges.push_back(Edge(edges_[i].getEnd(), edges_[i].getStart(), edges_[i].getWeight()));
		}
	}

	for(int i = 0; i < this->nodes.size(); i++){
		this->adjacencyList[this->nodes[i]] = {};
	}
	for(int j = 0; j < edges.size(); j++){
		this->adjacencyList[this->edges[j].getStart()].push_back(this->edges[j].getEnd());
	}
}

void Graph::addEdge(Edge e,bool bi){
	this->edges.push_back(e);
	if(!inVector<Node>(this->nodes, e.getStart())){
		this->nodes.push_back(e.getStart());
	}
	if(!inVector<Node>(this->nodes, e.getEnd())){
		this->nodes.push_back(e.getEnd());
	}
	this->adjacencyList[e.getStart()].push_back(e.getEnd());
	if(bi){
		this->edges.push_back(Edge(e.getEnd(),e.getStart(),e.getWeight()));
		this->adjacencyList[e.getEnd()].push_back(e.getStart());
	}
	
}
void Graph::addNode(Node n){
	this->nodes.push_back(n);
	this->adjacencyList[n] = {};
}

void Graph::print(){
	for(std::map<Node,std::vector<Node> >::iterator it = this->adjacencyList.begin(); it != this->adjacencyList.end(); ++it) {
      	std::cout << it->first.getID() << " : ";
		if(this->adjacencyList[it->first].size() == 1)
			std::cout << this->adjacencyList[it->first][0].getID();
		else if(this->adjacencyList[it->first].size() > 1){
			std::cout << this->adjacencyList[it->first][0].getID();
			for(int j = 1; j < this->adjacencyList[it->first].size(); j++){
				std::cout << " , " << this->adjacencyList[it->first][j].getID();
			}
		}
		std::cout << std::endl;
    }
}

std::vector<Edge> Graph::getEdges() const{
	return this->edges;
}
std::vector<Node> Graph::getNodes() const{
	return this->nodes;
}

std::map<Node, std::vector<Node>, NodeComparator> Graph::getAdjacencyList() const{
	return this->adjacencyList;
}

bool Graph::getDirectional(){
	return this->directional;
}

