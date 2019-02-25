/*
 ============================================================================
 Name        : sparse.c
 Author      : ajinkya
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define sz 100
struct sparse
{
	int r , c , val;
};

void create(struct sparse x[]);
void Strans(struct sparse A[] , struct sparse T[]);
void Ftrans(struct sparse A[sz] , struct sparse T[]);
void add(struct sparse A[] , struct sparse B[] , struct sparse C[]);
void disp(struct sparse A[]);


void create(struct sparse x[sz])
{
	int row , col , i , j , k , ele , a[sz][sz];

	printf("enter the no of rows and cols :\n");
	scanf("%d%d",&row,&col);

	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			a[i][j] = 0;
		}
	}

	while(1)
	{
		printf("\nenter the element(enter zero(0) to stop):\n");
		scanf("%d",&ele);

		if(ele==0)
			break;

		printf("\nenter row and col subscript :\n");
		scanf("%d%d",&i,&j);

		if(i<0 || i>row-1 || j<0 || j>col-1)
			printf("\ninvalid position...\n");
		else
			a[i][j] = ele;
	}

	k = 1;

	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			if(a[i][j]!=0)
			{
				x[k].r = i;
				x[k].c = j;
				x[k].val = a[i][j];
				k++;
			}
		}

	}

	x[0].r = row;
	x[0].c = col;
	x[0].val = k-1;
}

void disp(struct sparse A[sz])
{
	int i;
	printf("\n");
	
	for(i=0;i<=A[0].val;i++)
	{
		printf("\n%d\t%d\t%d",A[i].r,A[i].c,A[i].val);
	}
}


void Strans(struct sparse A[sz] , struct sparse T[sz])
{
	
	int i , j , k;
	T[0].r = A[0].c;
	T[0].c = A[0].r;
	T[0].val = A[0].val;
	
	k = 1;
	
	for(i=0;i<A[0].c;i++)
	{
		for(j=1;j<=A[0].val;j++)
		{
			if(A[j].c==i)
			{
				T[k].r = A[j].c;
				T[k].c = A[j].r;
				T[k].val = A[j].val;
			}
		}
	}
	
}

void Ftrans(struct sparse A[sz] , struct sparse T[sz])
{
	int i , j , k , cnt[sz] , pos[sz];
	
	T[0].r = A[0].c;
	T[0].c = A[0].r;
	T[0].val = A[0].val;
	
	for(i=0;i<A[0].c;i++)
		cnt[i] = 0;
		
	for(j=1;j<A[0].val;j++)		
		cnt[A[j].c]++;
		
	pos[0] = 1;
	
	for(i=0;i<A[0].c;i++)
		pos[i] = pos[i-1] + cnt[i-1];
				
	for(j=1;j<A[0].val;j++)
	{
		
		k = pos[A[j].c];
		T[k].r = A[j].c;
		T[k].c = A[j].r;
		T[k].val = A[j].val;
		pos[A[j].c]++;		
	}			
}

void add(struct sparse A[sz] , struct sparse B[sz] , struct sparse C[sz]) 
{
	
	int i , j , k;
	
	if(A[0].r==B[0].r && A[0].c==B[0].c)
	{
		
		for(i=j=k=1;i<=A[0].val && j<=B[0].val;k++)
		{
			
			if(A[i].r==B[j].r)
			{
				if(A[i].c==B[j].c)
				{
					
					C[k] = A[i];
					C[k].val = A[i].val + B[j].val;
					i++;
					j++;				
				}
				else
				{
					
					if(A[i].c<B[j].c)
					{
						C[k] = A[i];
						i++;
					}
					else
					{
						C[k] = B[j];
						j++;
					}
					
				}
			}
			else
			{
				
				if(A[i].r<B[j].r)
					{
						C[k] = A[i];
						i++;
					}
					else
					{
						C[k] = B[j];
						j++;
					}
				
				
			}
			
		}
		
		while(i<=A[0].val)
		{
			C[k] = A[i];
			i++;
			k++;
		}
		
		while(j<=B[0].val)
		{
			C[k] = B[j];
			j++;
			k++;
		}
		
		C[0] = A[0];
		C[0].val = k-1;
		
		disp(C);
				
	}
	
	else
		printf("\naddition not possible...");
	
	
}

int main()
{
	int ch;
	struct sparse A[sz] , B[sz] , C[sz] , T[sz];

	do
	{

		printf("\nenter the choice");
		printf("\n1.create A :");
		printf("\n2.create B :");
		printf("\n3.display A :");
		printf("\n4.display B :");
		printf("\n5.simple transpose :");
		printf("\n6.fast transpose :");
		printf("\n7.add :");
		scanf("%d",&ch);

		switch(ch)
		{

		case 1:
				create(A);
				break;

		case 2:
				create(B);
				break;

		case 3:
				disp(A);
				break;

		case 4:
				disp(B);
				break;

		case 5:
				Strans(A , T);
				disp(T);
				break;

		case 6:
				Ftrans(A , T);
				disp(T);
				break;

		case 7:
				add(A , B , C);
				break;

		default:
				printf("\nINVALID CHOICE...");

		}


	}while(1);

return 0;
}

