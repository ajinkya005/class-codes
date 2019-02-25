#include<stdio.h>

void main()
{
	
	int top = -1 , st[16] , no;
	
	printf("\nenter number :");
	scanf("%d",&no);
	
	/*while(no!=0)
	{
		top++;
		st[top] =no%2;
		no = no/2;
	}*/
	
	while(top!=-1)
	{
		if(st[top]<=9)
			printf("\n%d\t",st[top]);
			
		else
			printf("%c\t",st[top+55]);	
			
		top--;	
	}
	
	while(top!=-1)
	{
		printf("\n%d\t",st[top]);

	}
		
		
	
		
}
