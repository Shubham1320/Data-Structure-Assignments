/*
 *  Author: Shubham Yewalekar
 *  Div : SE 9 H9
 *  Roll No : 23182
 *  File Name : Stack Header File
 */
#include "linkedL.cpp"
#ifndef STACKLL_H_
#define STACKLL_H_

template<class T>
class stack_ll
{
	private:
		linkedL<T> L;
		Node<T> *top;
	public:
		stack_ll();
		//function to insert data at top of stack
		void push(T dat);
		//function to get data from top of the stack
		T pop();
		//function to check the top of the stack
		T getTop();
		//function which tells whether stack is empty
		int isEmpty();
};

#endif /* STACKLL_H_ */
