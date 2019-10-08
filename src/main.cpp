#include <iostream>
#include "Graph.h"


using namespace std;

int main()
{
    bool typeOfGraph=true,typeOfRepresentation=true;//true = directed false = undirected | true=matrix false = list
    Graph *g = new Graph(5);
    g->display(typeOfGraph,typeOfRepresentation);
    return 0;
}
