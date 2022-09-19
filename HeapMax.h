#pragma once
#include <string>
#include <iostream>

#define MAXSIZE 100
#define UNDEFINED -1

using namespace std;


struct Pair {
	int priority;
	string data; //satellite data
	Pair* dupPair = nullptr;
	int index;
};


class HeapMax {
	Pair* data[MAXSIZE] = { };
	int heapSize = 0;
	static int Left(int node);
	static int Right(int node);
	static int Parent(int node);
	void FixHeap(int node);

public:
	HeapMax() {};
	Pair Max();
	Pair* DeleteMax();
	void Insert(Pair* item);
	void Swap(Pair* pair1, Pair* pair2);
	void DeleteIMax(int i);
	
	Pair* getData(int i)
	{
		return data[i];
	}

	int getHeapSize() const
	{
		return heapSize;
	}

	void setHeapSize(int _heapSize)
	{
		heapSize = _heapSize;
	}

	int returnIndex(Pair x);
};