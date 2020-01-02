#ifndef HEAP_H
#define HEAP_H
#include <vector>
#include <Edge.h>
using namespace std;
/*this is a min heap*/
class Heap
{
    public:

		Heap(vector<Edge*> a, int maxSize,int n);
		~Heap() { delete[]heapArr; }
		void Insert(const Edge&e);
		void DeleteTop();
		Edge& GetTop()const;
		bool IsEmpty() const { return CurrentSize == 0; };
		bool IsFull() const{ return CurrentSize == maxSize; };
		int getSize() const{ return CurrentSize; };
		void setEmpty() { CurrentSize = 0; };
		
    protected:

    private:
		Edge* heapArr;
		int CurrentSize;
		int maxSize;
		void FilterDown(const int start);
		void FilterUp(int End);
};

#endif // HEAP_H
