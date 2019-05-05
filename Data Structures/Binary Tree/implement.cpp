/*
 *  Author: Shubham Yewalekar
 *  Div : SE 9 H9
 *  Roll No : 23182
 *  File Name : Client File
 */

#include<iostream>
using namespace std;
#include"binTree.cpp"

int main()
{
	int choice,flag,data,check;
	Node1<int> *temp = NULL;
	binTree<int> b1;//binary tree object
	cout<<"\n**********CREATION OF BINARY TREE**********\n\n";
	b1.createTree(b1.getRoot());
	cout<<"\n---------------------------------------------------------------------------\n";
	do
	{
		cout<<"\n**********WELCOME TO THE MENU**********\n ";
		cout<<"Which operation do you want to perform :\n		1)Recursive Display\n		2)Non-Recursive Display\n";
		cout<<"		3)Breadth-Wise Display\n		4)Insert Tree\n";
		cout<<" 		5)Copy Tree\n		6)Display Leaf Nodes\n		7)Height of Tree\n";
		cout<<"Choice : ";
		cin>>choice;
		switch(choice)
		{
			case 1 :
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
			case 2 :
				cout<<"\n***** NON-RECURSIVE DISPLAY *****\n";
				cout<<"\n-----------------------------------------------\n";
				cout<<"In Order Non-Recursive Traversal : ";
				b1.inOrderDisplay1();
				cout<<"\n-----------------------------------------------\n";
				cout<<"\n-----------------------------------------------\n";
				cout<<"Pre Order Non-Recursive Traversal : ";
				b1.preOrderDisplay1();
				cout<<"\n-----------------------------------------------\n";
				cout<<"\n-----------------------------------------------\n";
				cout<<"Post Order Non-Recursive Traversal : ";
				b1.postOrderDisplay1();
				cout<<"\n-----------------------------------------------\n";
				break;
			case 3 :
				cout<<"\n-----------------------------------------------\n";
				cout<<"Breadth-Wise Traversal : ";
				b1.breadthDisplay();
				cout<<"\n-----------------------------------------------\n";
				break;
			case 4:
				cout<<"\n-----------------------------------------------\n";
				cout<<"Enter the data you want to insert in the tree : ";
				cin>>data;
				cout<<"\nAvailable Nodes : ";
				b1.inOrderDisplay(b1.getRoot());
				cout<<"\n------------------------------------------------\n";

				check = b1.insert(data,0);

				if(check == 1)
				{
					cout<<"In Order Traversal : ";
					b1.inOrderDisplay(b1.getRoot());
				}
				cout<<"\n-----------------------------------------------\n";
				break;
			case 5:
				cout<<"\n-----------------------------------------------\n";
				cout<<"\nTree Copied Successfully!\n";
				temp = b1.copyTree(b1.getRoot(),1,NULL);
				cout<<"Enter the data you want to insert in the tree : ";
				cin>>data;
				cout<<"\nAvailable Nodes : ";
				b1.inOrderDisplay(temp);
				cout<<"\n------------------------------------------------\n";

				check = b1.insert(data,1);
				cout<<"\n-----------------------------------------------\n";
				cout<<"Original Tree In Order Non-Recursive Traversal : ";
				b1.inOrderDisplay(b1.getRoot());
				cout<<"\n-----------------------------------------------\n";
				cout<<"Copy Tree In Order Non-Recursive Traversal : ";
				b1.inOrderDisplay(temp);
				cout<<"\n-----------------------------------------------\n";
				break;
			case 6:
				cout<<"\n-----------------------------------------------\n";
				cout<<"Leaf Nodes : ";
				b1.displayLeaf(b1.getRoot());
				cout<<"\n-----------------------------------------------\n";
				break;
			case 7:
				cout<<"\n-----------------------------------------------\n";
				cout<<"Height : ";
				cout<<b1.findHeight(b1.getRoot());
				cout<<"\n-----------------------------------------------\n";
				break;
		}
		cout<<"\nDo you want to continue [Y - Press 1/N - Press 0] : ";
		cout<<"\nChoice : ";
		cin>>flag;
	}while(flag == 1);
	return 0;
}
