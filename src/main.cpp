#include <iostream>
#include "Graph.h"
#include <fstream>
#include <cstdio>
#include <windows.h>
#include <cstddef>
using namespace std;

int main()
{
    bool typeOfGraph=true,typeOfRepresentation=false;//true = directed false = undirected | true=matrix false = list
    //Graph g;
    Graph *g = new Graph(5);
    g->display(typeOfGraph,typeOfRepresentation);
    return 0;
//    if(MessageBox(NULL,"Do you want t"))
//    ifstream read_file;
//    read_file.open("Files/InputFile.txt",ios::in);
//    ///Graph *g2 = new Graph(&read_file);
//
//    string line,lines[3];
//    //char ch[3];
//    int i=0,Nb_Vertices=0;
//    while(getline(*of,line)){
//        lines[i]=line;
//        if(i++>=3){
//            printf("error:lines exceeded");
//            return;
//        }
//    }
//    if(Nb_Vertices=stoi(lines[0],NULL,0)<=0){
//        printf("error:invalid vertex number");
//        return;
//        }
//    if(lines[1]!="o"&&lines[1]!="n"){
//        printf("error:invalid graph type");
//        return;
//        }
//    if(lines[2]!="m"&&lines[2]!="l"){
//        printf("error:invalid graph representation");
//        return;
//        }
//    if(lines[1]=="o"){//directed
//        typeOfGraph=true;
//        if(lines[2]=="l"){
//                typeOfRepresentation=false;//list
//           ///g=new Graph(Nb_Vertices,typeOfGraph,typeOfRepresentation);
//        }
//        else{
//            typeOfRepresentation=true;//matrix
//            ///g=new Graph(Nb_Vertices,typeOfGraph,typeOfRepresentation);
//        }
//    }
//    else{//undirected
//            typeOfGraph=false;
//        if(lines[2]=="m"){
//                 typeOfRepresentation=true;//matrix
//          /// g=new Graph(Nb_Vertices,typeOfGraph,typeOfRepresentation);
//        }
//        else{
//            typeOfRepresentation=false;//list
//           /// g=new Graph(Nb_Vertices,typeOfGraph,typeOfRepresentation);
//        }
//    }
//    g=new Graph(Nb_Vertices,typeOfGraph,typeOfRepresentation);
//
//    return 0;
}
