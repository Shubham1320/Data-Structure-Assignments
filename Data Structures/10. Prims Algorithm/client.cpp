/*
 *  Author: Shubham Yewalekar
 *  Div : SE 9 H9
 *  Roll No : 23182
 *  File Name : Client File
 */

#include<iostream>
#include"prims.h"
using namespace std;

int main()
{
	prims P1;
	P1.getData();
	P1.initializeMatrix();
	P1.setMatrix();
	cout<<"\n\nENTERED GRAPH IS : \n";
	P1.displayAdjMat();
	//applying prims algo
	P1.primsAlgo();
	cout<<"\n\nMINIMUM SPANNING TREE IS : \n";
	P1.displayMST();

	return 0;
}
