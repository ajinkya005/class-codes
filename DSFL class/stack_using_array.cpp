#include<iostream>
#include<stdlib.h>
#define sz 10
using namespace std;

class Stack
{
	
	int st[sz];
	int top; 
	
	public:
		stack()
		{
			top = -1;
		}
		void push();
		void pop();
		void disp();
		int stFull()
		{
			if(top==sz-1)
				return(1);
			else
				return(0);	
		}
		int stEmpty()
		{
			if(top==-1)
				return(1);
			else
				return(0);	
			
		}
};

void Stack :: push()
{
	if(stFull()==1)
		cout<<"\n stack is full";
	else
	{
		disp();
		top++;
		cout<<"\n enter data :";
		cin>>st[top];
		disp();
			
	}	
}

void Stack :: pop()
{
	if(stEmpty()==1)
		cout<<"\n stack is empty...";
	else
	{
		
		disp();
		cout<<"\n "<<st[top]<<"  is popped...";
		top--;
		disp();	
		
	}		
		
}

void Stack :: disp()
{
	int i;
	if(stEmpty()==1)
		cout<<"\n stack is empty...";
	else
	{
		cout<<"\n top ->";
		for(i=top ; i!=-1 ; i--)
			cout<<"\t"<<st[i];
	}
	
	
}

int main()
{
	int ch;
	Stack s;
	
	do
	{
	
		cout<<"\n\n\t\t*******************MENU****************\n\n\t\t";
		cout<<"\n\t1.push";
		cout<<"\n\t2.pop";
		cout<<"\n\t3.display";
		cout<<"\n\t4.exit";
		cout<<"\n\n\t\t enter your choice :\n";
		cin>>ch;
		
		switch(ch)
		{
			case 1:
					s.push();
					break;
			
			case 2:
					s.pop();
					break;
			
			case 3:
					s.disp();
					break;
			
			case 4:
					cout<<"\n coming out......";
					break;
					
			default:
					cout<<"\n WRONG CHOICE....\n RE-ENTER CHOICE....";		
			
			
		}
		
	
		
	}while(ch!=4);
	
	
	
	return 0;
	
}

