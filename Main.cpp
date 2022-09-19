#include "NewHeap.h"
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

void extractFromString(string line, NewHeap& mainHeap, int& countE, int& countOper, bool& isInsert, bool& isCreateEmpty);
bool validNumber(string number);
void invalidInput();

void main()
{
	NewHeap mainHeap;
	string line,s;
	int numOfOperations = 0, countOper = 0, countE = 0;
	bool isInsert = false,start=true, isCreateEmpty=false;


	//size of arr
	cin >> numOfOperations;
	cout << endl;

	s = getchar();//eat white space

	if (numOfOperations < 0)
		invalidInput();
	
	

	if (numOfOperations > 0)
	{
		while (start)
		{			
			getline(cin, line);

			if (!line.empty())
			{
				extractFromString(line, mainHeap, countE, countOper, isInsert, isCreateEmpty);
				countOper++;
			}
			else
				start = false;
		}			

		if (countOper != numOfOperations) // if there is less or more inputs than expected
			invalidInput();
	}
}


void extractFromString(string line,NewHeap& mainHeap,int & countE, int& countOper,bool & isInsert,bool & isCreateEmpty)
{
	Pair retPair;
	stringstream str;
	string data=" ",temp,checkNum;
	int num=UNDEFINED;
	char oper;

	str << line;

	str >> oper;//get the operation 
	str >> checkNum;

	switch (oper)
	{
	case 'a':		
		
		if (!isInsert || !isCreateEmpty || !checkNum.empty())//checck if there were members and structure before operations
			invalidInput();//check if we need to return value before get any input
		else
		{
			retPair = mainHeap.Max();
			cout << retPair.priority << " " << retPair.data << endl;
		}
		break;
	case 'b':

		if (!isInsert || !isCreateEmpty || !checkNum.empty())//check if we need to return value before get any input
			invalidInput();		
		else
		{
			retPair = mainHeap.DeleteMax();
			cout << retPair.priority << " " << retPair.data << endl;
		}
		break;

	case 'c':

		if (!isInsert || !isCreateEmpty || !checkNum.empty())//check if we need to return value before get any input
			invalidInput();		
		else
		{
			retPair = mainHeap.Min();
			cout << retPair.priority << " " << retPair.data << endl;
		}
		break;

	case 'd':

		if (!isInsert || !isCreateEmpty || !checkNum.empty())//check if we need to return value before get any input
			invalidInput();
		else
		{
			retPair = mainHeap.DeleteMin();
			cout << retPair.priority << " " << retPair.data << endl;
		}
		break;

	case 'e':

		if (!checkNum.empty())
			invalidInput();

		isCreateEmpty = true;
		countE++;

		if (countE != 1) // if there is more than one 'e' operation
			invalidInput();

		if (countE == 1 && countOper != 0) // if there is operation 'e', but not in first line
			invalidInput();

		mainHeap.CreateEmpty();
		break;

	case 'f':

		if (!isCreateEmpty || checkNum.empty() || !validNumber(checkNum))
			invalidInput();
		else
			stringstream(checkNum) >> num;
		
		while (str >> temp) // get from str the string value
		{
			data += temp + ' ';
		}

		isInsert = true;
		mainHeap.insert(num,data);
		break;

	case 'g':

		if (!isInsert || !isCreateEmpty || !checkNum.empty())//check if we need to return value before get any input
			invalidInput();//check if we need to return value before get any input
		else
		{
			retPair = mainHeap.Median();
			cout << retPair.priority << " " << retPair.data << endl;
		}
		break;

	default:
		invalidInput();//check if the first char isnt an operation
		
	}

	
}

bool validNumber(string number)
{
	if (number[0] != '-' && (!isdigit(number[0])))
		return false;	
	
	for (int i = 1; i < number.length(); i++)
	{
		if (!isdigit(number[i]))
			return false;
	}

	return true;
}

void invalidInput()
{
	cout << "Wrong input." << endl;
	exit(0);
}