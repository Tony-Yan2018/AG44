#pragma once

struct ElemNode {
	int data;
	int parent;
};

class Disjoint_Set_Union
{
protected:
	ElemNode* sets; 
	int size;
	int Find(int e)const;//return the root element index
public:
	Disjoint_Set_Union(int* es,int n);
	virtual ~Disjoint_Set_Union();
	int GetElem(int p) const;//return the element indexed by p
	int GetOrder(int e)const;//return the index of e
	void Union(int a, int b);//unite set a and set b
	bool Differ(int a, int b);//tell if a and b are in the same set
};

