#include "Heap.h"

Heap::Heap(vector<Edge*> a, int maxSize, int n) {
	maxSize = maxSize;
	heapArr = new Edge[maxSize];
	for (auto i = 0; i < n; i++) {
		heapArr[i] = *a[i];
	}
	CurrentSize = n;
	int i = (CurrentSize - 2) / 2;
	while (i >= 0) {
		FilterDown(i);
		i--;
	}
}

void Heap::Insert(const Edge& e) {
	if(IsFull())
	return;
	heapArr[CurrentSize] = e;
	FilterUp(CurrentSize);
	CurrentSize++;
}

void Heap::DeleteTop() {
	if (CurrentSize == 0)
	return;
	heapArr[0] = heapArr[CurrentSize - 1];
	FilterDown(0);
	CurrentSize--;
}

Edge& Heap::GetTop ()const {
	if (CurrentSize == 0) {}
	return heapArr[0];
}

void Heap::FilterDown(const int start) {//from high to low
	int i=start,j;// i is the index of an array starting from 0; j is the smallest child of i
	Edge temp = heapArr[i];
	j = 2 * i + 1;//get left child of i
	while (j <= CurrentSize - 1) {//to check i is the last father
		if (j < CurrentSize - 1 && heapArr[j].cost>heapArr[j + 1].cost)//if i has a right child && it is smaller than the left one
			j++;			//j is now the smallest child
		if (temp.cost <= heapArr[j].cost)// if father is no bigger than the smallest child
			break;
		else {
			heapArr[i] = heapArr[j];//change the value
			i = j;
			j = 2 * j + 1;//go to next level;
		}
		heapArr[i] = temp;
	}
}

void Heap::FilterUp(int End) {//from low to high
	int i = End;
	Edge temp;
	while (i > 0) {
		if (heapArr[(i-1)/ 2].cost > heapArr[i].cost)
		{
			temp = heapArr[i];
			heapArr[i] = heapArr[(i - 1) / 2];
			heapArr[(i - 1) / 2] = temp;
		}
		else break;
		i = (i-1) / 2;
	}
}