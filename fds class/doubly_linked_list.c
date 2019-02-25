#include<stdio.h>
#include<stdlib.h>

struct dll
{
	int d;
	struct dll *pp , *np;
};

struct dll * getnode()
{
	struct dll *n;
	n = (struct dll *)malloc(sizeof(struct dll));
	
	n->pp = n->np = NULL;
	
	printf("\nenter the data :\n");
	scanf("%d",&n->d);
	return(n);
}

void disp(struct dll *s)
{
	struct dll *q;
	
	if(s==NULL)
		printf("\nlist is empty..\n");
	else
	{
		printf("\nlist is :");
		for(q=s;q!=NULL;q=q->np)
			printf("%d\t",q->d);	
	}	
	
}

struct dll *add(struct dll *s)
{
	
	struct dll *pp , *np , *n , *p , *q;
	int pos , i , cont;
	do
	{
			
		n = getnode();
		if(s==NULL)
			s=n;
		else
		{	
			disp(s);
			printf("\nenter position :\n");
			scanf("%d",&pos);
		
			if(pos==1)
			{
				n->np = s;
				s->pp = n;
				s = n;
			}
			else
			{
				for(p=q=s , i=1; i<pos-1 && q!=NULL; p=q , q=q->np , i++);
			
				if(q==NULL)
				{
					n->pp = p;
					p->np = n;
				}
				else
				{
				
					if(q->np==NULL)
					{
						n->pp = q;
						q->np = n;
					}
					else
					{
						n->np = q->np;
						n->pp = q;
					
						(n->np)->pp = n;
						(n->pp)->np = n;
					}
				}
			}
		
	}
	
		disp(s);
		printf("\ncontinue(press 1 for yes) :\n");
		scanf("%d",&cont);	
	
	}while(cont==1);
	return(s);
}

struct dll *del(struct dll *s)
{
	
	struct dll *pp , *np , *n , *p , *q;
	int pos , i , cont;
	do
	{
			
		//n = getnode();
		if(s==NULL)
			printf("\nlist is empty....\n");
		else
		{	
			disp(s);
			printf("\nenter position :\n");
			scanf("%d",&pos);
		
			if(pos==1)
			{
				p = s;
				s = s->np;
				if(s!=NULL)
					s->pp = NULL;
					
				p->np = NULL;
				free(p);	
			}
			else
			{
				for(q=s , i=1; i<pos-1 && q!=NULL; p=q , q=q->np , i++);
			
				if(q==NULL || q->np==NULL)
					printf("\nposition out of list...");
					
				else
				{
					p= q->np;
						if(p->np==NULL)
							q->np = NULL;
					
					else
					{
						(p->np)->pp = p->pp;
						(p->pp)->np = p->np;
					}
					
					p->np = p->pp = NULL;
					free(p);
				}
		}
		
	}
	
		disp(s);
		printf("\ncontinue(press 1 for yes) :\n");
		scanf("%d",&cont);	
	
	}while(cont==1);
	return(s);
}

void dll_revert(struct dll *s)
{
	struct dll *q;
	
	if(s==NULL)
		printf("\nempty list...");
		
	else
	{
		for(q=s;q->np!=NULL;q=q->np);
		
		printf("\nlist is :");
		
		while(q!=NULL)
		{
			printf("%d\t",q->d);
			q=q->pp;	
		}	
	}	
	
}

int main()
{
	int ch;
	struct dll *s;
	
	s = NULL;
	
	do
	{
		printf("\n\n\t\tMENU\n\n\t1.add\n\t2.delete\n\t3.display\n\t4.exit\n\t5.revert dll\n\n\t\tENTER YOUR CHOICE...\n");
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
						return 0;
						break;
						
				case 5:
						dll_revert(s);
						break;		
						
				default:
						printf("\nwrong choice...");								
			}
		
	}while(ch!=4);
	
	return 0;
}
