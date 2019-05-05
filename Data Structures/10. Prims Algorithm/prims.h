/*
 *  Author: Shubham Yewalekar
 *  Div : SE 9 H9
 *  Roll No : 23182
 *  File Name : Prims Algo Header File
 */

#ifndef PRIMS_H_
#define PRIMS_H_

typedef struct
{
	char *name;
	int ID;
}vertex;

class prims
{
	private:
		int no_cities;
		vertex arr[10];
		int MSTmat[10][10];
		int mat[10][10];
	public:
		void getData();
		void initializeMatrix();
		void setMatrix();
		void primsAlgo();
		int findIndex(char *name1);
		int findMin(int *visit,int *index);
		void displayAdjMat();
		void displayMST();
};



#endif /* PRIMS_H_ */
