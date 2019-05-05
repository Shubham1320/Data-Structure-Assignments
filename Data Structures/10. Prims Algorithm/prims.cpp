/*
 *  Author: Shubham Yewalekar
 *  Div : SE 9 H9
 *  Roll No : 23182
 *  File Name : Prims Algo Implementation File
 */

#include<iostream>
#include"prims.h"
#include<string.h>
#include<iomanip>
using namespace std;

//function to set all elements of matrix as 0
void prims :: initializeMatrix()
{
	int i,j;
	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
		{
			mat[i][j] = 0;
			MSTmat[i][j] = 0;
		}
	}
}

//function to input city data
void prims :: getData()
{
	cout<<"\nEnter the number of cities present in network : ";
	cin>>no_cities;
	int i,len;
	char temp1[10];
	for(i=0;i<no_cities;i++)
	{
		cout<<"\nCurrent Entry : ";
		cout<<i+1;
		cout<<"\n------------------------------------------\n";
		cout<<"Name : ";
		cin>>temp1;
		len = strlen(temp1);
		arr[i].name = new char[len];
		strcpy(arr[i].name,temp1);
		arr[i].ID = i+1;
	}
}

//function to accept the graph from user
void prims :: setMatrix()
{
	int i,flag,len,j;
	char temp1[10],*name_temp = NULL;
	for(i=0;i<no_cities;i++)
	{
		cout<<"\nCURRENT CITY : "<<arr[i].name;
		cout<<"\nDo you want to add a link from current city : ";
		cin>>flag;
		while(flag == 1)
		{
			cout<<"\nEnter the name of the city you want to add link to :";
			cin>>temp1;
			len = strlen(temp1);
			name_temp = new char[len];
			strcpy(name_temp,temp1);
			j = findIndex(name_temp);
			if(j == -1)
				cout<<"\n ERROR :: INVALID CITY NAME\n";
			else
			{
				if(mat[i][j] == 0)
				{
					cout<<"EDGE WT : ";
					cin>>mat[i][j];
					mat[j][i] = mat[i][j];
				}
				else
					cout<<"\nERROR :: EDGE ALREADY PRESENT\n";
			}
			delete []name_temp;
			name_temp = NULL;
			cout<<"\nDo you want to add another link from current city : ";
			cin>>flag;
		}
	}
}

//function to find index of the given city
int prims :: findIndex(char *name1)
{
	int i;
	for(i=0;i<no_cities;i++)
	{
		if(strcmp(arr[i].name,name1) == 0)
		{
			return arr[i].ID - 1;
		}
	}
	return -1;
}

//function to find MST on prims algo
void prims :: primsAlgo()
{
	char* temp,temp1[10];
	int src;
	cout<<"\nSource :";
	cin>>temp1;
	int len = strlen(temp1);
	temp = new char[len];
	strcpy(temp,temp1);
	src = findIndex(temp);
	int visited[10],i,j=0,min=0,loop,index;
	for(i=0;i<no_cities;i++)
		visited[i] = 0;
	visited[src] = 1;
	for(i=0;i<no_cities;i++)
	{
		if(((mat[src][i] < mat[src][min]) && mat[src][i]!=0) || (mat[src][i] != 0 && mat[src][min] == 0))
			min = i;
	}
	visited[min] = 1;
	cout<<endl<<arr[src].name<<" - > "<<arr[min].name<<" -  "<<mat[src][min]<<" : ACCEPTED\n";
	MSTmat[src][min] = mat[src][min];
	MSTmat[min][src] = mat[src][min];
	for(loop = 2;loop<no_cities;loop++)
	{
		j = findMin(visited,&index);
		visited[j] = 1;
		cout<<endl<<arr[index].name<<" - > "<<arr[j].name<<" - "<<mat[index][j]<<" : ACCEPTED\n";
		MSTmat[index][j] = mat[index][j];
		MSTmat[j][index] = mat[index][j];
	}
}

//function to find minimum edge from the visited vertices
int prims :: findMin(int *visit,int *index)
{
	int i,min,j;
	min = 0;
	(*index) = 0;
	for(i=0;i<no_cities;i++)
	{
		if(visit[i] == 1)
		{
			for(j=0;j<no_cities;j++)
			{
				if(((mat[*index][min] > mat[i][j] && mat[i][j] != 0) || (mat[i][j] != 0 && mat[*index][min]==0)) && visit[j] == 0)
				{
					min = j;
					(*index) = i;
				}
			}
		}
	}
	return min;
}

//function to display MST
void prims :: displayMST()
{
	int i,j;
	cout<<"          "<<left<<setw(10)<<arr[0].name;
	for(i=1;i<no_cities;i++)
		cout<<left<<setw(10)<<arr[i].name;
	cout<<"\n\n";
	for(i=0;i<no_cities;i++)
	{
		cout<<left<<setw(10)<<arr[i].name;
		for(j=0;j<no_cities;j++)
			cout<<left<<setw(10)<<MSTmat[i][j];
		cout<<"\n\n";
	}
}

//function to display graph
void prims :: displayAdjMat()
{
	int i,j;
	cout<<"          "<<left<<setw(10)<<arr[0].name;
	for(i=1;i<no_cities;i++)
		cout<<left<<setw(10)<<arr[i].name;
	cout<<"\n\n";
	for(i=0;i<no_cities;i++)
	{
		cout<<left<<setw(10)<<arr[i].name;
		for(j=0;j<no_cities;j++)
			cout<<left<<setw(10)<<mat[i][j];
		cout<<"\n\n";
	}
}
