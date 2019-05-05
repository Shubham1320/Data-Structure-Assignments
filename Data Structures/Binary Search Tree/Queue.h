/*
 *  Author: Shubham Yewalekar
 *  Div : SE 9 H9
 *  Roll No : 23182
 *  File Name : Queue Header File
 */

#ifndef QUEUE_H_
#define QUEUE_H_

template<class T>
class queue
{
	private:
		T *data;
		int count;
		int front;
		int rear;
		int size;
	public:
		queue(int n);
		//function to add element in queue
		void enqueue(T temp);
		//function to remove data from queue
		T dequeue();
		//function to check whether queue is empty
		int isEmpty();
		//function to check whether queue is full
		int isFull();
		~queue();

};

#endif /* QUEUE_H_ */
