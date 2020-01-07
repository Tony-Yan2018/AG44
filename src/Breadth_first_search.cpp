#include "Breadth_first_search.h"
#include "Vertex.h"
#include <Vector>

Breadth_first_search::Breadth_first_search(Graph* g) {
    int firstVertex = 1,u=0;
    vector<int> Queue(1,0);

    cout << endl << "BFS" << endl << endl;
    for (int i = 0; i < g->listVertex.size(); i++) {//init
        g->listVertex[i]->color = 1; //1 white 0 black 2 gray
        g->listVertex[i]->dist = 1;
        g->listVertex[i]->pred = 0;
    }
    g->listVertex[firstVertex]->color = 2;
    g->listVertex[firstVertex]->dist = 0;
    g->listVertex[firstVertex]->pred = 0;
    cout << "ON PART DE " << firstVertex << endl;
    while (Queue.size() != 0)Queue.pop_back();
    Queue.push_back(firstVertex);
    while (Queue.size() != 0) {
        u = Queue[0];
        Queue.erase(Queue.begin());
        for (int v = 0; v < g->nbNodes; v++) {
            if (g->matrices[v][u] != 0 && g->listVertex[v]->color==1) {
                g->listVertex[v]->color = 2;
                g->listVertex[v]->dist = g->listVertex[u]->dist + 1;
                g->listVertex[v]->pred = u;
                Queue.push_back(v);
            }
        }
        g->listVertex[u]->color = 0;
        cout<<u<<" is finished at "<<g->listVertex[u]->dist<<endl<<endl;
    }

}

Breadth_first_search::~Breadth_first_search()
{
    //dtor
}
