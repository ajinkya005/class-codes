#include<stdio.h>

void main()
{
	
	int top = -1 , i;
	char str[80] , st[40];
	
	printf("\nenter string :\n");
	gets(str);
	
	for(i=0;str[i]!='\0';i++)
	{
		if(str[i]!=' ')
		{
			top++;
			st[top] = str[i];
		}
		else
		{
			while(top!=-1)
			{
				printf("%c",st[top]);
				top--;
			}
			
			printf(" ");
		}
		
	}
	
	while(top!=-1)
	{
		printf("%c",st[top]);
		top--;
	}
	
	
}
