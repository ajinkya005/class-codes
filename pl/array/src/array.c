/*
 ============================================================================
 Name        : array.c
 Author      : kunal
 Version     :
 Copyright   : Your copyright notice
 Description : arrays  in C, Ansi-style
 ============================================================================
 */
/* header files declaration*/
#include <stdio.h>
#include <stdlib.h>

/*main program*/
int main()
{
	/* declaration of variables*/
	int a[50],b[50],limit,i,choice,element;
	printf("enter the value of limit\n");
	scanf("%d",&limit);

	printf("enter the value of choice:\n 1 for scanning the arrays,\n 2 for printing the arrays,\n 3 for comparing the arrays,\n 4 for copying the arrays'\n 5 for searching the array");
	scanf("%d",&choice);
	switch(choice)
	{
	case 1:
			/*taking input of elements of  arrays*/
			printf ("enter the elements of 1st array\n");
			for(i=0;i<limit;i++)
			    {
				    scanf("%d",&a[i]);
			    }
			printf("enter the elements of 2nd array\n");
			for(i=0;i<limit;i++)
				{
					scanf("%d",&b[i]);
				}
			break;

	case 2:
			/*printing the arrays*/
			printf("1st array is\n");
			for(i=0;i<limit;i++)
			{
				printf("%d",a[i]);
			}
			printf("\n2nd array is\n");
			for(i=0;i<limit;i++)
			{
				printf("%d",b[i]);
			}
			break;
	case 3:
			/*compare the arrays*/
			for(i=0;i<limit;i++)
			{
				if(a[i]==b[i])
		        {
					printf("arrays are equal");
		         }
				else
			    {
					printf("arrays are not equal");
		         }
	        }
			break;
	case 4:
			/*copying the array*/
			for(i=0;i<limit;i++)
			{
				int temp;
				temp=b[i];
				b[i]=a[i];
				a[i]=temp;
			}
		    printf("after copying array becomes");
			for(i=0;i<limit;i++)
			{
				printf("%d",b[i]);
			}
			break;

	case 5:
			/*SEARCHING OF A PARTICULAR ELEMENT*/
		   printf("enter the element to be searched in the 1st array");
		   scanf("%d",&element);
		   for(i=0;i<limit;i++)
		   {
			   if(a[i]==element)
			   {
				   printf("element is there in the array");
			   }
		   }
	}


	return 0;




}
