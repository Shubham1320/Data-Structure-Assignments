/*
 *  Author: Shubham Yewalekar
 *  Div : SE 9 H9
 *  Roll No : 23182
 *  File Name : Binary Tree Header File
 */

#ifndef BINTREE_H_
#define BINTREE_H_

template<class T>
class Node1 //node class
{
	private:
		T data;//data
		Node1 *lchild;//left child address
		Node1 *rchild;//right child address
	public:
		Node1();

		//getters
		T getData();
		Node1* getLchild();
		Node1* getRchild();

		//setters
		void setRchild(Node1 *temp);
		void setData(T data);
		void setLchild(Node1 *temp);

		~Node1();
};

template<class T>
class binTree
{
	private :
		Node1<T>* root;//original root
		Node1<T>* newRoot;//copy tree root
		int count;
	public :
		binTree();

		//function to create binary tree
		void createTree(Node1<T> *temp);
		//getter
		Node1<T>* getRoot();
		//recursive display
		void inOrderDisplay(Node1<T> *temp);
		void preOrderDisplay(Node1<T> *temp);
		void postOrderDisplay(Node1<T> *temp);
		//Non-Recursive display
		void inOrderDisplay1();
		void preOrderDisplay1();
		void postOrderDisplay1();
		//level wise display
		void breadthDisplay();
		//finding height of tree
		int findHeight(Node1<T> *temp);
		//display leaf nodes recursive
		void displayLeaf(Node1<T> *temp);
		//display non-recursive leaf nodes
		void displayLeaf1();
		//function to copy tree and initialize newRoot
		Node1<T>* copyTree(Node1<T> *temp,int flag,Node1<T> *prev);
		//function to insert data in tree
		int insert(T data,int flag1);
};

#endif /* BINTREE_H_ */
