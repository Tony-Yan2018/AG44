#ifndef KRUSKAL_H
#define KRUSKAL_H
#include "Graph.h"
#include <Vector>


class Kruskal
{
    public:
        Graph* g;
        Kruskal(Graph* g);
        virtual ~Kruskal();
        //int Kruskal::dfsVisit(Graph* g, int u,int source);
        //int Kruskal::detectCycle(Graph* g, int source);
    protected:

    private:
};

#endif // KRUSKAL_H
