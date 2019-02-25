/*write a program for implementation of queue dynamically(using linked list)*/
#include<stdio.h>
#include<stdlib.h>

struct Queue
{	
	int d;
	struct Queue *lp	
}*f,*r,*n,*q;

struct Queue *getnode()
{
	struct Queue *n;	
	n = (struct Queue*)malloc(sizeof(struct Queue));
	
	n->lp = NULL;
	printf("\nenter data :\n");
	scanf("%d",&n->d);
	return(n);
}

void disp()
{
	if(f==NULL)
	printf("\nQueue is empty...");
	
	else
	{
		printf("\ntop->\t");
		for(q=f;q!=NULL;q=q->lp)
			printf("%d\t",q->d);
		
		printf("<-rear");	
	}
	
}

void add()
{
	int cont;
	
	do
	{
		disp();
		n = getnode();
		
		if(f==NULL)
			f = r = n;
		else	
		{
			r->lp = n;
			r = n;
		}
		
		disp();
		
		printf("\ncontinue (1.yes) :\n");
		scanf("%d",&cont);	
	}while(cont==1);
}

void del()
{
	int cont;
	
	do
	{
		if(f==NULL)
		{		
			printf("\nQueue is empty...");
			break;	
		}
		else
		{
			disp();
			printf("\n%d deleted",f->d);
			q = f;
		 	f = f->lp;
			q->lp = NULL;
			free(q);
			disp();
		}
		printf("\ncontinue (1.yes) :\n");
		scanf("%d",&cont);
	}while(cont==1);
}

int main()
{
	int ch;
	f = r = NULL;
	
	do
	{
		printf("\nenter choice\n");
		printf("\n1.add");
		printf("\n2.delete");
		printf("\n3.display");
		printf("\n4.exit");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:
					add();
					break;
			
			case 2:
					del();
					break;
			
			case 3:
					disp();
					break;
			
			case 4:
					printf("\ncoming out");
					break;
					
			default:
					printf("\nwrong choice...");		
		}
	}while(ch!=4);
	
	return 0;
}
