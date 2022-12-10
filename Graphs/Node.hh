#ifndef NODE
#define NODE

#include<iostream>
#include<string>

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
    bool operator!=(const Node& other) const;
    bool operator<(const Node& other) const;

    private:
    int weight;
    int ID;
};

#endif /* end of include guard: NODE */