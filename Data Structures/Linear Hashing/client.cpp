/*
 *  Author: Shubham Yewalekar
 *  Div : SE 9 H9
 *  Roll No : 23182
 *  File Name : Client File
 */

#include<iostream>
using namespace std;
#include "hash.h"

int main()
{
	data ins;
	int temp;
	Hash h1;
	int flag,ch,flag1,flag2;
	bool check;
	do
	{
		cout<<"\nWhich operation do you want to perform : ";
		cout<<"\n		1)Insert Element\n		2)Search\n";
		cin>>ch;
		switch(ch)
		{
			case 1:
				flag = 1;
				h1.setHashTable();
				cout<<"\nWhich Hashing Technique do you want to implement : ";
				cout<<"\n		1)Chaining without replacement\n		2)Chaining With Replacement\n";
				cout<<"Choice : ";
				cin>>flag1;
				if(flag1 == 1)
				{
					while(flag == 1)
					{
						ins = h1.getData();
						h1.hashWithoutReplacement(ins);
						cout<<"\nIndex    Name          Mobile No   Chain\n";
						h1.displayHashTable();
						cout<<"Do you want to add another record : ";
						cin>>flag;
					}
				}
				else if(flag1 == 2)
				{
					while(flag == 1)
					{
						ins = h1.getData();
						h1.hashWithReplacement(ins);
						cout<<"\nIndex    Name          Mobile No   Chain\n";
						h1.displayHashTable();
						cout<<"Do you want to add another record : ";
						cin>>flag;
					}
				}
				break;
			case 2:
				check = h1.search(&temp);
				if(check == true)
				{
					cout<<"\nENTRY FOUND IN HASH TABLE AT INDEX '"<<temp<<"'"<<endl;

				}
				else
					cout<<"\nENTRY NOT FOUND IN HASH TABLE\n";
				break;
		}
		cout<<"Do you want to continue[Y-1/N-0] : ";
		cin>>flag2;
	}while(flag2 == 1);
	return 0;
}
