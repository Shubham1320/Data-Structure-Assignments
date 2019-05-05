/*
 *  Author: Shubham Yewalekar
 *  Div : SE 9 H9
 *  Roll No : 23182
 *  File Name : Client File
 */

#include<iostream>
using namespace std;
#include"binSearchTree.cpp"

int main()
{
	int data;
	int flag,ch;
	bool check;
	Node1<int> *temp;
	temp = new Node1<int>;
	binSTree<int> b1;
	cout<<"\n********** CREATE TREE **********\n";
	b1.createTree();
	cout<<"\n---------------------------------\n";
	do
	{
		cout<<"\n********** WELCOME TO THE MENU ! **********\n";
		cout<<"\nWhich operation do you want to perform : \n";
		cout<<"		1) Insert in Tree Recursive\n";
		cout<<"		2) Insert in Tree Non-Recursive\n";
		cout<<"		3) Search in Tree Recursive\n";
		cout<<"		4) Search in Tree Non-Recursive\n";
		cout<<"		5) Delete Node Recursive\n";
		cout<<"		6) Delete Node Non-Recursive\n";
		cout<<"		7) Display Leaf\n";
		cout<<"		8) Find Height\n";
		cout<<"		9) Mirror Recursive\n";
		cout<<"		10) Mirror Non-Recursive\n";
		cout<<"		11) Display Recursive\n";
		cout<<"Choice : ";
		cin>>ch;
		switch(ch)
		{
			case 1 :
				cout<<"\n***** INSERT IN TREE (RECURSIVE) *****\n";
				cout<<"\nEnter the data you want to insert :";
				cin>>data;
				b1.insertBST(b1.getRoot(),data,NULL,2);
				cout<<"\nData Inserted Successfully ! \n";
				cout<<"\n--------------------------------------\n";
				break;
			case 2 :
				cout<<"\n***** INSERT IN TREE (NON-RECURSIVE) *****\n";
				cout<<"\nEnter the data you want to insert :";
				cin>>data;
				b1.insert(data);
				cout<<"\nData Inserted Successfully ! \n";
				cout<<"\n--------------------------------------\n";
				break;
			case 3 :
				cout<<"\n***** SEARCH IN TREE (RECURSIVE) *****\n";
				cout<<"\nEnter the data you want to search :";
				cin>>data;
				temp = b1.searchBST(b1.getRoot(),data);
				if(temp == NULL)
				{
					cout<<"\nDATA NOT FOUND\n";
				}
				else
				{
					cout<<"\nDATA FOUND AT THE ADDRESS : "<<temp;
				}
				cout<<"\n---------------------------------------\n";
				break;
			case 4 :
				cout<<"\n***** SEARCH IN TREE (NON-RECURSIVE) *****\n";
				cout<<"\nEnter the data you want to search :";
				cin>>data;
				temp = b1.search(data);
				if(temp != NULL)
				{
					cout<<"\nDATA FOUND AT THE ADDRESS : "<<temp;
				}
				cout<<"\n---------------------------------------\n";
				break;
			case 5 :
				cout<<"\n***** DELETE NODE *****\n";
				cout<<"\nEnter the data you want to delete :";
				cin>>data;
				check = b1.deleteBST(b1.getRoot(),data,NULL,-1);
				if(check == false)
				{
					cout<<"\nDATA NOT FOUND AND HENCE CANNOT BE DELETED\n";
				}
				else if(check == true)
				{
					cout<<"\nNODE DELETED SUCCESSFULLY !\n";
				}
				cout<<"\n---------------------------------------\n";
				break;
			case 6 :
				cout<<"\n***** DELETE NODE *****\n";
				cout<<"\nEnter the data you want to delete :";
				cin>>data;
				check = b1.deleteNode(data,0);
				if(check == false)
				{
					cout<<"\nDATA NOT FOUND AND HENCE CANNOT BE DELETED\n";
				}
				else if(check == true)
				{
					cout<<"\nNODE DELETED SUCCESSFULLY !\n";
				}
				cout<<"\n---------------------------------------\n";
				break;
			case 7 :
				cout<<"\n***** DISPLAY LEAF NODE *****\n";
				cout<<"\nLeaf Nodes : ";
				b1.displayLeaf(b1.getRoot());
				cout<<"\n---------------------------------------\n";
				break;
			case 8 :
				cout<<"\n***** FIND HEIGHT *****\n";
				cout<<"\nHeight : ";
				cout<<b1.findHeight(b1.getRoot());
				cout<<"\n---------------------------------------\n";
				break;
			case 9 :
				cout<<"\n***** MIRROR (RECURSIVE) *****\n";
				cout<<"\n-----ORIGINAL TREE-----\n";
				cout<<"\nIn-Order Display :";
				b1.inOrderDisplay(b1.getRoot());
				b1.mirrorBST(b1.getRoot());
				cout<<"\n\nMirror Tree created successfully ! \n";
				cout<<"\n-----MIRROR TREE-----\n";
				cout<<"\nIn-Order Display :";
				b1.inOrderDisplay(b1.getRoot());
				b1.mirrorBST(b1.getRoot());
				cout<<"\n---------------------------------------\n";
				break;
			case 10 :
				cout<<"\n***** MIRROR (NON-RECURSIVE) *****\n";
				cout<<"\n-----ORIGINAL TREE-----\n";
				cout<<"\nIn-Order Display :";
				b1.inOrderDisplay(b1.getRoot());
				b1.mirrorItr();
				cout<<"\n\nMirror Tree created successfully ! \n";
				cout<<"\n-----MIRROR TREE-----\n";
				cout<<"\nIn-Order Display :";
				b1.inOrderDisplay(b1.getRoot());
				b1.mirrorItr();
				cout<<"\n---------------------------------------\n";
				break;
			case 11 :
				cout<<"\n***** RECURSIVE DISPLAY *****\n";
				cout<<"\n-----------------------------------------------\n";
				cout<<"In Order Traversal : ";
				b1.inOrderDisplay(b1.getRoot());
				cout<<"\n-----------------------------------------------\n";
				cout<<"\n-----------------------------------------------\n";
				cout<<"Pre Order Traversal : ";
				b1.preOrderDisplay(b1.getRoot());
				cout<<"\n-----------------------------------------------\n";
				cout<<"\n-----------------------------------------------\n";
				cout<<"Post Order Traversal : ";
				b1.postOrderDisplay(b1.getRoot());
				cout<<"\n-----------------------------------------------\n";
				break;
			default :
				cout<<"\nINVALID INPUT\n";
				break;
		}
		cout<<"\nDo you want to continue [Y-1/N-0] : ";
		cin>>flag;
	}while(flag == 1);
	return 0;
}

