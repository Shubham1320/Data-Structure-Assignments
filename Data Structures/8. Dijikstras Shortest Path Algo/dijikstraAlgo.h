/*
 *  Author: Shubham Yewalekar
 *  Div : SE 9 H9
 *  Roll No : 23182
 *  File Name : Dijikstra's Algo Header File
 */

#ifndef DIJIKSTRAALGO_H_
#define DIJIKSTRAALGO_H_

typedef struct
{
	char *name;
	int ID;
}data;

class dijikstraAlgo
{
	private:
		data arr[10];
		int adjMat[10][10];
		int vertexCnt;
		int edgeCnt;
	public:
		dijikstraAlgo();

		void setData();
		void setMatrix();
		void findShrtsPath();
		int findIndex(char *name);
		void displayAdjMat();
};

#endif /* DIJIKSTRAALGO_H_ */
