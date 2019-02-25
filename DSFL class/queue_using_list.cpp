#include<iostream>
#include<stdlib.h>
using namespace std;

class Node
{	
	int d;
	Node *lp;	
	friend class Queue;
};

class Queue
{
	Node *f , *r;
	
	public:
		Queue()
		{
			f = r = NULL;
		}
		
		void add();
		void del();
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


void Queue :: add()
{
	Node *n;
	n = getNode();
	
	if(f==NULL)
		f = r = n;
	else
	{
		r->lp = n;
		r = n;
	}
	disp();	
		
}

void Queue :: del()
{
	
	Node *t;
	if(f==NULL)
		cout<<"\n queue is empty....";
	else
	{
		disp();
		cout<<"\n "<<f->d<<"  element is deleted";
		
		t = f;
		f = f->lp;
		t->lp = NULL;
		delete(t);
		disp();
				
	}
	
}

void Queue :: disp()
{
	
	Node *q;
	
	if(f==NULL)
		cout<<"\n queue is empty...";
	else
	{
		
		cout<<"\n front ->";
		for(q=f ; q!=NULL ; q=q->lp)
			cout<<"\t"<<q->d;
		
		cout<<"\t"<<"<- rear";	
		
	}	
	
	
}

int main()
{
	int ch;
	Queue q;
	
	do
	{
	
		cout<<"\n\n\t\t******************MENU*******************\n\n\t\t";
		cout<<"\n\t1.add";
		cout<<"\n\t2.delete";
		cout<<"\n\t3.display";
		cout<<"\n\t4.exit";
		cout<<"\n\n\t\t enter your choice :\n";
		cin>>ch;
		
		switch(ch)
		{
			
				case 1:
						q.add();
						break;
						
				case 2:
						q.del();
						break;
			
				case 3:
						q.disp();
						break;
			
				case 4:
						cout<<"\n coming out...";
						break;
			
				default:
						cout<<"\n enter correct choice....";			
						
		}
		
	}while(ch!=4);
	
	return 0;
	
}
