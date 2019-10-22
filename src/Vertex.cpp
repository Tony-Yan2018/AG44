#include "Vertex.h"
#include<cstddef>
Vertex::Vertex(){
    id=-1;
    color=-1;
}
Vertex::Vertex(int Id)
{
    id=Id;
}

Vertex::~Vertex()
{
    //dtor
}
