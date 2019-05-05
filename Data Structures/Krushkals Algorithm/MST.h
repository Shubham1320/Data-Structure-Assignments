/*
 * Name - Shubham Yewalekar
 * Roll No - 23182
 * Class - SE 9
 * Batch - H9
 * File Name - Krushkal's Algorithm Header File
 */

#ifndef MST_H_
#define MST_H_


typedef struct
{
	int wt;
	int flag;
}edge;


class MST
{
	private:

	edge d1[10][10];
	int no_vertex;
	int no_edges;
	int matrixT[10][3];
	int visited[10];
	int comp[10];

	public:


	MST();

	edge** getMatrix();
	void crtMatrix();
	void setMatrix();
	void matrixTable();
	void sortTable();
	void displayTable();
	void krushkalAlgo();
	int findMin(int i,int j);
	void displayAdjMat();

	//~MST();
};



#endif /* MST_H_ */
