#include "Graph.h"
#include <time.h>
#include <cstdlib>
#include <cstddef>
#include <fstream>
#include <string>
#include <regex>
#include <iostream>
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
                listVertex[j]->nextEdgeNode.push_back(make_pair(i,e->id));
            }
        }
    }
}

Graph::Graph(int _nbNodes,bool typeOfGraph,bool typeOfRepresentation)//construction of a directed graph with a randomly generated matrices
{
    this->nbNodes = _nbNodes;

    matrices=new int*[nbNodes];
    for(int i=0;i<nbNodes;i++){
        matrices[i]=new int[nbNodes];
    }//allocate memory for matrices

    display(typeOfGraph,typeOfRepresentation);//just display parameters

    if(typeOfGraph && typeOfRepresentation){//directed & matrix
        randGeneMat_directed();
        displayMatrix();
    }else if(!typeOfGraph && typeOfRepresentation){//undirected & matrix
        randGeneMat_undirected();
        displayMatrix();
    }else if(typeOfGraph && !typeOfRepresentation){//directed & list
        randGeneAdjLt_directed();
        displayList();
    }else if(!typeOfGraph && !typeOfRepresentation){//undirected & list
        randGeneAdjLt_undirected();
        displayList();
    }
}
Graph::Graph(){//constructor with an input file
    ifstream myFeed("Files/Result.txt");
    bool typeOfGraph,typeOfRepresentation;
    if(myFeed){
        string s_nbNode,s_typeOfGraph,s_typeOfRepresentation;

        regex pattern_nbNode {"^[0-9]{1,2}"};
        regex pattern_typeOfGraph {"^[o,n]"};
        regex pattern_typeOfRepresentation {"^[m,l]"};

        getline(myFeed,s_nbNode);
        getline(myFeed,s_typeOfGraph);
        getline(myFeed,s_typeOfRepresentation);

        if(regex_match(s_nbNode,pattern_nbNode)){nbNodes = stoi(s_nbNode,nullptr,10);}
        else{cout<<"ERROR WRONG NBNODES INPUT";}

        if(regex_match(s_typeOfGraph,pattern_typeOfGraph)){
            if(s_typeOfGraph=="o"){typeOfGraph=true;}
            else{typeOfGraph=false;}
        }
        else{cout<<"ERROR WRONG TYPE OF GRAPH INPUT";}

        if(regex_match(s_typeOfRepresentation,pattern_typeOfRepresentation)){
            if(s_typeOfRepresentation=="m"){typeOfRepresentation=true;}
            else{typeOfRepresentation=false;}
        }
        else{cout<<"ERROR WRONG TYPE OF REPRESENTATION INPUT";}

        cout<<"NBNODES "<<nbNodes<<endl<<"TYPEOFGRAPH "<<typeOfGraph<<endl<<"TYPEOFREPRESENTATION "<<typeOfRepresentation;
    }else {printf("Erreur lecture");}
}

Graph::~Graph()
{
    for(unsigned int i=0;i<listVertex.size();i++)
        delete[] matrices[i];
    delete[] matrices;
}

void Graph::display(bool typeOfGraph,bool typeOfRepresentation){
    ofstream myFeed("Files/Result.txt");//supprime l'ancien fichier ou en créé un nouveau
    //display the number of vertexes
    cout<<nbNodes<<endl;
    myFeed<<nbNodes<<endl;
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
    }else{//type of representation : list
        cout<<"l"<<endl;
        myFeed<<"l"<<endl;
    }
}

void Graph::displayMatrix(){
   /// int matrices[listVertex.size()][listVertex.size()];
    ofstream myFeed("Files/Result.txt", ios::app);

    if(myFeed){

        for (int y = 0; y < nbNodes;y++)
            cout<<"\t"<<y;
        cout<<endl;

        for (int x = 0; x < nbNodes;x++){
            cout<<x;
             for (int y = 0; y < nbNodes;y++){
                    cout<<"\t"<<matrices[x][y];//display to console
                    myFeed<<"\t"<<matrices[x][y];
             }
            cout<<endl;
            myFeed<<endl;
        }
    }else{
    cout<<"ERROR .TXT"<<endl;
    }
}

void Graph::displayList(){
    ofstream myFeed("Files/Result.txt", ios::app);
    if(myFeed){
        //display
        for (int i = 0; i < nbNodes;i++){
                int sze = listVertex[i]->nextEdgeNode.size();
            for( int k=0; k<listVertex[i]->nextEdgeNode.size(); k++){
                    Edge* e = findEdge(listVertex[i]->nextEdgeNode[k].second); /// deuxieme para de edge
                    if (e == NULL) continue;

                    cout<<i<<"->"<<listVertex[i]->nextEdgeNode[k].first<<","<<e->cost;//display to console
                    myFeed<<i<<"->"<<listVertex[i]->nextEdgeNode[k].first<<","<<e->cost;

                    cout<<endl;
                    myFeed<<endl;
            }
        }
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
