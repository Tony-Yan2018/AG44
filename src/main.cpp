#include <iostream>
#include "Graph.h"
#include <fstream>

using namespace std;

int main()
{
    bool typeOfGraph=true,typeOfRepresentation=true;//true = directed false = undirected | true=matrix false = list
    Graph *g = new Graph(5);
    g->display(typeOfGraph,typeOfRepresentation);
    ifstream read_file;
    read_file.open("Files/InputFile.txt",ios::in);
    Graph *g2 = new Graph(&read_file);

    return 0;
}
