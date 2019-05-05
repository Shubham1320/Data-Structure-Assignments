/*
Name    - Shubham Yewalekar
Roll No - 23182
Title   - File Operations in C++
*/

#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;

class student
{
	protected:
		string name_of_stu;
		int roll_no;
		string sub;
};

class subject:public student
{
	protected:
		string sub_code;
		double internals;
		double exam_marks;
	public:
		void showdata();
		void create();
		int search(string key);
		void edit();
		void Delete();
};

int main()
{
	subject s;
	string key;
	int flag=0,choice,n,i,ch,check;
	ifstream infile;
	ofstream outfile;
	fstream inoutfile;
	cout<<"Do you want to create a new file:  Yes-Press 0 No-Press 1\n";
	cin>>ch;
	if(ch==0)
	{
		outfile.open("Student.dat",ios::out);
		cout<<"How many entries do you want to enter in the file:";
		cin>>n;
		for(i=0;i<n;i++)
		{
			s.create();
			outfile.write((char *)&s,sizeof(s));
		}
		outfile.close();
	}	
	do
	{
		cout<<"Which operation do you want to perform:\n1)Display\n2)Insert\n3)Search\n4)Edit\n5)Delete\n";
		cin>>choice;
		switch(choice)
		{
			case 1:
				infile.open("Student.dat",ios::in);
				cout<<"Name           Roll_No   Subject        Subject Code   Internals  Exam Marks\n";
				for(i=0;i<n;i++)
				{
					infile.read((char *)&s,sizeof(s));
					s.showdata();
				}
				infile.close();
				break;
			case 2:
				outfile.open("Student.dat",ios::app);
				s.create();
				n++;
				outfile.write((char *)&s,sizeof(s));
				outfile.close();
				break;
			case 3:
				cin.ignore();
				cout<<"Enter the name of the student you want to search:\n";
				getline(cin,key);
				infile.open("Student.dat");
				for(i=0;i<n;i++)
				{
					infile.read((char *)&s,sizeof(s));
					check = s.search(key);
				}
				if(check==1)
				{
					cout<<"Data Found\n";
				}
				else
				{
					cout<<"Data not found\n";
				}
				infile.close();
				break;
			case 4:
				cin.ignore();
				cout<<"Enter the name of the student whose data you want to edit:\n";
				getline(cin,key);
				outfile.open("temp.dat",ios::out);
				infile.open("Student.dat",ios::in);
				for(i=0;i<n;i++)
				{
					infile.read((char *)&s,sizeof(s));
					check = s.search(key);
					if(check==0)
					{
						s.edit();
						cout<<"Data edited successfully\n";
						outfile.write((char *)&s,sizeof(s));
					}
					else
						outfile.write((char *)&s,sizeof(s));
				}
				remove("Student.dat");
				rename("temp.dat","Student.dat");
				
				infile.close();
				outfile.close();
				break;
			case 5:
				cin.ignore();
				cout<<"Enter the name of the student whose data you want to delete:\n";
				getline(cin,key);
				outfile.open("temp.dat",ios::out);
				infile.open("Student.dat",ios::in);
				for(i=0;i<n;i++)
				{
					infile.read((char *)&s,sizeof(s));
					check = s.search(key);
					if(check==0)
					{
						cout<<"Data deleted successfully\n";
					}
					else
						outfile.write((char *)&s,sizeof(s));
				}
				remove("Student.dat");
				rename("temp.dat","Student.dat");
				infile.close();
				outfile.close();
				n--;
				break;	
					
				
					
					
		}
	}while(flag==0);
	return 0;		

}

void subject::create()
{	
	cin.ignore();
	cout<<"Enter name of student:";
	getline(cin,name_of_stu);
	cout<<"Enter the roll no:";
	cin>>roll_no;
	cin.ignore();
	cout<<"Enter the subject name:";
	getline(cin,sub);
	cout<<"Enter the subject code:";
	getline(cin,sub_code);
	cout<<"Enter the internal assessment marks:";
	cin>>internals;
	cout<<"Enter the examination marks:";
	cin>>exam_marks;
}

void subject::showdata()
{
	cout<<left<<setw(15)<<name_of_stu<<left<<setw(10)<<roll_no<<left<<setw(15)<<sub<<left<<setw(15)<<sub_code;
	cout<<left<<setw(11)<<internals<<left<<setw(10)<<exam_marks;
	cout<<endl;
}

int subject::search(string key)
{
	if(key.compare(name_of_stu)==0)
	{
		return 0;
	}
	else 
		return 1;
}

void subject:: edit()
{
	int ch;
	cout<<"Which entry do you want to edit : 1)Name 2)Roll No 3)Subject Name 4)subject Code 5)Internal Assessment Marks 6)Examination Marks\n";
	cin>>ch;
	switch(ch)
	{
		case 1:	
			cin.ignore();
			cout<<"Enter name of student:";
			getline(cin,name_of_stu);
			break;
		case 2:	
			cout<<"Enter the roll no:";
			cin>>roll_no;
			break;
		case 3:	
			cin.ignore();
			cout<<"Enter the subject name:";
			getline(cin,sub);
			break;
		case 4:
			cin.ignore();	
			cout<<"Enter the subject code:";
			getline(cin,sub_code);
			break;
		case 5:	
			cout<<"Enter the internal assessment marks:";
			cin>>internals;
			break;
		case 6:	
			cout<<"Enter the examination marks:";
			cin>>exam_marks;
			break;
		default:
			cout<<"Invalid Input\n";	
	}	
}





 
