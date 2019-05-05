/*
 *  Author: Shubham Yewalekar
 *  Div : SE 9 H9
 *  Roll No : 23182
 *  File Name : Direct Access File Header
 */

#ifndef DAF_H_
#define DAF_H_

typedef struct
{
	int index;
	char name[10];
	int rollNo;
	char department[10];
	int year;
	float CGPA;
	int chain;
}data;

class DAF
{
	private:
		int count;
	public:
		DAF();
		void createFile();
		void insertRecord(data ins);
		data searchRecord(int key);
		void modifyRecord(int key);
		void deleteRecord(int key);
		data getData();
		int findEmptyPos(int index);
		void readFile();
};



#endif /* DAF_H_ */
