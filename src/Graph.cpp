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
    //display the number of vertexes
    cout<<listVertex.size()<<endl;
    myFeed<<listVertex.size()<<endl;
    if(typeOfGraph){//Type of graph : directed graph
        cout<<"o"<<endl;
        myFeed<<"o"<<endl;
    }else{//Type of graph : undirected graph
        cout<<"n"<<endl;
        myFeed<<"n"<<endl;
    }
    if(typeOfRepresentation){//type of representation : matrix
        cout<<"m"<<endl;
        myFeed<<"m"<<endl;
        displayMatrix();
    }else{//type of representation : list
        cout<<"l"<<endl;
        myFeed<<"l"<<endl;
        displayList();
    }
}

void Graph::displayMatrix(){
    int matrix[listVertex.size()][listVertex.size()];
    ofstream myFeed("Files/Result.txt", ios::app);

    //calcul of the matrix
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
        for(int x=0; x<listVertex.size();x++){
                for(int y=0; y<listVertex.size();y++){
                    myFeed<<matrix[x][y]<<";";
                    cout<<matrix[x][y]<<";";
                }
                myFeed<<endl;
                cout<<endl;
        }
    }else{
    cout<<"ERROR .TXT"<<endl;
    }
}

void Graph::displayList(){

}

void Graph::learnTxtFile(){

}

/* a faire :
globaliser la matrice à graph et faire une fct qui lit correctement le fichier .txt dans part1 2.bfile error*/
