#include"AdjListEdgeNode.h"
#include<cstddef>
#include"Edge.h"
AdjListEdgeNode::AdjListEdgeNode(){
    nextVertex=-1;
    weight=0;
    IdEdge=-1;
    nextEdgeNode=NULL;
}
AdjListEdgeNode::AdjListEdgeNode(const Edge *e){
    nextVertex=e->destination->id;
    weight=e->cost;
    IdEdge=e->id;
    nextEdgeNode=NULL;
}
