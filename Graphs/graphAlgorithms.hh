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

template<class T>
bool inVector(std::vector<T>& con, T element){
	for(int i = 0; i < con.size(); i++){
		if(con[i] == element){
			return true;
		}
	}
	return false;
}

void printParentDistance(Graph& g, std::map<Node,int>& distance, std::map<Node, Node>& parent){
    for(Node n : g.getNodes()){
        std::cout << n.getID() << " parent: " << parent[n].getID() << " distance: " << distance[n] << std::endl;
    }
}


void Dijkstra(Graph& g, Node& start, std::map<Node,int>& distance, std::map<Node, Node>& parent){
    // init
    distance.clear();
    parent.clear();
    for(Node n: g.getNodes()){
        distance[n] = INT_MAX;
        parent[n] = -1;
    }
    distance[start] = 0;
    parent[start] = start;
    std::deque<Node> Q; 
    Q.push_front(start); // initialize deque with Q
    
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

    // print each node with parent and distance from start
    printParentDistance(g, distance, parent);
}

std::vector<Node> findPath(Graph g, Node& start, Node& end){
    // call shortestPathDijkstra and try to retieve a path
    std::map<Node,int> distance; 
    std::map<Node, Node> parent;
    std::vector<Node> path;

    Dijkstra(g, start ,distance, parent);

    if(distance[end] == INT_MAX)
        return path;

    path.push_back(end);


    while(path.back() != start){
        path.push_back(parent[path.back()]);
    }
    
    std::reverse(path.begin(), path.end());

    return path;
}


void BreadthFirstSearch(){
    ;
}