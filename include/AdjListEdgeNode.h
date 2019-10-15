#ifndef ADJLISTEDGENODE_H_INCLUDED
#define ADJLISTEDGENODE_H_INCLUDED
#include"Edge.h"
class AdjListEdgeNode{
private:
        int nextVertex;
        int weight;
        int IdEdge;//easier to tell two vertices in an undirected graph
        AdjListEdgeNode *nextEdgeNode;
public:
        AdjListEdgeNode();
        AdjListEdgeNode(const Edge* );
};

#endif // ADJLISTEDGENODE_H_INCLUDED
