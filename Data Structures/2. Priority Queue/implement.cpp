/*
 * File Name - prQueue.cpp
 * Author: Shubham Yewalekar
 * Roll No - 23182 SE 9 H9
 * Description - Client File
 */

#include"prQueue.h"
#include"linkedL.h"
#include<iostream>

using namespace std;

int main()
{
	int flag,choice,check,*check1;
	prQueue prQ;//object of class prQueue
	data1 temp;
	do
	{
		cout<<"\n**********WELCOME TO THE MENU!**********\n";
		cout<<"\nWhich Operation do you want to perform : \n			1)Add a New Entry\n			2)Call the next patient\nChoice : ";
		cin>>choice;
		switch(choice)
		{
			case 1 :
				cout<<"\n************GET DATA************\n";
				check1 = temp.getdata();//input data
				check = temp.isValid();//check for valid data
				if(check==0)
				{
					prQ.enqueue(temp);//if valid data,enter the data in queue according to priority
					cout<<"Entry Registered Successfully!";
				}
				else//invalid data error message display
				{
					(*check1)--;
					if(check==1)
					{
						cout<<"\nERROR : INVALID NAME\n";
					}
					else if(check==2)
					{
						cout<<"\nERROR : INVALID AGE\n";
					}
					else if(check==3)
					{
						cout<<"\nERROR : INVALID PRIORITY\n";
					}
				}
				cout<<"\n---------------------------------------\n";
				break;
			case 2 :
				cout<<"\n************NEXT PATIENT************\n";
				temp = prQ.dequeue();//remove the next patient from queue according to priority
				cout<<"Next Patient Is :\n";
				cout<<"\nPatientID   Name                Age    Disease             Priority\n";
				temp.showdata();//display patient data
				cout<<"\n---------------------------------------\n";
				break;
		}
		cout<<"\n\nDo you want to continue (Yes - Press 1/No- Press 0) : ";
		cin>>flag;
	}while(flag==1);
}

