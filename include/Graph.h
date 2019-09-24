#ifndef GRAPH_H
#define GRAPH_H
#include "Vertex.h"
#include "Edge.h"
#include <vector>
#include <iostream>
using namespace std;


class Graph
{
    public:

        vector <Vertex*> listVertex;
        vector <Edge*> listEdges;
        int **Cout;


        Graph(int nbNodes);
        virtual ~Graph();
        void afficher();

    protected:

    private:
};

#endif // GRAPH_H
