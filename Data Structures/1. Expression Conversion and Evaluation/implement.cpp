#include <iostream>
#include "expression.h"
using namespace std;

int main()
{
	expression e;
	int ch,flag,flag1=0;
	float ans;
	do
	{
		cout<<"\n\n*********************\n";
		cout<<"WELCOME TO THE MENU ! \n";
		cout<<"*********************\n";

		cout<<"Which operation do you want to perform :\n		1)Input Infix Expression      - Press 1\n		2)Infix to Postfix Conversion - Press 2\n		3)Infix to Prefix Conversion  - Press 3\n		4)Evaluate PostFix            - Press 4\n		5)Evaluate PreFix             - Press 4\n";
		cout<<"Choice : ";
		cin>>ch;
		switch(ch)
		{
			case 1 :
				cout<<"\n<<<<<<<< INPUT INFIX EXPRESSION >>>>>>>>\n";
				e.setExp();
				cout<<"\n----------------------------------------\n";
				break;
			case 2 :
				cout<<"\n<<<<<<<< INFIX TO POSTFIX EXPRESSION >>>>>>>>\n";
				e.inToPostFix();
				e.printPostFix();
				flag1 = 1;
				cout<<"\n--------------------------------------------\n";
				break;
			case 3 :
				cout<<"\n<<<<<<<< INFIX TO PREFIX EXPRESSION >>>>>>>>\n";
				e.inToPreFix();
				e.printPreFix();
				cout<<"\n--------------------------------------------\n";
				break;
			case 4 :
				cout<<"\n<<<<<<<< EVALUATE EXPRESSION >>>>>>>>\n\n";
				ans = e.eval_postExp();
				cout<<"Answer : "<<ans;
				cout<<"\n\n-------------------------------------\n";
				break;
			case 5 :
				cout<<"\n<<<<<<<< EVALUATE EXPRESSION >>>>>>>>\n\n";
				ans = e.eval_preExp();
				cout<<"Answer : "<<ans;
				cout<<"\n\n-------------------------------------\n";
				break;
			default :
				cout<<"Invalid Input\n";
				break;
		}
		cout<<"\nDo you want to continue (Yes - Press 1 / No - Press 0) : ";
		cin>>flag;
	}while(flag==1);
	return 0;

}

