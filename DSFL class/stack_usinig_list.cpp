#include<iostream>
#include<stdlib.h>
using namespace std;

class Node
{
	int d;
	Node *lp;
	friend class Stack;
};

class Stack
{
	
	Node *top;
	public:
		Stack()
		{
			top = NULL;
		}
		
		void push();
		void pop();
		void disp();
		Node *getNode()
		{
			Node *n;
			n = new Node;
			n->lp = NULL;
			cout<<"\n enter data :\n";
			cin>>n->d;
			
			return(n);
		}
	
};


void Stack :: push()
{
	Node *n;
	n = getNode();
	
	if(top == NULL)
		top = n;
	else
	{
		n->lp = top;
		top = n;	
	}
	disp();		
		
}

void Stack :: pop()
{
	Node *t;
	if(top == NULL)
		cout<<"\n stack is empty.....";
	else
	{
		disp();
		cout<<"\n"<<top->d<<"  is popped";
		t = top;
		top = top->lp;
		t->lp = NULL;
		delete(t);	
		disp();
		
	}	
		
}

void Stack :: disp()
{
	Node *q;
	
	if(top == NULL)
		cout<<"\n stack is empty...";
	else
	{
		cout<<"\n top ->";
		for(q=top ; q!=NULL ; q = q->lp)
			cout<<"\t"<<q->d;
	}
		
}

int main()
{
	Stack s;
	int ch;
	
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
