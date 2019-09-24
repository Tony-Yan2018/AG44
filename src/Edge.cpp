#include "Edge.h"

Edge::Edge(int Id,Vertex* Src,Vertex* Dest)
{
    this->id=Id;
    source=Src;
    destination=Dest;
}

Edge::~Edge()
{
    //dtor
}
