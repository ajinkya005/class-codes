#include<iostream>
using namespace std;

class Node
{
	char d;
	Node *lp , *rp;
	friend class ET;
};

class ET
{
	Node *root;
	char pexp[30];
	
	public:
		ET()
		{
			root = NULL;
		}
		
		Node* getNode()
		{
			Node *n;
			n = new Node;
			
			n->lp = n->rp = NULL;
			
			return(n);
		}
		
		void create();
		void inOrder_non_recursive(Node*);
		void postOrder_recursive(Node*);
		void preOrder_non_recursive(Node*);
		
		int isOp(char ch)
		{
			if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '$' || ch == '^')
				return(1);
			else
				return(0);	
		}
		
		Node* getroot()
		{
			return(root);
		}
		
};


void ET::create()
{
	
	Node *st[50] , *n;
	int top = -1 , i;
	
	
	cout<<"\n enter postfix expression :\n";
	cin>>pexp;
	
	for(i=0 ; pexp[i]!='\0' ; i++)
	{
		n = getNode();
		
		n->d = pexp[i];
		
		if(isOp(pexp[i])==0)
		{
			top++;
			st[top] = n;
		}
		else
		{
			n->rp = st[top];
			top--;
			n->lp = st[top];
			st[top] = n;		
		}
		
		root = st[top];		
	}
	
	
	
}

void ET::preOrder_non_recursive(Node *r)
{
	
	int top = -1 , flag , eflag = 0;
	Node *st[50];
	
	do
	{
		flag = 0;
		
		while(r!=NULL)
		{
			cout<<r->d<<" ";
			top++;
			st[top] = r;
			r = r->lp;
		}
		
		do
		{
			if(top == -1)
			{
				eflag = 1;
				break;
			}
			
			else
			{
				r = st[top];
				top--;
				
				if(r->rp!=NULL)
				{
					r = r->rp;
					flag = 1;
				}
			}
		}while(flag==0);
	}while(eflag==0);
	
	
	
}

void ET::inOrder_non_recursive(Node *r)
{
	
	int top = -1 , flag , eflag = 0;
	Node *st[50];
	
	do
	{
		flag = 0;
		
		while(r!=NULL)
		{
			//cout<<r->d<<" ";
			top++;
			st[top] = r;
			r = r->lp;
		}
		
		do
		{
			if(top == -1)
			{
				eflag = 1;
				break;
			}
			
			else
			{
				r = st[top];
				top--;
				
				cout<<r->d<<" ";	
				
				if(r->rp!=NULL)
				{
					r = r->rp;
					flag = 1;
				}
			}
		}while(flag==0);
	}while(eflag==0);
	
	
	
}

void ET::postOrder_recursive(Node *r)
{

		if(r!=NULL)
		{

			postOrder_recursive(r->lp);
			postOrder_recursive(r->rp);
			cout<<r->d<<" ";
		}

}

int main()
{

	ET T;
	
	T.create();cout<<"\n";

	cout<<"preorder expression :\t";
	T.preOrder_non_recursive(T.getroot());cout<<"\n";
	
	cout<<"inorder expression :\t";
	T.inOrder_non_recursive(T.getroot());cout<<"\n";
	
	cout<<"postorder expression :\t";
	T.postOrder_recursive(T.getroot());cout<<"\n";
	
	
return(0);	
	
}
