/*
 *  Author: Shubham Yewalekar
 *  Div : SE 9 H9
 *  Roll No : 23182
 *  File Name : Hashing Class Header File
 */

#ifndef HASH_H_
#define HASH_H_

typedef struct
{
	char *name;
	long long int mobileNo;
	int chain;
}data;

class Hash
{
	private:
		data hashTable[11];
		int count;
	public:
		Hash();
		void setHashTable();
		void hashWithoutReplacement(data temp);
		void hashWithReplacement(data temp);
		int findEmptyPos(int temp);
		data getData();
		void displayHashTable();
		bool search(int *temp);
};



#endif /* HASH_H_ */
