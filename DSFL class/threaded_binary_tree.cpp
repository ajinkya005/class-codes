#include<iostream>
using namespace std;

class Node
{
	int d , lt , rt;
	Node *lp , *rp;
	friend class TBT;
};

class TBT
{
	
	Node *root;
	public:
		TBT()
		{
			root = NULL;
		}
		
		void insert();
		void inOrder();
		void preOrder();
		void postOrder();
		
		Node *getNode()
		{
			Node *n;
			n = new Node;
			n->lp = n->rp = NULL;
			n->lt =n->rt = 1;
			
			cout<<"\n enter data :\n";
			cin>>n->d;
			
			return(n);
		}
			
};


void TBT::insert()
{
	
	int cont;
	Node *n , *r;
	
	do
	{
		n = getNode();
		
		if(root == NULL)
			root = n;
			
		else
		{
			r = root;
			
			while(1)
			{
				if(r->d >n->d)
				{
					if(r->lt==1)
					{
					
						n->lp = r->lp;
						n->rp = r;
						r->lp = n;
						r->lt = 0;
						break;	
					}
					else
						r = r->lp;
			
				}
				else
				{
					if(r->d < n->d)
					{
						if(r->rt==1)
						{
							n->lp = r;
							n->rp = r->rp;
							r->rp = n;
							r->rt = 0;
							break;	
						}
						else
							r = r->rp;	
					}
					else
					{
						delete(n);
						cout<<"\n duplicate node...\n";
						break;	
					}	
				}				
			}
		}
		
		cout<<"\ncontinue ?? (1 for yes) :\n";
		cin>>cont;
			
	}while(cont == 1);
	
}

void TBT::inOrder()
{
	
	int flag = 0;
	Node *r;
	r= root;
	
	while(r!=NULL)
	{
		while(r->lt == 0 && flag == 0)
			r = r->lp;
		
		cout<<r->d<<" ";
		
		if(r->rt == 0)
		{
			r = r->rp;
			flag = 0;	
		}
		else
		{
			r = r->rp;
			flag = 1;	
		}	
	}
	
	
}

void TBT::preOrder()
{
	
	int flag = 0;
	Node *r;
	r = root;
	
	while(r!=NULL)
	{
		
		while(r->lt == 0 && flag ==0)
		{
			
			cout<<r->d<<" ";
			r = r->lp;
			
		}
		
		if(flag == 0)
			cout<<r->d<<" ";
			
		if(r->rt == 0)
		{
			r = r->rp;
			flag = 0;
		}
		else
		{
			r = r->rp;
			flag = 1;	
		}	
	}
	
	
}

void TBT::postOrder()
{
	
	int flag = 0 , top = -1;
	Node *st[50] , *r , *t;
	r = root;
	
	while(r!=NULL)
	{
		
		while(r->lt == 0 && flag ==0)
		{
			top++;
			st[top] = r;
			r = r->lp;
		}
		
		if(r->rt == 0)
		{
			top++;
			st[top] = r;
			r = r->rp;
			flag = 0;
		}
		else
		{
			cout<<r->d<<" ";
			t = r->rp;
			flag = 1;
			
			while(top!= -1 && st[top]!=t)
			{
				cout<<st[top]->d<<" ";
				top--;
			}
			
			r = t;
			top--;
			
		}
		
	}
	
	
}


int main()
{
	
	int ch;
	TBT T;
	
	do
	{
		cout<<"\n\n\t\t***************MENU******************";
		cout<<"\n\t1.insert";
		cout<<"\n\t2.inorder";
		cout<<"\n\t3.preorder";
		cout<<"\n\t4.postorder";
		cout<<"\n\t5.exit";
		cin>>ch;
		
		switch(ch)
		{
			
			case 1:
						T.insert();
						break;
						
			case 2:
						T.inOrder();
						break;
						
			case 3:
						T.preOrder();
						break;
						
			case 4:
						T.postOrder();
						break;
						
			case 5:
						cout<<"\n coming out....\n";
						break;
						
			default:
						cout<<"\n wrong choice...\n";
													
								
		}
			
	}while(ch!=5);
	
	return 0;
	
}
