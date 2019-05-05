/*
 * linkedL.cpp
 *
 *  Created on: 27-Dec-2018
 *      Author: h9
 */

#include "linkedL.h"
#include<iostream>
using namespace std;

template<class T>
linkedL<T> :: linkedL()
{
	head = NULL;
	n_o_n = 0;
}

template<class T>
void linkedL<T> :: create()
{
	int flag = 1;
	Node<T> *temp;
	do
	{
		Node<T> *node1 = new Node<T>;
		cout<<"Enter the data of the node: ";
		cin>>node1->data;
		n_o_n++;
		if(head==NULL)
		{
			head = node1;
			node1->next = NULL;
			temp = head;
		}
		else
		{
			temp->next = node1;
			node1->next = NULL;
			temp = temp->next;
		}
		cout<<"Do you want to add another node (Y-1/N-0) : ";
		cin>>flag;
	}while(flag==1);
}

template<class T>
void linkedL<T> :: display()
{
	Node<T> *temp = head;
	cout<<"Linked List Created is as follows : \n";
	while(temp!=NULL)
	{
		cout<<temp->data<<"|"<<temp->next;
		if(temp->next!=NULL)
		{
			cout<<"-->";
		}
		temp = temp->next;
	}
	cout<<endl;
}

template<class T>
void linkedL<T> :: modify(T key)
{
	Node<T>* temp = head;
	while(temp->data!=key && temp != NULL)
	{
			temp = temp->next;
	}
	if(temp==NULL)
	{
		cout<<"Node not found.PLease enter valid node data."<<endl;
	}
	else
	{
		cout<<"Enter the modified data to be stored in the node : ";
		cin>>temp->data;
	}
}

template<class T>
int linkedL<T> :: search(T key)
{
	int count = 0;
	Node<T> *temp = head;
	while(temp->data!=key && temp!=NULL)
	{
		temp = temp->next;
		count++;
	}
	if(temp == NULL)
	{
		return -1;
	}
	else
	{
		return count+1;
	}
}

template<class T>
void linkedL<T> :: insert(int pos,T dat)
{
	Node<T> *node1 = new Node<T>;
	node1->data = dat;
	if(head == NULL)
	{
		head = node1;
		n_o_n++;
	}
	else
	{
		if(pos==1)
		{
			node1->next = head;
			head = node1;
		}
		else if(pos>n_o_n)
		{
			Node<T> *temp = head;
			while(temp->next!=NULL)
			{
				temp = temp->next;
			}
			temp->next = node1;
			node1->next = NULL;
		}
		else
		{
			Node<T> *temp = head;
			int i;
			for(i=0;i<pos-2;i++)
			{
				temp = temp->next;
			}
			node1->next = temp->next;
			temp->next = node1;
		}
	}
}

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

template<class T>
void linkedL<T> :: delete_node(T key)
{
	Node<T> *temp = head;
	Node<T> *prev = NULL;
	while(temp!=NULL && temp->data!=key)
	{
		prev = temp;
		temp = temp->next;
	}
	if(temp==NULL)
	{
		cout<<"Node not found."<<endl;
	}
	else if(temp == head)
	{
		head = temp->next;
		delete temp;
	}
	else if(temp->next==NULL)
	{
		prev->next = NULL;
		delete temp;
	}
	else
	{
		prev->next = temp->next;
		delete temp;
	}
}

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

template<class T>
Node<T>* linkedL<T> :: getHead()
{
	return head;
}


