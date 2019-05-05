/*
 *  Author: Shubham Yewalekar
 *  Div : SE 9 H9
 *  Roll No : 23182
 *  File Name : Client File
 */

#include <iostream>
#include "graph.h"
using namespace std;
#include <string.h>

int main()
{
	int flag,choice,len;
	char *name1,*name2,*temp1=new char[20],*temp2=new char[20];
	graph g1;
	g1.createAdjList();
	do
	{
		cout<<"\n\nWhich Operation do you want to perform : \n";
		cout<<"		1) Display Graph\n";
		cout<<"		2) Check Birthday\n";
		cout<<"		3) Check who has maximum friends\n";
		cout<<"		4) Check who has done maximum and minimum comments\n";
		cout<<"		5) Add new data entry\n";
		cout<<"		6) Make Friends\n";
		cout<<"CHOICE :";
		cin>>choice;
		switch(choice)
		{
			case 1 :
				cout<<"\nCREATED GRAPH : \n\n";
				g1.displayAdjList();
				break;
			case 2 :
				cout<<"\nBIRTHDAY LIST : \n\n";
				g1.checkBirthday();
				break;
			case 3 :
				cout<<"\nMAXIMUM FRIENDS : \n\n";
				g1.BFS_maxfriends();
				break;
			case 4 :
				cout<<"\nMAXIMUM AND MINIMUM COMMENTS : \n\n";
				g1.findMaxMinComments();
				break;
			case 5 :
				cout<<"\nNEW DATA ENTRY : \n\n";
				g1.addNewEntry();
				break;
			case 6 :
				cout<<"\nMAKE FRIENDS : \n\n";
				cout<<"\nENTER NAME OF PERSON SENDING FRIEND REQUEST :";
				cin>>temp1;
				len = strlen(temp1);
				name1 = new char[len];
				strcpy(name1,temp1);
				cout<<"\nENTER NAME OF PERSON TO WHOM FRIEND REQUEST IS TO SENT :";
				cin>>temp2;
				len = strlen(temp2);
				name2 = new char[len];
				strcpy(name2,temp2);
				g1.makeFriend(name1,name2);
				break;
			default :
				cout<<"\nINVALID INPUT\n";
		}
		cout<<"\n\nDo you want to continue[Y-1/N-0] : \n";
		cout<<"CHOICE : ";
		cin>>flag;
	}while(flag == 1);


	return 0;
}


