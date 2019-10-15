#include "Vertex.h"
#include<cstddef>
Vertex::Vertex(){
    id=-1;
    color=-1;
    nextEdge=NULL;
}
Vertex::Vertex(int Id)
{
    id=Id;
}

Vertex::~Vertex()
{
    //dtor
}
