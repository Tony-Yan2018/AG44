#ifndef GRAPH_H
#define GRAPH_H
#include "Vertex.h"
#include "Edge.h"
#include "AdjListEdgeNode.h"
#include <vector>
#include <iostream>
using namespace std;
class Graph
{
    public:
        vector <Vertex*> listVertex;
        vector <Edge*> listEdges;
        ///int **Cout;
       /// static Vertex *AdjacencyList;
        static int **matrix;


        Graph(int nbNodes); //constructor of a directed graph
        Graph(ifstream *);
        void randGeneMat_directed(const int &);
        void randGeneMat_undirected(const int &);
        void randGeneAdjLt_directed(const int &);
        void randGeneAdjLt_undirected(const int &);
        virtual ~Graph();//destructor
        void display(bool typeOfGraph,bool typeOfRepresentation);
        void displayMatrix();
        void displayList();
        void learnTxtFile();

    protected:

    private:
};

#endif // GRAPH_H
