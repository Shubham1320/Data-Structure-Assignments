/*
 *  Author: Shubham Yewalekar
 *  Div : SE 9 H9
 *  Roll No : 23182
 *  File Name : Dijikstra's Algo Implementation File
 */

#include<iostream>
#include"dijikstraAlgo.h"
#include<limits.h>
#include<string.h>
#include<iomanip>
using namespace std;

//function to find minimum from distance array
int findMin(int *arr,int *visited,int size);

//constructor
dijikstraAlgo :: dijikstraAlgo()
{
	int i,j;
	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
			adjMat[i][j] = 0;
	}
	vertexCnt = 0;
	edgeCnt = 0;
}

//function to initialize adjacency matrix and get input graph
void dijikstraAlgo :: setMatrix()
{
	int looper = 0,flag,edgeWt,len,node;
	char temp1[10],*temp2;
	for(looper=0;looper<vertexCnt;looper++)
	{
		cout<<"\nCurrent Node : "<<arr[looper].name;
		cout<<"\nDo you want to add any link from the current city[Y-1/N-0] : ";
		cin>>flag;
		while(flag == 1)
		{
			cout<<"\nEnter the city name you want to add link to : ";
			cin>>temp1;
			len = strlen(temp1);
			temp2 = new char[len];
			strcpy(temp2,temp1);
			node = findIndex(temp2);
			if(node>vertexCnt)
			{
				cout<<"\nERROR : INVALID CITY NAME";
			}
			else
			{
				if(adjMat[looper][node] == 0)
				{
					cout<<"\nEdge Weight : ";
					cin>>edgeWt;
					adjMat[looper][node] = edgeWt;
					adjMat[node][looper] = edgeWt;
				}
				else
					cout<<"\nERROR : Edge already present";
			}
			cout<<"\nDo you want to add another link from the current city[Y-1/N-0] : ";
			cin>>flag;
		}
	}
}

//function to find shortest path base on Dijikstra's Algo
void dijikstraAlgo :: findShrtsPath()
{
	int src,destination,arr1[vertexCnt],visited[vertexCnt],len;
	char temp1[10],*temp2,*temp3;
	cout<<"\nSource : ";
	cin>>temp1;
	len = strlen(temp1);
	temp2 = new char[len];
	strcpy(temp2,temp1);
	src = findIndex(temp2);
	cout<<"\nDestination : ";
	cin>>temp1;
	len = strlen(temp1);
	temp3 = new char[len];
	strcpy(temp3,temp1);
	destination = findIndex(temp3);
	if(destination>vertexCnt || src>vertexCnt)
	{
		cout<<"\nERROR : INVALID CITY NAME";
	}
	else
	{
	    for (int i = 0; i < vertexCnt; i++)
	    {
	       arr1[i] = INT_MAX;
	       visited[i] = 0;
	    }
	    arr1[src] = 0;
	    cout<<"\nPath : ";
	    while(visited[destination] != 1)
	    {
	    	 int u = findMin(arr1, visited , vertexCnt);
	    	 visited[u] = 1;
	    	 cout<<arr[u].name<<" -> ";
	    	 for (int v = 0; v < vertexCnt; v++)
	    	 {
	    		 if(visited[v] == 0 && adjMat[u][v] != 0 && arr1[u] != INT_MAX && arr1[u]+adjMat[u][v]<arr1[v])
	    			 arr1[v] = arr1[u] + adjMat[u][v];
	    	 }
	    }
	    cout<<"SHORTEST DISTANCE :";
	    cout<<arr1[destination];

	}
}

int findMin(int* arr,int* visited,int size)
{
	 int min = INT_MAX, min_index;

	  for (int v = 0; v < size ; v++)
	     if (visited[v] == 0 && arr[v] <= min)
	     {
	         min = arr[v],
			 min_index = v;
	     }

	   return min_index;
}

//function to get input data from user of cities
void dijikstraAlgo :: setData()
{
	cout<<"\nHow many vertices do you want to add (MAX = 10): ";
	cin>>vertexCnt;
	char temp1[10],*temp2;
	int i;
	for(i=0;i<vertexCnt;i++)
	{
		arr[i].ID = i;
		cout<<"\n---------DATA ENTRY----------\n";
		cout<<"Name of City : ";
		cin>>temp1;
		cout<<"\n-----------------------------\n";
		int len = strlen(temp1);
		temp2 = new char[len];
		strcpy(temp2,temp1);
		arr[i].name = temp2;
	}
}

//function to find index based on input city name
int dijikstraAlgo :: findIndex(char *name)
{
	int i;
	for(i=0;i<vertexCnt;i++)
	{
		if(strcmp(arr[i].name,name) == 0)
		{
			return arr[i].ID;
		}
	}
	return vertexCnt+1;
}

void dijikstraAlgo :: displayAdjMat()
{
	int i,j;
	cout<<"          "<<left<<setw(10)<<arr[0].name;
	for(i=1;i<vertexCnt;i++)
		cout<<left<<setw(10)<<arr[i].name;
	cout<<"\n\n";
	for(i=0;i<vertexCnt;i++)
	{
		cout<<left<<setw(10)<<arr[i].name;
		for(j=0;j<vertexCnt;j++)
			cout<<left<<setw(10)<<adjMat[i][j];
		cout<<"\n\n";
	}
}

