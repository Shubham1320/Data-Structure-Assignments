/*
 *  Author: Shubham Yewalekar
 *  Div : SE 9 H9
 *  Roll No : 23182
 *  File Name : Client File
 */


#include<iostream>
#include"dijikstraAlgo.h"
using namespace std;

int main()
{
	dijikstraAlgo d1;
	d1.setData();
	d1.setMatrix();
	d1.displayAdjMat();
	d1.findShrtsPath();
}
