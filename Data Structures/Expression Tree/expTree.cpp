/*
 *  Author: Shubham Yewalekar
 *  Div : SE 9 H9
 *  Roll No : 23182
 *  File Name : Expression Tree Implement File
 */

#include<iostream>
#include"expTree.h"
#include<string.h>
#include"stackll.cpp"
using namespace std;

//function to create expression tree from the postfix expression generated
template<class T>
void expTree<T>::createTree() {
	stack_ll<Node1<T> *> stack;
	char token;
	int i = 0;
	E1.setExp();
	E1.inToPostFix();
	Node1<T>* op2 = NULL;
	Node1<T>* op1 = NULL;
	char *temp = new char[E1.getPostSize()];
	strcpy(temp, E1.getPostFix());
	Node1<T> *temp1 = NULL;
	while (i < E1.getPostSize()) {
		token = temp[i];
		//if it is operand then create node and push into stack
		if (E1.isOperand(token) == 1) {
			temp1 = new Node1<T>;
			temp1->setData(token);
			stack.push(temp1);
		}
		//if it is operator the pop stack twice and attach then to operator node
		else if (E1.isOperator(token) == 1) {
			if (stack.isEmpty() == 0) {
				op1 = stack.pop();
			}
			if (stack.isEmpty() == 0) {
				op2 = stack.pop();
			}
			temp1 = new Node1<T>;
			temp1->setData(token);
			temp1->setLchild(op2);
			temp1->setRchild(op1);
			//push back into stack
			stack.push(temp1);
		}
		i++;
	}
	//output final root
	setRoot(stack.pop());

}

//function to display in order display recursive
template<class T>
void expTree<T>::inOrderDisplay(Node1<T> *temp) {
	if (root == NULL) {
		cout << "Tree not created \n";
	} else {
		if (temp->getLchild() != NULL) {
			//go left
			inOrderDisplay(temp->getLchild());
		}
		//print data
		cout << temp->getData() << " ";

		//go right
		if (temp->getRchild() != NULL) {
			inOrderDisplay(temp->getRchild());
		}
	}
}

//function to display pre order display recursive
template<class T>
void expTree<T>::preOrderDisplay(Node1<T> *temp) {
	if (root == NULL) {
		cout << "Tree not created \n";
	} else {
		//print data
		cout << temp->getData() << " ";

		if (temp->getLchild() != NULL) {
			//go left
			preOrderDisplay(temp->getLchild());
		}

		if (temp->getRchild() != NULL) {
			//go right
			preOrderDisplay(temp->getRchild());
		}
	}
}

//function to display post order display recursive
template<class T>
void expTree<T>::postOrderDisplay(Node1<T> *temp) {
	if (root == NULL) {
		cout << "Tree not created \n";
	} else {
		if (temp->getLchild() != NULL) {
			//go left
			postOrderDisplay(temp->getLchild());
		}

		if (temp->getRchild() != NULL) {
			//go right
			postOrderDisplay(temp->getRchild());
		}
		//print data
		cout << temp->getData() << " ";
	}
}

//function to display in order display non-recursive
template<class T>
void expTree<T>::inOrderDisplay1() {
	Node1<T> *temp;
	temp = root;
	stack_ll<Node1<T>*> stack;
	int i = 0;
	if (temp == NULL) {
		cout << "Empty Tree/n";
	}
	while ((temp != NULL || stack.isEmpty() == 0) && i < E1.getPostSize()) {
		while (temp != NULL) {
			//psuh onto stack
			stack.push(temp);
			//go left
			temp = temp->getLchild();
		}
		if (stack.isEmpty() == 0) {
			temp = stack.pop();
			//print data
			cout << temp->getData() << " ";
			i++;
		}
		//go right
		temp = temp->getRchild();
	}
}

//function to display pre-order display non-recursive
template<class T>
void expTree<T>::preOrderDisplay1() {
	Node1<T> *temp;
	temp = root;
	stack_ll<Node1<T>*> stack;
	int i = 0;
	if (temp == NULL) {
		cout << "Empty Tree/n";
	}
	while ((temp != NULL || stack.isEmpty() == 0) && i < E1.getPostSize()) {
		while (temp != NULL) {
			//print data
			cout << temp->getData() << " ";
			//push onto stack
			stack.push(temp);
			i++;
			//go left
			temp = temp->getLchild();
		}
		if (stack.isEmpty() == 0) {
			temp = stack.pop();
		}
		//go right
		temp = temp->getRchild();
	}
}

//function to display post order display non-recursive
template<class T>
void expTree<T>::postOrderDisplay1() {
	int flag = 0;
	Node1<T> *temp;
	temp = root;
	stack_ll<int> stack1;
	stack_ll<Node1<T>*> stack2;
	int i = 0;
	while (temp != NULL) {
		//push into stack with flag 0
		stack2.push(temp);
		stack1.push(0);
		temp = temp->getLchild();
	}
	while (i < E1.getPostSize()) {
		temp = stack2.pop();
		flag = stack1.pop();
		if (flag == 1) {
			//print data
			cout << temp->getData() << " ";
			i++;
		} else {
			//change flag to 1 and push back to stack
			stack1.push(1);
			stack2.push(temp);
			temp = temp->getRchild();
			while (temp != NULL) {
				//repeat for sub-tree
				stack2.push(temp);
				stack1.push(0);
				temp = temp->getLchild();
			}
		}
	}
}

//getter
template<class T>
Node1<T> * expTree<T>::getRoot() {
	return root;
}

//setter
template<class T>
void Node1<T>::setData(T data) {
	this->data = data;
}

template<class T>
void Node1<T>::setLchild(Node1 *temp) {
	lchild = temp;
}

template<class T>
void Node1<T>::setRchild(Node1 *temp) {
	rchild = temp;
}

//getter
template<class T>
T Node1<T>::getData() {
	return data;
}

template<class T>
Node1<T>* Node1<T>::getLchild() {
	return lchild;
}

template<class T>
Node1<T>* Node1<T>::getRchild() {
	return rchild;
}

template<class T>
Node1<T>::Node1() {
	lchild = NULL;
	rchild = NULL;
}

//setter
template<class T>
void expTree<T>::setRoot(Node1<T> *temp) {
	root = temp;
}
