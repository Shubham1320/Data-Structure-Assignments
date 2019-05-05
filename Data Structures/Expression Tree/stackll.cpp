/*
 * stackll.cpp
 *
 *  Created on: 27-Dec-2018
 *      Author: h9
 */

#include "stackll.h"
#include "linkedL.cpp"
#include<iostream>
using namespace std;

template<class T>
stack_ll<T>::stack_ll()
{
	top = NULL;

}

template<class T>
void stack_ll<T>::push(T dat)
{
	L.insert(1,dat);
	top = L.getHead();
}

template<class T>
T stack_ll<T>::pop()
{
	T temp = top->data;
	L.delete_node(top->data);
	top = L.getHead();
	return temp;
}

template<class T>
T stack_ll<T>::getTop()
{
	if(isEmpty()==0)
	{
		return top->data;
	}
}

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




