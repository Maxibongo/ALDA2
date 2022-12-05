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

    private:
    int weight;
    int ID;
};


struct NodeComparator{
    public:
    bool operator() (const Node& lNode, const Node& rNode) const
   {
       return lNode.getID() < rNode.getID();
   }
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

    private:
    Node start;
    Node end;
    int weight;
};





class Graph{
public:
    Graph(bool dir = false);
    Graph(Node n, bool dir = false);
    Graph(Edge e, bool dir = false);
    Graph(Node n, Edge e, bool dir = false);
    Graph(std::vector<Node>& nodes_, std::vector<Edge>& edges_, bool dir = false);
    void addEdge(Edge e, bool bi=false);
    void addNode(Node n);
    void print();
    std::vector<Edge> getEdges() const;
    std::vector<Node> getNodes() const;
    std::map<Node, std::vector<Node>, NodeComparator> getAdjacencyList() const;
    bool getDirectional();
private:
    std::vector<Node> nodes;
    std::vector<Edge> edges;
    std::map<Node, std::vector<Node>, NodeComparator> adjacencyList;
    bool directional;
};

template<class T>
bool inVector(std::vector<T>& con, T element);



#endif /* end of include guard: GRAPH */