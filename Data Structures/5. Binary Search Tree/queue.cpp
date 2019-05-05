/*
 *  Author: Shubham Yewalekar
 *  Div : SE 9 H9
 *  Roll No : 23182
 *  File Name : Queue Implementation  File
 */
#include <iostream>
using namespace std;
#include"Queue.h"

//queue constructor
template<class T>
queue<T> :: queue(int n)
{
	size = n;
	data = new T[n];
	count = 0;
	front = -1;
	rear = -1;
}

//add data from rear of queue
template<class T>
void queue<T> :: enqueue(T temp)
{
	if(front == -1 && rear == -1)
	{
		data[0] = temp;
		front = 0;
		rear = 0;
		count++;
	}
	else if(rear == size-1 && isFull()!=1 )
	{
		data[0] = temp;
		rear = 0;
		count++;
	}
	else if(isFull()!=1)
	{
		rear++;
		data[rear] = temp;
		count++;
	}
}

//remove data from front of queue
template<class T>
T queue<T> :: dequeue()
{
	if(isEmpty() == 1)
	{
		cout<<"Cannot dequeue from empty queue !";
	}
	else if(front != size-1)
	{
		front++;
		count--;
		return data[front-1];
	}
	else if(front == size-1)
	{
		front = 0;
		count--;
		return data[size-1];
	}
}

//function to check whether queue is empty
template<class T>
int queue<T> :: isEmpty()
{
	if(front == -1 && rear == -1)
	{
		return 1;
	}
	else if(count == 0)
	{
		return 1;
	}
	else
		return 0;
}

//function to check whether queue is full
template<class T>
int queue<T> :: isFull()
{
	if(count == size)
	{
		return 1;
	}
	else
		return 0;
}

//queue destructor
template<class T>
queue<T> :: ~queue()
{
	delete []data;
}
