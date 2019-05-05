/*
 *  Author: Shubham Yewalekar
 *  Div : SE 9 H9
 *  Roll No : 23182
 *  File Name : Direct Access File Implementation
 */

#include"DAF.h"
using namespace std;
#include<iostream>
#include<string.h>
#include<iomanip>
#include<fstream>

DAF :: DAF()
{
	count = 0;
}

//function to get a single database entry
data DAF :: getData()
{
	data rec;
	cout<<"\n------------------DATA ENTRY------------------\n";
	cout<<"NAME : ";
	cin>>rec.name;
	cout<<"ROLL NO : ";
	cin>>rec.rollNo;
	cout<<"DEPARTMENT : ";
	cin>>rec.department;
	cout<<"YEAR OF STUDY : ";
	cin>>rec.year;
	cout<<"CGPA : ";
	cin>>rec.CGPA;
	rec.chain = -1;
	cout<<"\n---------------------END----------------------\n";
	return rec;
}

//function to initialize 11 entries in file
void DAF :: createFile()
{
	fstream inout;
	data def;
	strcpy(def.name,"NONE");
	def.rollNo = -1;
	strcpy(def.department,"NONE");
	def.year = -1;
	def.CGPA = -1;
	def.chain = -1;
	inout.open("student.bin",ios::binary|ios::out);
	int i;
	for(i=0;i<11;i++)
	{
		inout.seekp(i*sizeof(data),ios::beg);
		def.index = i;
		inout.write((char *)&def,sizeof(def));
	}
	inout.close();
}

//function using hashing without replacement to insert data in file
void DAF :: insertRecord(data ins)
{
	if(count <= 11)
	{
		count++;
		int loc,last;
		data temp;
		fstream inout;
		inout.open("student.bin",ios::binary|ios :: in|ios :: out);
		int index = ins.rollNo%11;
		inout.seekg(index*sizeof(data),ios :: beg) ;
		inout.read((char *)&temp,sizeof(temp));
		inout.seekp(index*sizeof(data),ios :: beg) ;
		if(strcmp(temp.name,"NONE")==0)
		{
			inout.write((char *)&ins,sizeof(ins));
		}
		else if(strcmp(temp.name,"NONE") != 0 && temp.chain == -1)
		{
			loc = findEmptyPos(index);
			inout.seekp(index*sizeof(data),ios::beg);
			temp.chain = loc;
			inout.write((char*)&temp,sizeof(temp));
			inout.seekp(loc*sizeof(data),ios::beg);
			inout.write((char*)&ins,sizeof(ins));
		}
		else if(strcmp(temp.name,"NONE") != 0 && temp.chain != -1)
		{
			last = index;
			while(temp.chain != -1)
			{
				last = temp.chain;
				inout.seekg(last*sizeof(data),ios::beg);
				inout.read((char*)&temp,sizeof(temp));
			}
			loc = findEmptyPos(index);
			inout.seekp(last*sizeof(data),ios::beg);
			temp.chain = loc;
			inout.write((char*)&temp,sizeof(data));
			inout.seekp(loc*sizeof(data),ios::beg);
			inout.write((char*)&ins,sizeof(data));
		}
		inout.close();
		cout<<"\nINSERT SUCCESSFULL\n";
	}
	else
		cout<<"\nERROR :: FILE FULL\n";

}

//function to find the next empty position in file using linear probing
int DAF :: findEmptyPos(int index)
{
	data temp;
	fstream inout;
	inout.open("student.bin",ios::binary|ios :: in);
	inout.seekg(index*sizeof(data),ios::beg);
	inout.read((char*)&temp,sizeof(temp));
	while(strcmp(temp.name,"NONE") != 0)
	{
		if(index == 10)
			index = 0;
		else
			index++;
		inout.seekg(index*sizeof(data),ios::beg);
		inout.read((char*)&temp,sizeof(temp));
	}
	inout.close();
	return index;
}

//function to read the file
void DAF :: readFile()
{
	int index = 0;
	fstream inout;
	data temp;
	inout.open("student.bin",ios::binary|ios :: in);
	cout<<"\nNAME      ROLL-NO  DEPARTMENT   YEAR   CGPA  CHAIN\n";
	while(index<11)
	{
		inout.seekg(index*sizeof(data),ios::beg);
		inout.read((char*)&temp,sizeof(temp));
		cout<<left<<setw(10)<<temp.name;
		cout<<left<<setw(9)<<temp.rollNo;
		cout<<left<<setw(13)<<temp.department;
		cout<<left<<setw(7)<<temp.year;
		cout<<left<<setw(6)<<temp.CGPA;
		cout<<left<<setw(5)<<temp.chain;
		cout<<endl;
		index++;
	}
	inout.close();
}

//function to search data in file
data DAF :: searchRecord(int key)
{
	fstream inout;
	data ret,def;
	strcpy(def.name,"NONE");
	def.rollNo = -1;
	strcpy(def.department,"NONE");
	def.year = -1;
	def.CGPA = -1;
	def.chain = -1;
	int index = key%11;
	inout.open("student.bin",ios::binary|ios::in);
	inout.seekg(index*sizeof(data),ios::beg);
	inout.read((char* )&ret,sizeof(ret));
	while(ret.rollNo != key)
	{
		index = ret.chain;
		if(index != -1)
		{
			inout.seekg(index*sizeof(data),ios::beg);
			inout.read((char* )&ret,sizeof(ret));
		}
		else
			break;
	}
	if(index != -1)
	{
		inout.close();
		cout<<"\nSEARCH SUCCESSFULL\n";
		return ret;
	}
	else
		cout<<"\nERROR :: RECORD NOT FOUND\n";
	return def;
}

//function to modify the data in file
void DAF :: modifyRecord(int key)
{
	int flag1,ch,newRoll= -1;
	fstream inout;
	data node,temp1;
	int index = key%11;
	inout.open("student.bin",ios::binary|ios::in|ios::out);
	inout.seekg(index*sizeof(data),ios::beg);
	inout.read((char* )&node,sizeof(node));
	while(node.rollNo != key)
	{
		index = node.chain;
		if(index != -1)
		{
			inout.seekg(index*sizeof(data),ios::beg);
			inout.read((char* )&node,sizeof(node));
		}
		else
			break;
	}
	if(index != -1)
	{
		do
		{
			cout<<"\nWhich Entry do you want to update : \n";
			cout<<"		1)Name\n";
			cout<<"		2)Department\n";
			cout<<"		3)Year\n";
			cout<<"		4)CGPA\n";
			cout<<"Chocie : ";
			cin>>ch;
			switch(ch)
			{
				case 1 :
					cout<<"\nORIGINAL NAME : "<<node.name;
					cout<<"\nUPDATED NAME : ";
					cin>>node.name;
					break;
				case 2 :
					cout<<"\nORIGINAL DEPARTMENT : "<<node.department;
					cout<<"\nUPDATED DEPARTMENT : ";
					cin>>node.department;
					break;
				case 3 :
					cout<<"\nORIGINAL YEAR : "<<node.year;
					cout<<"\nUPDATED YEAR : ";
					cin>>node.year;
					break;
				case 4 :
					cout<<"\nORIGINAL CGPA : "<<node.CGPA;
					cout<<"\nUPDATED NAME : ";
					cin>>node.CGPA;
					break;
			}
			cout<<"\nDo you want to continue updating entries [Y-1/N-0] : ";
			cin>>flag1;
		}while(flag1 == 1);
		inout.seekp(index*sizeof(data),ios::beg);
		inout.write((char*)&node,sizeof(node));
		inout.close();
		cout<<"\nMODIFY SUCCESSFULL\n";
	}
	else
		cout<<"\nERROR :: RECORD NOT FOUND AND CANNOT BE MODIFIED\n";
}

//function to delete record from file
void DAF :: deleteRecord(int key)
{
	fstream inout;
	data node,def,temp1;
	strcpy(def.name,"NONE");
	def.rollNo = -1;
	strcpy(def.department,"NONE");
	def.year = -1;
	def.CGPA = -1;
	def.chain = -1;
	int index = key%11,last = -1;
	inout.open("student.bin",ios::binary|ios::in|ios::out);
	inout.seekg(index*sizeof(data),ios::beg);
	inout.read((char* )&node,sizeof(node));
	if(node.rollNo == key)
	{
		last = index;
		index = node.chain;
		inout.seekg(sizeof(data)*index,ios::beg);
		inout.read((char *)&temp1,sizeof(temp1));
		inout.seekp(sizeof(data)*last,ios::beg);
		inout.write((char *)&temp1,sizeof(temp1));
		inout.seekp(sizeof(data)*index,ios::beg);
		inout.write((char *)&def,sizeof(def));
	}
	else
	{
		while(node.rollNo != key)
		{
			last = index;
			index = node.chain;
			if(index != -1)
			{
				inout.seekg(index*sizeof(data),ios::beg);
				inout.read((char* )&node,sizeof(node));
			}
			else
				break;
		}
		if(index != -1)
		{
			count--;
			int newChain = node.chain;
			inout.seekp(index*sizeof(data),ios::beg);
			inout.write((char*)&def,sizeof(def));
			if(last!=-1)
			{
				inout.seekg(last*sizeof(data),ios::beg);
				inout.read((char*)&node,sizeof(node));
				node.chain = newChain;
				inout.seekp(last*sizeof(data),ios::beg);
				inout.write((char*)&node,sizeof(node));
			}
			cout<<"\nDELETE OPERATION SUCCESSFUL\n";
			inout.close();
		}
		else
			cout<<"\nERROR :: RECORD NOT FOUND AND CANNOT DELETE\n";
	}
}
