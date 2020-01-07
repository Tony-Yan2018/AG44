#include "Strongly_related.h"
#include "Vertex.h"
#include <vector>

int time,flagDeuxiemeDFS=0;
vector <int> Result(1);
void dfsVisit(Graph* g, int u);
void depth_first_search(Graph* g);

void dfsVisit(Graph* g, int u){
    time++;
    g->listVertex[u]->date=time;
    g->listVertex[u]->color=2;
    for(int y=0;y<g->nbNodes;y++){
        if(flagDeuxiemeDFS==0){
            if(g->matrices[y][u]!=0){//voir pr utiliser edge instead
                if(g->listVertex[y]->color==1){
                    g->listVertex[y]->pred=u;
                    dfsVisit(g,y);
                }
            }
        }else{
            if(g->matrices[u][y]!=0){//voir pr utiliser edge instead
                if(g->listVertex[y]->color==1){
                    g->listVertex[y]->pred=u;
                    dfsVisit(g,y);
                }
            }
        }
    }
    g->listVertex[u]->color=0;
    time++;
    if(flagDeuxiemeDFS==0)Result.push_back(u);
    else Result.pop_back();
    cout<<u<<" is finished at "<<time<<endl<<endl;


}

void depth_first_search(Graph* g,int start){
    if(flagDeuxiemeDFS==1)Result.pop_back();
    int firstVertex=start;
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
                cout<<"on trouve un autre depart\n";
                if(flagDeuxiemeDFS==0)dfsVisit(g,i);
                else{
                        printf("\n\nNOUVEAU GRP depart : %d\n",Result[Result.size()]);
                        dfsVisit(g,Result[Result.size()]);
                }
        }
    }
}


Strongly_related::Strongly_related(Graph* g)
{
    while(Result.size()!=0)Result.pop_back();
    ///DFS
    printf("FIRST DFS\nPREMIER GROUPE");
    depth_first_search(g,2);
    ///Compute
    flagDeuxiemeDFS=1;

    ///DFS on the opposite order
    printf("Second DFS RESULTAT \n");
    depth_first_search(g,Result[Result.size()-1]);
    ///output each time you need to find a new start
}

Strongly_related::~Strongly_related()
{
    //dtor
}
