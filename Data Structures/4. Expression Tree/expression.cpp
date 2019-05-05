/*
 *  Author: Shubham Yewalekar
 *  Div : SE 9 H9
 *  Roll No : 23182
 *  File Name : Expression Implement File
 */

#include <iostream>
#include "expression.h"
#include "stackll.cpp"
#include<math.h>
#include<string.h>
#include<iomanip>
using namespace std;

expression :: expression()
{
	exp = NULL;
	postFix = NULL;
	exp_size = 0;
	preFix = NULL;
	postFix_size = 0;
}

void expression :: setExp()
{
	cout<<"Enter the expression : ";
	int size;
	char *temp = new char[50];
	cin>>temp;
	size = strlen(temp);
	exp_size = size;
	exp = new char[exp_size];
	strcpy(exp,temp);
	delete []temp;
	if(isValid()==1)
	{
		if(isValid1()==1)
		{
			cout<<"Expression Accepted Successfully\n";
			printExp();
		}
		else
		{
			cout<<"ERROR : INVALID INFIX EXPRESSION\n";
			delete []exp;
		}
	}
	else
	{
		cout<<"ERROR : INVALID INFIX EXPRESSION\n";
		delete []exp;
	}
	int i=0;
	int count = exp_size;
	while(i<exp_size)
	{
		if(exp[i]=='(' || exp[i]==')')
		{
			count--;
		}
		i++;
	}
	postFix_size = count;
	preFix = new char[postFix_size];
	postFix = new char[postFix_size];
}

void expression :: inToPostFix()
{
	//cout<<"\nInput               Stack               Output              \n";
	stack_ll<char> stack;
	int counter = 0;
	int loop_pf = 0;
	char token;
	char topToken;
	char tokenOut;
	while(counter<exp_size)
	{
		token = exp[counter];
		//cout<<setw(20)<<left<<token;
		//if(stack.isEmpty()==0)
		//{
			//cout<<setw(20)<<left<<stack.getTop();
		//}
		//else
			//cout<<setw(20)<<left<<"NONE";
		if(token == '(')
		{
			stack.push(token);
		}
		else if(token == ')')
		{
			token = stack.pop();
			while(token != '(')
			{
				postFix[loop_pf] = token;
				token = stack.pop();
				loop_pf++;
			}
		}
		else if(isOperator(token))
		{
			topToken = stack.getTop();
			while(stack.isEmpty() == 0 && priority(token)<priority(topToken))
			{
				tokenOut = stack.pop();
				postFix[loop_pf] = tokenOut;
				loop_pf++;
				topToken = stack.getTop();
			}
			if(priority(token)>priority(topToken))
			{
				stack.push(token);
			}
			else if(priority(token) == priority(topToken))
			{
					if((associativity(token) == 1) && (associativity(topToken)==1))
					{
						tokenOut = stack.pop();
						postFix[loop_pf] = tokenOut;
						loop_pf++;
						stack.push(token);
					}
					if((associativity(token) == 2) && (associativity(topToken)==2))
					{
						stack.push(token);
					}
			}
		}
		else
		{
			postFix[loop_pf] = token;
			loop_pf++;
		}
		//cout<<setw(20)<<left<<postFix<<endl;
		counter++;
	}
	while(stack.isEmpty() != 1)
	{
		//cout<<setw(20)<<left<<"NONE";
		//cout<<setw(20)<<left<<stack.getTop();
		token = stack.pop();
		postFix[loop_pf] = token;
		//cout<<setw(20)<<left<<postFix<<endl;
		loop_pf++;
	}
}

float expression :: eval_postExp()
{
	stack_ll<float> stack;
	int loop_pf = 0;
	float ans;
	float temp1=-1,temp2=-1;
	while(loop_pf<postFix_size)
	{
		char token = postFix[loop_pf];
		if(isOperand(token))
		{
			stack.push(token);
		}
		else if(isOperator(token))
		{
			if(stack.isEmpty()==0)
			{
				float o1,o2;
				float op1 = stack.pop();
			    if((char)op1 == '$')
			    {
			    	op1 = stack.pop();
			    	temp1 = op1;
			    }
				float op2 = stack.pop();
			    if((char)op2 == '$')
			   	{
			    	op2 = stack.pop();
			    	temp2 = op2;
			   	}
				if(isalpha((char)op1)!=0 && op1!=temp1)
				{
					cout<<"Enter the data of variable "<<(char)op1<<" : ";
					cin>>o1;
				}
				else
				{
					o1 = op1;
				}
				if(isalpha((char)op2)!=0 && op2!=temp2)
				{
					cout<<"Enter the data of variable "<<(char)op2<<" : ";
					cin>>o2;
				}
				else
				{
					o2 = op2;
				}

				ans = calculate(token,o2,o1);
				stack.push(ans);
				stack.push('$');
			}
			else
				cout<<"Stack is empty";
		}
		loop_pf++;
	}
	float temp3 = stack.pop();
	return (stack.pop());
}

float expression :: eval_preExp()
{
	stack_ll<float> stack;
	int loop_pf = postFix_size-1;
	float ans;
	float temp1=-1,temp2=-1;
	while(loop_pf>=0)
	{
		char token = preFix[loop_pf];
		if(isOperand(token))
		{
			stack.push(token);
		}
		else if(isOperator(token))
		{
			if(stack.isEmpty()==0)
			{
				float o1,o2;
				float op1 = stack.pop();
			    if((char)op1 == '$')
			    {
			    	op1 = stack.pop();
			    	temp1 = op1;
			    }
				float op2 = stack.pop();
				if((char)op2 == '$')
			   	{
			    	op2 = stack.pop();
			    	temp2 = op2;
			   	}
				if(isalpha((char)op1)!=0 && op1!=temp1)
				{
					cout<<"Enter the data of variable "<<(char)op1<<" : ";
					cin>>o1;
				}
				else
				{
					o1 = op1;
				}
				if(isalpha((char)op2)!=0 && op2!=temp2)
				{
					cout<<"Enter the data of variable "<<(char)op2<<" : ";
					cin>>o2;
				}
				else
				{
					o2 = op2;
				}

				ans = calculate(token,o1,o2);
				stack.push(ans);
				stack.push('$');
			}
			else
				cout<<"Stack is empty";
		}
		loop_pf--;
	}
	float temp3 = stack.pop();
	return (stack.pop());
}


int expression :: priority(char check)
{
	switch(check)
	{
		case '+' :
			return 1;
		case '-' :
			return 1;
		case '*' :
			return 2;
		case '/' :
			return 2;
		case '%' :
			return 2;
		case '^' :
			return 3;
		default :
			return 0;
			break;
	}
}

int expression :: isOperator(char temp)
{
	if(temp == '+' || temp == '-' || temp == '*' || temp == '/' || temp == '^' || temp == '%')
	{
		return 1;
	}
	else
		return 0;
}

int expression :: isOperand(char temp)
{
	if(((float)temp>=65 && (float)temp<=90) || ((float)temp>=97 && (float)temp<=122))
	{
		return 1;
	}
	else
		return 0;
}

int expression :: associativity(char temp)
{
	switch(temp)
	{
	 	 case '+':
	 		 return 1;
	 	 case '-':
	 		 return 1;
	 	 case '*':
	 		 return 1;
	 	 case '/':
	 		 return 1;
	 	 case '%':
	 		 return 1;
	 	 case '^':
	 		 return 2;
	 	 default:
		 	 return 0;
	}
}

float expression :: calculate(char temp,float o1,float o2)
{
	switch(temp)
	{
		case '+':
			return o1 + o2;
		case '-':
			return o1 - o2;
		case '*':
			return o1*o2;
		case '/':
			return o1/o2;
		case '^' :
			return pow(o1,o2);
		case '%' :
			return o1/o2;
		default :
			return 0;
	}
}

void expression :: inToPreFix()
{
	stack_ll<char> stack;
	int loop = exp_size-1;
	int loop_pf = postFix_size-1;
	char token;
	cout<<"\nInput               Stack               Output              \n";
	while(loop>=0)
	{
		token = exp[loop];
		cout<<setw(20)<<left<<token;

		if(stack.isEmpty()==0)
		{
				cout<<setw(20)<<left<<stack.getTop();
		}
		else
			cout<<setw(20)<<left<<"NONE";

		if(isOperand(token))
		{
			preFix[loop_pf] = token;
			loop_pf--;
		}
		else if(token == ')')
		{
			stack.push(token);
		}
		else if(token == '(')
		{
			char tempToken;
			tempToken = stack.pop();
			while(tempToken != ')')
			{
				preFix[loop_pf] = tempToken;
				loop_pf--;
				tempToken = stack.pop();
			}
		}
		else if(isOperator(token))
		{
			char topToken = stack.getTop();
			if(priority(token)>priority(topToken))
			{
				stack.push(token);
			}
			else if(priority(token)<priority(topToken))
			{
				while(priority(token)<priority(topToken) && stack.isEmpty()==0)
				{
					char temp = stack.pop();
					preFix[loop_pf] = temp;
					loop_pf--;
					topToken = stack.getTop();
				}
				stack.push(token);
			}
			else if(priority(token) == priority(topToken))
			{
				if(associativity(token)==1 && associativity(topToken)==1)
				{
					stack.push(token);
				}
				else if(associativity(token)==2 && associativity(topToken)==2)
				{
					char temp = stack.pop();
					preFix[loop_pf] = temp;
					stack.push(token);
					loop_pf--;
				}
			}
		}
		cout<<setw(20)<<left<<preFix<<endl;
		loop--;
	}
	while(stack.isEmpty()==0)
	{
		cout<<setw(20)<<left<<"NONE";
		cout<<setw(20)<<left<<stack.getTop();
		token = stack.pop();
		preFix[loop_pf] = token;
		cout<<setw(20)<<left<<preFix<<endl;
		loop_pf--;
	}
}


void expression :: printPostFix()
{
	int count ;
	cout<<"\nPOSTFIX Expression is : ";
	for(count = 0;count<postFix_size;count++)
	{
		cout<<postFix[count];
	}
	cout<<endl;
}

void expression :: printPreFix()
{
	int count ;
	cout<<"\nPREFIX Expression is  : ";
	for(count = 0;count<postFix_size;count++)
	{
		cout<<preFix[count];
	}
	cout<<endl;
}

void expression :: printExp()
{
	int count ;
	cout<<"Entered Expression is : ";
	for(count = 0;count<exp_size;count++)
	{
		cout<<exp[count];
	}
	cout<<endl;
}


int expression :: isValid()
{
	int cnt_openb=0;
	int cnt_closeb=0;
	int cnt_operand=0;
	int cnt_operator =0;
	if(exp == NULL)
	{
		cout<<"Expression not entered\nPlease enter the expression first\n";
		return 0;
	}
	else
	{
		int loop_pf=0;
		while(loop_pf<exp_size)
		{
			if(exp[loop_pf]==')')
			{
				cnt_closeb++;
			}
			else if(exp[loop_pf] == '(')
			{
				cnt_openb++;
			}

			if(isOperand(exp[loop_pf])==1)
			{
				cnt_operand++;
			}
			else if(isOperator(exp[loop_pf])==1)
			{
				cnt_operator++;
			}

			if(isOperand(exp[loop_pf])||isOperator(exp[loop_pf]) || exp[loop_pf] == '(' || exp[loop_pf] == ')')
			{
				loop_pf++;
			}
			else
				break;
		}
		if((loop_pf == exp_size) && (cnt_openb == cnt_closeb) && (cnt_operand == (cnt_operator+1)))
		{
			return 1;
		}
		else
			return 0;
	}
}

int expression :: isValid1()
{
	int loop_pf = 1;
	while(loop_pf<exp_size)
	{
		if(isOperand(exp[loop_pf-1]) && isOperand(exp[loop_pf]))
		{
			return 0;
		}
		if(isOperator(exp[loop_pf-1]) && isOperator(exp[loop_pf]))
		{
			return 0;
		}
		loop_pf++;
	}
	return 1;
}

expression :: ~expression()
{
	delete []exp;
	delete []postFix;
	delete []preFix;
}

int expression :: getPostSize()
{
	return postFix_size;
}

char* expression :: getPostFix()
{
	return postFix;
}

