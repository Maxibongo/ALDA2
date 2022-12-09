#include"graph.hh"
#include"graphAlgorithms.hh"

int main(){
    std::vector<Node> Nodes;
	for(int i = 0; i < 7; i++){
		Nodes.push_back(Node(0));
	}
	std::vector<Edge> Edges = {Edge(Nodes[0], Nodes[1],10),
		Edge(Nodes[1], Nodes[2],2),Edge(Nodes[1], Nodes[3],4),Edge(Nodes[1], Nodes[4],3),
		Edge(Nodes[2], Nodes[6],9),
		Edge(Nodes[3], Nodes[2],5),Edge(Nodes[3], Nodes[4],2),Edge(Nodes[3], Nodes[5],2),
		Edge(Nodes[4], Nodes[2],2),
		Edge(Nodes[5], Nodes[4],3),};
	
	Graph HdN(Nodes, Edges, false);

    std::map<Node,int> distance; 
    std::map<Node, Node> parent;

    shortestPathDijkstra(HdN, HdN.getNodes()[5],distance, parent);
    
    std::cout << std::endl;

    std::vector<Node> cNodes;
    cNodes.push_back(Node(0));
    cNodes.push_back(Node(0));
    cNodes.push_back(Node(0));

    std::vector<Edge> cEdges;
    cEdges.push_back(Edge(cNodes[0], cNodes[1], 12));
    cEdges.push_back(Edge(cNodes[0], cNodes[2], 11));
    cEdges.push_back(Edge(cNodes[1], cNodes[2], -3));
    // cEdges.push_back(Edge(cNodes[2], cNodes[0], -100)); with this edge dijkstras algorithm does not finish because we create with this edge a negative cycle

    Graph c(cNodes, cEdges, true);

    shortestPathDijkstra(c, c.getNodes()[0], distance, parent);

    return 0;
}