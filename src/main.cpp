#include <iostream>
#include "Graph.h"
#include <fstream>
#include <cstdio>
#include <cstddef>
#include "Depth_first_search.h"
using namespace std;

int main()
{
	bool txtOrRandom = true;//generate a graph from: true£ºtxt; false: random
	bool typeOfGraph = true;// true = directed false = undirected
	bool typeOfRepresentation = true;// true=matrix false = list
	Graph* g;
	if (txtOrRandom) { g = new Graph(); }
	//constructor with a random generated matrice
	else { g = new Graph(5, typeOfGraph, typeOfRepresentation); }
	//g->displayGraph();
	//Depth_first_search DFS(g);
	//g->n_list2matrix();
	//g->displayMatrix();
	//g->BFSListN();
	//g->DFSListN();
	//g->TopoSortList(g->nbNodes);
	g->DijkstraList(g->listVertex[6]);
    return 0;
}
