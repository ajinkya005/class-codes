#include<iostream>
using namespace std;

class Node
{
	char d;
	Node *lp , *rp
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
		
		Node *getNode()
		{
			Node *n;
			n = new Node;
			
			n->lp = n->rp = NULL;
			
			return(n);
		}
		
		void create();
		void inOrder();
		void postOrder();
		
		Node *getNode()
		{
			retrurn(root);
		}
		
		int isOp(char ch)
		{
			if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '$' || ch == '^')
				return(1);
			else
				return(0);	
		}
		
};


void ET::create()
{
	
	Node *st[50] , *n;
	int top = -1 , i;
	
	
	cout<<"\n enter postfix expression :\n";
	cin.getline(pexp);
	
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
