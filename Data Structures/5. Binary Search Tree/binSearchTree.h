/*
 *  Author: Shubham Yewalekar
 *  Div : SE 9 H9
 *  Roll No : 23182
 *  File Name : Binary Search Tree Header File
 */

#ifndef BINSEARCHTREE_H_
#define BINSEARCHTREE_H_

template<class T>
class Node1
{
	private:
		T data;
		Node1 *lchild;
		Node1 *rchild;
	public:
		Node1();

		T getData();
		Node1* getLchild();
		Node1* getRchild();

		void setRchild(Node1 *temp);
		void setData(T data);
		void setLchild(Node1 *temp);

};


template<class T>
class binSTree
{
	private :
		Node1<T> *root;
		Node1<T> *dltRoot;
	public:
		binSTree();
		void createTree();
		Node1<T>* getRoot();
		void insert(T data);
		void insertBST(Node1<T>* temp,T data1,Node1<T> *prev,int flag);
		Node1<T>* search(T data1);
		Node1<T>* searchBST(Node1<T>* temp,T data1);
		bool deleteBST(Node1<T>* temp,T data1,Node1<T>* prev,int flag);
		bool deleteNode(T data1,int flag1);
		void displayLeaf(Node1<T> *temp);
		int findHeight(Node1<T> *temp);
		void mirrorBST(Node1<T> *temp);
		void mirrorItr();
		void inOrderDisplay(Node1<T> *temp);
		void preOrderDisplay(Node1<T> *temp);
		void postOrderDisplay(Node1<T> *temp);
};

#endif /* BINSEARCHTREE_H_ */
