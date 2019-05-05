/*
 *  Author: Shubham Yewalekar
 *  Div : SE 9 H9
 *  Roll No : 23182
 *  File Name : Binary Search Tree Implementation File
 */

#include <iostream>
#include "binSearchTree.h"
#include "queue.cpp"

using namespace std;

//setters of node1 class
template<class T>
void Node1<T> :: setData(T data)
{
	this->data = data;
}

template<class T>
void Node1<T> :: setLchild(Node1 *temp)
{
	lchild = temp;
}

template<class T>
void Node1<T> :: setRchild(Node1 *temp)
{
	rchild = temp;
}

//getters of node1 class
template<class T>
T Node1<T> :: getData()
{
	return data;
}

template<class T>
Node1<T>* Node1<T> :: getLchild()
{
	return lchild;
}

template<class T>
Node1<T>* Node1<T> :: getRchild()
{
	return rchild;
}

//constructor of node1
template<class T>
Node1<T> :: Node1()
{
	lchild = NULL;
	rchild = NULL;
}

//constructor of binSTree class
template<class T>
binSTree<T> :: binSTree()
{
	root = NULL;
	dltRoot = NULL;
}

//non-recursive insert function
template<class T>
void binSTree<T> :: insert(T data)
{
	Node1<T>* parent = NULL;
	Node1<T>* temp = new Node1<T>;
	temp->setData(data);
	if(root == NULL)
	{
		root = temp;
	}
	else
	{
		Node1<T>* pWalk = root;
		while(pWalk != NULL)
		{
			parent = pWalk;
			if(temp->getData() < pWalk->getData())
			{
				//move left if data is less
				pWalk = pWalk->getLchild();
			}
			else if(temp->getData() > pWalk->getData())
			{
				//move right if data is greater
				pWalk = pWalk->getRchild();
			}
			else
				cout<<"\nERROR : DUPLICATE ENTRIES NOT ALLOWED\n";
		}
		//set appropriate links
		if(temp->getData() < parent->getData())
		{
			parent->setLchild(temp);
		}
		else
			parent->setRchild(temp);
	}
}

//recursive insert function
template<class T>
void binSTree<T> :: insertBST(Node1<T> *temp,T data1,Node1<T> *prev,int flag)
{
	if(temp == NULL)
	{
		temp = new Node1<T>;
		temp->setData(data1);
		//set appropriate links
		if(flag == 0)
		{
			prev->setLchild(temp);
		}
		else if(flag == 1)
		{
			prev->setRchild(temp);
		}
		if(root == NULL)
		{
			//set root
			root = temp;
		}
	}
	else
	{
		if(data1 < temp->getData())
		{
			//move left is data is less
			insertBST(temp->getLchild(),data1,temp,0);
		}
		else if(data1 > temp->getData())
		{
			//move right if data is greater
			insertBST(temp->getRchild(),data1,temp,1);
		}
	}
}

//non-recursive search function
template<class T>
Node1<T>* binSTree<T> :: search(T data1)
{
	Node1<T> *temp = NULL;
	temp = root;
	while(temp != NULL)
	{
		if(data1 == temp->getData())
		{
			//return data found
			return temp;
		}
		else if(data1 > temp->getData())
		{
			//move right
			temp = temp->getRchild();
		}
		else if(data1 < temp->getData())
		{
			//move left
			temp = temp->getLchild();
		}
	}
	cout<<"\nERROR :: DATA NOT FOUND\n";
	return NULL;
}

//recursive search function
template<class T>
Node1<T>* binSTree<T> :: searchBST(Node1<T>* temp,T data1)
{
	if(temp == NULL)
	{
		return NULL;
	}
	else if(temp->getData() == data1)
	{
		//return found data
		return temp;
	}
	else if(temp->getData() > data1)
	{
		//move left
		return searchBST(temp->getLchild(),data1);
	}
	else if(temp->getData() < data1)
	{
		//move right
		return searchBST(temp->getRchild(),data1);
	}
}

//delete recursive function
template<class T>
bool binSTree<T> :: deleteBST(Node1<T>* temp,T data1,Node1<T> *prev,int flag)
{
	Node1<T>* dltptr = NULL;
	//finding data to be deleted
	if(temp == NULL)
	{
		return false;
	}
	else if(data1<temp->getData())
	{
		return deleteBST(temp->getLchild(),data1,temp,0);
	}
	else if(data1>temp->getData())
	{
		return deleteBST(temp->getRchild(),data1,temp,1);
	}
	else
	{
		//leaf node deletion
		if(temp->getLchild() == NULL && temp->getRchild() == NULL)
		{
			if(flag == 0)
			{
				prev->setLchild(NULL);
				delete temp;
			}
			else if(flag == 1)
			{
				prev->setRchild(NULL);
				delete temp;
			}
		}
		//left is null node deletion
		else if(temp->getLchild() == NULL)
		{
			if(flag == 0)
			{
				prev->setLchild(temp->getRchild());
				delete temp;
			}
			else if(flag == 1)
			{
				prev->setRchild(temp->getRchild());
				delete temp;
			}
		}
		//right is null node deletion
		else if(temp->getRchild() == NULL)
		{
			if(flag == 0)
			{
				prev->setLchild(temp->getLchild());
				delete temp;
			}
			else if(flag == 1)
			{
				prev->setRchild(temp->getLchild());
				delete temp;
			}
		}
		//internal node deletion with both child using successor
		else
		{
			Node1<T> *dltptr = temp;
			prev = temp;
			temp = temp->getRchild();
			while(temp->getLchild() != NULL)
			{
				prev = temp;
				temp = temp->getLchild();
			}
			dltptr->setData(temp->getData());
			deleteBST(dltptr->getRchild(),temp->getData(),NULL,-1);
		}
		return true;
	}
}

//create tree function
template<class T>
void binSTree<T> :: createTree()
{
	T data;
	int flag;
	do
	{
		cout<<"\nEnter data you want to insert in tree : ";
		cin>>data;
		insert(data);
		cout<<"\nDo you want to insert another node [Y-1/N-0] :";
		cin>>flag;
	}while(flag == 1);
}

//getter
template<class T>
Node1<T>* binSTree<T> :: getRoot()
{
	return root;
}

//function to display leaf nodes
template<class T>
void binSTree<T> :: displayLeaf(Node1<T> *temp)
{
	if(root == NULL)
	{
		cout<<"Tree is Empty/n";
	}
	else
	{
		if(temp->getLchild()!=NULL || temp->getRchild() != NULL)
		{
			if(temp->getLchild() != NULL)
			{
				displayLeaf(temp->getLchild());
			}

			if(temp->getRchild() != NULL)
			{
				displayLeaf(temp->getRchild());
			}
		}
		else
		{
			//display leaf node data
			cout<<temp->getData()<<"  ";
		}
	}
}

//function to find height
template<class T>
int binSTree<T> :: findHeight(Node1<T> *temp)
{
	if(temp == NULL)
	{
		return 0;
	}
	else
	{
		return 1+max(findHeight(temp->getLchild()),findHeight(temp->getRchild()));
	}
}

//non-recursive mirror function
template<class T>
void binSTree<T> :: mirrorBST(Node1<T> *temp)
{
	Node1<T> *temp1 = NULL;
	if(temp != NULL)
	{
		//interchange left and right child of the node
		temp1 = temp->getRchild();
		temp->setRchild(temp->getLchild());
		temp->setLchild(temp1);
		//go left
		mirrorBST(temp->getLchild());
		//go right
		mirrorBST(temp->getRchild());
	}
}

//recursive mirror function
template<class T>
void binSTree<T> :: mirrorItr()
{
	Node1<T> *temp1 = NULL;
	Node1<T> *temp2 = NULL;
	queue<Node1<T> *> Q1(50);
	if(root == NULL)
	{
		cout<<"\nERROR : TREE NOT CREATED\n";
	}
	else
	{
		Q1.enqueue(root);
		while(Q1.isEmpty() == 0)
		{
			temp1 = Q1.dequeue();
			if(temp1->getLchild() == NULL && temp1->getRchild() == NULL)
			{
				continue;
			}
			if(temp1->getLchild() != NULL && temp1->getRchild() != NULL)
			{
				//interchange links
				temp2 = temp1->getRchild();
				temp1->setRchild(temp1->getLchild());
				temp1->setLchild(temp2);
				Q1.enqueue(temp1->getLchild());
				Q1.enqueue(temp1->getRchild());
			}
			else if(temp1->getLchild() == NULL)
			{
				//left link is null case
				temp1->setLchild(temp1->getRchild());
				temp1->setRchild(NULL);
				Q1.enqueue(temp1->getLchild());
			}
			else
			{
				//right link is null case
				temp1->setRchild(temp1->getLchild());
				temp1->setLchild(NULL);
				Q1.enqueue(temp1->getRchild());
			}
		}
	}
}

//recursive in-order display function
template<class T>
void binSTree<T> :: inOrderDisplay(Node1<T> *temp)
{
	if(root == NULL)
	{
		cout<<"Tree not created \n";
	}
	else
	{
		 if(temp->getLchild() != NULL)
		 {
			 inOrderDisplay(temp->getLchild());
		 }

		 cout<<temp->getData()<<" ";

		 if(temp->getRchild() != NULL)
		 {
			 inOrderDisplay(temp->getRchild());
		 }
	}
}

//recursive pre-order display function
template<class T>
void binSTree<T> :: preOrderDisplay(Node1<T> *temp)
{
	if(root == NULL)
	{
		cout<<"Tree not created \n";
	}
	else
	{
		 cout<<temp->getData()<<" ";

		 if(temp->getLchild() != NULL)
		 {
			 preOrderDisplay(temp->getLchild());
		 }

		 if(temp->getRchild() != NULL)
		 {
			 preOrderDisplay(temp->getRchild());
		 }
	}
}

//recursive post-order display function
template<class T>
void binSTree<T> :: postOrderDisplay(Node1<T> *temp)
{
	if(root == NULL)
	{
		cout<<"Tree not created \n";
	}
	else
	{
		 if(temp->getLchild() != NULL)
		 {
			 postOrderDisplay(temp->getLchild());
		 }

		 if(temp->getRchild() != NULL)
		 {
			 postOrderDisplay(temp->getRchild());
		 }

		 cout<<temp->getData()<<" ";
	}
}

//non-recursive delete function
template<class T>
bool binSTree<T> :: deleteNode(T data1,int flag1)
{
	Node1<T> *prev = NULL;
	Node1<T> *cur = root;
	if(flag1 == 1)
	{
		cur = dltRoot;
	}
	int flag;
	//find data to be deleted
	while(cur != NULL && cur->getData() != data1)
	{
		if(cur->getData()>data1)
		{
			prev = cur;
			cur = cur->getLchild();
			flag = 0;
		}
		else if(cur->getData()<data1)
		{
			prev = cur;
			cur = cur->getRchild();
			flag = 1;
		}
	}
	//data not found
	if(cur == NULL)
	{
		return false;
	}
	//data found
	else
	{
		//leaf node deletion and set links
		if(cur->getLchild() == NULL && cur->getRchild() == NULL)
		{
			if(flag == 0)
			{
				prev->setLchild(NULL);
			}
			else if(flag == 1)
			{
				prev->setRchild(NULL);
			}
			delete cur;
		}
		//left child is null case and set links
		else if(cur->getLchild() == NULL)
		{
			if(flag == 0)
			{
				prev->setLchild(cur->getRchild());
			}
			else if(flag == 1)
			{
				prev->setRchild(cur->getRchild());
			}
			delete cur;
		}
		//right child is null case and set links
		else if(cur->getRchild() == NULL)
		{
			if(flag == 0)
			{
				prev->setLchild(cur->getLchild());
			}
			else if(flag == 1)
			{
				prev->setRchild(cur->getLchild());
			}
			delete cur;
		}
		else
		{
			//internal node deletion and finding predecessor
			Node1<T> *dltptr = NULL;
			dltptr = cur;
			prev  = cur;
			cur = cur->getLchild();
			while(cur->getRchild() != NULL)
			{
				prev  = cur;
				cur = cur->getRchild();
			}
			dltptr->setData(cur->getData());
			dltRoot = dltptr->getLchild();
			deleteNode(cur->getData(),1);
		}
		return true;
	}

}

