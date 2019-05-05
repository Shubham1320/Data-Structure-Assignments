/*
 * Name - Shubham Yewalekar
 * Roll No - 23182
 * Class - SE 9
 * Batch - H9
 * File Name - Krushkal's Algorithm Implementation File
 */

#include<iostream>
#include"MST.h"
#include<iomanip>
using namespace std;

MST :: MST()
{
	no_vertex = 0;
	no_edges = 0;
}

//function to initialize adjacency matrix
void MST :: crtMatrix()
{

	cout<<"NO OF VERTICES : ";
	cin>>no_vertex;
	int i,j;
	for(i=0;i<no_vertex;i++)
	{
		for(j=0;j<no_vertex;j++)
		{
			d1[i][j].wt = 0;
			d1[i][j].flag = 0;
		}
	}
	for(i=0;i<no_vertex;i++)
	{
		visited[i] = 0;
		comp[i] = 0;
	}
}

//function to get adjacency matrix from user
void MST :: setMatrix()
{
	int i,j=0,flag,flag1=0;
	for(i=0;i<no_vertex;i++)
	{
		cout<<"Current Node : "<<i+1;
		cout<<"\nDo you want to add node [Y-1/N-0]";
		cin>>flag;
		while(flag == 1)
		{
			cout<<"\nENTER NODE NUMBER TO BE CONNECTED : ";
			cin>>j;
			j--;
			if(j>no_vertex)
			{
				cout<<"\nERROR : NODE NO CANNOT BE GREATER THAN"<<no_vertex<<endl;
				i--;
				break;
			}
			else if(d1[i][j].wt != 0)
			{
				cout<<"\nERROR : EDGE ALREADY INSERTED\n";
				i--;
				break;
			}
			cout<<"\nEDGE WEIGHT : ";
			cin>>d1[i][j].wt;
			d1[j][i].wt = d1[i][j].wt;
			no_edges++;
			cout<<"\nDo you want to add another node [Y-1/N-0]";
			cin>>flag;
		}
	}
}

//function to set sparse matrix table
void MST :: matrixTable()
{
	int i,j,k=0;
	for(i=0;i<no_vertex;i++)
	{
		for(j=0;j<no_vertex;j++)
		{
			if(d1[i][j].wt != 0 && d1[i][j].flag != 1)
			{
				matrixT[k][0] = i+1;
				matrixT[k][1] = j+1;
				matrixT[k][2] = d1[i][j].wt;
				d1[j][i].flag = 1;
				k++;
			}
		}
	}
}

//function to sort sparse matrix table
void MST :: sortTable()
{
	int i,min,j;
	for(i=0;i<no_edges;i++)
	{
		min = i;
		for(j=i+1;j<no_edges;j++)
		{
			if(matrixT[j][2] < matrixT[min][2])
			{
				min = j;
			}
		}
		if(min != i)
		{
			int temp1,temp2,temp3;
			temp1 = matrixT[i][0];
			temp2 = matrixT[i][1];
			temp3 = matrixT[i][2];
			matrixT[i][0] = matrixT[min][0];
			matrixT[i][1] = matrixT[min][1];
			matrixT[i][2] = matrixT[min][2];
			matrixT[min][0] = temp1;
			matrixT[min][1] = temp2;
			matrixT[min][2] = temp3;
		}
	}
}

//function to display sparse matrix table
void MST :: displayTable()
{
	int i;
	for(i=0;i<no_edges;i++)
	{
		cout<<matrixT[i][0]<<"  "<<matrixT[i][1]<<"  "<<matrixT[i][2]<<endl;
	}
}

//function to implement krushkal's Algo
void MST :: krushkalAlgo()
{
	int i,j=1,k=0,l;
	for(i=0;i<no_vertex;i++)
	{
		visited[i] = 0;
		comp[i] = 0;
	}
	for(i=0;i<no_edges;i++)
	{
		if(visited[matrixT[i][0]-1] == 0 && visited[matrixT[i][1]-1] == 0)
		{
			cout<<"ITERATION NO : "<<k+1<<"  ";
			cout<<"WT OF EDGE :"<<matrixT[i][2]<<" :: ACCEPTED"<<endl;
			comp[matrixT[i][0]-1] = j;
			comp[matrixT[i][1]-1] = j;
			j++;
			k++;
			visited[matrixT[i][0]-1] = 1;
			visited[matrixT[i][1]-1] = 1;
		}
		else if(visited[matrixT[i][0]-1] == 0 && visited[matrixT[i][1]-1] == 1)
		{
			cout<<"ITERATION NO : "<<k+1<<"  ";
			cout<<"WT OF EDGE :"<<matrixT[i][2]<<" :: ACCEPTED"<<endl;
			comp[matrixT[i][0]-1] = comp[matrixT[i][1]-1];
			visited[matrixT[i][0]-1] = 1;
			k++;
		}
		else if(visited[matrixT[i][0]-1] == 1 && visited[matrixT[i][1]-1] == 0)
		{
			cout<<"ITERATION NO : "<<k+1<<"  ";
			cout<<"WT OF EDGE :"<<matrixT[i][2]<<" :: ACCEPTED"<<endl;
			comp[matrixT[i][1]-1] = comp[matrixT[i][0]-1];
			visited[matrixT[i][1]-1] = 1;
			k++;
		}
		else if(comp[matrixT[i][0]-1] != comp[matrixT[i][1]-1])
		{
			cout<<"ITERATION NO : "<<k+1<<"  ";
			cout<<"WT OF EDGE :"<<matrixT[i][2]<<" :: ACCEPTED"<<endl;
			k++;
			int check = findMin(comp[matrixT[i][0]-1],comp[matrixT[i][1]]-1);
			if(check == 0)
			{
				int temp = comp[matrixT[i][1]-1];
				int temp1 = comp[matrixT[i][0]-1];
				for(l=0;l<no_vertex;l++)
				{
					if(temp == comp[l])
					{
						comp[l] = temp1;
					}
				}
			}
			else if(check == 1)
			{
				int temp = comp[matrixT[i][0]-1];
				int temp1 = comp[matrixT[i][1]-1];
				for(l=0;l<no_vertex;l++)
				{
					if(temp == comp[l])
					{
						comp[l] = temp1;
					}
				}
			}
		}
		else
		{
			cout<<"ITERATION NO : "<<k+1<<"  ";
			cout<<"WT OF EDGE :"<<matrixT[i][2]<<" :: REJECTED"<<endl;
			k++;
		}
	}
}

//function to find minimum
int MST :: findMin(int i,int j)
{
	if(i<j)
		return 0;
	if(i>j)
		return 1;
}

//function to display graph
void MST :: displayAdjMat()
{
	int i,j;
	cout<<"          "<<left<<setw(10)<<"0";
	for(i=1;i<no_vertex;i++)
		cout<<left<<setw(10)<<i;
	cout<<"\n\n";
	for(i=0;i<no_vertex;i++)
	{
		cout<<left<<setw(10)<<i;
		for(j=0;j<no_vertex;j++)
			cout<<left<<setw(10)<<d1[i][j].wt;
		cout<<"\n\n";
	}
}
