#include "Graph.h"
#include <time.h>
#include <cstdlib>
#include <cstddef>
#include <fstream>
#include <string>
using namespace std;

void Graph::randGeneMat_directed(){
    srand (time(NULL)+1);

    for(int x=0; x<nbNodes;x++){
        for(int y=0; y<nbNodes;y++){
            matrices[x][y]=0;
        }
    }//initialization of matrices

    for(int i=0; i<nbNodes;i++){//initialize all the nodes/Vertexes and give them a color
        Vertex *v = new Vertex(i);// to initialize
        v->color = 0; //O black & 1 white
        listVertex.push_back(v);
    }

    int p=0;//index of the edges
    for(int i=0; i<nbNodes;i++){//to create the matrices
        for(int j=0; j<nbNodes;j++){
            int index =rand() % 2;//generate an random number between 0,1
            int weight=rand() % 100+1;
            if(index == 1){//if an edge exist
                Edge *e = new Edge(p, listVertex[i],listVertex[j],weight);
                matrices[i][j]=weight;
                p++;
                listEdges.push_back(e);
            }
        }
    }

}
void Graph::randGeneMat_undirected(){
    srand (time(NULL)+1);

    for(int x=0; x<nbNodes;x++){
            for(int y=0; y<nbNodes;y++){
                matrices[x][y]=0;
            }
    }//initialization of matrices

    for(int i=0; i<nbNodes;i++){//initialize all the nodes/Vertexes and give them a color
        Vertex *v = new Vertex(i);// to initialize
        v->color = 0; //O black & 1 white
        listVertex.push_back(v);
    }
    int p=0;//index of the edges
    for(int i=0; i<nbNodes;i++){//to create the matrices
        for(int j=0; j<i;j++){
            int index =rand() % 2;//generate an random number between 0,1
            int weight=rand() % 100+1;
            if(index == 1){//if an edge exist
                Edge *e = new Edge(p, listVertex[i],listVertex[j],weight);
                matrices[i][j]=weight;
                matrices[j][i]=weight;
                p++;
                listEdges.push_back(e);
            }
        }
    }
}
void Graph::randGeneAdjLt_directed(){
    srand (time(NULL)+1);
    for(int i=0; i<nbNodes;i++){//initialize all the nodes/Vertexes and give them a color
        Vertex *v = new Vertex(i);// to initialize
        v->color = 0; //O black & 1 white
        listVertex.push_back(v);
    }

    int p=0;//index of the edges
    for(int i=0; i<nbNodes;i++){//to create the matrices
        for(int j=0; j<nbNodes;j++){
            if (i==j) continue;
            int index =rand() % 2;//generate an random number between 0,1
            int weight=rand() % 100+1;
            if(index == 1){//if an edge exist
                Edge *e = new Edge(p, listVertex[i],listVertex[j],weight);
                p++;
                listEdges.push_back(e);
                listVertex[i]->nextEdgeNode.push_back(make_pair(j,e->id));
            }
        }
    }
}
void Graph::randGeneAdjLt_undirected(){

}
Graph::Graph(int _nbNodes)//construction of a directed graph with a randomly generated matrices
{

    this->nbNodes = _nbNodes;

    matrices=new int*[nbNodes];
    for(int i=0;i<nbNodes;i++){
        matrices[i]=new int[nbNodes];
    }//allocate memory for matrices


    randGeneAdjLt_directed();
    ///(nbNodes);
}
//Graph::Graph(int vertex,bool typeOfGraph, bool typeOfRepre,){
//
//    if(typeOfGraph){//directed
//        if(typeOfRepre){//matrices
//
//        }
//        else{//list
//
//        }
//    }
//    else{//undirected
//        if(typeOfRepre){//matrices
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
    for(unsigned int i=0;i<listVertex.size();i++)
        delete[] matrices[i];
    delete[] matrices;
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
    if(typeOfRepresentation){//type of representation : matrices
        cout<<"m"<<endl;
        myFeed<<"m"<<endl;
        ///displaymatrices();
    }else{//type of representation : list
        cout<<"l"<<endl;
        myFeed<<"l"<<endl;
        displayList();
    }
}

//void Graph::displaymatrices(){
//   /// int matrices[listVertex.size()][listVertex.size()];
//    ofstream myFeed("Files/Result.txt", ios::app);
//
//    //calculation of the matrices
//
//
//    if(myFeed){
//        //display
//        for(int x=0; x<listVertex.size();x++){
//                for(int y=0; y<listVertex.size();y++){
//                    myFeed<<matrices[x][y]<<";";
//                    cout<<matrices[x][y]<<";";
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
    if(myFeed){
        //display
        for (int i = 0; i < nbNodes;i++){
                int sze = listVertex[i]->nextEdgeNode.size();
            for( int k=0; k<listVertex[i]->nextEdgeNode.size(); k++){
                    Edge* e = findEdge(listVertex[i]->nextEdgeNode[k].second); /// deuxieme para de edge
                    if (e == NULL) continue;

                    cout<<i<<":"<<listVertex[i]->nextEdgeNode[k].first<<","<<e->cost<<"->";//display to console


                    cout<<endl;
            }
        }

        /*
        for (int i = 0; i < nbNodes;i++)
            cout<<"\t"<<i;
        cout<<endl;

        for (int i = 0; i < nbNodes;i++){
            cout<<i;
             for (int j = 0; j < nbNodes;j++)
                    cout<<"\t"<<matrices[i][j];//display to console
             cout<<endl;
        }*/
    }else{
    cout<<"ERROR .TXT"<<endl;
    }
}

void Graph::learnTxtFile(){

}

Edge* Graph::findEdge(int ID){

    for(auto iter=listEdges.begin(); iter!=listEdges.end();iter++){
        if ((*iter)->id == ID) return (*iter);
    }
    return NULL;
}

/* a faire :
globaliser la matrice à graph et faire une fct qui lit correctement le fichier .txt dans part1 2.bfile error*/
