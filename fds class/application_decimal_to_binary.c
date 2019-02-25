#include<stdio.h>

void main()
{
	
	int top = -1 , st[16] , no;
	
	printf("\nenter number :");
	scanf("%d",&no);
	
	while(no!=0)
	{
		top++;
		st[top] = no%2;
		no = no/2;
	}
	
	printf("\nbinary equivalent is :\n");
	
	while(top!=-1)
	{
		printf("%d\t",st[top]);
		top--;
	}
		
}
