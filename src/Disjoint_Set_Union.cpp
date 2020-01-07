#include "Disjoint_Set_Union.h"

int Disjoint_Set_Union::Find(int e)const {//return the root element index
	int p = 0;
	while (p < size && sets[p].data != e)
		p++;//get the index of e
	if (p == size)
		return -1;//does not exist
	while (sets[p].parent > -1)
		p = sets[p].parent;//get the root of the set which consists p
	return p;
}

Disjoint_Set_Union::Disjoint_Set_Union(int* es, int n) {
	size = n;
	sets = new ElemNode[size];
	for (auto i = 0; i < size; i++) {
		sets[i].data = es[i];
		sets[i].parent = -1;
	}
}

 Disjoint_Set_Union::~Disjoint_Set_Union() {
	delete[] sets;
}
 
 int Disjoint_Set_Union::GetElem(int p) const {
	 if (p >= 0&&p<size)
		 return sets[p].data;
 }
 
 int Disjoint_Set_Union::GetOrder(int e)const {
	 int p = 0;
	 while (p < size && sets[p].data != e)
		 p++;
	 if (p == size)
		 return -1;
	 return p;
 }

 void Disjoint_Set_Union::Union(int a, int b) {
	 int r1 = Find(a);
	 int r2 = Find(b);
	 if (r1 != r2 && r1 != -1 && r2 != -1) {
		 sets[r1].parent += sets[r2].parent;
		 sets[r2].parent = r1;
	 }
 }

 bool Disjoint_Set_Union::Differ(int a, int b){//tell if a and b are in the same set
	 if (Find(a) == Find(b))
		 return false;
	 else
		 return true;
 }
