#include "Edge.h"

Edge::Edge(int Id,Vertex* Src,Vertex* Dest,int&c)
{
    this->id=Id;
    source=Src;
    destination=Dest;
    cost=c;
}

Edge::~Edge()
{
    //dtor
}
