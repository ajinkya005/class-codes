#include<iostream>
using namespace std;

class Node
{
	int d;
	int v;
	Node *lp , *rp;
	
	friend class BT;
};

class BT
{
	Node *root , *c;
	
	
	public:
		BT()
		{
			root = NULL;
			c = NULL;
		}
		
		void insert_non_recursive();
		void insert_recursive();
		void preOrder_recursive(Node*);
		void inOrder_recursive(Node*);
		void postOrder_recursive(Node*);
		void preOrder_non_recursive(Node*);
		void inOrder_non_recursive(Node*);
		void postOrder_non_recursive(Node*);
		void leafNodes(Node*);
		void mirror_recursive(Node*);
		void mirror_non_recursive(Node*);
		int depth(Node*);
		Node *copy(Node*);
		//void dispCopy();
		
		Node *getNode()
		{
			Node *n;
			n = new Node;
			n->lp = n->rp = NULL;
			
			cout<<"\n enter data :\n";
			cin>>n->d;
			
			return(n);
		}
		
		
		Node *getRoot()
		{
			return(root);
		}
		
		Node *getCopy()
		{
			return(c);
		}

};

void BT::insert_non_recursive()
{
	int cont , lr;
	Node *n , *r;
	
	do
	{
		n = getNode();
		
		if(root==NULL)
			root = n;
			
		else
		{
			r = root;
			
			while(1)
			{
				cout<<"\n want to enter \n 1.for left\n any other key for right of\t"<<r->d<<":\n";
				cin>>lr;
				
				if(lr==1)
				{
					if(r->lp==NULL)
					{
						r->lp = n;
						break;
					}				
					else
						r = r->lp;						
							
				}
				else
				{
					if(r->rp==NULL)
					{
						r->rp = n;
						break;	
					}
					else
						r = r->rp;	
				}	
			}	
		}
		
		cout<<"\n continue ? (1 for yes) :\n";
		cin>>cont;
			
	}while(cont==1);
	
}


void BT::preOrder_recursive(Node *r)
{

		if(r!=NULL)
		{

			cout<<r->d<<" ";
			preOrder_recursive(r->lp);
			preOrder_recursive(r->rp);
		}

}


void BT::inOrder_recursive(Node *r)
{

		if(r!=NULL)
		{

			inOrder_recursive(r->lp);
			cout<<r->d<<" ";
			inOrder_recursive(r->rp);
		}

}

void BT::postOrder_recursive(Node *r)
{

		if(r!=NULL)
		{

			postOrder_recursive(r->lp);
			postOrder_recursive(r->rp);
			cout<<r->d<<" ";
		}

}


void BT::preOrder_non_recursive(Node *r)
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

void BT::inOrder_non_recursive(Node *r)
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

void BT::leafNodes(Node *r)
{
	
	int top = -1 , flag , eflag = 0;
	Node *st[50];
	
	do
	{
		flag = 0;
		
		while(r!=NULL)
		{
			//cout<<r->d<<" ";
			
			if(r->lp==NULL && r->rp==NULL)
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
				
				//cout<<r->d<<" ";	
				
				if(r->rp!=NULL)
				{
					r = r->rp;
					flag = 1;
				}
			}
		}while(flag==0);
	}while(eflag==0);
	
	
	
}

void BT::postOrder_non_recursive(Node *r)
{
	
	int top = -1 , flag , eflag = 0;
	Node *st[50];
	
	do
	{
		flag = 0;
		
		while(r!=NULL)
		{
			//cout<<r->d<<" ";
			
			//if(r->lp==NULL && r->rp==NULL)
			//	cout<<r->d<<" ";
			
			r->v = 1;
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
				
				//cout<<r->d<<" ";	
				
				if(r->v==1)
				{
					r->v = 2;
					top++;
					st[top] = r;
					r = r->rp;
					break;
				}
				else	
					cout<<r->d<<" ";
			}
		}while(flag==0);
	}while(eflag==0);
	
	
	
}

void BT::mirror_recursive(Node *r)
{
	Node *t;
	
	if(r!=NULL)
	{
		mirror_recursive(r->lp);
		mirror_recursive(r->rp);
		
		t = r->lp;
		r->lp = r->rp;
		r->rp = t;
	}
}

void BT::mirror_non_recursive(Node *r)
{
	
	int top = -1 , flag , eflag= 0;
	Node *st[50] , *t;
	
	do
	{
		flag = 0;
		
		while(r!=NULL)
		{
			r->v = 1;
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
				
				if(r->v==1)
				{
					r->v = 2;
					top++;
					st[top] = r;
					r = r->rp;
					break;
				}
				else
				{
					t = r->lp;
					r->lp = r->rp;
					r->rp = t;
				}
			}
		}while(flag==0);
	}while(eflag==0);
	
	
	
}

int BT::depth(Node *r)
{
	
	if(r==NULL)
		return(-1);
	else
	{
		int l = depth(r->lp);
		int m = depth(r->rp);
		
		
		if(l>m)
			return(l+1);
		else
			return(m+1);		
	}	
		
}



Node* BT::copy(Node *r)
{
	Node *t;
	
	if(r!=NULL)
	{
		t->lp = copy(r->lp);
		t->rp = copy(r->rp);
		t->d = r->d;
		
		return(t);
	}
}
  
int main()
{
	 
	int ch , d;
	BT T;
	Node *m;
	
	do
	{
		cout<<"\n\n\t\t********************MENU*************************";
		cout<<"\n\t1.insert";
		cout<<"\n\t2.preorder";
		cout<<"\n\t3.inorder";
		cout<<"\n\t4.postorder";
		cout<<"\n\t5.display leaf nodes";
		cout<<"\n\t6.mirror";
		cout<<"\n\t7.depth";
		cout<<"\n\t8.copy";
		cout<<"\n\t9.exit";
		cin>>ch;
		
		switch(ch)
		{
			case 1:
					T.insert_non_recursive();
					break;
					
			case 2:
					T.preOrder_non_recursive(T.getRoot());
					break;		
			
			case 3:
					T.inOrder_non_recursive(T.getRoot());
					break;		
			
			case 4:
					T.postOrder_non_recursive(T.getRoot());
					break;		
			
			case 5:
					T.leafNodes(T.getRoot());
					break;		
			
			case 6:
					T.inOrder_non_recursive(T.getRoot());
					T.mirror_non_recursive(T.getRoot());
					T.inOrder_non_recursive(T.getRoot());
					T.mirror_non_recursive(T.getRoot());
					break;		
			
			case 7:
					  d = T.depth(T.getRoot());
					
					 if(d==-1)
					 	cout<<"\n empty tree...\n";
					else
						cout<<"\n depthn of tree is :"<<d<<endl;	 	
					break;		
			
			case 8:
					  
					  break;		
			
			case 9:
					cout<<"\n coming out....\n";
					break;		
			
			default:
					cout<<"\n wrong choice...\n";
			
		}
	}while(ch!=9);
	
	
	
	
	
	
	
return 0;	
	
}
