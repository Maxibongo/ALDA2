#include<deque>
#include"Graph.hh"

bool inContainer(std::deque<Node>& Nodes, Node n){
    for(auto it = Nodes.cbegin(); it != Nodes.cend(); ++it){
        if(*it == n){
            return true;
        }
    }
    return false;
}


void shortestPathDijkstra(Graph g, Node& start, std::map<Node,int>& distance, std::map<Node, Node>& parent){
    distance.clear();
    parent.clear();
    for(Node n: g.getNodes()){
        distance[n] = INT_MAX;
    }
    distance[start] = 0;
    parent[start] = start;
    std::deque<Node> Q; 
    Q.push_front(start); // Q.insert(s)
    
    while(!Q.empty()){
        Node u = Q.front(); // get top element of stack
        Q.pop_front(); // remove top element of stack

        std::vector<Edge> Edges = g.getAdjacencyList()[u];

        for(Edge e: Edges){ // for each edge e=(u,v)
            Node v = e.getEnd();
            if(distance[u] + e.getWeight() < distance[v]){
                distance[v] = distance[u] + e.getWeight();
                parent[v] = u;
                if(!inContainer(Q,v)){
                    Q.push_front(v);
                }
            }
        }
    }

    for(Node n : g.getNodes()){
        std::cout << n.getID() << " parent: " << parent[n].getID() << " distance: " << distance[n] << std::endl;
    }
}