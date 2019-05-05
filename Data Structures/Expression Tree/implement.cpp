/*
 *  Author: Shubham Yewalekar
 *  Div : SE 9 H9
 *  Roll No : 23182
 *  File Name : Client File
 */

#include<iostream>
#include"expTree.cpp"

using namespace std;

int main()
{
	expTree<char> ET;
	ET.createTree();
	int ch,flag;

	do
	{
		cout<<"\n**********WELCOME TO MENU !**********\n";
		cout<<"Which operation do you want to perform : \n		1)In-Order Display\n";
		cout<<"		2)Pre-Order Display\n		3)Post-Order Display\n		4)Non-Recursive In-Order Display \n";
		cout<<"		5)Non-Recursive Pre-Order Display\n		6)Non-Recursive Post-Order Display\n";
		cout<<"Choice : ";
		cin>>ch;
		switch(ch)
		{
			case 1 :
				cout<<"\n**********IN-ORDER DISPLAY**********\n";
				cout<<"In-Order Expression : ";
				ET.inOrderDisplay(ET.getRoot());
				cout<<"\n-------------------------------------\n";
				break;
			case 2 :
				cout<<"\n**********PRE-ORDER DISPLAY**********\n";
				cout<<"Pre-Order Expression : ";
				ET.preOrderDisplay(ET.getRoot());
				cout<<"\n-------------------------------------\n";
				break;
			case 3 :
				cout<<"\n**********POST-ORDER DISPLAY**********\n";
				cout<<"Post-Order Expression : ";
				ET.postOrderDisplay(ET.getRoot());
				cout<<"\n-------------------------------------\n";
				break;
			case 4 :
				cout<<"\n**********NON-RECURSIVE IN-ORDER DISPLAY**********\n";
				cout<<"Non-Recursive In-Order Expression : ";
				ET.inOrderDisplay1();
				cout<<"\n-------------------------------------\n";
				break;
			case 5 :
				cout<<"\n**********NON-RECURSIVE PRE-ORDER DISPLAY**********\n";
				cout<<"Non-Recursive Pre-Order Expression : ";
				ET.preOrderDisplay1();
				cout<<"\n-------------------------------------\n";
				break;
			case 6 :
				cout<<"\n**********NON-RECURSIVE POST-ORDER DISPLAY**********\n";
				ET.postOrderDisplay1();
				cout<<"\n-------------------------------------\n";
				break;
		}
		cout<<"\nDo you want to continue : [Y-Press 1 / N- Press 0]\n";
		cin>>flag;
	}while(flag == 1);

	return 0;




}
