/*
 * File Name - prQueue.cpp
 * Author: Shubham Yewalekar
 * Roll No - 23182 SE 9 H9
 * Description - Linked List Implementation File
 */

#include "linkedL.h"
#include<iostream>
#include<string.h>
using namespace std;

/*
 	 Default Constructor
 */
template<class T>
linkedL<T> :: linkedL()
{
	head = NULL;
	n_o_n = 0;
}

/*
 	 Function to create linked list
 */
template<class T>
void linkedL<T> :: create()
{
	int flag = 1;
	Node<T> *temp;
	do
	{
		Node<T> *node1 = new Node<T>;//node to be inserted in list
		cout<<"Enter the data of the node: ";
		cin>>node1->data;
		n_o_n++;
		if(head==NULL)//in case head is NULL
		{
			head = node1;
			node1->next = NULL;
			temp = head;
		}
		else//attach node at the end of list
		{
			temp->next = node1;
			node1->next = NULL;
			temp = temp->next;
		}
		cout<<"Do you want to add another node (Y-1/N-0) : ";
		cin>>flag;
	}while(flag==1);
}

/*
 	 function to display linked list
 */
template<class T>
void linkedL<T> :: display()
{
	Node<T> *temp = head;
	while(temp!=NULL)
	{
		temp->data.showdata();//display data
		temp = temp->next;//traverse list
	}
	cout<<endl;
}

/*
 	 function to modify contents of linked list
 */
template<class T>
void linkedL<T> :: modify(T key)
{
	Node<T>* temp = head;
	while(temp->data!=key && temp != NULL)//search node to be deleted
	{
			temp = temp->next;
	}
	if(temp==NULL)//if node not found in list
	{
		cout<<"Node not found.PLease enter valid node data."<<endl;
	}
	else//if found,modify node
	{
		cout<<"Enter the modified data to be stored in the node : ";
		cin>>temp->data;
	}
}

/*
 	 function to search data in linked list
 */

template<class T>
int linkedL<T> :: search(T key)
{
	int count = 0;
	Node<T> *temp = head;
	while(temp->data!=key && temp!=NULL)//search for the node with given data
	{
		temp = temp->next;
		count++;
	}
	if(temp == NULL)
	{
		return -1;//not found
	}
	else
	{
		return count+1;//found,return position
	}
}

/*
 	 function to insert data in linked list
 */

template<class T>
void linkedL<T> :: insert(int pos,T dat)
{
	Node<T> *node1 = new Node<T>;
	node1->data = dat;
	if(head == NULL)//insert in empty list
	{
		head = node1;
		n_o_n++;
	}
	else
	{
		if(pos==1)//insert at beginning
		{
			node1->next = head;
			head = node1;
			n_o_n++;
		}
		else if(pos>n_o_n)//insert at last position
		{
			Node<T> *temp = head;
			while(temp->next!=NULL)
			{
				temp = temp->next;
			}
			temp->next = node1;
			node1->next = NULL;
			n_o_n++;
		}
		else//insert at specified position
		{
			Node<T> *temp = head;
			int i;
			for(i=0;i<pos-2;i++)
			{
				temp = temp->next;
			}
			node1->next = temp->next;
			temp->next = node1;
			n_o_n++;
		}
	}
}

/*
 	 function to display linked list in reverse
 */

template<class T>
void linkedL<T> :: display_rev(Node<T> *temp,int check)
{
	if(check == 0)
	{
		temp = head;
		display_rev(temp->next,1);
	}
	else
	{
		if(temp->next!=NULL)
		{
			display_rev(temp->next,1);
		}
	}
	cout<<temp->data<<endl;
}

/*
 	 function to delete node from linked list
 */

template<class T>
void linkedL<T> :: delete_node(T key)
{
	Node<T> *temp = head;
	Node<T> *prev = NULL;
	while(temp!=NULL && temp->data.patientID!=key.patientID)//search for data to be deleted
	{
		prev = temp;
		temp = temp->next;
	}
	if(temp==NULL)//node not found
	{
		cout<<"Node not found."<<endl;
	}
	else if(temp == head)//delete from beginning
	{
		head = temp->next;
		n_o_n--;
		delete temp;
	}
	else if(temp->next==NULL)//delete from last
	{
		prev->next = NULL;
		n_o_n--;
		delete temp;
	}
	else//delete from in between the list
	{
		n_o_n--;
		prev->next = temp->next;
		delete temp;
	}
}

/*
 	 function to revert the linked list
 */

template<class T>
void linkedL<T> :: revert_list()
{
	Node<T> *prev = NULL;
	Node<T> *temp = head;
	Node<T> *next = temp->next;
	while(temp!=NULL)
	{
		temp->next = prev;
		prev = temp;
		temp = next;
		if(next!=NULL)
		{
			next = temp->next;
		}
	}
	head = prev;
}

/*
	function to return head of linked list
 */

template<class T>
Node<T>* linkedL<T> :: getHead()
{
	return head;
}

/*
	function to set head of linked list
 */

template<class T>
void linkedL<T> :: setHead(Node<T>* temp)
{
	head = temp;
}





