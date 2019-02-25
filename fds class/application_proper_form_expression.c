#include<stdio.h>

void main()
{
	int top = -1 , i , flag;
	char str[80] , st[40];
	
	printf("\nenter the expression in paranthesis :\n");
	gets(str);
	
	for(i=0;str[i]!='\0';i++)
	{
		
		if(str[i]=='(')
		{
			top++;
			st[top] = '(';
		}
		else
		{
			if(str[i]==')')
			{
				if(top==-1)
				{
					flag = 1;
					break;
				}
				else
					top--;
			}
		}
		
	}
	if(top!=-1)
		flag=1;
	if(flag==0)
		printf("\nexpression is in proper form.");
	else
		printf("\nexpression is not in proper form...");		

}
