/*
 *  Author: Shubham Yewalekar
 *  Div : SE 9 H9
 *  Roll No : 23182
 *  File Name : Expression Tree Header File
 */

#ifndef EXPTREE_H_
#define EXPTREE_H_
#include"expression.h"

template<class T>
class Node1
{
	private:
		T data;
		Node1 *lchild;
		Node1 *rchild;
	public:
		Node1();

		//T getData();
		//Node1* getLchild();
		//Node1* getRchild();

		//void setRchild(Node1 *temp);
		//void setData(T data);
		//void setLchild(Node1 *temp);

		~Node1();
};

template<class T>
class expTree
{
	private:
		expression E1;
		Node1<T> *root;
	public:
		//constructor
		void createTree();
		//recursive display
		void inOrderDisplay(Node1<T>* temp);
		void preOrderDisplay(Node1<T>* temp);
		void postOrderDisplay(Node1<T>* temp);
		//non-recursive display
		void inOrderDisplay1();
		void preOrderDisplay1();
		void postOrderDisplay1();
		//getters and setters
		Node1<T>* getRoot();
		void setRoot(Node1<T> *temp);


};



#endif /* EXPTREE_H_ */
