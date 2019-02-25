#include<stdio.h>

#define sz 10

struct stack
{
	int st[sz] , top;
}S;

int stfull()
{
	if(S.top==sz-1)
		return(1);
	else
		return(0);	
}

int stempty()
{
	if(S.top == -1)
		return(1);
	else
		return(0);	
}

void disp()
{
	int i;
	
	if(stempty() == 1)
		printf("\nstack is empty");
		
	else
	{
		printf("\ntop -> ");
		for(i=S.top;i>0;i--)
			printf("%d\t",S.st[i]);
		}	
}

void push()
{
	
	if(stfull()==1)
		printf("\nstack is full");
		
	else
	{
		disp();
		S.top++;
		
		printf("\nneter the element :\n");
		scanf("%d",&S.st[S.top]);
		disp();	
	}		
	
}

void pop()
{
	
	if(stempty()==1)
		printf("\nstack is empty");
		
		else
		{
			disp();
			printf("\n%d element popped",&S.st[S.top]);
			S.top--;
			disp();
		}
	
}

int main()
{
	
	int ch;
	S.top = -1;
	
	do
	{
		
		printf("\nenter the choice..\n");
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
					return 0;
			
			default:
					printf("\nINVALID CHOICE...	");
			
		}
		
	}while(1);
	
	return 0;
}
