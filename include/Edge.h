#ifndef EDGE_H
#define EDGE_H
#include "Vertex.h"

class Edge
{
    public:
        int id;
        Vertex *source;
        Vertex *destination;
        int cost;

		Edge();
        Edge(int Id,Vertex* Src,Vertex* Dest,int&);
        virtual ~Edge();

		int getID();
		Edge& operator=(const Edge& t);

    protected:

    private:
};

#endif // EDGE_H
