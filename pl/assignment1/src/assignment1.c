/*
 ============================================================================
 Name        : assignment1.c
 Author      : kunal sachdev
 Roll no     : 23132
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
//declaration of functions
int setunion(int set1[],int set2[],int set3[],int lim1,int lim2);
int intersection(int set1[],int set2[],int set3[],int lim1,int lim2);
int difference1(int set1[],int set2[],int set3[],int lim1,int lim2);
int difference2(int set1[],int set2[],int set3[],int lim1,int lim2);
int symmetric(int set1[],int set2[],int set3[],int lim1,int lim2);

int main(void)
{
	//declaration of variables
	int set1[10];
	int set2[10];
	int set3[20];
	int set4[20];
	int set5[20];
	int lim1,lim2,i,j,chk=1;
	int choice;
	int lim4=0;
	int lim5=0;
	while(chk)
	{
	int lim3=0;
	printf("*********Enter choice***********:\n 1 for input,\n 2 for displaying the sets,\n 3 for union of set,\n 4 for intersection of sets,\n 5 for the difference of sets,\n 6 for the symmetric difference,\n 7 for exit ");
	scanf("%d",&choice);
    switch(choice)
    {
    case 1:
    		//input of sets
    		printf("for set 1\n");
    		lim1=input(set1);
    		printf("for set2\n");
    		lim2=input(set2);
    		break;
    case 2:
    		//diplaying the sets
    		printf(" set1 is");
    		display(set1,lim1);
    		printf( "set2 is");
    		display(set2,lim2);
    		break;
    case 3:
    		//union of sets
    		printf("UNION OPERATION\n");
    		printf(" set1 is");
    		display(set1,lim1);
    		printf("set2 is");
    		display(set2,lim2);
    		lim3=setunion(set1,set2,set3,lim1,lim2);
    		printf("Set of union is");
    		display(set3,lim3);
    		break;
    case 4:
    		//intersection of sets
    		printf("INTERSECTION OPERATION\n");
    		printf(" set1 is");
    		display(set1,lim1);
    		printf("set2 is");
    		display(set2,lim2);
    		lim3=intersection(set1,set2,set3,lim1,lim2);
    		printf("Intersection set is");
    		display(set3,lim3);
    		break;
    case 5:
		//difference of sets
		printf("DIFFERENCE OPERATION\n");
		printf(" set1 is");
    	display(set1,lim1);
    	printf("set2 is");
    	display(set2,lim2);
    	lim4=difference1(set1,set2,set4,lim1,lim2);
    	lim5=difference2(set1,set2,set5,lim1,lim2);
		printf("Set of set2-set1 is");
		display(set4,lim4);
		printf("Set of set1-set2 is");
		display(set5,lim5);
		break;
    case 6:
    		// symmetric difference of sets
    		printf("SYMMETRIC DIFFERENCE OPERATION\n");
    		printf(" set1 is");
    		display(set1,lim1);
    		printf("set2 is");
    		display(set2,lim2);
    		lim3=symmetric(set4,set5,set3,lim4,lim5);
    		printf("Set of symmetric difference is");
		display(set3,lim3);
    		break;		
    case 7:
    		//exit
    		chk=0;
    		break;
	}
}
	 return 0;
}
int input(int set[])//function for input the sets
{
	int lim,i;
	do              //validation for size of set
	{
		printf("Enter the size of set\n");
		scanf("%d",&lim);
		if((lim<0)||(lim>10)) //comparison of size of set
		{
		printf("INVALID SIZE!!!!!!!\n");
		}
	}
	while((lim<0)||(lim>10));  //for repetition of loop
	printf("Enter the elements of set considering Universal set as{1,2,3,....,100}\n");
	int j;
	for(i=0;i<lim;i++)
	{
		printf("Element %d:",i+1);
		scanf("%d",&set[i]);
		if(i==0&&set[i]>100)	//checking first element to be in universal set
		{
			printf("Element does not belong to Universal set\n");
			i--;
		}
	    for(j=i-1;j>=0;j--)    //validation for non-repeated elements of set
	    {
	    	if(set[i]==set[j]) //comparison of elements of set
	    	{
	    		printf("Duplicate element is not allowed!!!!!\n");
	    		i--;
	    		continue;
	    	}
	    	else if(set[i]>100) //comparison of element to be part of universal set
	    	{
	    		printf("Element does not belong to Universal set\n");
	    		i--;
	    		continue;
			}
	    }
	}
	return lim;
}
int display(int set[],int size) //function for displaying the sets
{
	int i;
	printf(" :{");
	for(i=0;i<size;i++)
	{
	    printf("%d,",set[i]);
	}
	printf("}\n");
}
int setunion(int set1[],int set2[],int set3[],int lim1,int lim2)//function for union of sets
{
	int lim3=0,i,j;
	for(i=0;i<lim1;i++)   //copying set1 in set3
	{
		set3[lim3]=set1[i];
		lim3++;
	}

	for(j=0;j<lim2;j++)  //finding uncommon elements in set1 and set2
	{
		for(i=0;i<lim1;i++)
		{
			if(set2[j]==set1[i])
			break;//stop the inner for loop if common elements found
		}
		if(i==lim1)     //copying uncommon elements of set1 and set2 in set3
		{
			set3[lim3]=set2[j];
			lim3++;
		}
	}
	return lim3;
}
int intersection(int set1[],int set2[],int set3[],int lim1,int lim2)//function for intersection of sets
{   
	int lim3=0,i,j;
	for(j=0;j<lim2;j++)
    {
		for(i=0;i<lim1;i++)
		{
			if(set2[j]==set1[i])    //finding common elements in set1 and set2
			{
				set3[lim3]=set2[j];//copying common elements in set3
				lim3++;
			}
		}
			
	}
    return lim3;
}
int difference1(int set1[],int set2[],int set3[],int lim1,int lim2)//function for difference set2-set1
{
	int lim3=0,i,j;	
	for(j=0;j<lim2;j++)
	{
		for(i=0;i<lim1;i++)
		{
			if(set2[j]==set1[i])//comparison of elements of set1 and set2
			break;//stop the inner for loop if common elements found
		}
		if(i==lim1)
		{	
			set3[lim3]=set2[j];//copying of uncommon elements of set2 which are not in set1 in set3
			lim3++;
		}
	}
	return lim3;	
}
int difference2(int set1[],int set2[],int set3[],int lim1,int lim2)//function for difference set1-set2
{
	int lim3=0,i,j;
	for(i=0;i<lim1;i++)
    {
		for(j=0;j<lim2;j++)
		{
			if(set1[i]==set2[j])//comparison of elements of set1 and set2
			break;//stop the inner for loop if common elements found
		}
		if(j==lim2)
		{	
			set3[lim3]=set1[i];//copying of uncommon elements of set1 which are not in set2 in set3
			lim3++;
		}
	}
	return lim3;	
}
int symmetric(int set1[],int set2[],int set3[],int lim1,int lim2)//function for symmetric difference
{
	int lim3=0,i,j;
	for(i=0;i<lim1;i++) //copying set1 in set3
	{
    	set3[lim3]=set1[i];
    	lim3++;
    }
	for(j=0;j<lim2;j++) //finding uncommon elements in set1 and set2
    {
		for(i=0;i<lim1;i++)
		{
			if(set2[j]==set1[i])
			break;//stop the inner for loop if common elements found
		}
		if(i==lim1) //copying uncommon elements of set1 and set2 in set3
		{
			set3[lim3]=set2[j];
			lim3++;
		}
	}
	return lim3;
}
/* **********output***********
*********Enter choice***********:
 1 for input,
 2 for displaying the sets,
 3 for union of set,
 4 for intersection of sets,
 5 for the difference of sets,
 6 for the symmetric difference,
 7 for exit 1
for set 1
Enter the size of set
12
INVALID SIZE!!!!!!!
Enter the size of set
3
Enter the elements of set considering Universal set as{1,2,3,....,100}
Element 1:101
Element does not belong to Universal set
Element 1:1
Element 2:1
Duplicate element is not allowed!!!!!
Element 2:1
Duplicate element is not allowed!!!!!
Element 2:2
Element 3:3
for set2
Enter the size of set
4
Enter the elements of set considering Universal set as{1,2,3,....,100}
Element 1:1
Element 2:3
Element 3:4
Element 4:5
*********Enter choice***********:
 1 for input,
 2 for displaying the sets,
 3 for union of set,
 4 for intersection of sets,
 5 for the difference of sets,
 6 for the symmetric difference,
 7 for exit 2
 set1 is :{1,2,3,}
set2 is :{1,3,4,5,}
*********Enter choice***********:
 1 for input,
 2 for displaying the sets,
 3 for union of set,
 4 for intersection of sets,
 5 for the difference of sets,
 6 for the symmetric difference,
 7 for exit 3
UNION OPERATION
 set1 is :{1,2,3,}
set2 is :{1,3,4,5,}
Set of union is :{1,2,3,4,5,}
*********Enter choice***********:
 1 for input,
 2 for displaying the sets,
 3 for union of set,
 4 for intersection of sets,
 5 for the difference of sets,
 6 for the symmetric difference,
 7 for exit 4
INTERSECTION OPERATION
 set1 is :{1,2,3,}
set2 is :{1,3,4,5,}
Intersection set is :{1,3,}
*********Enter choice***********:
 1 for input,
 2 for displaying the sets,
 3 for union of set,
 4 for intersection of sets,
 5 for the difference of sets,
 6 for the symmetric difference,
 7 for exit 5
DIFFERENCE OPERATION
 set1 is :{1,2,3,}
set2 is :{1,3,4,5,}
Set of set2-set1 is :{4,5,}
Set of set1-set2 is :{2,}
*********Enter choice***********:
 1 for input,
 2 for displaying the sets,
 3 for union of set,
 4 for intersection of sets,
 5 for the difference of sets,
 6 for the symmetric difference,
 7 for exit 6
SYMMETRIC DIFFERENCE OPERATION
 set1 is :{1,2,3,}
set2 is :{1,3,4,5,}
Set of symmetric difference is :{4,5,2,}
*********Enter choice***********:
 1 for input,
 2 for displaying the sets,
 3 for union of set,
 4 for intersection of sets,
 5 for the difference of sets,
 6 for the symmetric difference,
 7 for exit 7

--------------------------------
Process exited after 150.9 seconds with return value 0*/
