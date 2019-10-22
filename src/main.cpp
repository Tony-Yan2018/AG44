#include <iostream>
#include "Graph.h"
#include <fstream>
#include <cstdio>
#include <cstddef>
using namespace std;

int main()
{
    bool typeOfGraph=false,typeOfRepresentation=false;//true = directed false = undirected | true=matrix false = list
    //Graph g;
    Graph *g = new Graph(5,typeOfGraph,typeOfRepresentation);
    return 0;
}
