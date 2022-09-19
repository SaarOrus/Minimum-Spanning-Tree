#pragma once
#include "HeapMax.h"

#include <string>
#include <iostream>

#define MAXSIZE 100

using namespace std;


class HeapMin {
	Pair* data[MAXSIZE];
	int heapSize = 0;
	static int Left(int node);
	static int Right(int node);
	static int Parent(int node);
	void FixHeap(int node);

public:
	HeapMin() { };
	Pair Min();
	Pair* DeleteMin();
	void Insert(Pair* item);
	void Swap(Pair* pair1, Pair* pair2);
	void DeleteIMin(int i);
	int returnIndex(Pair x);
	int getHeapSize() const
	{
		return heapSize;
	}

	Pair* getData(int i)
	{
		return data[i];
	}

	void setHeapSize(int _heapSize)
	{
		heapSize = _heapSize;
	}
};
