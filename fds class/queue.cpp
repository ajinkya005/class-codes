#include<stdio.h>

#define sz 10

struct queue
{
	int q[sz] , f , r;
}Q;

int Qfull()
{
	if(Q.r==sz-1)
		return(1);
	else
		return(0);	
}

int Qempty()
{
	if(Q.f == Q.r+1)
		return(1);
	else
		return(0);	
}

void disp()
{
	int i;
	
	if(Qempty() == 1)
		printf("\nqueue is empty");
		
	else
	{
		printf("\nfront -> ");
		for(i=Q.f;i<=Q.r;i++)
			printf("%d\t",Q.q[i]);
		}	
		printf("<- rear");
}

void add()
{
	
	if(Qfull()==1)
		printf("\nqueue is full");
		
	else
	{
		disp();
		Q.r++;
		
		printf("\nneter the element :\n");
		scanf("%d",&Q.q[Q.r]);
		disp();	
	}		
	
}

void del()
{
	
	if(Qempty()==1)
		printf("\nqueue is empty");
		
		else
		{
			disp();
			printf("\n%d element deleted",Q.q[Q.f]);
			Q.f++;
			disp();
		}
	
}

int main()
{
	
	int ch;
	Q.f = 0;
	Q.r = -1;
	
	do
	{
		
		printf("\nenter the choice..\n");
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
					return 0;
			
			default:
					printf("\nINVALID CHOICE...	");
			
		}
		
	}while(1);
	
	return 0;
}
