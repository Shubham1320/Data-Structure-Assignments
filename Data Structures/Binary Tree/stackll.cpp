/*
 *  Author: Shubham Yewalekar
 *  Div : SE 9 H9
 *  Roll No : 23182
 *  File Name : Stack Implementation File
 */

#include "stackll.h"
#include "linkedL.h"
#include<iostream>
using namespace std;

//stack constructor
template<class T>
stack_ll<T>::stack_ll()
{
	top = NULL;

}

//function to push data onto stack
template<class T>
void stack_ll<T>::push(T dat)
{
	L.insert(1,dat);
	top = L.getHead();
}

//function to pop top data from stack
template<class T>
T stack_ll<T>::pop()
{
	T temp = top->data;
	L.delete_node(top->data);
	top = L.getHead();
	return temp;
}

//function which tells data at the top of stack
template<class T>
T stack_ll<T>::getTop()
{
	if(isEmpty()==0)
	{
		return top->data;
	}
}

//function to check whether stack is empty or not
template<class T>
int stack_ll<T>::isEmpty()
{
	if(top == NULL)
	{
		return 1;
	}
	else
		return 0;
}




