#ifndef EDGE_H
#define EDGE_H
#include <Vertex.h>

class Edge
{
    public:
        int id;
        Vertex *source;
        Vertex *destination;
        int cost;


        Edge(int Id,Vertex* Src,Vertex* Dest);
        virtual ~Edge();

    protected:

    private:
};

#endif // EDGE_H
