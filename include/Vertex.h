#ifndef VERTEX_H
#define VERTEX_H
#include <utility>
#include <vector>
#include <iostream>

//class AdjListEdgeNode;//avoid cycling include


using namespace std;

class Vertex
{
    public:
        int id, date, pred;
        int color;
       /// int * neighbours;
       vector <pair<int,int> > nextEdgeNode; /// (id dest, id edge)

        Vertex();
        Vertex(int Id);
        virtual ~Vertex();

    protected:

    private:
};

#endif // VERTEX_H
