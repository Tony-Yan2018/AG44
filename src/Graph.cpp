#include "Graph.h"
#include <time.h>
#include <cstdlib>
#include <cstddef>
#include <fstream>
#include <string>
using namespace std;
//void Graph::randGeneMat_directed(const int &nbNodes){
//    srand (time(NULL)+1);
//    matrix=new int*[nbNodes];
//    for(int i=0;i<nbNodes;i++){
//        matrix[i]=new int[nbNodes];
//    }//allocate memory for matrix
//
//    for(int x=0; x<nbNodes;x++){
//            for(int y=0; y<nbNodes;y++){
//                matrix[x][y]=0;
//            }
//    }//initialization of matrix
//    for(int i=0; i<nbNodes;i++){//initialize all the nodes/Vertexes and give them a color
//        Vertex *v = new Vertex(i);// to initialize
//        v->color = 0; //O black & 1 white
//        listVertex.push_back(v);
//    }
//
//    int p=0;//index of the edges
//    for(int i=0; i<nbNodes;i++){//to create the matrix
//        for(int j=0; j<nbNodes;j++){
//            int index =rand() % 2;//generate an random number between 0,1
//            int weight=rand() % 100+1;
//            if(index == 1){//if an edge exist
//                Edge *e = new Edge(p, listVertex[i],listVertex[j],weight);
//                matrix[i][j]=weight;
//                p++;
//                listEdges.push_back(e);
//            }
//        }
//    }
//
//}
//void Graph::randGeneMat_undirected(const int &nbNodes){
//    srand (time(NULL)+1);
//     matrix=new int*[nbNodes];
//    for(int i=0;i<nbNodes;i++){
//        matrix[i]=new int[nbNodes];
//    }//allocate memory for matrix
//
//    for(int x=0; x<nbNodes;x++){
//            for(int y=0; y<nbNodes;y++){
//                matrix[x][y]=0;
//            }
//    }//initialization of matrix
//    for(int i=0; i<nbNodes;i++){//initialize all the nodes/Vertexes and give them a color
//        Vertex *v = new Vertex(i);// to initialize
//        v->color = 0; //O black & 1 white
//        listVertex.push_back(v);
//    }
//    int p=0;//index of the edges
//    for(int i=0; i<nbNodes;i++){//to create the matrix
//        for(int j=0; j<i;j++){
//            int index =rand() % 2;//generate an random number between 0,1
//            int weight=rand() % 100+1;
//            if(index == 1){//if an edge exist
//                Edge *e = new Edge(p, listVertex[i],listVertex[j],weight);
//                matrix[i][j]=weight;
//                matrix[j][i]=weight;
//                p++;
//                listEdges.push_back(e);
//            }
//        }
//    }
//}
void Graph::randGeneAdjLt_directed(const int &nbNodes){
    srand (time(NULL)+1);
    for(int i=0; i<nbNodes;i++){//initialize all the nodes/Vertexes and give them a color
        Vertex *v = new Vertex(i);// to initialize
        v->color = 0; //O black & 1 white
        listVertex.push_back(v);
    }

    int p=0;//index of the edges
    for(int i=0; i<nbNodes;i++){//to create the matrix
        for(int j=0; j<nbNodes;j++){
            int index =rand() % 2;//generate an random number between 0,1
            int weight=rand() % 100+1;
            if(index == 1){//if an edge exist
                Edge *e = new Edge(p, listVertex[i],listVertex[j],weight);
                p++;
                listEdges.push_back(e);
            }
        }
    }
    AdjListEdgeNode *next;
    for(auto iter = listEdges.begin();iter != listEdges.end();iter++){
        next = (*iter)->source->nextEdgeNode;
        if((*iter)->source!=NULL){
            while(next != NULL){
                next= next->nextEdgeNode;
            }
            next = new AdjListEdgeNode(*iter);
        }

    }


}
void Graph::randGeneAdjLt_undirected(const int &){

}
Graph::Graph(int nbNodes)//construction of a directed graph with a randomly generated matrix
{

    randGeneAdjLt_directed(nbNodes);
    ///randGene_undirected(nbNodes);
}
//Graph::Graph(int vertex,bool typeOfGraph, bool typeOfRepre,){
//
//    if(typeOfGraph){//directed
//        if(typeOfRepre){//matrix
//
//        }
//        else{//list
//
//        }
//    }
//    else{//undirected
//        if(typeOfRepre){//matrix
//
//        }
//        else{//list
//
//        }
//    }
//
//
//}

Graph::~Graph()
{
//    for(int i=0;i<listVertex.size();i++)
//        delete[] matrix[i];
//    delete[] matrix;
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
        ///displayMatrix();
    }else{//type of representation : list
        cout<<"l"<<endl;
        myFeed<<"l"<<endl;
        displayList();
    }
}

//void Graph::displayMatrix(){
//   /// int matrix[listVertex.size()][listVertex.size()];
//    ofstream myFeed("Files/Result.txt", ios::app);
//
//    //calculation of the matrix
//
//
//    if(myFeed){
//        //display
//        for(int x=0; x<listVertex.size();x++){
//                for(int y=0; y<listVertex.size();y++){
//                    myFeed<<matrix[x][y]<<";";
//                    cout<<matrix[x][y]<<";";
//                }
//                myFeed<<endl;
//                cout<<endl;
//        }
//    }else{
//    cout<<"ERROR .TXT"<<endl;
//    }
//}

void Graph::displayList(){
    ofstream myFeed("Files/Result.txt", ios::app);
    AdjListEdgeNode* next;
    if(myFeed){
        //display
        for(auto iter=listVertex.begin(); iter!=listVertex.end();iter++){
                next=(*iter)->nextEdgeNode;
                while(next != NULL){
                    myFeed<<iter-listVertex.begin()<<":"<<next->nextVertex<<","<<next->weight<<"->";//output to file
                    cout<<iter-listVertex.begin()<<":"<<next->nextVertex<<","<<next->weight<<"->";//display to console
                }
                myFeed<<endl;
                cout<<endl;
        }
    }else{
    cout<<"ERROR .TXT"<<endl;
    }
}

void Graph::learnTxtFile(){

}

/* a faire :
globaliser la matrice à graph et faire une fct qui lit correctement le fichier .txt dans part1 2.bfile error*/
