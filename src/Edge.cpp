#include "Edge.h"
Edge::Edge() {
	id = -1;
	source = NULL;
	destination = NULL;
	cost = -1;
}
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
int Edge::getID() {
	return id;
}
Edge& Edge::operator=(const Edge& t) {
	if (this != &t) {
		this->id = t.id;
		this->cost = t.cost;
		this->destination = t.destination;
		this->source = t.source;
	}
	return *this;
}
