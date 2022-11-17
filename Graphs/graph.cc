#include "graph.hh"

Graph::Graph(){
	;
}

Graph::Graph(Vertex v){
	this->vertices.push_back(v);
}

Graph::Graph(vector<Vertex> v){
	this->vertices = v;
}	

Graph::Graph(vector<Vertex>v , vector<Edge> e){
	this->vertices = v;

	// assert each vertices of every eadge are in the graph already elsewise do not insert edge
	this->edges = e;
}

vector<Vertex> Graph::getVertices(){
	// return all vertices of the graph
	return this->vertices;
}

vector<Edge> Graph::getEdges(){
	// return all edges of the graph
	return this->edges;
}

vector<vector<Edge> > Graph::getAdjEdges(){
	// return all adjacency edges corresponding to their vertices of the graph
	return this->adjEdges;
}

void Graph::insertVertex(const Vertex v){
	return;
}

void Graph::removeVertex(Vertex v){
	return;
}

void Graph::insertEdge(const Edge e){
	return;
}

void Graph::removeEdge(Edge e){
	return;
}