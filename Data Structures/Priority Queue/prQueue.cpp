/*
 * File Name - prQueue.cpp
 * Author: Shubham Yewalekar
 * Roll No - 23182 SE 9 H9
 * Description - Priority Queue Implementation
 */


#include<iostream>
#include"prQueue.h"
#include"linkedL.h"
#include<iomanip>

using namespace std;

/*
 	Default Constructor
 */

prQueue :: prQueue()//constructor
{
	front1 = NULL;
	rear1 = NULL;
	front2 = NULL;
	rear2 = NULL;
	front3 = NULL;
	rear3 = NULL;
	highPr = 0;
	lowPr = 0;
	midPr = 0;
	totalCnt = 0;
}

/*
 	 Function to insert new node in queue according to priority
 */

void prQueue :: enqueue(data1 temp)//insert data in queue
{
	Node<data1> *temp1;
	int hPr = 1;//initial position of insertion
	int lPr = 1;
	int mPr = 1;
	if(temp.priority == 'H')
	{
		L.insert(hPr+highPr,temp);//insert data at calculated position
		highPr ++;
		totalCnt++;
		if(front1 == NULL)
		{
			front1 = L.getHead();//set front and rear pointers of high priority Q
			rear1 = front1;
		}
		else
			rear1 = rear1 -> next;//increment rear ptr
	}
	else if(temp.priority == 'M')
	{
		temp1 = L.getHead();
		L.insert(mPr+highPr+midPr,temp);
		midPr++;
		totalCnt++;
		if(front2 == NULL)
		{
			if(front1 == NULL)//in case head is NULL
			{
				front2 = L.getHead();
				rear2 = front2;
			}
			else//set front and rear pointer of medium priority Q finding the first node having priority M
			{
				while(temp1->data.priority != 'M')
				{
					temp1 = temp1->next;
				}
				front2 = temp1;
				rear2 = front2;
			}
		}
		else
			rear2 = rear2 -> next;//increment rear ptr

	}
	else if(temp.priority == 'L')
	{
		temp1 = L.getHead();
		L.insert(lPr+highPr+midPr+lowPr,temp);
		totalCnt++;
		lowPr++;
		if(front3 == NULL)
		{
			if(front1 == NULL)//in case head is NULL
			{
				front3 = L.getHead();
				rear3 = front3;
			}
			else//set front and rear pointer of medium priority Q finding the first node having priority M
			{
				while(temp1->data.priority != 'L')
				{
					temp1 = temp1->next;
				}
				front3 = temp1;
				rear3 = front3;
			}
		}
		else
			rear3 = rear3 -> next;//increment rear ptr
	}
	cout<<"\nPatientID   Name                Age    Disease             Priority\n";
	L.display();

}

/*
 	 Function to remove node from queue
 */

data1 prQueue :: dequeue()
{
	if(highPr != 0)//check for high priority nodes
	{
		data1 temp1 = front1->data;
		front1 = front1->next;
		L.delete_node(temp1);//delete node
		highPr--;
		return temp1;
	}
	else if(midPr != 0)//check for medium priority nodes
	{
		data1 temp1 = front2->data;
		front2 = front2->next;
		L.delete_node(temp1);//delete node
		midPr--;
		return temp1;
	}
	else if(lowPr != 0)//check for low priority nodes
	{
		data1 temp1 = front3->data;
		front3 = front3->next;
		L.delete_node(temp1);//delete node
		lowPr--;
		return temp1;
	}

}

/*
	Function to input patient data
*/

int* data1 ::getdata()
{
	int ch;
	static int x = 1000;
	patientID = x;
	x++;
	cout<<"\nPlease enter the name of patient : ";
	cin>>name;
	cout<<"\nPLease enter the age of patient : ";
	cin>>age;
	cout<<"\nPLease enter the name of the disease : \n";
	cout<<"\nTB = 1,Flu = 2,Cancer = 3,Malaria = 4,Dengue = 5,";
	cout<<"Polio = 6,Gastric = 7,Fever = 8,Other = 9\nChoice : ";
	cin>>ch;
	switch(ch)
	{
		case 1:
			strcpy(disease,"TB");
			break;
		case 2:
			strcpy(disease,"Flu");
			break;
		case 3:
			strcpy(disease,"Cancer");
			break;
		case 4:
			strcpy(disease,"Malaria");
			break;
		case 5:
			strcpy(disease,"Dengue");
			break;
		case 6:
			strcpy(disease,"Polio");
			break;
		case 7:
			strcpy(disease,"Gastric");
			break;
		case 8:
			strcpy(disease,"Fever");
			break;
		default:
			cout<<"Disease : ";
			cin>>disease;
			break;
	}
	cout<<"\nPlease enter the priority(eg - H->High , M->Medium , L->Low) : ";
	cin>>priority;
	return &x;
}


/*
 	 Function to display patient data
*/

void data1 :: showdata()
{
	cout<<setw(12)<<left<<patientID;
	cout<<setw(20)<<left<<name;
	cout<<setw(7)<<left<<age;
	cout<<setw(20)<<left<<disease;
	cout<<setw(8)<<left<<priority<<endl;
}


/*
 	 Function to input valid patient data
*/

int data1 :: isValid()
{
	int i;
	for(i=0;name[i]!=NULL;i++)
	{
		if(isalpha(name[i])==0)//name validation
		{
			return 1;
		}
	}
	if(age<=0 || age>=100)//age validation
	{
		return 2;
	}
	if(priority != 'H' && priority != 'M' && priority != 'L')//priority validation
	{
		return 3;
	}
	return 0;

}
