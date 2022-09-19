#include "HeapMax.h"

int HeapMax::Left(int node)
{
	return (2 * node + 1);
}
int HeapMax::Right(int node)
{
	return (2 * node + 2);
}
int HeapMax::Parent(int node)
{
	return (node - 1) / 2;
}
void HeapMax::FixHeap(int node)
{
	int max;
	int left = Left(node);
	int right = Right(node);

	//find maximum amond data, left and right
	if ((left < heapSize) && (data[left]->priority > data[node]->priority))
		max = left;
	else
		max = node;
	if ((right < heapSize) && (data[right]->priority > data[max]->priority))
		max = right;

	if (max != node)
	{
		Swap(data[node], data[max]);
		FixHeap(max);
	}
}

Pair HeapMax::Max()
{
	return *(data[0]);
}
Pair* HeapMax::DeleteMax()
{
	if (heapSize < 1)
		cout << "error" << endl;

	Pair* max = data[0];
	heapSize--;
	data[0]= data[heapSize];
	data[0]->index = 0;
	FixHeap(0);
	return (max);

}
void HeapMax::Insert(Pair* item)
{

	if (heapSize == MAXSIZE)
		cout << "error" << endl;

	int i = heapSize;
	heapSize++;

	while ((i > 0) && (data[Parent(i)]->priority < item->priority))
	{
		data[i] = data[Parent(i)];
		data[i]->index = i;
		i = Parent(i);
	}

	data[i] = item;
	item->index= i;
}

void HeapMax::Swap(Pair* pair1, Pair* pair2)
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

void HeapMax::DeleteIMax(int i)
{
	Pair* right = data[heapSize - 1];
	data[i] = right;
	data[i]->index = i;


	if (Right(i) < heapSize)
	{
		//not ok with his kids
		if (data[i]->priority < data[Right(i)]->priority)
			FixHeap(i);
	}
	else if (Left(i) < heapSize)
	{
		if (data[i]->priority < data[Left(i)]->priority)
			FixHeap(i);
	}

	if (i != 0)
	{
		//not ok with his parent
		while (data[i]->priority > data[Parent(i)]->priority)
			Swap(data[i], data[Parent(i)]);
	}
	
	heapSize--;
}

int HeapMax::returnIndex(Pair x)
{
	for (int i = 0; i < heapSize; i++)
	{
		if ((data[i]->data == x.data) && (data[i]->priority == x.priority))
			return i;
	}
	return UNDEFINED;
}

