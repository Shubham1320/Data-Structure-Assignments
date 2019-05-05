/*
 *  Author: Shubham Yewalekar
 *  Div : SE 9 H9
 *  Roll No : 23182
 *  File Name : Expression Header File
 */

#ifndef IMPLEMENT_H_
#define IMPLEMENT_H_

class expression
{
	private:
		char *exp;
		int exp_size;
		int postFix_size;
		char *postFix;
		char *preFix;
	public:
		expression();//constructor

		void setExp();//input infix expression
		void inToPostFix();//infix to postfix conversion
		void inToPreFix();//infix to prefix conversion

		float eval_postExp();//function to evaluate postfix expression
		float eval_preExp();//function to evaluate prefix expression

		int isOperator(char temp);//function to check if the entered character is an operator
		int isOperand(char temp);

		int isValid();//validations
		int isValid1();

		int priority(char check);//function to check priority of operators
		int associativity(char temp);//function to check associativity of operators

		float calculate(char temp,float o1,float o2);

		void printExp();
		void printPostFix();
		void printPreFix();

		int getPostSize();
		char* getPostFix();

		~expression();
};

#endif /* IMPLEMENT_H_ */
