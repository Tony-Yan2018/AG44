#ifndef ADJLISTEDGENODE_H_INCLUDED
#define ADJLISTEDGENODE_H_INCLUDED
class Edge;
class AdjListEdgeNode{
public:
        int nextVertex;
        int weight;
        int IdEdge;//easier to tell two vertices in an undirected graph
        AdjListEdgeNode *nextEdgeNode;

        AdjListEdgeNode();
        AdjListEdgeNode(const Edge* );

};


#endif // ADJLISTEDGENODE_H_INCLUDED
