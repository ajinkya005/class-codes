#include<stdio.h>
 void main()
 {
 	int top = -1 , st[20] , no;
	long f = 1;
	
	printf("enter no :\n");
	scanf("%d",&no);
	
	while(no>1)
	{
		top++;
		st[top] = no;
		no--;	
	}	
	
	while(top!=-1)
	{
		f = f*st[top];
		top--;
	}
	
	printf("\nfactorial is : %d",f);
 }
