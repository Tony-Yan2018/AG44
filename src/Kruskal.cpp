#include "Kruskal.h"
#include "Vertex.h"
#include "Edge.h"
#include <Vector>

//
//vector<int> QueueAnt(1);
//
//int dfsVisit(Graph* g, int u,int source){
//    g->listVertex[u]->color=2;
//    for(int y=0;y<g->nbNodes;y++){
//        if(g->matrices[y][u]!=0){//voir pr utiliser edge instead
//            for(int i=0 ;i<QueueAnt.size();i++)if(y==QueueAnt[i]){//tester s'il fait prtie d'un ant?
//                        printf("here");
//                        return 1;
//            }
//            if(g->listVertex[y]->colorBis==0){//s'il fait parti du nouveau graph
//               // printf("la %d %d",source,y);
//
//                if(g->listVertex[y]->pred==1){
//                    QueueAnt.push_back(u);
//                    g->listVertex[y]->pred=u;
//                    dfsVisit(g,y,source);
//                }
//            }
//        }
//    }
//    g->listVertex[u]->color=0;
//    //cout<<u<<" is finished at "<<endl<<endl;
//    return 0;
//
//}
//
//
//int detectCycle(Graph* g, int source){
//        int firstVertex=1,result;
//        //cout<<"DFS"<<endl<<endl;
//        for(int i=0;i<g->listVertex.size();i++){//init
//            g->listVertex[i]->color=1;
//            g->listVertex[i]->pred=0;
//        }
//        while (QueueAnt.size()!=0)QueueAnt.pop_back();
//        QueueAnt.push_back(firstVertex);
//        //cout<<"ON PART DE "<<firstVertex<<endl;
//        if(g->listVertex[firstVertex]->color==1){result = dfsVisit(g,firstVertex,source);}
///*
//        for(int i=0;i<g->listVertex.size();i++){
//            if(g->listVertex[i]->color==1){
//                    //cout<<"on trouve un autre départ";
//                    result = dfsVisit(g,i,source);}
//        }*/
//        return result;
//}
//
//
//Kruskal::Kruskal(Graph* g){
//    printf("\n\nKRUSKAL\n\n");
//    vector<Edge*> Queue(1),QueueResult(1);
//    int min = 0;
//    while (Queue.size() != 0)Queue.pop_back();
//    while (QueueResult.size() != 0)QueueResult.pop_back();
//    for(int i=0;i<g->listEdges.size();i++){
//        Queue.push_back(g->listEdges[i]);
//        printf("Edge nb : %d weight : %d src : %d dest : %d \n",Queue[i]->id,Queue[i]->cost,Queue[i]->source->id,Queue[i]->destination->id);
//    }
//
//    while(Queue.size() != 0){
//        min = Queue[0]->cost;
//        for(int i=0; i<Queue.size() ;i++){
//            if(Queue[i]->cost<min)min=Queue[i]->cost;
//        }
//
//        for(int i=0; i<Queue.size() ;i++){
//            if(Queue[i]->cost==min){
//                    Queue[i]->source->colorBis=0;
//                    Queue[i]->destination->colorBis=0;
//                    if(detectCycle(g,i)!=1){//il faut detecter une boucle
//                        printf("res Edge nb : %d weight : %d src : %d dest : %d \n",Queue[i]->id,Queue[i]->cost,Queue[i]->source->id,Queue[i]->destination->id);
//                        QueueResult.push_back(Queue[i]);
//                    }else{
//                        Queue[i]->source->colorBis=-1;
//                        Queue[i]->destination->colorBis=-1;
//                    }
//                    Queue.erase(Queue.begin()+i);
//                    //break;
//            }
//        }
//    }
//
//}
//
//Kruskal::~Kruskal()
//{
//    //dtor
//}









//#include <bits/stdc++.h>
using namespace std;

#define V 5
int parent[V];

// Find set of vertex i
int find(int i)
{
	while (parent[i] != i)
		i = parent[i];
	return i;
}

// Does union of i and j. It returns
// false if i and j are already in same
// set.
void union1(int i, int j)
{
	int a = find(i);
	int b = find(j);
	parent[a] = b;
}

// Finds MST using Kruskal's algorithm
void kruskalMST(int cost[][V])
{
	int mincost = 0; // Cost of min MST.

	// Initialize sets of disjoint sets.
	for (int i = 0; i < V; i++)
		parent[i] = i;

	// Include minimum weight edges one by one
	int edge_count = 0;
	while (edge_count < V - 1) {
		int min = INT_MAX, a = -1, b = -1;
		for (int i = 0; i < V; i++) {
			for (int j = 0; j < V; j++) {
				if (find(i) != find(j) && cost[i][j] < min) {
					min = cost[i][j];
					a = i;
					b = j;
				}
			}
		}

		union1(a, b);
		printf("Edge %d:(%d, %d) cost:%d \n",
			edge_count++, a, b, min);
		mincost += min;
	}
	printf("\n Minimum cost= %d \n", mincost);
}

// driver program to test above function

Kruskal::Kruskal(Graph* g){
	int cost[][V] = {
		{ INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX },
		{ INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX},
		{ INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX},
		{ INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX},
		{ INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX},
	};
    for(int x=0;x<g->nbNodes;x++){
        for(int y=0; y<g->nbNodes;y++){
            if(g->matrices[x][y]==0)cost[x][y]=INT_MAX;
            else cost[x][y]=g->matrices[x][y];
        }
    }

	// Print the solution
	kruskalMST(cost);

}

Kruskal::~Kruskal()
{
    //dtor
}



