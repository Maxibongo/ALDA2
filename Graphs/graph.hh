#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct Vertex{
	double pot;
	Vertex() : pot(0){};
	Vertex(double pot) : pot(pot){};
};

struct Edge{
	Vertex start, end;
	double weight;
	Edge() : weight(0){};
	Edge(Vertex start, Vertex end) : start(start), end(end), weight(0){};
	Edge(Vertex start, Vertex end, double weight) : start(start), end(end), weight(weight){};
};

class Graph{
public:
	Graph();
	Graph(Vertex v);
	Graph(Edge e);
	Graph(vector<Edge> e);
	Graph(vector<Vertex> v);
	Graph(vector<Vertex> v, vector<Edge> e);
	vector<Vertex> getVertices();
	vector<Edge> getEdges();
	vector<vector<Edge> > getAdjEdges();
	void insertVertex(const Vertex v);
	void removeVertex(Vertex v);
	void insertEdge(const Edge e);
	void removeEdge(Edge e);


private:	
	vector<Vertex> vertices;
	vector<Edge> edges;
	map<vector<Edge> > adjEdges;
};