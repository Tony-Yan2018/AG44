#include "Graph.h"
#include <Vertex.h>
#include <Edge.h>
#include <time.h>
#include <cstdlib>

Graph::Graph(int nbNodes)
{
    srand (time(NULL)+1);
    for(int i=0; i<nbNodes;i++){//initialize all the nodes/Vertexes and give them a color
        Vertex *v = new Vertex(i);// to initialize
        v->color = 0; //O black & 1 white
        listVertex.push_back(v);
    }
    int p=0;//index of the listEdge to find an edge
    for(int i=0; i<nbNodes;i++){//to create the matrice
        for(int j=0; j<nbNodes;j++){
            int index =rand() % 2;//generate an random number between 0,1
            if(index == 1){//if an edge exist
                Edge *e = new Edge(p, listVertex[i],listVertex[j]);
                p++;
                listEdges.push_back(e);
            }
        }
    }
}

Graph::~Graph()
{
    //dtor
}
void Graph::afficher(){
    cout<<"Liste Vertex : "<<endl;
    for(int id=0; id<listVertex.size();id++){
        cout<<", "<<listVertex[id]->id<<endl;
    }
    cout<<"Liste Edges : "<<endl;
    for(int id=0; id<listEdges.size();id++){
        cout<<", "<<listEdges[id]->id<<"src : "<< listEdges[id]->source
        <<"Dest : "<< listEdges[id]->destination <<endl;
    }
}
