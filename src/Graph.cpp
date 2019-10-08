#include "Graph.h"
#include <Vertex.h>
#include <Edge.h>
#include <time.h>
#include <cstdlib>
#include <fstream>
using namespace std;

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
void Graph::display(bool typeOfGraph,bool typeOfRepresentation){
    ofstream myFeed("Files/Result.txt");//supprime l'ancien fichier ou en créé un nouveau

    if(typeOfGraph){//directed graph
        cout<<"Type of graph : o"<<endl;
        myFeed<<"Type of graph : o"<<endl;
    }else{//undirected graph
        cout<<"Type of graph : n"<<endl;
        myFeed<<"Type of graph : n"<<endl;
    }
    if(typeOfRepresentation){//matrix
        displayMatrix();
    }else{//list
        //displayList();
    }
/*
    cout<<"Liste Vertex : "<<endl;
    for(int id=0; id<listVertex.size();id++){
        cout<<", "<<listVertex[id]->id<<endl;
    }
    cout<<"Liste Edges : "<<endl;
    for(int id=0; id<listEdges.size();id++){
        cout<<", "<<listEdges[id]->id<<"src : "<< listEdges[id]->source
        <<"Dest : "<< listEdges[id]->destination <<endl;
    }*/
}

void Graph::displayMatrix(){
    int matrix[listVertex.size()][listVertex.size()];
    ofstream myFeed("Files/Result.txt", ios::app);

    for(int x=0; x<listVertex.size();x++){
            for(int y=0; y<listVertex.size();y++){
                matrix[x][y]=0;
            }
    }
    for(int i=0;i<listEdges.size();i++){
        matrix[listEdges[i]->source->id][listEdges[i]->destination->id]=1;
    }
    if(myFeed){
        //display
        cout<<" ";
        myFeed<<" ";
        for(int i=0; i<listVertex.size();i++){//1st of the tab to display " 123.."
            cout<<listVertex[i]->id+1;
            myFeed<<listVertex[i]->id+1;
        }
        myFeed<<endl;
        cout<<endl;
        for(int x=0; x<listVertex.size();x++){
                myFeed<<x+1;
                cout<<x+1;
                for(int y=0; y<listVertex.size();y++){
                    myFeed<<matrix[x][y];
                    cout<<matrix[x][y];
                }
                myFeed<<endl;
                cout<<endl;
        }
    }else{
    cout<<"ERROR .TXT"<<endl;
    }
}

