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
	/*for (auto it = 0; it != g->listVertex.size(); it++) {
		cout << "start point:" << it + 1 << endl;
		if (g->IsCyclicDFSList(it + 1, it + 1)) {
			cout << "cycle detected!" << endl;
			g->IsThereACycle = true;
			break;
		}
		else {
			for (auto it = g->listVertex.begin(); it != g->listVertex.end(); it++) {
				(*it)->color = 0;
			}
		}
	}*/
	//if (!g->IsThereACycle) {
	//	g->TopoSortList();
	//}
	g->TopoSortList(g->nbNodes);
    return 0;
}
