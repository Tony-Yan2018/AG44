#include <Graph.h>
#include <Heap.h>
#include <Disjoint_Set_Union.h>
#include <time.h>
#include <cstdlib>
#include <cstddef>
#include <fstream>
#include <string>
#include <regex>
#include <iostream>
#include <sstream>
#include <queue>
#include <stack>
#define INFINITE 0x3f//for Dijkstra (1061109567 in int for 4 bytes)
using namespace std;
void Graph::InputListGene(bool TOG,int nbNodes,ifstream& f){
    string* line = new string[nbNodes];
    int count =0;
    while(!f.eof()){
        if(count >=nbNodes) break;//the eof character is the one after the last character
        getline(f,line[count],';');
        count++;
    }
    for(int i=0;i<count;i++){
        Vertex *v = new Vertex(i);// to initialize
        v->color = 0; //O black & 1 white
        listVertex.push_back(v);
    }
    int p=0;
    regex pattern_node("\\d+,\\d+");
    for(int i=0;i<count;i++){
            int dest,weight;
        for(sregex_iterator it(line[i].begin(),line[i].end(),pattern_node),end;it!=end;it++){
            char *cstr = new char[it->str().size()+1];
            char delim=',';//splitter of the numbers
            strcpy(cstr,it->str().c_str());//convert string to char
            dest = atoi(strtok(cstr,&delim));//cut the first number of the pair
            weight = atoi(strtok(NULL,&delim));//cut the next one
            Edge *e = new Edge(p, listVertex[i],listVertex[dest-1],weight);//pay attention to the subscript of vector
			int id=p;
			if(!TOG){//undirected
				for (auto iter = listEdges.begin(); iter != listEdges.end(); iter++) {//to detect if the new edge is redundant
					if ((*iter)->destination == e->source && (*iter)->source == e->destination) { //redundance detected
						id = (*iter)->getID();//the id of an edge should be unique
						p--;
						delete e;
						e = NULL;
						break;
					}
					else
						id = p;
				}
			}
			if (e) {//if the new edge is not redundant 
				listEdges.push_back(e);
			}
            listVertex[i]->nextEdgeNode.push_back(make_pair(dest,id));
			p++;
            delete[] cstr;
        }
    }
    display(TOG,false);
    displayList();
    delete[] line;
}
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
Graph::Graph(int _nbNodes,bool tOG,bool tOR)//construction of a directed graph with a randomly generated matrices
{
    this->nbNodes = _nbNodes;
	typeOfGraph = tOG;
	typeOfRepresentation = tOR;
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
    ifstream myFeed("Files/Input_Kruskal_Prim.txt");
   // bool typeOfGraph,typeOfRepresentation;
    if(myFeed){
        string s_nbNode,s_typeOfGraph,s_typeOfRepresentation;

        regex pattern_nbNode {"\\d{1,2}"};
        regex pattern_typeOfGraph {"^[o,n]"};
        regex pattern_typeOfRepresentation {"^[m,l]"};

        getline(myFeed,s_nbNode);
        getline(myFeed,s_typeOfGraph);
        getline(myFeed,s_typeOfRepresentation);

        if(regex_match(s_nbNode,pattern_nbNode)){
                nbNodes = stoi(s_nbNode,nullptr,10);
        }
        else{cout<<"ERROR WRONG NBNODES INPUT"<<endl;}
		cout << nbNodes << endl;
        if(regex_match(s_typeOfGraph,pattern_typeOfGraph)){
            if(s_typeOfGraph=="o"){typeOfGraph=true;}
            else{typeOfGraph=false;}
        }
		else { cout << "ERROR WRONG TYPE OF GRAPH INPUT" << endl;; }

        if(regex_match(s_typeOfRepresentation,pattern_typeOfRepresentation)){
            if(s_typeOfRepresentation=="m"){typeOfRepresentation=true;}
            else{typeOfRepresentation=false;}
        }
        else{cout<<"ERROR WRONG TYPE OF REPRESENTATION INPUT"<<endl;}
    }
	else {
		printf("Erreur lecture");
	}
	if (typeOfRepresentation) {//matrix
		matrices = new int* [nbNodes];
		for (int i = 0; i < nbNodes; i++) {//to initialise the matrice
			matrices[i] = new int[nbNodes];
		}

		for (int i = 0; i < nbNodes; i++) {//initialize all the nodes/Vertexes and give them a color
			Vertex* v = new Vertex(i);// to initialize
			v->color = -1; //O black & 1 white
			listVertex.push_back(v);
		}
		learnMatrixTxtFile();

		int p = 0;//index of the edges
		for (int i = 0; i < nbNodes; i++) {//to create the matrices
			for (int j = 0; j < nbNodes; j++) {
				if (matrices[i][j] > 0) {//if an edge exist
					int weight = matrices[i][j];
					Edge* e = new Edge(p, listVertex[i], listVertex[j], weight);
					p++;
					listEdges.push_back(e);
				}
			}
		}
		cout << "BILAN" << endl;
		displayMatrix();
	}
	else {//list
		InputListGene(typeOfGraph, nbNodes, myFeed);
	}

	
}

Graph::~Graph(){
    for(unsigned int i=0;i<listVertex.size();i++)
        delete[] matrices[i];
    delete[] matrices;
    for(auto iter = listVertex.begin();iter!=listVertex.end();iter++)
        if(*iter!=NULL)
            delete *iter;
    for(auto iter = listEdges.begin();iter!=listEdges.end();iter++)
        if(*iter!=NULL)
            delete *iter;
    listVertex.~vector<Vertex*>();
    listEdges.~vector<Edge*>();
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

void Graph::displayMatrix() {
	/// int matrices[listVertex.size()][listVertex.size()];
	ofstream myFeed("Files/Result.txt", ios::app);

	if (myFeed) {

		for (int y = 0; y < nbNodes; y++)
			cout << "\t" << y;
		cout << endl;

		for (int y = 0; y < nbNodes; y++) {
			cout << y;
			for (int x = 0; x < nbNodes; x++) {
				cout << "\t" << matrices[x][y];//display to console
				myFeed << "\t" << matrices[x][y];
			}
			cout << endl;
			myFeed << endl;
		}
	}
	else {
		cout << "ERROR .TXT" << endl;
	}
}

void Graph::displayList(){
    ofstream myFeed("Files/Result.txt", ios::app);
    if(myFeed){
        //display
        for (int i = 0; i < nbNodes;i++){ //run through vertices
            int sze = listVertex[i]->nextEdgeNode.size();//number of EdgeNodes owned by i th vertex
			cout << i +1<< "->";
			myFeed << i +1<< "->";
            for( int k=0; k<sze; k++){ // run through every node of the i th vertex
				int p = k+1;// to indicate if reached the last node
                    Edge* e = findEdge(listVertex[i]->nextEdgeNode[k].second); //to find an edge through ID
                    if (e == NULL) continue;
                    cout<<listVertex[i]->nextEdgeNode[k].first<<","<<e->cost;//display to console
					if (p == sze)
						cout << ";"<<endl;
					else
						cout << "->";
                    myFeed<<listVertex[i]->nextEdgeNode[k].first<<","<<e->cost;//write to file
					if (p == sze)
						myFeed << ";" << endl;
					else
						myFeed << "->";
            }
            if(sze==0) {
                cout<<";"<<endl;
				myFeed << ";" << endl;
                continue;
            }
        }
    }else{
    cout<<"ERROR .TXT"<<endl;
    }
}

void Graph::displayGraph() {

	cout << "Liste des vertex" << endl;
	for (int i = 0; i < listVertex.size(); i++) {
		cout << listVertex[i]->id << "  ";
	}
	cout << endl;

	cout << "Liste des edges" << endl;
	for (int i = 0; i < listEdges.size(); i++) {
		cout << "@ : " << listEdges[i] << " Id : " << listEdges[i]->id << " Source : " << listEdges[i]->source->id << " Destination : " << listEdges[i]->destination->id << " Cout : " << listEdges[i]->cost << endl;

	}
}
void Graph::learnMatrixTxtFile() {
	ifstream myFeed("Files/Input.txt");
	string s_value;
	int i_value, x = 0, y = 0;
	regex pattern_value{ "^[0-9]{1,3}" };
	regex pattern_linereturn{ "^[0-9]{1,3}\n.*" };
	regex pattern_startlinereturn{ "\n[0-9]{1,3}" };

	while (getline(myFeed, s_value, '\t')) {
		if (regex_match(s_value, pattern_value)) {///we use regular expression to locate the value we want
			i_value = stoi(s_value, nullptr, 10);
			matrices[x][y] = i_value;
			x++;
		}
		else if (regex_match(s_value, pattern_linereturn) || regex_match(s_value, pattern_startlinereturn)) {///if it's the last value we delete the \n from the string and convert it in int and add in the matrice
			for (unsigned int i = 0; i < s_value.size(); ++i) {  //On parcourt la chaine
				if (s_value[i] == ('47') || s_value[i] == ('n') || s_value[i] == ('t') || s_value[i] == ('r'))// 47 is \ in ascii
				{
					s_value.erase(i, 1);
				}
			}
			i_value = stoi(s_value, nullptr, 10);
			matrices[x][y] = i_value;
			y++;
			x = 0;
		}
		if ((x || y) >= nbNodes)cout << "ERROR THE MATRICE IS BIGGER THAN INDICATED IN TE PARA";
	}
	cout << "matrice recuperee" << endl;
	for (y = 0; y < nbNodes; y++) {
		for (x = 0; x < nbNodes; x++) cout << matrices[x][y] << " ";
		cout << endl;
	}
	myFeed.close();
}

Edge* Graph::findEdge(int ID){
    for(auto iter=listEdges.begin(); iter!=listEdges.end();iter++){
        if ((*iter)->id == ID) return (*iter);
    }
    return NULL;
}
void Graph::o_list2matrix() {//directed graph
	//for (unsigned int i = 0; i < listVertex.size(); i++)
	//	if(matrices[i]!=NULL)
	//	delete[] matrices[i];
	//delete[] matrices;//delete will do nothing if nullptr
	int sze = listVertex.size();
	if (sze > 0) {
		matrices = new int* [sze];
		for (int i = 0; i < sze; i++) {
			matrices[i] = new int[sze];
		}//allocate memory for matrices
		for (int i = 0; i < sze; i++) {
			for (int j = 0; j < sze; j++) {
					matrices[i][j] = 0;
			}
		}
		for (auto it = listEdges.begin(); it != listEdges.end(); it++) {
			if ((*it) != NULL) {
				matrices[(*it)->source->id][(*it)->destination->id] = (*it)->cost;
			}
		}
	}
}
void Graph::n_list2matrix() {
	int sze = listVertex.size();
	if (sze > 0) {
		matrices = new int* [sze];
		for (int i = 0; i < sze; i++) {
			matrices[i] = new int[sze];
		}//allocate memory for matrices
		for (int i = 0; i < sze; i++) {
			for (int j = 0; j < sze; j++) {
				matrices[i][j] = 0;
			}
		}
		for (auto it = listEdges.begin(); it != listEdges.end(); it++) {
			if ((*it) != NULL) {
				matrices[(*it)->source->id][(*it)->destination->id] = (*it)->cost;
				matrices[(*it)->destination->id][(*it)->source->id] = (*it)->cost;
			}
		}
	}

}
void Graph::BFSListO(int startFrom) {
	/*the principle is to firstly choose a random vertex, if it has 0 out degree, then choose the first
		unvisited vertex in the list; moreover,if one way is exhausted to continue,also push the first univisited vertex
		in the list to the queue*/
	cout << "BFS of oriented Adjacey List:" << endl;
	srand((unsigned int)time(NULL));
	int sze = listVertex.size();
	int rdm = rand() % sze ;//[0,sze)
	while (listVertex[rdm]->nextEdgeNode.empty()) {
		rdm = rand() % sze;//randomly choose a vertex whose out degree is not 0
	}
	queue<Vertex*> myQueue;
	if(startFrom==-1)//default treatment is random choose
	myQueue.push(listVertex[rdm]);
	else {//designated choose
		myQueue.push(listVertex[startFrom-1]);
	}
	int countVisitedAll = 0;
	while (!myQueue.empty()) {// travel through until there is nothing in the queue
		Vertex* V = myQueue.front();
		if (V->color == 0) {
			V->color = 1; //O black(unvisited) & 1 white(visited)//V visited white 1
			cout << "Vertex visited:" << V->id +1<< endl;
			countVisitedAll++;
		}
		if (!V->nextEdgeNode.empty()) {//if the out degree is not zero
			for (auto it = V->nextEdgeNode.begin(); it != V->nextEdgeNode.end(); it++) {//travel through all outgoing vertices
				if(listVertex[(*it).first - 1]->color==0)
				myQueue.push(listVertex[(*it).first-1]);//push into queue for next round travel
			}
		}
		myQueue.pop();
		if (countVisitedAll != listVertex.size()) {
			for (auto it = listVertex.begin(); it != listVertex.end(); it++) {
				if ((*it)->color == 0)
					myQueue.push(*it);
				break;
			}
		}
	}
}
void Graph::BFSListN(int startFrom) {
	/*the principle is to firstly choose a random vertex, if it has 0 out degree, then choose the first
		unvisited vertex in the list; moreover,if one way is exhausted to continue,also push the first univisited vertex
		in the list to the queue*/
	cout << "BFS of non-oriented Adjacey List:" << endl;
	srand((unsigned int)time(NULL));
	int sze = listVertex.size();
	int rdm = rand() % sze;//[0,sze)
	while (listVertex[rdm]->nextEdgeNode.empty()) {
		rdm = rand() % sze;//randomly choose a vertex whose out degree is not 0
	}
	queue<Vertex*> myQueue;
	if (startFrom == -1) {//default treatment is random choose
		myQueue.push(listVertex[rdm]);
		listVertex[rdm]->color = 2;
	}
	else {//designated choose
		myQueue.push(listVertex[startFrom - 1]);
		listVertex[startFrom - 1]->color = 2;
	}
	while (!myQueue.empty()) {// travel through until there is nothing in the queue
		Vertex* V = myQueue.front();
		V->color = 1; //O black(unvisited) & 1 white(visited) & 2 gray(now in queue)//V visited white 1
		cout << "Vertex visited:" << V->id + 1 << endl;
			for (auto it = V->nextEdgeNode.begin(); it != V->nextEdgeNode.end(); it++) {//travel through all outgoing vertices
				if (listVertex[(*it).first - 1]->color !=1&& listVertex[(*it).first - 1]->color !=2){
					myQueue.push(listVertex[(*it).first - 1]);//push into queue for next round travel
					listVertex[(*it).first - 1]->color = 2;
				}
			}
		myQueue.pop();
	}
}
void Graph::DFSListO(int startFrom) {
	cout << "Non recursive DFS of oriented Adjacey List:" << endl;
	srand((unsigned int)time(NULL));
	int sze = listVertex.size();
	int rdm = rand() % sze;//[0,sze)
	while (listVertex[rdm]->nextEdgeNode.empty()) {
		rdm = rand() % sze;//randomly choose a vertex whose out degree is not 0
	}
	stack<Vertex*> myStack;
	Vertex* tempV;
	int countVisitedAll = 0;//to control overall number of visited vertices
	if (startFrom == -1) {
		tempV = listVertex[rdm];//randomly chosed
	}
	else
	{
		tempV = listVertex[startFrom - 1];//designated
	}
	tempV->color = 1;//O black(unvisited) & 1 white(visited)
	cout << "Vertex visited:" << tempV->id + 1 << endl;
	myStack.push(tempV);
	countVisitedAll++;
	while (!myStack.empty()) {
		tempV = myStack.top();
			int countVisited = 0;//to control number of visited vertices of one certain vertex
			for (auto it = tempV->nextEdgeNode.begin(); it != tempV->nextEdgeNode.end(); it++) {
				if (listVertex[(*it).first-1]->color==0) {//if an unvisited vertex has been found
					listVertex[(*it).first - 1]->color = 1;//O black(unvisited) & 1 white(visited)
					cout << "Vertex visited:" << listVertex[(*it).first - 1]->id + 1 << endl;
					myStack.push(listVertex[(*it).first - 1]);//visit it and push into stack
					countVisitedAll++;
					break;
				}
				else//if a visited vertex found
				{
					countVisited++;//then increment the count
				}
			}
			if (countVisited == tempV->nextEdgeNode.size()) {
				myStack.pop();
			}//all adjacent vertices of the current vertex have been visited, then pop the current one
			if (countVisitedAll != listVertex.size() && myStack.empty()) {
				for (auto it = listVertex.begin(); it != listVertex.end(); it++)
					if ((*it)->color == 0) {
						(*it)->color = 1;//O black(unvisited) & 1 white(visited)
						cout << "Vertex visited:" << (*it)->id+ 1 << endl;
						countVisitedAll++;
						myStack.push(*it);
						break;
					}
			}
		}
	}
void Graph::DFSListN(int startFrom) {
	cout << "Recursive DFS of non-oriented Adjacey List:" << endl;
	srand((unsigned int)time(NULL));
	int sze = listVertex.size();
	int rdm = rand() % sze;//[0,sze)
	while (listVertex[rdm]->nextEdgeNode.empty()) {
		rdm = rand() % sze;//randomly choose a vertex whose out degree is not 0
	}
	Vertex* tempV;
	if (startFrom == -1)
		tempV = listVertex[rdm];
	else
		tempV = listVertex[startFrom - 1];
	if (tempV->color == 0) {//not visited
		tempV->color = 1;//O black(unvisited) & 1 white(visited)
		cout << "Vertex visited:" << tempV->id+1 << endl;
		for (auto it = tempV->nextEdgeNode.begin(); it != tempV->nextEdgeNode.end(); it++) {
			if (listVertex[(*it).first - 1]->color == 0) {
				DFSListN((*it).first);
			}
		}
	}
}
bool Graph::TopoSortList(int nbNodes) {
	/*this algoritm runs without changing the original graph data*/
	cout << "Topological sort started:" << endl;
	stack<Vertex *> zeroDegree;
	int* InDegree= new int[nbNodes];// indegree array for all vertices
	int count = 0; //to verify if there is a cycle
	memset(InDegree, 0, sizeof(InDegree) *nbNodes);//sizeof(InDegree) = sizeof(int) =4 bytes
	for (auto it = listEdges.begin(); it != listEdges.end(); it++) {
		InDegree[(*it)->destination->id]++;
	}//initialization of the indegree array
	for (auto it = 0; it < nbNodes; it++) {
		if (InDegree[it] == 0) {
			zeroDegree.push(listVertex[it]);//initialization of zeroDegree stack
			InDegree[it] = -1;//delete it from the array
		}
	}
	while (!zeroDegree.empty()) {
		Vertex* temp = zeroDegree.top();
		cout << "Vertex:" << temp->id + 1 << endl;
		count++;
		for (auto it = listEdges.begin(); it != listEdges.end(); it++) {
			if ((*it)->source->id == temp->id) {
				InDegree[(*it)->source->id] = -1;//abandon current vertex because it's been output
				InDegree[(*it)->destination->id]--;//update indegree information on out degree vertex
			}
		}
		zeroDegree.pop();
		if (zeroDegree.empty()) {
			if (count == listVertex.size()) {// to ensure the last vertex is output only once
				delete[] InDegree;
				cout << "Topological sort finished! " << endl;
				return true;
			}
			for (auto it = 0; it < nbNodes; it++) {
				if (InDegree[it] == 0) {
					zeroDegree.push(listVertex[it]);
					InDegree[it] = -1;
				}
			}
		}
	}
	if (count < listVertex.size()) {// to detect cycle
		cout << "There is a cycle! Exiting...... " << endl;
		delete[] InDegree;
		return false;
	}
}
void Graph::DijkstraList(Vertex* v) {
	/*
		O black(not been calculated,Set U) & 1 white(calculated,Set S )
	*/
	cout <<endl<< "Dijkstra starts from Vertex " <<v->id+1<<": "<< endl;
	/*Initialization of distance[]*/
	int* distance = new int[listVertex.size()];
	memset(distance,INFINITE,sizeof(distance)*listVertex.size());//INFINITE means the vertex is not directly connected to vertex v
	v->color = 1;
	distance[v->id] = 0;
	for (auto it = v->nextEdgeNode.begin(); it != v->nextEdgeNode.end(); it++) {
		distance[it->first-1] = findEdge(it->second)->cost;
	}
	/*end of initialization*/
	while (1) {
		/*to test break condition*/
		int count = 0;
		for (auto it = listVertex.begin(); it != listVertex.end(); it++) {
			if ((*it)->color == 1)
				count++;
		}
		if (count == listVertex.size())
			break;
		/*to find the minimum non zero and not calculated vertex's value in distance[]*/
		int minVal = distance[0], minValNum = 0;
		while (minVal == 0|| listVertex[minValNum]->color == 1) {// not source itself, not calculated vertex
			minValNum++;
			minVal = distance[minValNum];
		}
		for (int i = minValNum + 1; i < listVertex.size(); i++) {
			if ((distance[i] != 0) && (distance[i] < minVal) && (listVertex[i]->color !=1))
			{
				minVal = distance[i];
				minValNum = i;
			}
			else
				continue;
		}
		/*end find*/
		Vertex* temp = listVertex[minValNum];
		for (auto it = temp->nextEdgeNode.begin(); it != temp->nextEdgeNode.end(); it++) {
			if (distance[it->first - 1] > findEdge(it->second)->cost + minVal)//RELAX operation
				distance[it->first - 1] = findEdge(it->second)->cost + minVal;
		}
		temp->color = 1;//1=white=calculated
		
	}
	for (auto it = 0; it < listVertex.size(); it++) {
		if(distance[it]== 1061109567) // (= 0x3f3f3f3f)
			cout << "Shortest path value to Vertex " << it + 1 << " is: UNREACHABLE" << endl;
		else
			cout << "Shortest path value to Vertex " << it + 1 << " is: " << distance[it] << endl;
	}
	
}
int MaxIndex(int* v, int size) {//auxiliary function for strongly connected components
	int max = v[0];
	int i = 0;
	for (auto it = 1; it < size; it++) {
		if (v[it] > max) {
			max = v[it];
			i = it;
		}

	}
	return i;
} 
void Graph::StronglyConnectedComp(int nbNodes,int startFrom) {
	cout << "Detecting strongly connected components: " << endl;
	/*choose a vertex randomly or designate with parameter*/
	srand((unsigned int)time(NULL));
	Vertex* tempV;
	if (startFrom == -1) {
		int sze = listVertex.size();
		int rdm = rand() % sze;//[0,sze)
		tempV = listVertex[rdm];
	}
	else
		tempV = listVertex[startFrom - 1];
	int count = 0;// to check if all vertices have been visited
	int* mark = new int[nbNodes];// to store the numbers marked on vertex
	stack<Vertex* > myStack;// to assist dfs algo
	myStack.push(tempV);//initialization
	/*DFS algo to mark the vertices from leaves*/
	while (!myStack.empty()) {
		//cout << "colored:" << myStack.top()->id << endl;
		myStack.top()->color = 1;// visit the vertex on top
		int visited = 0;// to check if all adjacent vertices have been visited
		for (auto it = myStack.top()->nextEdgeNode.begin(); it != myStack.top()->nextEdgeNode.end(); it++) {
			if (listVertex[it->first - 1]->color == 0)//O black(unvisited) & 1 white(visited))
			{
				myStack.push(listVertex[it->first - 1]);
				break;
			}
			else
				visited++;
		}
		/*if the vertex and all its adjacent vertices have been visited, 
		which means the end of DFS, then mark it and pop it out*/
		if (visited == myStack.top()->nextEdgeNode.size() && myStack.top()->color == 1) {
			//cout << "mark:" << myStack.top()->id<<endl;
			count++;
			mark[myStack.top()->id] = count;// mark the vertex
			myStack.pop();
		}
		/*check if all vertices in graph have been visited*/
		if (myStack.empty() && count < nbNodes) {
			for (auto it = listVertex.begin(); it != listVertex.end(); it++) {
				if ((*it)->color == 0) {//O black(unvisited) & 1 white(visited)
					myStack.push(*it);
					break;
				}	
			}
		}
	}
	/*end of DFS and the marking procedure*/
	/*restore the visit flag*/
	for (auto it = listVertex.begin(); it != listVertex.end(); it++) {
		(*it)->color = 0;//O black(unvisited) & 1 white(visited)
	}
	/*begin to reverse the edges with no change of original data*/
	vector<int>* tempAdjList = new vector<int>[nbNodes];//temporary assisting structure
	int max = MaxIndex(mark,nbNodes);
	for (auto it = listEdges.begin(); it != listEdges.end(); it++) {
		Vertex* temp;
		temp = (*it)->destination;
		(*it)->destination = (*it)->source;
		(*it)->source = temp;
		//store the just reversed data
		tempAdjList[(*it)->source->id].push_back((*it)->destination->id);
	}
	/*end of reserve procedure*/
	myStack.push(listVertex[max]);//initialization
	mark[max] = 0;
	int component = 0;//component counter
	int pushchecker = 1;
	while (!myStack.empty()) {
		if (myStack.top()->color == 0) {
			cout << "This is strongly connected component " << component+1 << "." << endl;
			myStack.top()->color = 1;//O black(unvisited) & 1 white(visited)
			mark[myStack.top()->id] = 0;//exclude visited vertex
			cout << "Vertex: " << myStack.top()->id + 1 << endl;
		}
		int popchecker = 0;
		for (auto it = tempAdjList[myStack.top()->id].begin(); it != tempAdjList[myStack.top()->id].end(); it++) {
			if (listVertex[*it]->color == 0) {//O black(unvisited) & 1 white(visited)
				myStack.push(listVertex[*it]);
				pushchecker++;
				break;
			}
			else
				popchecker++;
		}
		if (popchecker == tempAdjList[myStack.top()->id].size() && myStack.top()->color == 1)//O black(unvisited) & 1 white(visited)
		{// end of the road, pop 
			myStack.pop();
		}
		/*if the current component is all visited and not all vertices in graph are visited,
		then add the vertex with the biggest number marked into stack*/
		if (myStack.empty() && pushchecker < nbNodes) {
			myStack.push(listVertex[MaxIndex(mark,nbNodes)]);
			pushchecker++;
			component++;
		}
	}
	delete[] mark;
}
void Graph::KruskalList() {
	cout << "Kruskal Algorithm starting:" << endl;//no modification of any original data
	Heap minHeap = Heap(listEdges,listEdges.capacity(),listEdges.size());
	int* VertKrus = new int[listVertex.size()];
	for (auto i = 0; i < listVertex.size(); i++) {
		VertKrus[i] = (listVertex[i]->id);
	}
	Disjoint_Set_Union ds = Disjoint_Set_Union(VertKrus,listVertex.size());
	int count = 0;//number of edges in minimal spanning tree
	Edge temp;
	while (count != listVertex.size() - 1) {//the minimal spanning tree is built when they are equal
		temp = minHeap.GetTop();
		if (ds.Differ(temp.destination->id, temp.source->id)) {//if in different sets
			cout << "Edge: " << temp.id << ",Weight: " << temp.cost << ",Connecting vertex " << temp.source->id+1 << ",vertex " << temp.destination->id+1 << endl;
			ds.Union(temp.destination->id, temp.source->id);
		}
		else//if in the same set, skip
			continue;
		minHeap.DeleteTop();
		count++;
		
	}
}