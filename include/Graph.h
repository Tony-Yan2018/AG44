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
        ///int **Cout;
        Vertex *AdjacencyList;


        Graph(int nbNodes); //constructor of a directed graph with a randomly generated matrix
        Graph(ifstream *);
        virtual ~Graph();//destructor
        void display(bool typeOfGraph,bool typeOfRepresentation);
        void displayMatrix();
        void displayList();
        void learnTxtFile();

    protected:

    private:
};

#endif // GRAPH_H
