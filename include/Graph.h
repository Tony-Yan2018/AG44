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
        int nbNodes;
        ///int **Cout;
       /// static Vertex *AdjacencyList;
        int **matrices;

        Graph(int _nbNodes,bool typeOfGraph,bool typeOfRepresentation); //constructor of a directed graph
        Graph();
        Graph(ifstream *);
        void randGeneMat_directed();
        void randGeneMat_undirected();
        void randGeneAdjLt_directed();
        void randGeneAdjLt_undirected();
        virtual ~Graph();//destructor
        void display(bool,bool);
        void displayMatrix();
        void displayList();
        void learnTxtFile();
        Edge* findEdge(int);

    protected:

    private:
};

#endif // GRAPH_H
