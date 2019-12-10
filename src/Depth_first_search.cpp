#include "Depth_first_search.h"
#include "Vertex.h"

Depth_first_search::Depth_first_search(Graph* g){

    int firstVertex=1;
    cout<<"DFS"<<endl<<endl;
    for(int i=0;i<g->listVertex.size();i++){//init
        g->listVertex[i]->color=1;
        g->listVertex[i]->pred=0;
        time=0;
    }
    cout<<"ON PART DE "<<firstVertex<<endl;
    if(g->listVertex[firstVertex]->color==1){dfsVisit(g,firstVertex);}

    for(int i=0;i<g->listVertex.size();i++){
        if(g->listVertex[i]->color==1){
                cout<<"on trouve un autre départ";
                dfsVisit(g,i);}
    }
}

void Depth_first_search::dfsVisit(Graph* g, int u){
    time++;
    g->listVertex[u]->date=time;
    g->listVertex[u]->color=2;
    for(int y=0;y<g->nbNodes;y++){
        if(g->matrices[y][u]!=0){//voir pr utiliser edge instead
            if(g->listVertex[y]->color==1){
                g->listVertex[y]->pred=u;
                dfsVisit(g,y);
            }
        }
    }
    g->listVertex[u]->color=0;
    time++;
    cout<<u<<" is finished at "<<time<<endl<<endl;


}

Depth_first_search::~Depth_first_search(){

}
