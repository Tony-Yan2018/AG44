#include <iostream>
#include "Graph.h"
#include <fstream>
#include <cstdio>
#include <cstddef>
#include "Depth_first_search.h"
#include "Breadth_first_search.h"
#include "Strongly_related.h"
#include "Prim.h"
#include "Kruskal.h"
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
	//g->BFSListO();
	//g->BFSListN();
	//g->DFSListO(); //compatible with ./File/Input1.txt
	//g->DFSListN(); //compatible with ./File/Input2.txt
	//g->TopoSortList(g->nbNodes); //compatible with ./File/Input1.txt and ./File/Input1.1.txt
	//g->DijkstraList(g->listVertex[6]); //runs perfectly with ./File/Input1.txt
	//g->StronglyConnectedComp(g->nbNodes,1); //runs perfectly with ./File/Input1.txt
	//g->KruskalList(); //runs perfectly with ./File/Input1.txt

	//Depth_first_search DFS(g);
	//Breadth_first_search BFS(g);
	Kruskal Ksk(g);
	//Prim prim(g);
	//Strongly_related Strongly_related(g);

    return 0;
}
