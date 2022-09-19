#include "HeapMin.h"

int HeapMin::Left(int node)
{
	return (2 * node + 1);
}
int HeapMin::Right(int node)
{
	return (2 * node + 2);
}
int HeapMin::Parent(int node)
{
	return (node - 1) / 2;
}
void HeapMin::FixHeap(int node)
{
	int min;
	int leftIndex = Left(node);
	int rightIndex = Right(node);

	//find maximum amond data, left and right
	if ((leftIndex < heapSize) && (data[leftIndex]->priority < data[node]->priority))
		min = leftIndex;
	else
		min = node;
	if ((rightIndex < heapSize) && (data[rightIndex]->priority < data[min]->priority))
		min = rightIndex;

	if (min != node)
	{
		Swap(data[node], data[min]);
		FixHeap(min);
	}
}

Pair HeapMin::Min()
{
	return *(data[0]);
}
Pair* HeapMin::DeleteMin()
{
	if (heapSize < 1)
		cout << "error" << endl;

	Pair* min = data[0];
	heapSize--;
	data[0] = data[heapSize];
	data[0]->index = 0;
	FixHeap(0);
	return (min);

}
void HeapMin::Insert(Pair* item)
{
	if (heapSize == MAXSIZE)
		cout << "error" << endl;

	int i = heapSize;
	heapSize++;

	while ((i > 0) && (data[Parent(i)]->priority > item->priority))
	{
		data[i] = data[Parent(i)];
		data[i]->index = i;
		i = Parent(i);
	}
	data[i]= item;
	item->index = i;
}

void HeapMin::Swap(Pair* pair1, Pair* pair2)
{	
	Pair temp;
	temp = *pair1;
	*pair1 = *pair2;
	*pair2 = temp;

	// swaping the index
	int tempIndex;
	tempIndex = pair1->index;
	pair1->index = pair2->index;
	pair2->index = pair1->index;
}

void HeapMin::DeleteIMin(int i)
{
	Pair* right = data[heapSize-1];
	data[i] = right;
	data[i]->index= i;

	//not ok with his kids
	if (Right(i) < heapSize)
	{
		if (data[i]->priority > data[Right(i)]->priority)
			FixHeap(i);

	}
	else if (Left(i) < heapSize)
	{
		if(data[i]->priority > data[Left(i)]->priority)
			FixHeap(i);
	}
			
	//not ok with his parent
	if (i != 0)
	{
		while (data[i]->priority < data[Parent(i)]->priority)
			Swap(data[i], data[Parent(i)]);
	}

	heapSize--;
}

int HeapMin::returnIndex(Pair x)
{
	for (int i = 0; i < heapSize; i++)
	{
		if ((data[i]->data == x.data) && (data[i]->priority == x.priority))
			return i;
	}
	return UNDEFINED;
}
