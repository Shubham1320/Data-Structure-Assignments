/*
 *  Author: Shubham Yewalekar
 *  Div : SE 9 H9
 *  Roll No : 23182
 *  File Name : Linked List Header File
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
		//function to create a linked list having required no of nodes
		void create();
		//function to display all the nodes present in the linked list
		void display();
		//function to search the node by data stored in it and modify that data
		void modify(T key);
		//function to search the node based on data stored in the node
		int search(T key);
		//function to insert new node in the linked list
		void insert(int pos,T dat);
		//function to display linked list in reverse order
		void display_rev(Node<T> *temp,int check);
		//function to delete
		void delete_node(T key);
		void revert_list();
		Node<T>* getHead();
};

#endif /* LINKEDL_H_ */
