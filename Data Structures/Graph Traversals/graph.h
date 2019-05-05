/*
 *  Author: Shubham Yewalekar
 *  Div : SE 9 H9
 *  Roll No : 23182
 *  File Name : Graph Header File
 */

#ifndef GRAPH_H_
#define GRAPH_H_

typedef struct
{
	int day;
	int year;
	int month;
}DOB;

class Node1;

//friend of vertex class
class Node2
{
	private	:
		char *name;
		int no_comments;
		Node2 *next;
		Node1 *address;
	public :
		Node2();

		void setDat();
		void setDat1(char *name1,char *name2);
		void setDat2(char *name1,int ncomments);
		void setAdd(char *temp,Node1 *temp1);
		void setNext(Node2 *temp);
		void setComments(int ncomments);

		char* getName();
		int getComments();
		Node2* getNext();
		Node1* getAdd();
};

//vertex class
class Node1
{
	private :
		int ID;
		char *name;
		DOB d1;
		Node2 *next;
		Node1 *down;
	public :
		Node1();

		void setData(int temp);
		void setDown(Node1* temp);
		void setNext(Node2* temp);

		int getID();
		char* getName();
		DOB getDOB();
		Node2* getNext();
		Node1* getDown();

		~Node1();
};

//main class
class graph
{
	private :
		Node1* root;
		int no_entries;
		int visited[10];
		Node2 arr[10];
	public :
		graph();

		void setRoot(Node1 *temp);
		Node1* getRoot();
		bool validateVertex(Node1* temp1);
		bool validateFriends(Node2* temp,Node1 *temp1);

		void createAdjList();
		void addNewEntry();
		void makeFriend(char* vertex,char* friend1);
		void displayAdjList();
		void adjustList(Node1* temp,Node1* temp1);
		void findMaxMinComments();
		void DFS_birthday(DOB date);
		void BFS_maxfriends();
		void checkBirthday();
};

#endif /* GRAPH_H_ */
