#ifndef EDGE
#define EDGE

#include "Node.hh"

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

#endif /* end of include guard: Edge */