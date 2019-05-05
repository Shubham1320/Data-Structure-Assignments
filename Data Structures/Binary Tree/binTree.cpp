/*
 *  Author: Shubham Yewalekar
 *  Div : SE 9 H9
 *  Roll No : 23182
 *  File Name : Binary Tree Implementation File
 */

#include<iostream>
using namespace std;
#include"binTree.h"
#include"stackll.cpp"
#include"queue.cpp"

//setters
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

//getters
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

//node constructor
template<class T>
Node1<T> :: Node1()
{
	lchild = NULL;
	rchild = NULL;
}

//binary tree constructor
template<class T>
binTree<T> :: binTree()
{
	root = NULL;
	newRoot = NULL;
	count = 0;
}

//function to create binary tree
template<class T>
void binTree<T> :: createTree(Node1<T> *temp)
{
	int choice;
	Node1<T> *curNode = temp;
	if(root == NULL)
	{
		T dat;
		cout<<"Enter the data you want to enter in root node : ";
		cin>>dat;
		curNode = new Node1<T>;
		curNode->setData(dat);
		root = curNode;
		count++;
		createTree(curNode);
	}
	else
	{
		if(curNode->getLchild() == NULL)
		{
			cout<<"\nCurrent Node Data -> "<<curNode->getData()<<endl;
			cout<<"\nDo you want to enter data in the left child of the current node : [Press 0 - No / Press 1 - Yes]\n";
			cin>>choice;
			//insert data as left node
			if(choice == 0)
			{
				curNode->setLchild(NULL);
			}
			else if(choice > 0)
			{
				count++;
				Node1<T> *node1;
				T dat;
				cout<<"Enter the data you want to enter in left node : ";
				cin>>dat;
				node1 = new Node1<T>;
				curNode->setLchild(node1);
			    curNode->getLchild()->setData(dat);
			    createTree(curNode->getLchild());
			}
		}
		//insert data as right node
		if(curNode->getRchild() == NULL)
		{
			cout<<"Current Node Data -> "<<curNode->getData()<<endl;
			cout<<"\nDo you want to enter data in the right child of the current node : [Press 0 - No / Press 1 - Yes]\n";
			cin>>choice;
			if(choice == 0)
			{
				curNode->setRchild(NULL);
			}
			else if(choice > 0)
			{
				count++;
				Node1<T> *node1;
				T dat;
				cout<<"Enter the data you want to enter in right node : ";
				cin>>dat;
				node1 = new Node1<T>;
				curNode->setRchild(node1);
				curNode->getRchild()->setData(dat);
				createTree(curNode->getRchild());
			}
		}
	}
}

//getter
template<class T>
Node1<T>* binTree<T> :: getRoot()
{
	return root;
}

//recursive in order display
template<class T>
void binTree<T> :: inOrderDisplay(Node1<T> *temp)
{
	if(root == NULL)
	{
		cout<<"Tree not created \n";
	}
	else
	{
		//go left
		 if(temp->getLchild() != NULL)
		 {
			 inOrderDisplay(temp->getLchild());
		 }

		 //print
		 cout<<temp->getData()<<" ";

		 //go right
		 if(temp->getRchild() != NULL)
		 {
			 inOrderDisplay(temp->getRchild());
		 }
	}
}

//recursive pre order display
template<class T>
void binTree<T> :: preOrderDisplay(Node1<T> *temp)
{
	if(root == NULL)
	{
		cout<<"Tree not created \n";
	}
	else
	{
		//print
		 cout<<temp->getData()<<" ";

		 //go left
		 if(temp->getLchild() != NULL)
		 {
			 preOrderDisplay(temp->getLchild());
		 }

		 //go right
		 if(temp->getRchild() != NULL)
		 {
			 preOrderDisplay(temp->getRchild());
		 }
	}
}

//recursive post order display
template<class T>
void binTree<T> :: postOrderDisplay(Node1<T> *temp)
{
	if(root == NULL)
	{
		cout<<"Tree not created \n";
	}
	else
	{
		//go left
		 if(temp->getLchild() != NULL)
		 {
			 postOrderDisplay(temp->getLchild());
		 }
		 //go right
		 if(temp->getRchild() != NULL)
		 {
			 postOrderDisplay(temp->getRchild());
		 }
		 //print
		 cout<<temp->getData()<<" ";
	}
}

//non-recursive in order display
template<class T>
void binTree<T> :: inOrderDisplay1()
{
	Node1<T> *temp;
	temp = root;
	stack_ll<Node1<T>*> stack;
	if(temp == NULL)
	{
		cout<<"Empty Tree/n";
	}
	while(temp != NULL || stack.isEmpty() == 0)
	{
		while(temp != NULL)
		{
			//push into stack
			stack.push(temp);
			//go left
			temp = temp->getLchild();
		}
		if(stack.isEmpty() == 0)
		{
			//pop from stack
			temp = stack.pop();
			//print data
			cout<<temp->getData()<<"  ";
		}
		//go right
		temp = temp->getRchild();
	}
}

//npn-recursive pre order display
template<class T>
void binTree<T> :: preOrderDisplay1()
{
	Node1<T> *temp;
	temp = root;
	stack_ll<Node1<T>*> stack;
	if(temp == NULL)
	{
		cout<<"Empty Tree/n";
	}
	while(temp != NULL || stack.isEmpty() == 0)
	{
		while(temp != NULL)
		{
			//print data
			cout<<temp->getData()<<"  ";
			//push into stack
			stack.push(temp);
			//go left
			temp = temp->getLchild();
		}
		if(stack.isEmpty() == 0)
		{
			//pop from stack
			temp = stack.pop();
		}
		//go right
		temp = temp->getRchild();
	}
}

//non-recursive post order display
template<class T>
void binTree<T> :: postOrderDisplay1()
{
	int flag=0;
	Node1<T> *temp;
	temp = root;
	stack_ll<int> stack1;
	stack_ll<Node1<T>*> stack2;
	int i=0;
	while(temp != NULL)
	{
		//push into stack with 0
		stack2.push(temp);
		stack1.push(0);
		temp = temp->getLchild();
	}
	while(i<count)
	{
		temp = stack2.pop();
		flag = stack1.pop();
		if(flag == 1)
		{
			//print data
			cout<<temp->getData()<<"  ";
			i++;
		}
		else
		{
			//change int flag to 1 and push into stack again
			stack1.push(1);
			stack2.push(temp);
			//go right
			temp = temp->getRchild();
			//repeat the process for subtree
			while(temp != NULL)
			{
				stack2.push(temp);
				stack1.push(0);
				temp = temp->getLchild();
			}
		}
	}
}

//recursive breadth - wise display
template<class T>
void binTree<T> :: breadthDisplay()
{
	Node1<T> *temp = NULL;
	temp = root;
	queue<Node1<T>*> Q1(50);
	if(temp == NULL)
	{
		cout<<"Tree is Empty/n";
	}
	else
	{
		//insert into queue
		Q1.enqueue(temp);
		while(Q1.isEmpty() == 0)
		{
			//remove from queue
			temp = Q1.dequeue();
			//print data
			cout<<temp->getData()<<"  ";
			if(temp->getLchild() != NULL)
			{
				//insert left child into queue
				Q1.enqueue(temp->getLchild());
			}
			if(temp->getRchild() != NULL)
			{
				//insert right child into queue
				Q1.enqueue(temp->getRchild());
			}
		}
	}
}

//finding height of tree
template<class T>
int binTree<T> :: findHeight(Node1<T> *temp)
{
	if(temp == NULL)
	{
		return 0;
	}
	else
	{
		//find max of the left and right subtree
		return 1+max(findHeight(temp->getLchild()),findHeight(temp->getRchild()));
	}
}

//recursive display leaf nodes
template<class T>
void binTree<T> :: displayLeaf(Node1<T> *temp)
{
	if(root == NULL)
	{
		cout<<"Tree is Empty/n";
	}
	else
	{
		//not a leaf node
		if(temp->getLchild()!=NULL || temp->getRchild() != NULL)
		{
			//go left
			if(temp->getLchild() != NULL)
			{
				displayLeaf(temp->getLchild());
			}

			//go right
			if(temp->getRchild() != NULL)
			{
				displayLeaf(temp->getRchild());
			}
		}
		else
		{
			//print leaf node
			cout<<temp->getData()<<"  ";
		}
	}
}

//function to copy tree
template<class T>
Node1<T>* binTree<T> :: copyTree(Node1<T> *temp,int flag,Node1<T> *prev)
{
	Node1<T> *copy = NULL;
	if(temp != NULL)
	{
		//new node assigned and data copied
		copy = new Node1<T>;
		copy->setData(temp->getData());
		if(flag == 2)//set as left
		{
			if(prev != NULL)
			{
				prev->setLchild(copy);
			}
		}
		else if(flag ==3)//set as right
		{
			if(prev != NULL)
			{
				prev->setRchild(copy);
			}
		}
		if(temp->getLchild() != NULL)
		{
			//go left
			copyTree(temp->getLchild(),2,copy);
		}
		if(temp->getRchild() != NULL)
		{
			//go right
			copyTree(temp->getRchild(),3,copy);
		}
	}

	if(flag == 1)
	{
		//initialize new root
		newRoot = copy;
		return copy;
	}
}

//function to insert data in tree
template<class T>
int binTree<T> :: insert(T data,int flag1)
{
	int flag = 0,ch;
	T dat;
	Node1<T> *node = NULL;
	stack_ll<Node1<T>*> stack;
	Node1<T> *temp = NULL;
	if(flag1 == 0)
		temp = root;
	else if(flag1 == 1)
		temp = newRoot;
	//accept data to be entered
	cout<<"Enter the data of Parent Node : ";
	cin>>dat;
	while(temp != NULL || stack.isEmpty() == 0)
	{
		while(temp != NULL)
		{
			if(temp->getData() == dat)
			{
				flag = 1;
				break;
			}
			else
			{
				//push into stack
				stack.push(temp);
				//go left
				temp = temp->getLchild();
			}
		}
		if(flag == 0)
		{
			if(stack.isEmpty() == 0)
			{
				//pop from stack
				temp = stack.pop();
			}
			//go right
			temp = temp->getRchild();
		}
		else if(flag == 1)
			break;
	}
	if(flag == 1)
	{
		//parent node = leaf node
		if(temp->getLchild() == NULL && temp->getRchild() == NULL)
		{
			cout<<"Do you want to enter the new data as left child or right child of the parent node [L-Press 1/R-Press 2] : ";
			cin>>ch;
			if(ch == 1)
			{
				node = new Node1<T>;
				node->setData(data);
				temp->setLchild(node);
			}
			else if(ch == 2)
			{
				node = new Node1<T>;
				node->setData(data);
				temp->setRchild(node);
			}
		}
		//insert as left child
		else if(temp->getLchild() == NULL)
		{
			node = new Node1<T>;
			node->setData(data);
			temp->setLchild(node);
		}
		//insert as right child
		else if(temp->getRchild() == NULL)
		{
			node = new Node1<T>;
			node->setData(data);
			temp->setRchild(node);
		}
		else
		{
			cout<<"\nERROR : PARENT NODE DOES NOT HAVE A FREE SPACE TO INSERT DATA\n";
			return 0;
		}
	}
	return 1;
}

//non-recursive display leaf nodes
template<class T>
void binTree<T> :: displayLeaf1()
{
	Node1<T> *temp = NULL;
	temp = root;
	int i=0;
	stack_ll<Node1<T>*> stack;
	while(temp != NULL || stack.isEmpty() == 0)
	{
		while(temp != NULL)
		{
			stack.push(temp);
			temp = temp->getLchild();
		}
		if(stack.isEmpty() == 0)
		{
			temp = stack.pop();
		}
		if(temp->getRchild() == NULL && temp->getLchild() == NULL)
		{
			cout<<temp->getData()<<"  ";
			temp = NULL;
		}
		else if(temp->getRchild() != NULL)
		{
			temp = temp->getRchild();
		}
		else
		{

			temp = NULL;
		}
	}

}



