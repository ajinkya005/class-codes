#include<stdio.h>
#include<stdlib.h>

struct sll
{
	int d;
	struct sll *lp;
};

struct sll *getnode()
{
	struct sll *n;
	
	n = (struct sll *)malloc(sizeof(struct sll));
	n->lp = NULL;
	
	printf("\nenter data :\n");
	scanf("%d",&n->d);
	
	return(n);
		
}

void disp(struct sll *s)
{
	struct sll *q;
	
	if(s==NULL)
		printf("\nlist is empty...\n");
		
	else
	{
		printf("\nlist is :\n");
		for(q=s;q!=NULL;q=q->lp)
			printf("%d\t",q->d);	
	}		
}

struct sll *add(struct sll *s)
{
	struct sll *p , *q , *n;
	int pos , i , cont;
	
	do
	{
		n = getnode();
		if(s==NULL)
			s = n;
		else
		{
			disp(s);
			printf("\nenter position :\n");
			scanf("%d",&pos);
			
			if(pos==1)
			{
				n->lp = s;
				s = n;
			}
			else
			{
				for(p=q=s,i=1;i<pos-1 && q!=NULL;p=q,q=q->lp,i++);
					if(q==NULL)
						p->lp = n;
					else
					{
						n->lp = q->lp;
						q->lp = n;	
					}	
			}
		}
		
		disp(s);
		printf("\ncontinue (1:yes) :\n");
		scanf("%d",&cont);	
	}while(cont==1);
	
	return(s);	
}

struct sll *del(struct sll *s)
{
	struct sll *p , *q , *n;
	int pos , i , cont;
	
	do
	{
		if(s==NULL)
			printf("\nlist is empty...\n");
		else
		{
			disp(s);
			printf("\nenter position :\n");
			scanf("%d",&pos);
			
			if(pos==1)
			{
				p = s;
				s = s->lp;
				p->lp = NULL;
				free(p);
			}
			else
			{
				for(q=s,i=1;i<pos-1 && q!=NULL;p=q,q=q->lp,i++);
					if(q==NULL||q->lp==NULL)
						printf("\ninvalid position...\n");
					else
					{
						p = q->lp;
						q->lp = p->lp;
						p->lp = NULL;
						free(p);
					}	
			}
		}
		
		disp(s);
		printf("\ncontinue (1:yes) :\n");
		scanf("%d",&cont);	
	}while(cont==1);
	
	return(s);	
}

void sll_reverse(struct sll *s)
{
	struct sll *st[50] , *q;
	int top = -1;
	
	for(q=s ; q!=NULL ; q=q->lp)
	{
		top++;
		st[top] = q;		
	}
	
	printf("\nreverse is :\n");
	while(top!=-1)
	{
		printf("%d\t",st[top]->d);
		top--;
	}
}

struct sll *sllrevert(struct sll *s)
{
	struct sll *q , *p , *t;
	
	if(s==NULL)
		printf("\nempty list...");
	
	else
	{
		p = s;
		q = s->lp;p->lp=NULL;
		while(q!=NULL)
		{
			t = q->lp;
			q->lp = p;
			p = q;
			q = t;	
		}	
		
			s = p;
					
	}	
   return(s);
}

void sort(struct sll *s)
{
	struct sll *i , *j;
	int t;
	
	if(s==NULL)
		printf("\nlist is empty...\n");
		
	else
	{
	
		for(i=s;i->lp!=NULL;i=i->lp)
		{
			for(j=i->lp;j!=NULL;j=j->lp)
			{
				if(i->d > j->d)
				{
					t = i->d;
					i->d = j->d;
					j->d = t;
				}
			}
		}	
	
	}	
}

struct sll *merge(struct sll *s1 , struct sll *s2)
{
	struct sll *s , *l;
	
	if(s1->d <= s2->d)
	{
		s = l = s1;
		s1 = s1->lp;
	}
	else
	{
		s = l = s2;
		s2 = s2->lp;
	}
	
	while(s1!=NULL && s2!=NULL)
	{
		if(s1->d <= s2->d)
		{
			l->lp = s1;
			l = s1;
			s1 = s1->lp;
		}
		else
		{
			l->lp = s2;
			l = s2;
			s2 = s2->lp;
		}
	}
	
	if(s2!=NULL)
		l->lp = s2;
	
	if(s1!=NULL)
		l->lp = s1;
		
	return(s);		
}


int main()
{
	struct sll *s,  *s1=NULL , *s2=NULL , *s3;
	s = NULL;
	int ch;
	
	do
	{
		printf("\nenter the choice");
		printf("\n1.add");
		printf("\n2.delete");
		printf("\n3.display");
		printf("\n4.exit");
		printf("\n5.reverse");
		printf("\n6.revert");
		printf("\n7.sort and merge");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:
						s = add(s);
						break;
						
			case 2:
						s = del(s);
						break;
						
			case 3:
						disp(s);
						break;
			
			case 4:
						printf("\ncoming out...");
						break;
						
			case 5:
						sll_reverse(s);
						break;
						
			case 6:
						s = sllrevert(s);
						break;		
						
			case 7:
						//s1 = s2 = NULL;
						
						s1 = add(s1);
						s2 = add(s2);
						
						sort(s1);
						sort(s2);
						printf("\nlist 1 :");
						disp(s1);
						printf("\nlist 2 :");
						disp(s2);
						
						s3 = merge(s1 , s2);
						printf("\nsorted list :");
						disp(s3);
						
						break;							
						
			default:
						printf("\nINVALID CHOICE...");													
		}	
	}while(ch!=4);	
	
	return 0;
}	
