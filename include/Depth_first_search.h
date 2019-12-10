#ifndef DEPTH_FIRST_SEARCH_H
#define DEPTH_FIRST_SEARCH_H
#include "Graph.h"

class Depth_first_search
{
    public:
        Graph* g;
        int time;
        Depth_first_search(Graph* g);
        virtual ~Depth_first_search();
        void dfsVisit(Graph* g, int u);

    protected:

    private:
};

#endif // DEPTH_FIRST_SEARCH_H
