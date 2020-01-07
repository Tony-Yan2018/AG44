#include "Vertex.h"
#include<cstddef>
Vertex::Vertex(){
    id=-1;
    color=-1;
	pred = 0;
	date = 0;
	dist = 0;
}
Vertex::Vertex(int Id)
{
    id=Id;
}

Vertex::~Vertex()
{
    //dtor
}
