/*
 *  Author: Shubham Yewalekar
 *  Div : SE 9 H9
 *  Roll No : 23182
 *  File Name : Client File
 */

#include"DAF.h"
using namespace std;
#include<iostream>

int main()
{
	data temp;
	DAF d1;
	int flag,ch,key;
	d1.createFile();
	do
	{
		cout<<"\nWhich Operation do you want to perform : ";
		cout<<"\n		1)Insert Record";
		cout<<"\n		2)Modify Record";
		cout<<"\n		3)Search Record";
		cout<<"\n		4)Delete Record";
		cout<<"\n		5)Display File";
		cout<<"\nCHOICE : ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				temp = d1.getData();
				d1.insertRecord(temp);
				break;
			case 2:
				cout<<"\nRoll-No : ";
				cin>>key;
				d1.modifyRecord(key);
				break;
			case 3:
				cout<<"\nRoll-No : ";
				cin>>key;
				temp = d1.searchRecord(key);
				cout<<"\nRECORD : ";
				cout<<"\nNAME : "<<temp.name;
				cout<<"\nROLL-NO : "<<temp.rollNo;
				cout<<"\nDEPARTMENT : "<<temp.department;
				cout<<"\nYEAR : "<<temp.year;
				cout<<"\nCGPA : "<<temp.CGPA;
				break;
			case 4:
				cout<<"\nRoll-No : ";
				cin>>key;
				d1.deleteRecord(key);
				break;
			case 5:
				d1.readFile();
				break;
		}
		cout<<"\nDo you want to continue [Y-1/N-0] : ";
		cin>>flag;
	}while(flag == 1);

	return 0;
}



