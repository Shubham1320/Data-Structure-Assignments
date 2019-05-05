/*
 * Name - Shubham Yewalekar
 * Roll No - 23182
 * Class - SE 9
 * Batch - H9
 * File Name - Client File for MST
 */

#include<iostream>
#include"MST.h"
using namespace std;


int main()
{
	MST m1;
	m1.crtMatrix();
	m1.setMatrix();
	cout<<"\nENTERED GRAPH IS : \n";
	m1.displayAdjMat();
	m1.matrixTable();
	m1.sortTable();
	cout<<"\nSORTED SPARSE MATRIX TABLE IS :\n";
	m1.displayTable();
	cout<<"\nMST ACCORDING TO KRUSHKAL'S ALGO : \n";
	m1.krushkalAlgo();
}

