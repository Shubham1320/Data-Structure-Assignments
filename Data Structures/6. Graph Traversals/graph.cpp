/*
 *  Author: Shubham Yewalekar
 *  Div : SE 9 H9
 *  Roll No : 23182
 *  File Name : Graph Implementation file
 */

#include<string.h>
#include "graph.h"
#include <iostream>
#include <ctime>
#include<stack>
#include<queue>
#include<iomanip>
using namespace std;

//node1 class functions
Node1 :: Node1()
{
	ID = 0;
	name = NULL;
	d1.day = 0;
	d1.month = 0;
	d1.year = 0;
	next = NULL;
	down = NULL;
}

//setters
void Node1 :: setData(int temp)
{
	ID = temp;
	char* name1 = new char[20];
	cout<<"\n-----DATA ENTRY-----\n";
	cout<<"Name : ";
	cin>>name1;
	int len = strlen(name1);
	name = new char[len];
	strcpy(name,name1);
	delete []name1;
	cout<<"Data of Birth : \n";
	cout<<"Date : ";
	cin>>d1.day;
	cout<<"Month : ";
	cin>>d1.month;
	cout<<"Year : ";
	cin>>d1.year;
	cout<<"\n----------------------------\n";
}

void Node1 :: setNext(Node2 *temp)
{
	next = temp;
}

void Node1 :: setDown(Node1 *temp)
{
	down = temp;
}

//getters
char* Node1 :: getName()
{
	return this->name;
}

DOB Node1 :: getDOB()
{
	return this->d1;
}

Node2* Node1 :: getNext()
{
	return this->next;
}

Node1* Node1 :: getDown()
{
	return this->down;
}

int Node1 :: getID()
{
	return this->ID;
}

Node1 :: ~Node1()
{
	delete []name;
	delete next;
	delete down;
}
//node1 class function ends

//node2 class functions
Node2 :: Node2()
{
	name = NULL;
	next = NULL;
	address = NULL;
	no_comments = 0;
}

//setters
void Node2 :: setDat()
{
	char *name1 = new char[20];
	int len;
	cout<<"\nEnter the name of friend : ";
	cin>>name1;
	len = strlen(name1);
	name = new char[len];
	strcpy(name,name1);
	cout<<"Enter number of comments : ";
	cin>>no_comments;
}

void Node2 :: setDat1(char *name1,char *name2)
{
	name = name1;
	cout<<"Enter number of comments of "<<name1<<" on post of "<<name2<<" : ";
	cin>>no_comments;
}

void Node2 :: setDat2(char *name1,int ncomments)
{
	name = name1;
	no_comments = ncomments;
}

void Node2 :: setNext(Node2* temp)
{
	next = temp;
}

void Node2 :: setComments(int ncomments)
{
	no_comments = ncomments;
}

void Node2 :: setAdd(char* temp,Node1 *temp1)
{
	while(strcmp(temp1->getName(),temp) != 0)
	{
		temp1 = temp1->getDown();
	}
	address = temp1;
}

//getters
char* Node2 :: getName()
{
	return this->name;
}

int Node2 :: getComments()
{
	return this->no_comments;
}

Node2* Node2 :: getNext()
{
	return this->next;
}


Node1* Node2 :: getAdd()
{
	return this->address;
}

//node2 class functions ends

//graph class function starts
graph :: graph()
{
	root = NULL;
	no_entries = 0;
}

void graph :: setRoot(Node1* temp)
{
	root = temp;
}

Node1* graph :: getRoot()
{
	return this->root;
}

//function to create adjacency list
void graph :: createAdjList()
{
	int flag=0;
	int count,i;
	bool check1;
	Node1* temp = NULL;
	Node1* prev = NULL;

	//get count of vertices
	cout<<"\nHow many entries do you want to add : ";
	cin>>count;
	no_entries = count;

	//set the node1 nodes containing vertex info
	for(i=0;i<count;i++)
	{
		temp = new Node1;
		temp->setData(i+1);
		check1 = validateVertex(temp);
		if(check1 == false)
		{
			i--;
			continue;
		}

		if(i == 0)
		{
			root = temp;
		}
		else
		{
			prev->setDown(temp);
		}
		prev = temp;
	}

	i=0;
	temp = root;
	while(i<count)
	{
		bool check2;
		int check = 0;
		Node2* temp1 = NULL;
		Node2* temp2 = NULL;
		Node2* prev1 = NULL;
		//get friends for every vertex
		cout<<"\nCurrent Node : "<<temp->getName()<<endl;
		do
		{
			temp1 = new Node2;
			temp1->setDat();
			check2 = validateFriends(temp1,temp);
			if(check2 == false)
			{
				cout<<"\nDo you want to enter another friend [1-Y/0-N] : ";
				cin>>flag;
				if(flag == 1)
					continue;
				else
					break;
			}

			if(check == 0 && temp->getNext() == NULL)
			{
				temp->setNext(temp1);
				check ++;
			}
			else if(temp->getNext()!=NULL)
			{
				temp2 = temp->getNext();
				while(temp2 ->getNext() != NULL)
				{
					temp2 = temp2->getNext();
				}
				temp2->setNext(temp1);
			}
			else
			{
				prev1->setNext(temp1);
			}
			prev1 = temp1;
			temp1->setAdd(temp1->getName(),root);
			adjustList(temp1->getAdd(),temp);


			cout<<"\nDo you want to enter another friend [1-Y/0-N] : ";
			cin>>flag;
		}while(flag==1);
		temp = temp->getDown();
		i++;
	}
}

//function to adjust symmetry of graph
void graph :: adjustList(Node1* temp,Node1* temp1 )
{
	Node2* insNode = new Node2;
	Node2* temp2;
	insNode->setDat1(temp1->getName(),temp->getName());
	temp2 = temp->getNext();
	if(temp2 == NULL)
	{
		temp->setNext(insNode);
	}
	else
	{
		while(temp2->getNext() != NULL && strcmp(temp2->getName(),temp1->getName()) != 0)
		{
			temp2 = temp2->getNext();
		}
		if(strcmp(temp2->getName(),temp1->getName()) == 0)
		{
			cout<<"\nNode Already Present\n";
		}
		else
			temp2->setNext(insNode);
	}
	insNode->setAdd(insNode->getName(),root);
}

//function to find who has birthday today based on DFS
void graph :: DFS_birthday(DOB date)
{
	int i;
	for(i=0;i<no_entries+1;i++)
	{
		visited[i] = 0;
	}
	stack<Node1 *> stk;
	Node1* temp = root;
	stk.push(temp);
	Node2* Ntemp1 = NULL;
	while(stk.empty() == 0)
	{
		temp = stk.top();
		stk.pop();
		Ntemp1 = temp->getNext();
		if(visited[temp->getID()] == 0)
		{
			if(temp->getDOB().day == date.day && temp->getDOB().month == date.month)
			{
				cout<<"\n"<<temp->getName()<<" is having "<<date.year-temp->getDOB().year<<" th birthday today..Happy Birthday!!!\n";
			}
			visited[temp->getID()] = 1;
		}

		while(Ntemp1 != NULL)
		{
			if(visited[Ntemp1->getAdd()->getID()] == 0)
			{
				stk.push(Ntemp1->getAdd());
			}
			Ntemp1 = Ntemp1->getNext();
		}
	}
}

//function to find who has maximum friends using BFS
void graph :: BFS_maxfriends()
{
	int i,count=0,countMax=0;
	char *max;
	for(i=0;i<no_entries+1;i++)
	{
		visited[i] = 0;
	}
	queue <Node1 *> Q;
	Node1* temp = root;
	Q.push(temp);
	max = temp->getName();
	temp = NULL;
	Node2* Ntemp1 = NULL;
	while(Q.empty() == 0)
	{
		temp = Q.front();
		Q.pop();
		Ntemp1 = temp->getNext();
		if(visited[temp->getID()] == 0)
		{
			visited[temp->getID()] = 1;
		}
		count = 0;
		while(Ntemp1 != NULL)
		{
			count++;
			if(visited[Ntemp1->getAdd()->getID()] == 0)
			{
				Q.push(Ntemp1->getAdd());
			}
			Ntemp1 = Ntemp1->getNext();
		}
		if(count>countMax)
		{
			countMax = count;
			max = temp->getName();
		}
	}
	cout<<"Maximum friends : ";
	cout<<max<<" has "<<countMax<<" friends\n";
}

void graph :: checkBirthday()
{
	DOB temp;
	time_t t = time(NULL);
	tm* timePtr = localtime(&t);
	temp.day = timePtr->tm_mday ;
	temp.month = (timePtr->tm_mon)+1 ;
	temp.year = (timePtr->tm_year)+1900;
	DFS_birthday(temp);
}

bool graph :: validateVertex(Node1 *temp1)
{
	if(root == NULL)
	{
		return true;
	}
	Node1* temp = root;
	char* temp2 = temp1->getName();
	while(strcmp(temp->getName(),temp2) != 0)
	{
		temp = temp->getDown();
		if(temp == NULL)
		{
			break;
		}
	}
	if(temp != NULL)
	{
		cout<<"\nERROR :: DUPLICATE VERTEX NOT ALLOWED\n";
		return false;
	}
	return true;

}

bool graph :: validateFriends(Node2 *temp,Node1 *temp1)
{

	Node2* temp2 = temp1->getNext();
	if(temp2 == NULL)
		return true;
	if(strcmp(temp1->getName(),temp->getName()) == 0)
	{
		cout<<"\nERROR :: INVALID FRIEND NAME\n";
		return false;
	}
	while(strcmp(temp2->getName(),temp->getName()) != 0)
	{
		temp2 = temp2->getNext();
		if(temp2 == NULL)
		{
			break;
		}
	}
	if(temp2 != NULL)
	{
		cout<<"\nERROR :: DUPLICATE FRIEND NAME NOW ALLOWED\n";
		return false;
	}
	temp1 = root;
	while(strcmp(temp1->getName(),temp->getName()) != 0)
	{
		temp1 = temp1->getDown();
		if(temp1 == NULL)
		{
			break;
		}
	}
	if(temp1 == NULL)
	{
		cout<<"\nERROR :: INVALID FRIEND NAME\n";
		return false;
	}
	return true;
}

//function to make friend of a vertex
void graph :: makeFriend(char* vertex,char* friend1)
{
	Node2 *insNode = new Node2;
	insNode->setDat1(friend1,vertex);
	Node1 *temp1;
	Node2 *temp2;
	temp1 = root;
	while(temp1 != NULL && strcmp(temp1->getName(),vertex) != 0)
	{
		temp1 = temp1->getDown();
	}
	if(temp1 == NULL)
		cout<<"\nERROR :: Data Entry Not Found\n";
	else
	{
		bool check1 = validateFriends(insNode,temp1);
		if(check1 == true)
		{
			if(temp1->getNext()!=NULL)
			{
				temp2 = temp1->getNext();
				while(temp2->getNext() != NULL )
				{
					temp2 = temp2->getNext();
				}
				temp2->setNext(insNode);
			}
			else
				temp1->setNext(insNode);
			insNode->setAdd(insNode->getName(),root);
			adjustList(insNode->getAdd(),temp1);
		}
	}
}

//function to add new vertex
void graph :: addNewEntry()
{
	Node1 *loop = root;
	Node1 *insNode = new Node1;
	insNode->setData(no_entries+1);
	bool check1 = validateVertex(insNode);
	if(check1 == true)
	{
		while(loop->getDown() != NULL)
		{
			loop = loop->getDown();
		}
		no_entries++;
		loop->setDown(insNode);
	}
}

//function to display adjacency list
void graph :: displayAdjList()
{
	Node1 *temp1 = root;
	Node2 *temp2 ;
	cout<<"\nName           Friends\n";
	while(temp1 != NULL)
	{
		cout<<left<<setw(15)<<temp1->getName();
		temp2 = temp1->getNext();
		while(temp2 != NULL)
		{
			cout<<temp2->getName()<<"  ";
			temp2 = temp2->getNext();
		}
		cout<<"\n";
		temp1 = temp1->getDown();
	}
}

//function to find who has maximum and minimum comments
void graph :: findMaxMinComments()
{
	int i=0;
	Node1 *temp1 = root;
	Node2 *temp2 = NULL;
	while(temp1 != NULL)
	{
		arr[i].setDat2(temp1->getName(),0);
		i++;
		temp1 = temp1->getDown();
	}
	temp1 = root;
	while(temp1 != NULL)
	{
		temp2 = temp1->getNext();
		while(temp2 != NULL)
		{
			arr[temp2->getAdd()->getID() - 1].setComments(temp2->getComments()+arr[temp2->getAdd()->getID() - 1].getComments());
			temp2 = temp2->getNext();
		}
		temp1 = temp1->getDown();
	}

	int max = 0;
	int min = 0;
	for(i=0;i<no_entries;i++)
	{
		if(arr[i].getComments() > arr[max].getComments())
		{
			max = i;
		}
		if(arr[i].getComments() < arr[min].getComments())
		{
			min = i;
		}
	}
	cout<<"\nMaximum Comments : \n";
	cout<<arr[max].getName()<<"  ==>  "<<arr[max].getComments();
	cout<<"\nMinimum Comments : \n";
	cout<<arr[min].getName()<<"  ==>  "<<arr[min].getComments()<<endl;
}
//graph class functions ends
