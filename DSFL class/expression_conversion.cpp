//============================================================================
// Name        : ass.cpp
// Author      : 23129
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<string.h>
#include<math.h>
using namespace std;
class ExpConv
{

	char exp[80] , pexp[80] , st[20];
	int top;

public:
		ExpConv()
		{
			top = -1;
		}

		void input()
		{

			cout<<"\n enter expression :\n";
			cin>>exp;

		}
		void inToPost();
		void inToPost1();
		void inToPre();
		void preToPost();
		void preToInfix();
		void postToInFix();
		void postToPrefix();
		void postEval();
		void preEval();
		int prio(char);

		
		void display()
		{

			cout<<"\n infix expression is :"<<exp;
			cout<<"\n converted expression is :"<<pexp;

		}
		int isop(char ch)
		{
			if(ch=='*' || ch=='/' || ch=='+' || ch=='-' || ch== '^' || ch=='$')
				return(1);
			else
				return(0);
		}
		void push(char ch)
		{
			top++;
			st[top] = ch;
		}
		char pop()
		{
			char ch;
			ch = st[top];
			top--;
		}
		
};

int ExpConv ::prio(char ch)
{

	switch(ch)
	{
	case '^':	//return(3);
	case '$':	return(3); break;
	case '*':	//return(2);
	case '/':	return(2);break;
	case '+':	//return(1);
	case '-':	return(1);break;
	default : 	return(0);

	}

}

void ExpConv::inToPost()
{

	int i , j=0;
	top = -1;
	char ch;

	for(i=0 ; exp[i]!='\0' ; i++)
	{

		ch = exp[i];
		if(ch=='(')
			push(ch);
		else
		{
			if(isop(ch)==1)
			{
				while(top!=-1 && prio(st[top])>=prio(ch))
				{
					pexp[j] = pop();
					j++;
				}
				push(ch);
					
			}
			else
			{
				if(ch == ')')
				{
					while(top!=-1 && st[top]!='(')
					{
						pexp[j] = pop();
						j++;
					}
					top--;
				}
				else
				{
					pexp[j] = ch;
					j++;
				}
			}
		}

	}

	while(top!=-1)
	{
		pexp[j] = pop();
		j++;
	}

	pexp[j] = '\0';

	cout<<"\n postfix expression is :\t"<<pexp;

}

void ExpConv::inToPost1()
{



	int i , j=0;
	top = -1;
	char ch;

	for(i=0 ; exp[i]!='\0' ; i++)
	{

		ch = exp[i];
		if(ch=='(')
			push(ch);
		else
		{
			if(isop(ch)==1)
			{
				while(top!=-1 && prio(st[top])>=prio(ch))
				{
					pexp[j] = pop();
					j++;
				}
				push(ch);
			}
			else
			{
				if(ch == ')')
				{
					while(top!=-1 && st[top]!='(')
					{
						pexp[j] = pop();
						j++;
					}
					top--;
				}
				else
				{
					pexp[j] = ch;
					j++;
				}
			}
		}

	}

	while(top!=-1)
	{
		pexp[j] = pop();
		j++;
	}

	pexp[j] = '\0';


}


void ExpConv::inToPre()
{

	int i , j=0;
	char ch;
	strrev(exp);

	for(i=0 ; exp[i]!='\0' ; i++)
	{
		if(exp[i] == '(')
			exp[i] = ')';
		else
		{
			if(exp[i] = ')')
				exp[i] = '(';
		}
	}


	inToPost1();
	strrev(pexp);
	cout<<"\n prefix expression is :\t"<<pexp;

}


void ExpConv::preToPost()
{
	
	
	int i , top = -1;
	char ch , st[20][80] , texp[80] , opstr[2] = {" "} , oprstr[2] = {" "} , opr1[80] , opr2[80];
	
	cout<<"\n enter prefix expression :\n";
	cin>>pexp;
	
	for(i = (strlen(pexp)-1) ; i>=0 ; i--)
	{
		
		ch = pexp[i];
		
		if(isop(ch)==0)
		{
			oprstr[0] = ch;
			top++;
			strcpy(st[top] , oprstr);
		}
		else
		{
			strcpy(opr1 , st[top]);
			top--;
			strcpy(opr2 , st[top]);
			opstr[0] = ch;
			
			strcpy(texp , opr1);
			strcat(texp , opr2);
			strcat(texp , opstr);
			strcpy(st[top] , texp);
			
			
		}
		
		
		
	}
		
		cout<<"\n postfix expression is :\t"<<st[top];
}



void ExpConv::preToInfix()
{
	
	
	int i , top = -1;
	char ch , st[20][80] , texp[80] , opstr[2] = {" "} , oprstr[2] = {" "} , opr1[80] , opr2[80];
	
	cout<<"\n enter prefix expression :\n";
	cin>>pexp;
	
	for(i = (strlen(pexp)-1) ; i>=0 ; i--)
	{
		
		ch = pexp[i];
		
		if(isop(ch)==0)
		{
			oprstr[0] = ch;
			top++;
			strcpy(st[top] , oprstr);
		}
		else
		{
			strcpy(opr1 , st[top]);
			top--;
			strcpy(opr2 , st[top]);
			opstr[0] = ch;
			
			strcpy(texp , "(");
			strcat(texp , opr1);
			strcat(texp , opstr);
			strcat(texp , opr2);
			strcat(texp , ")");
			strcpy(st[top] , texp);
			
			
		}
		
		
		
	}
		
		cout<<"\n infix expression is :\t"<<st[top];
		
}


void ExpConv::postEval()
{
	
	int farr[26] , i;
	float varr[26] , opr1 , opr2 , st[20];
	char ch;
	
	strlwr(pexp);
	
	cout<<"\n postfix expression :\t"<<pexp;
	
	for(i=0 ; i<26 ; i++)
		farr[i] = 0;
		
	for(i=0 ; pexp[i]!='\0' ; i++)
	{
		
		ch = pexp[i];
		
		if(isop(ch)==0)
		{
			if(farr[ch-97] == 0)
			{
				farr[ch-97] = 1;
				cout<<"\n enter value of "<<ch<<":";
				cin>>varr[ch-97];	
			}	
		}	
		
	}	
	
	for(i=0 ; pexp[i]!='\0' ; i++)
	{
		ch = pexp[i];
		
		if(isop(ch) == 0)
		{
			top++;
			st[top] = varr[ch-97];
		}
		else
		{
			opr2 = st[top];
			top--;
			opr1 = st[top];
			
			
				switch(ch)
				{
					case '^':
					case '$':	st[top] = pow(opr1 , opr2);
								break;
					
					case '*':	st[top] = opr1 * opr2;
								break;				
								
					case '/':	st[top] = opr1 / opr2;
								break;				
					
					case '+':	st[top] = opr1 + opr2;
								break;				
								
					case '-':	st[top] = opr1 - opr2;
								break;				
								
																				
				}
			
			
		}
	}
	
	cout<<"\n result is :\t"<<st[top];
	
	
}

void ExpConv::postToPrefix()
{
			
	int i , top = -1;
	char ch , st[20][80] , texp[80] , opstr[2] = {" "} , oprstr[2] = {" "} , opr1[80] , opr2[80];
	
	cout<<"\n enter postfix expression :\n";
	cin>>pexp;
	
	for(i = 0 ; i<=(strlen(pexp)-1) ; i++)
	{
		
		ch = pexp[i];
		
		if(isop(ch)==0)
		{
			oprstr[0] = ch;
			top++;
			strcpy(st[top] , oprstr);
		}
		else
		{
			strcpy(opr2 , st[top]);
			top--;
			strcpy(opr1 , st[top]);
			opstr[0] = ch;
			
			strcpy(texp , opstr);
			strcat(texp , opr1);
			strcat(texp , opr2);
			strcpy(st[top] , texp);
			
			
		}
		
		
		
	}
		
		cout<<"\n postfix expression is :\t"<<st[top];	
	
}

void ExpConv::postToInFix()
{
	
		
	int i , top = -1;
	char ch , st[20][80] , texp[80] , opstr[2] = {" "} , oprstr[2] = {" "} , opr1[80] , opr2[80];
	
	cout<<"\n enter prefix expression :\n";
	cin>>pexp;
	
	for(i = 0 ; i<=(strlen(pexp)-1) ; i++)
	{
		
		ch = pexp[i];
		
		if(isop(ch)==0)
		{
			oprstr[0] = ch;
			top++;
			strcpy(st[top] , oprstr);
		}
		else
		{
			strcpy(opr2 , st[top]);
			top--;
			strcpy(opr1 , st[top]);
			opstr[0] = ch;
			
			strcpy(texp , "(");
			strcat(texp , opr1);
			strcat(texp , opstr);
			strcat(texp , opr2);
			strcat(texp , ")");
			strcpy(st[top] , texp);
			
			
		}
		
		
		
	}
		
		cout<<"\n infix expression is :\t"<<st[top];
	
	
}


int main()
{
	int ch;
	ExpConv exp;

	do
	{
		cout<<"\n\n\t\t *********************MENU***********************\n";
		cout<<"\n\t1.input expression";
		cout<<"\n\t2.infix to postfix conversion";
		cout<<"\n\t3.infix to prefix conversion";
		cout<<"\n\t4.exit";
		cout<<"\n\t5.prefix to postfix";
		cout<<"\n\t6.prefix to infix";
		cout<<"\n\t7.postfix evaluation";
		cout<<"\n\t8.postfix to prefix";
		cout<<"\n\t9.postfix to infix";
		cout<<"\n\n\t\t enter your choice\n";
		cin>>ch;
		
		switch(ch)
		{
			
			case 1:
					exp.input();
					break;
			
			case 2:
					exp.inToPost();
					break;
					
			case 3:
					exp.inToPre();
					break;
					
			case 4:
					return 0;
					
			case 5:
					exp.preToPost();
					break;
					
			case 6:
					exp.preToInfix();
					break;
					
					
			case 7:
					exp.postEval();
					break;
					
			case 8:
					exp.postToPrefix();
					break;
					
			case 9:
					exp.postToInFix();
					break;										
					
			default:
					cout<<"\n wrong choice...re-enter choice\n";								
					
								
			
		}		
		
	}while(1);



	return 0;

}
