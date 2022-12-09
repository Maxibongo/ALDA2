#ifndef GRAPH
#define GRAPH

#include <iostream>
#include <vector>
#include <map>

static int NodeID;

struct Node{
    public:
    Node();
    Node(int weight_);
    int getWeight() const;
    int getID() const;
    void setWeight(int weight_);
    void print();
    bool operator==(const Node& other) const ;
    bool operator<(const Node& other) const;

    private:
    int weight;
    int ID;
};



struct Edge{
    public:
    Edge();
    Edge(Node start_, Node end_, int weight_ = 0);
    Node getStart() const;
    Node getEnd() const;
    int getWeight() const;
    void setStart(Node start_);
    void setEnd(Node end_);
    void setWeight(int weight_);
    void print();
    bool operator==(const Edge& other);

    private:
    Node start;
    Node end;
    int weight;
};





class Graph{
public:
    Graph(bool dir = true);
    Graph(Node n, bool dir = true);
    Graph(Edge e, bool dir = true);
    Graph(Node n, Edge e, bool dir = true);
    Graph(std::vector<Node>& nodes_, std::vector<Edge>& edges_, bool dir = true);
    void addEdge(Edge e, bool bi=false);
    void addNode(Node n);
    void removeNode(Node n);
    void removeEdge(Edge e);
    void print();
    std::vector<Edge> getEdges() const;
    std::vector<Node> getNodes() const;
    std::map<Node, std::vector<Edge>> getAdjacencyList() const;
    bool getDirectional() const;
    bool operator==(const Graph& other);
private:
    void setAdjacency();
    std::vector<Node> nodes;
    std::vector<Edge> edges;
    std::map<Node, std::vector<Edge>> adjacencyList;
    bool directional;
};




#endif /* end of include guard: GRAPH */
