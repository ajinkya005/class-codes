//============================================================================
// Name        : binary.cpp
// Author      : 23129
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Node
{
	int d , v;
	Node *lp , *rp;
	friend class BST;
};

class BST
{

		Node *root;
public:
		BST()
		{
			root = NULL;
		}
		void inOrder_recursive(Node*);
		void preOrder_recursive(Node*);
		void postOrder_recursive(Node*);
		void inOrder_non_recursive(Node*);
		void preOrder_non_recursive(Node*);
		void postOrder_non_recursive(Node*);
		void disp();
		void displev();
		void delNode();
		void create();
		void mirror_non_recursive(Node*);
		void mirror_recursive(Node*);
		void insert_non_recursive();
		void insert_recursive(Node* , Node*);
		void search(Node*);		

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

};

void BST::search(Node *r)
{
	int x;
	cout<<"\n enter no to search\n";
	cin>>x;

	if(r==NULL)
	{
		cout<<"\n empty tree...";
	
	}
	while(r!=NULL)
	{

		if(r->d==x)
		{
			cout<<"\n element found!!!";
			break;
		
		}
		
		if(x<r->d)
			r = r->lp;
		else if(x>r->d)
			r = r->rp;
		else
		{
			cout<<"\n element not found...";
			break;
		}	
					

	}
	
	


}

void BST::create()
{
	root = NULL;
	insert_non_recursive();
}

void BST::insert_non_recursive()
{

	Node *n , *r;
	int cont;

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
				if(r->d < n->d)
				{
					if(r->rp == NULL)
					{
						r->rp = n;
						break;
					}
					else
						r = r->rp;
				}
				else
				{
					if(r->d > n->d)
					{
						if(r->lp == NULL)
						{
							r->lp = n;
							break;
						}
						else
							r = r->lp;
					}
					else
					{
						cout<<"\n duplicate node created...\n";
						delete(n);
						break;
					}
				}
			}


		}

		cout<<"\n continue :(1 for yes) :\n";
		cin>>cont;

	}while(cont==1);


}


void BST::insert_recursive(Node *r , Node *n)
{

	if(r->d > n->d)
	{
		if(r->lp == NULL)
			r->lp = n;
		else
			insert_recursive(r->lp , n);
	}
	else
	{
		if(r->d < n->d)
		{
			if(r->rp == NULL)
				r->rp = n;
			else
				insert_recursive(r->rp , n);
		}
		else
		{
			cout<<"\n duplicate node...\n";
			delete(n);
			
		}

	}


}


void BST::preOrder_recursive(Node *r)
{

		if(r!=NULL)
		{

			cout<<r->d<<" ";
			preOrder_recursive(r->lp);
			preOrder_recursive(r->rp);
		}

}


void BST::inOrder_recursive(Node *r)
{

		if(r!=NULL)
		{

			inOrder_recursive(r->lp);
			cout<<r->d<<" ";
			inOrder_recursive(r->rp);
		}

}

void BST::postOrder_recursive(Node *r)
{

		if(r!=NULL)
		{

			postOrder_recursive(r->lp);
			postOrder_recursive(r->rp);
			cout<<r->d<<" ";
		}

}

void BST::preOrder_non_recursive(Node *r)
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

				if(r->rp != NULL)
				{
					r = r->rp;
					flag = 1;
				}
			}
		}while(flag == 0);

	}while(eflag == 0);

}



void BST::inOrder_non_recursive(Node *r)
{

	int top = -1 , flag , eflag = 0;
	Node *st[top];

	do
	{

		flag = 0;

		while(r!=NULL)
		{

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


		}while(flag == 0);


	}while(eflag == 0);


}


void BST::postOrder_non_recursive(Node *r)
{

	int top = -1 , flag , eflag = 0;
	Node *st[50];

	do
	{

		flag  = 0;

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

				if(r->v == 1)
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

		}while(flag == 0);


	}while(eflag == 0);


}

void BST::delNode()
{

	Node *r , *p;
	int data  , cont , i = 0;

	do
	{

		inOrder_recursive(root);

		cout<<"\n enter data :\n";
		cin>>data;

		p = r = root;

		while(r!=NULL)
		{

			if(r->d == data)
				break;
			else
			{

				if(r->d > data)
				{
					p = r;
					r = r->lp;
					i = 1;
				}
				else
				{

					p = r;
					r =  r->rp;
					i = 2;

				}

			}


		}

		if(r == NULL)
			cout<<data<<"not present.....\n";
		else
		{

			if(i == 1)
			{
				p->lp = r->rp;
				if(r->lp != NULL)
					insert_recursive(p , r->lp);
			}
			else
			{
				if(i == 2)
				{
					p->rp = r->rp;
					if(r->lp != NULL)
						insert_recursive(p , r->lp);
				}
				else
				{
					if(r->rp == NULL)
						root = r->lp;
					else
					{
						root = r->rp;
						if(r->lp != NULL)
							insert_recursive(root , r->lp);
					}
				}
			}

		}

		r->lp = r->rp = NULL;
		delete(r);
		inOrder_recursive(root);
		cout<<"\n continue deletion : (1 for yes) :\n";
		cin>>cont;

	}while(cont == 1);



}


void BST::displev()
{

	Node *q[50] , *rev;
	int f , r;

	f = r = 0;
	q[0] = root;

	while(f<=r)
	{
		rev = q[f];
		f++;

		cout<<rev->d<<" ";

		if(rev->lp != NULL)
		{
			r++;
			q[r] = rev->lp;
		}
		if(rev->rp != NULL)
		{
			r++;
			q[r] = rev->rp;
		}
	}

}


void BST::mirror_non_recursive(Node *r)
{
	
	int top = -1 , flag , eflag = 0;
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
				if(r->v == 1)
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
		}while(flag == 0);
	}while(eflag == 0);
	
}

void BST::mirror_recursive(Node *r)
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

int main()
{

	int ch , res;
	BST T;

	do
	{

		cout<<"\n\n\t\t****************MENU******************\n\n\t\t";
		cout<<"\n\t1.create";
		cout<<"\n\t2.insert";
		cout<<"\n\t3.delete";
		cout<<"\n\t4.mirror";
		cout<<"\n\t5.display";
		cout<<"\n\t6.display levelwise";
		cout<<"\n\t7.exit";
		cout<<"\n\t8.search";
		cout<<"\n\n\t\t enter your choice :\n";
		cin>>ch;

		switch(ch)
		{

		case 1:
				T.create();
				break;
				
		case 2:
				T.insert_non_recursive();
				break;
				
		case 3:
				T.delNode();
				break;
				
		case 4:
				T.inOrder_non_recursive(T.getRoot());
				cout<<" ";
				T.mirror_recursive(T.getRoot());
				T.inOrder_non_recursive(T.getRoot());
				T.mirror_recursive(T.getRoot());
				
				break;
				
		case 5:
				int choice;
				do
				{
					cout<<"\ndisplay\n1.inorder\n2.preorder\n3.postorder\n4.exit\n enter choice :\n";
					cin>>choice;
					
					switch(choice)
					{
						case 1:
								T.inOrder_recursive(T.getRoot());
								break;
								
						case 2:
								T.preOrder_recursive(T.getRoot());
								break;
								
						case 3:
								T.postOrder_recursive(T.getRoot());
								break;
							
						case 4:
								cout<<"\n coming out...";
								break;	
								
						default:
								cout<<"\n wrong choice \n re-enter choice";				
												
					}									


				}while(choice!=4);
					
					
		case 6:
				T.displev();
				break;
		
				
		case 7:
				cout<<"\n coming out....\n";
				break;							
				
		
		case 8:
				T.search(T.getRoot());
								
				break;
				
		default:	
				cout<<"\nwrong choice...";		
		
		}

	}while(ch!=7);
	
	return(0);


}



