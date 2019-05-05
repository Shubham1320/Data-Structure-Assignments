/*
 * File Name - prQueue.cpp
 * Author: Shubham Yewalekar
 * Roll No - 23182 SE 9 H9
 * Description - Linked List Header File
 */

#ifndef LINKEDL_H_
#define LINKEDL_H_

template<class T>
class Node
{
	public:
		T data;
		Node *next;
};

template<class T>
class linkedL
{
	private:
		Node<T> *head;
		int n_o_n;
	public:
		linkedL();
		void create();//function to create a linked list having required no of nodes
		void display();//function to display all the nodes present in the linked list
		void modify(T key);//function to search the node by data stored in it and modify that data
		int search(T key);//function to search the node based on data stored in the node
		void insert(int pos,T dat);//function to insert new node in the linked list
		void display_rev(Node<T> *temp,int check);//function to display linked list in reverse order
		void delete_node(T key);//function to delete
		void revert_list();
		Node<T>* getHead();
		void setHead(Node<T> *temp);
};

#endif /* LINKEDL_H_ */

