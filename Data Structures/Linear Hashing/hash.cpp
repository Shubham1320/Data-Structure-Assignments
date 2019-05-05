/*
 *  Author: Shubham Yewalekar
 *  Div : SE 9 H9
 *  Roll No : 23182
 *  File Name : Hashing Class Implementation  File
 */

#include<iostream>
using namespace std;
#include "hash.h"
#include<iomanip>
#include<string.h>


Hash :: Hash()
{
	count = 0;
}

//function to initialize hash table
void Hash :: setHashTable()
{
	int i;
	for(i=0;i<11;i++)
	{
		hashTable[i].name = new char[10];
		strcpy(hashTable[i].name,"NONE");
		hashTable[i].chain = -1;
		hashTable[i].mobileNo = -1;
	}

}

//function to perform hashing without replacement
void Hash :: hashWithoutReplacement(data temp)
{
	int index = temp.mobileNo % 11;
	//direct hash
	if(hashTable[index].mobileNo == -1)
	{
		hashTable[index] = temp;
		count++;
	}
	//hashed location full and chain not present
	else if(hashTable[index].chain == -1)
	{
		int pos = findEmptyPos(index);
		if(pos == -1)
		{
			cout<<"ERROR :: HASH TABLE FULL";
		}
		else
		{
			count++;
			hashTable[pos] = temp;
			hashTable[index].chain = pos;
		}
	}
	else//hashed location full and chain present
	{
		int last = hashTable[index].chain;
		while(hashTable[last].chain != -1)
		{
			last = hashTable[last].chain;
		}
		int pos1 = findEmptyPos(index);
		if(pos1 == -1)
		{
			cout<<"ERROR :: HASH TABLE FULL";
		}
		else
		{
			count++;
			hashTable[pos1] = temp;
			hashTable[last].chain = pos1;
		}
	}
}

//function to perform hashing with replacement
void Hash :: hashWithReplacement(data temp)
{
	int index = temp.mobileNo % 11;
	//direct hash
	if(hashTable[index].mobileNo == -1)
	{
		hashTable[index] = temp;
		count++;
	}
	//hashed location full and correct but chain is not present
	else if(hashTable[index].mobileNo%11 == index && hashTable[index].chain == -1)
	{
		int pos = findEmptyPos(index);
		if(pos == -1)
		{
			cout<<"ERROR :: HASH TABLE FULL";
		}
		else
		{
			count++;
			hashTable[pos] = temp;
			hashTable[index].chain = pos;
		}
	}
	//hashed location full and correct but chain is present
	else if(hashTable[index].mobileNo%11 == index && hashTable[index].chain != -1)
	{
		int last = hashTable[index].chain;
		while(hashTable[last].chain != -1)
		{
			last = hashTable[last].chain;
		}
		int pos1 = findEmptyPos(index);
		if(pos1 == -1)
		{
			cout<<"ERROR :: HASH TABLE FULL";
		}
		else
		{
			count++;
			hashTable[pos1] = temp;
			hashTable[last].chain = pos1;
		}
	}
	//hashed location is fully and it is wrong hashed
	else
	{
		int last = hashTable[index].mobileNo % 11;
		while(hashTable[last].chain != index)
		{
			last = hashTable[last].chain;
		}
		int pos1 = findEmptyPos(index);
		if(pos1 == -1)
		{
			cout<<"ERROR :: HASH TABLE FULL";
		}
		else
		{
			count++;
			hashTable[pos1] = hashTable[index];
			hashTable[index] = temp;
			hashTable[last].chain = pos1;
		}
	}
}

//function to find empty position in hash table
int Hash :: findEmptyPos(int temp)
{
	if(count == 11)
	{
		return -1;
	}
	while(hashTable[temp].mobileNo != -1)
	{
		temp++;
		temp = temp % 11;
	}
	return temp;
}

data Hash :: getData()
{
	data temp;
	cout<<"Name : ";
	temp.name = new char[10];
	cin>>temp.name;
	cout<<"Mobile No :";
	cin>>temp.mobileNo;
	temp.chain = -1;
	return temp;

}

//function to display hash table
void Hash :: displayHashTable()
{
	int i;
	for(i=0;i<11;i++)
	{
		cout<<left<<setw(9)<<i<<left<<setw(14)<<hashTable[i].name;
		cout<<left<<setw(12)<<hashTable[i].mobileNo<<left<<setw(5)<<hashTable[i].chain;
		cout<<endl;
	}
}

//function to search an element in hash table
bool Hash :: search(int *temp1)
{
	data temp;
	temp.name = new char[10];
	cout<<"Enter Name you want to search : ";
	cin>>temp.name;
	cout<<"Enter mobile no you want to search : ";
	cin>>temp.mobileNo;
	int index = temp.mobileNo % 11;
	while(hashTable[index].mobileNo != temp.mobileNo && strcmp(hashTable[index].name,temp.name) != 0)
	{
		index = hashTable[index].chain;
		if(index == -1)
		{
			return false;
		}
	}
	(*temp1) = index;
	return true;


}

