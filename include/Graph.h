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
        int **matrices;
		bool typeOfGraph, typeOfRepresentation;//true = directed false = undirected | true=matrix false = list

        Graph(int _nbNodes,bool typeOfGraph,bool typeOfRepresentation); //constructor of a directed graph
        Graph();
        void InputListGene(bool TOG,int nbNodes,ifstream& f);
        void randGeneMat_directed();
        void randGeneMat_undirected();
        void randGeneAdjLt_directed();
        void randGeneAdjLt_undirected();
        virtual ~Graph();//destructor
        void display(bool,bool);
        void displayMatrix();
        void displayList();
        Edge* findEdge(int);
		void displayGraph();
		void learnMatrixTxtFile();
		void learnListTxtFile();
		void o_list2matrix();
		void n_list2matrix();
		void BFSListO(int startFrom =-1);
		void BFSListN(int startFrom = -1);
		void DFSListO(int startFrom = -1);
		void DFSListN(int startFrom = -1);
		bool TopoSortList(int );
		void DijkstraList(Vertex *);
		void StronglyConnectedComp(int nbNodes,int startFrom = -1);
		void KruskalList();

    protected:

    private:
};

#endif // GRAPH_H
