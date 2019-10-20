#ifndef VERTEX_H
#define VERTEX_H
//#include"AdjListEdgeNode.h"
//class AdjListEdgeNode;//avoid cycling include
#include "AdjListEdgeNode.h"
class Vertex
{
    public:
        int id;
        int color;
       /// int * neighbours;
       AdjListEdgeNode *nextEdgeNode;

        Vertex();
        Vertex(int Id);
        virtual ~Vertex();

    protected:

    private:
};

#endif // VERTEX_H
