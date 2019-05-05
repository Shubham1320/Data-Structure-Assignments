/*
 * stackll.h
 *
 *  Created on: 27-Dec-2018
 *      Author: h9
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
		void push(T dat);//function to insert data at top of stack
		T pop();//function to get data from top of the stack
		T getTop();//function to check the top of the stack
		int isEmpty();
};

#endif /* STACKLL_H_ */
