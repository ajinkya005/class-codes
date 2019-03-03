#include<iostream>
using namespace std;

class Node
{
	int d;
	Node* lp , *rp;
	friend class BST;
	
		
};

class BST
{
	Node *root;
	public:
		BST()
		{
			root  = NULL;
		}
		
		void insert_recursive(Node* , Node*);
		void insert_non_recursive();
		void preOrder_non_recursive(Node*);
		void inOrder_non_recursive(Node*);
		void postOrder_recursive(Node*I);
		void del();
		void displev();
		void mirror_recursive(Node*);
		void search(Node* , int);
		Node* getNode()
		{
			Node* n;
			n = new Node;
			n->lp = n->rp = NULL;
			cout<<"\n enter data :\n";
			cin>>n->d;
			
			return(n);
		}
		Node* getroot()
		{
			return(root);
		}
};


void BST::insert_non_recursive()
{
	Node* r , *n;
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
			if(n->d > r->d)
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
				if(n->d < r->d)
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
					cout<<"\n duplicate element.....";
					delete(n);
				}
				
			}
		}
		
		
	}	
	
		
	cout<<"\n do you want to continue (1: yes) :\n";
	cin>>cont;
			
	}while(cont==1);
	
		
}

void BST::insert_recursive(Node* r , Node* n)
{
	
	if(n->d > r->d)
	{
		if(r->rp == NULL)
		{
			r->rp = n;
		}
		else
			insert_recursive(r->rp , n);
	}
	else
	{
		if(n->d <r->d)
		{
			if(r->lp == NULL)
				r->lp = n;
			else
			    insert_recursive(r->lp , n);	
		}
		else
		{
			cout<<"\n duplicate element...\n";
			delete(n);
		}
	}
	
		
}

void BST::preOrder_non_recursive(Node* r)
{
	
	int top = -1 , cont , flag  , eflag=0;
	Node* st[50];

do
{
	
		while(r!=NULL)
	{
		cout<<"\t"<<r->d;
		top++;
		st[top] = r;
		r = r->lp;
	}
	
	do
	{
		flag = 0;
		if(top==-1)
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

void BST::inOrder_non_recursive(Node* r)
{
	
	int top = -1 , cont , flag  , eflag=0;
	Node* st[50];
	

	do
	{
			
		
	while(r!=NULL)
	{
		//cout<<"\t"<<r->d;
		top++;
		st[top] = r;
		r = r->lp;
	}
	
	do
	{
		flag = 0;
		if(top==-1)
		{
			eflag = 1;
			break;
		}
		else
		{
			r = st[top];
			top--;
			
			cout<<"\t"<<r->d;
			
			if(r->rp!=NULL)
			{
				r = r->rp;
				flag = 1;
			}
			
		}
		
				
	}while(flag==0);
	
		
			
				
	}while(eflag==0);
	
}

void BST::postOrder_recursive(Node* r)
{
	
	if(r!=NULL)
	{
		postOrder_recursive(r->lp);
		postOrder_recursive(r->rp);
		cout<<"\t"<<r->d;
	}
	
}

void BST::mirror_recursive(Node* r)
{
	
	Node* t;
	
	if(r!=NULL)
	{
		mirror_recursive(r->lp);
		mirror_recursive(r->rp);
		
		t = r->lp;
		r->lp = r->rp;
		r->rp = t;
	}
		
}
/*
void BST::del()
{
	
	int data , cont, i=0;
	Node*r , *p;
	
	
	do
	{
		
		inOrder_non_recursive(root);
		cout<<"\n enter data :\n";
		cin>>data;
		
		p = r = root;
		
		while(r!=NULL)
		{
			
			if(r->d==data)
				break
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
					r = r->rp;
					i = 2;	
				}	
			}	
						
		}
		
		if(r == NULL)
			cout<<"\n"<<data<<"not present...";
		else
		{
			
			if(i==1)
			{
				p->lp = r->rp;
				if(r->lp!=NULL)
					insert_recursive(p , r->lp);
			}
			else
			{
				if(i==2)
				{
					p->lp = r->rp;
					if(r->lp!=NULL)
						insert_recursive(p , r->lp);
				}
				else
				{
					
					if(r->rp == NULL)
						root = r->lp;
					else
					{
						root = r->rp;
						if(r->lp!=NULL)
							insert_recursive(p , r->lp);
					}
				}
			
			}
				
		}
		
		
		r->lp = r->rp = NULL;
		delete(r);
		
		inOrder_non_recursive(root);		
		
		cout<<"\n continue (1.yes):\n";
		cin>>cont;
	}while(cont==1);
	
	
}
*/

void BST::del()
{
	int cont , data , i;
	Node* r , *p;
	
	do
	{
		inOrder_non_recursive(root);
		cout<<"\n enter data to delete :\n";
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
						r = r->rp;
						i = 2;	
						
					}	
				}
			}
				
				if(r==NULL)
					cout<<"\n "<<data<<"not found";	
				else
				{
					
					if(i==1)
					{
						p->lp = r->rp;
						if(r->lp!=NULL)
							insert_recursive(p , r->lp);
					}
					else
					{
						
						if(i == 2)
						{
							
							p->rp = r->rp;
							if(r->lp!=NULL)
								insert_recursive(p , r->lp);
							
						}
						else
						{
							if(r->rp == NULL)
								root = r->lp;
							else
							{
								root = r->rp;
								if(r->lp!=NULL)
									insert_recursive(root , r->lp);	
							}	
						}
						
					}					
					
				}
				
				
			r->lp = r->rp = NULL;
			delete(r);
			inOrder_non_recursive(root);
			
			cout<<"\n continue ?? (1.yes) :\n";
			cin>>cont;	
		
				
	}while(cont==1);
	
	
}

void BST::search(Node *r , int x)
{
	
	if(r==NULL)
		cout<<"\n element not found...";
	else
	{
		
		if(r->d == x)
			cout<<"element found!!!";
		else
		{
			
			if(r->d > x)
				search(r->lp , x);
			else
				search(r->rp , x);	
				
		}		
		
		
	}	
	
	
	
	
}

void BST::displev()
{
	
	Node *q[50] , *r;
	int f , rear;
	
	q[0] = root;
	f = rear = 0;
	
	
	while(f<=rear)
	{
		
		r = q[f];
		f++;
		
		cout<<r->d<<"\t";
		
		if(r->lp!=NULL)
		{
			rear++;
			q[rear] = r->lp;
		}
		if(r->rp!=NULL)
		{
			rear++;
			q[rear] = r->rp;
		}
		
			
	}
	
	
}


int main()
{
	
	BST b;
	int ch;
	
	do
	{
		cout<<"\n\n\t\t******************MENU*******************";
		cout<<"\n\t1.insert";
		cout<<"\n\t2.inorder";
		cout<<"\n\t3.preorder";
		cout<<"\n\t4.postorder";
		cout<<"\n\t5.mirror";
		cout<<"\n\t6.delete";
		cout<<"\n\t7.search";
		cout<<"\n\t8.display levelwise";
		cout<<"\n\t9.exit";
		cout<<"\n\n\t\tenter your choice :\n";
		cin>>ch;
		
		switch(ch)
		{
			
			case 1:
						b.insert_non_recursive();
						break;
			
			case 2:	
						b.inOrder_non_recursive(b.getroot());
						break;
						
			case 3:
						b.preOrder_non_recursive(b.getroot());
						break;
						
			case 4:
						b.postOrder_recursive(b.getroot());
						break;
						
			case 5:
						b.inOrder_non_recursive(b.getroot());
						b.mirror_recursive(b.getroot());
						b.inOrder_non_recursive(b.getroot());
						b.mirror_recursive(b.getroot());
						break;
						
			case 6:
						b.del();
						break;
						
			case 7:
				
						int x;
						cout<<"\n enter element to search :\n";
						cin>>x;
						
						b.search(b.getroot() , x);
						break;			
						
			case 8:
						b.displev();
						break;
						
			case 9:
						return 0;																						
			
			
			
			
			
			
		}		
	}while(ch!=9);
	
	
	
	
	
	
	
	
}


