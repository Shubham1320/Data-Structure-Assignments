/*
 * File Name - prQueue.cpp
 * Author: Shubham Yewalekar
 * Roll No - 23182 SE 9 H9
 * Description - Priority Queue Header File
 */

#ifndef PRQUEUE_H_
#define PRQUEUE_H_
#include"linkedL.cpp"

class data1
{
	public:
		char name[20];
		int age;
		char disease[20];
		char priority;
		int patientID;
		int* getdata();
		void showdata();
		int isValid();//validations
};

class prQueue
{
	private :
			Node<data1> *front1;//front ptr of high priority Q
			Node<data1> *rear1;//rear ptr of high priority Q
			Node<data1> *front2;//front ptr of medium priority Q
			Node<data1> *rear2;//rear ptr of medium priority Q
			Node<data1> *front3;//front ptr of low priority Q
			Node<data1> *rear3;//rear ptr of low priority Q
			int highPr;//high priority nodes count
			int midPr;//medium priority nodes count
			int lowPr;//low priority nodes count
			int totalCnt;
			linkedL<data1> L;
	public :
			prQueue();//default constructor
			void enqueue(data1 temp);//function to insert node in queue
			data1 dequeue();//function to remove node from queue

};
#endif /* PRQUEUE_H_ */
