#include<stdio.h>
int input(int[] , int);
void display(int[] , int);
int binary_search(int a[] , int , int , int);

int input(int a[] , int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("element[%d] :",i);
		scanf("%d",&a[i]);
		printf("\n");

	}
	return n;

}//end of input function


void display(int a[] , int n)
{
	int i=0;

	for(i=0;i<n;i++)
	{

		printf("%d",a[i]);
		printf("\t");

	}//end of for


}//end of display function

int binary_search(int a[] , int low , int high , int x)
{
	int mid;
	
	if(low>high)
	return -1;
	
	mid = (low + high)/2;
	
	if(x==a[mid])
	return a[mid];
	
	else if(x<a[mid])
	return binary_search(a[mid] , low , mid-1 , x);
	
	else
	return  binary_search(a[mid] , mid-1 , high , x);
	
}


int main()		//main function
{

	int a[10];
	int ch;
	int n , i , x , res;
	
	printf("enter no of elements to be entered :\n");
	scanf("%d",&n);

	do
	{



		printf("\nenter the choice :");
		printf("\n1.input elements");
		printf("\n2.recursive binary search");
		printf("\n3.non recursive binary search");
		printf("\n4.exit");
		printf("\n5.exit");

		scanf("%d",&ch);
		

		switch(ch)		//switch case
		{

		case 1:			//case 1 - input elements

				printf("\nenter the elements :");
				input(a , n);
				break;

		case 2:			//case 2 - bubble sort
						
				printf("\nenter the element to be searched :\n");
				scanf("%d",&x);
				res = binary_search(a , 0 , n-1 , x);
				
				if(res=a[i])
				printf("\nelement found at %d location",i+1);
				else
				return -1;
				
				break;

		case 3:			//case 3 - display
				
				
				break;

		case 4:
								break;

		case 5:
				return 0;

		default:		//default case
				printf("\nenter the valid choice");


		}//end of switch case

	}while(1);	//end of do while loop

	return 0;
}
