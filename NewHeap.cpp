#include "NewHeap.h"

NewHeap::~NewHeap()
{
	if (heapSize > 0)
	{
		for (int i = 0; i < smallerMedMax.getHeapSize(); i++)
		{
			delete smallerMedMax.getData(i)->dupPair;
			delete smallerMedMax.getData(i);
		}

		for (int i = 0; i < biggerMedMax.getHeapSize(); i++)
		{
			delete biggerMedMax.getData(i)->dupPair;
			delete biggerMedMax.getData(i);
		}
	}
}

Pair NewHeap::Max()
{
	if (biggerMedMax.getHeapSize() != 0)
		return biggerMedMax.Max();
	else if(smallerMedMax.getHeapSize()!=0)
		return smallerMedMax.Max();
	else
	{
		cout << "Wrong input." << endl;
		exit(0);
	}
	
}
Pair NewHeap::DeleteMax()
{
	if (heapSize == 0)
	{
		cout << "Wrong input." << endl;
		exit(0);
	}

	Pair temp;
	Pair* x = biggerMedMax.DeleteMax();

	biggerMedMin.DeleteIMin(x->dupPair->index);
	
	//if there was odd number before delete
	if (smallerMedMin.getHeapSize() == biggerMedMin.getHeapSize() + 2)
	{
		Pair* y = smallerMedMax.DeleteMax();
		smallerMedMin.DeleteIMin(y->dupPair->index); //update also second heap
		Pair* y_ = duplicatePair(y);
		biggerMedMax.Insert(y);
		biggerMedMin.Insert(y_);

	}
	heapSize--;

	temp.data = x->data;
	temp.priority = x->priority;

	delete x->dupPair;
	delete x;

	return temp;
}

Pair* NewHeap::duplicatePair(Pair* _node)
{
	Pair* newPair = new Pair;

	newPair->data = _node->data;
	newPair->priority = _node->priority;
	newPair->dupPair = _node;

	_node->dupPair = newPair;
	
	return newPair;
}

Pair NewHeap::Min()
{
	if (smallerMedMin.getHeapSize() != 0)
		return smallerMedMin.Min();
	else if (biggerMedMin.getHeapSize() != 0)
		return biggerMedMin.Min();
	else
	{
		cout << "Wrong input." << endl;
		exit(0);
	}
}
Pair NewHeap::DeleteMin()
{
	if (heapSize == 0)
	{
		cout << "Wrong input." << endl;
		exit(0);
	}

	Pair temp;
	Pair* x = smallerMedMin.DeleteMin();

	smallerMedMax.DeleteIMax(x->dupPair->index);
	
	if (smallerMedMin.getHeapSize() < biggerMedMin.getHeapSize())
	{
		Pair* y = biggerMedMin.DeleteMin();
		biggerMedMax.DeleteIMax(y->dupPair->index);
		Pair* y_ = duplicatePair(y);
		smallerMedMax.Insert(y);
		smallerMedMin.Insert(y_);

	}
	heapSize--;

	temp.data = x->data;
	temp.priority = x->priority;

	delete x->dupPair;
	delete x;
	
	return temp;
}
void NewHeap::CreateEmpty()
{
	smallerMedMax = {};
	smallerMedMin = {};
	biggerMedMax = {};
	biggerMedMin = {};
}
void NewHeap::insert(int priority, string value)
{
	Pair* x = new Pair;
	x->data = value;
	x->priority = priority;

	if (heapSize == 0)
	{
		Pair* x_ = duplicatePair(x);
		smallerMedMax.Insert(x);
		smallerMedMin.Insert(x_);
	}
	else if (priority > Median().priority)
	{
		Pair* x_ = duplicatePair(x);
		biggerMedMax.Insert(x);
		biggerMedMin.Insert(x_);

		//when there is one more in bigger
		if (biggerMedMax.getHeapSize() == smallerMedMax.getHeapSize() + 1) 
		{
			Pair* y = biggerMedMin.DeleteMin();			
			biggerMedMax.DeleteIMax(y->dupPair->index);
			Pair* y_ = duplicatePair(y);
			smallerMedMax.Insert(y);
			smallerMedMin.Insert(y_);
		}
	}
	else //x<median
	{
		Pair* x_ = duplicatePair(x);
		smallerMedMax.Insert(x);		
		smallerMedMin.Insert(x_);

		//when there is two less in bigger
		if ( smallerMedMax.getHeapSize() == biggerMedMax.getHeapSize() + 2)
		{
			Pair* y = smallerMedMax.DeleteMax();			
			smallerMedMin.DeleteIMin(y->dupPair->index);
			Pair* y_ = duplicatePair(y);			
			biggerMedMax.Insert(y);
			biggerMedMin.Insert(y_);
		}

	}
	heapSize++;
}
Pair NewHeap::Median()
{
	if(smallerMedMax.getHeapSize()!=0)
		return smallerMedMax.Max();
	else
	{
		cout << "Wrong input." << endl;
		exit(0);
	}
}
