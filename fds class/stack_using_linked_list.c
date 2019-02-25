/*write a program for implementation of stack dynamically(using linked list)*/
#include<stdio.h>
#include<stdlib.h>

struct stack
{	
	int d;
	struct stack *lp	
}*top,*n,*q;

struct stack *getnode()
{
	struct stack *n;	
	n = (struct stack*)malloc(sizeof(struct stack));
	
	n->lp = NULL;
	printf("\nenter data :\n");
	scanf("%d",&n->d);
	return(n);
}

void disp()
{
	if(top==NULL)
	printf("\nstack is empty...");
	
	else
	{
		printf("\ntop->\t");
		for(q=top;q!=NULL;q=q->lp)
			printf("%d\t",q->d);
	}
	
}

void push()
{
	int cont;
	
	do
	{
		disp();
		n = getnode();
		
		if(top==NULL)
			top = n;
		else	
		{
			n->lp = top;
			top = n;
		}
		
		disp();
		
		printf("\ncontinue (1.yes) :\n");
		scanf("%d",&cont);	
	}while(cont==1);
}

void pop()
{
	int cont;
	
	do
	{
		if(top==NULL)
		{		
			printf("\nstack is empty...");
			break;	
		}
		else
		{
			disp();
			printf("\n%d popped",top->d);
			q = top;
			top = top->lp;
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
	top = NULL;
	
	do
	{
		printf("\nenter choice\n");
		printf("\n1.push");
		printf("\n2.pop");
		printf("\n3.display");
		printf("\n4.exit");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:
					push();
					break;
			
			case 2:
					pop();
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
