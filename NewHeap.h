#pragma once

#include "HeapMin.h"

class NewHeap {
	HeapMax smallerMedMax;
	HeapMin smallerMedMin;
	HeapMax biggerMedMax;
	HeapMin biggerMedMin;
	int heapSize = 0;

public:
	NewHeap() {};
	~NewHeap();
	Pair Max();
	Pair DeleteMax();
	Pair Min();
	Pair DeleteMin();
	void CreateEmpty();
	void insert(int priority, string value);
	Pair Median();
	Pair* duplicatePair(Pair* _node);
};