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
    for(Node n : HdN.getNodes()){
        std::cout << n.getID() << " parent: " << parent[n].getID() << " distance: " << distance[n] << std::endl;
    }

    return 0;
}