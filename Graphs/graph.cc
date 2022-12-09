#include "graph.hh"


template<class T>
bool inVector(std::vector<T>& con, T element){
	for(int i = 0; i < con.size(); i++){
		if(con[i] == element){
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

bool Node::operator==(const Node& other){
	if(this->getID() == other.getID()){
		return true;
	}
	return false;
}









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
	}
	setAdjacency();
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
	setAdjacency();
}

Graph::Graph(std::vector<Node>& nodes_, std::vector<Edge>& edges_,bool dir){
	this->nodes = nodes_;
	this->edges = edges_;
	for(int i = 0; i < this->edges.size(); i++){
		if(!inVector(this->nodes, this->edges[i].getStart())){
			this->nodes.push_back(this->edges[i].getStart());
		}
		if(!inVector(this->nodes, this->edges[i].getEnd())){
			this->nodes.push_back(this->edges[i].getEnd());
		}
		if(!dir){
			Edge reverse(this->edges[i].getEnd(),this->edges[i].getStart(), this->edges[i].getWeight());
			if(!inVector(this->edges, reverse)){
				this->edges.push_back(reverse);
			}
		}
	}
	setAdjacency();
}

void Graph::addEdge(Edge e,bool bi){
	this->edges.push_back(e);
	if(!inVector<Node>(this->nodes, e.getStart())){
		this->nodes.push_back(e.getStart());
	}
	if(!inVector<Node>(this->nodes, e.getEnd())){
		this->nodes.push_back(e.getEnd());
	}
	if(bi){
		this->edges.push_back(Edge(e.getEnd(),e.getStart(),e.getWeight()));
	}
	setAdjacency();
	
}
void Graph::addNode(Node n){
	this->nodes.push_back(n);
	this->adjacencyList[n] = {};
}

void Graph::removeNode(Node n){
	std::vector<Node> newNodes;
	std::vector<Edge> newEdges;
	for(int i = 0; i < this->nodes.size(); i++){
		if(!(this->nodes[i] == n))
			newNodes.push_back(this->nodes[i]);
	}
	for(int i = 0; i < this->edges.size(); i++){
		if(!(this->edges[i].getStart() == n) && !(this->edges[i].getEnd() == n))
			newEdges.push_back(this->edges[i]);
	}
	this->nodes = newNodes;
	this->edges = newEdges;
	setAdjacency();

}

void Graph::removeEdge(Edge e){
	std::vector<Edge> newEdges;
	for(int i = 0; i < this->edges.size(); i++){
		if(!(this->edges[i] == e))
			newEdges.push_back(this->edges[i]);
	}
	this->edges = newEdges;
	setAdjacency();
}

void Graph::print(){
	std::cout << "-------------------------------" << std::endl;
	for(std::map<Node,std::vector<Edge> >::iterator it = this->adjacencyList.begin(); it != this->adjacencyList.end(); ++it) {
      	std::cout << it->first.getID() << " : ";
		if(this->adjacencyList[it->first].size() == 1)
			std::cout << this->adjacencyList[it->first][0].getEnd().getID() << "(" << this->adjacencyList[it->first][0].getWeight() << ")";
		else if(this->adjacencyList[it->first].size() > 1){
			std::cout << this->adjacencyList[it->first][0].getEnd().getID() << "(" << this->adjacencyList[it->first][0].getWeight() << ")";
			for(int j = 1; j < this->adjacencyList[it->first].size(); j++){
				std::cout << " , " << this->adjacencyList[it->first][j].getEnd().getID() << "(" << this->adjacencyList[it->first][j].getWeight() << ")";
			}
		}
		std::cout << std::endl;
    }
	std::cout << "-------------------------------" << std::endl;
}

std::vector<Edge> Graph::getEdges() const{
	return this->edges;
}
std::vector<Node> Graph::getNodes() const{
	return this->nodes;
}

std::map<Node, std::vector<Edge>, NodeComparator> Graph::getAdjacencyList() const{
	return this->adjacencyList;
}

bool Graph::getDirectional() const{
	return this->directional;
}

bool Graph::operator==(const Graph& other){
	if(this->nodes.size() != other.getNodes().size() || this->edges.size() != other.getEdges().size() || this->directional != other.getDirectional()){
		return false;
	}
	for(int i = 0; i < this->nodes.size(); i++){
		if(!(this->nodes[i] == other.getNodes()[i]))
			return false;
	}
	for(int i = 0; i< this->edges.size(); i++){
		if(!(this->edges[i] == other.getEdges()[i]))
			return false;
	}
	return true;
}

void Graph::setAdjacency(){
	this->adjacencyList.clear();
	for(int i = 0; i < this->nodes.size(); i++){
		this->adjacencyList[nodes[i]] = {};
	}
	for(int i = 0; i < this->edges.size(); i++){
		this->adjacencyList[this->edges[i].getStart()].push_back(this->edges[i]);
	}
}
