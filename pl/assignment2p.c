/*
 ============================================================================
 Name        		: kunal sachdev
 roll no     		: 23132
 batch       		: F9
 Class       		: SE9
 Assign. no. 		:2(with pointer)
 Problem statement  :
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

//declaring the functions
void input(int *mat,int row,int col);
void display(int *mat,int row,int col);
void add(int (*mat1)[10],int (*mat2)[10],int (*mat3)[10],int row,int col);
void substract(int (*mat1)[10],int (*mat2)[10],int (*mat4)[10],int row,int col);
void transpose(int (*mat1)[10],int (*mat6)[10],int row,int col);
void matmul(int (*mat1)[10],int (*mat2)[10],int (*mat5)[10],int row1,int col1,int col2);
void saddle(int (*mat)[10],int row,int col);
int main(void)
{
	//declaring the variables
	int mat1[10][10],mat2[10][10],mat3[10][10],mat4[10][10],mat5[10][10],mat6[10][10];
	int row1, col1;
	int row2,col2;
	int key=1;
	int choice;
	while(key)
	{
		printf("******menu******\n1 for input\n2 for display\n3 for addition\n4 for substraction\n5 for multiplication\n6 for transpose\n7 for saddle point\n8 for exit\n");
		printf("enter choice:");
		scanf("%d",&choice);
		switch(choice)
		{
		case 1:
			//input
			printf("enter row1\n");
			row1=valid(row1);
			printf("enter column1\n");
			col1=valid(col1);
			printf("enter the elements of matrix 1\n");
			input(mat1,row1,col1);
			printf("enter row2\n");
			row2=valid(row2);
			printf("enter column2\n");
			col2=valid(col2);
			printf("enter the elements of matrix 2\n");
			input(mat2,row2,col2);

		    break;
		case 2:
			//display
			printf("matrix1:\n");
			display(mat1,row1,col1);
			printf("matrix2:\n");
			display(mat2,row2,col2);
			break;
		case 3:
			//addition
			printf("ADDITION OF MATRICES\n");
			printf("matrix1:\n");
			display(mat1,row1,col1);
			printf("matrix2:\n");
			display(mat2,row2,col2);
			if((row1==row2)&&(col1==col2))//comparing rows and columns of two matrices
			{
				add(mat1,mat2,mat3,row1,col1);
				printf("matrix of addition is:\n");
				display(mat3,row1,col1);
			}
			else
			{
				printf("addition cannot be done\n");//when rows and cols of matrices are not equal
			}

			break;
		case 4:
			//subtraction
			printf("SUBSTRACTION OF MATRICES\n");
			printf("matrix1:\n");
			display(mat1,row1,col1);
			printf("matrix2:\n");
			display(mat2,row2,col2);
			if((row1==row2)&&(col1==col2))//comparing rows and columns of two matrices
			{
				substract(mat1,mat2,mat4,row1,col1);
				printf("matrix of substraction is:\n");
				display(mat4,row1,col1);
			}
			else
			{
				printf("substraction cannot be done\n");//when rows and cols of matrices are not equal
			}
			break;
		case 5:
			//multiplication
			printf("MULTIPLICATION OF MATRICES\n");
			printf("matrix1:\n");
			display(mat1,row1,col1);
			printf("matrix2:\n");
			display(mat2,row2,col2);
			if(col1==row2)//comparing column of 1st matrix and row of 2nd matrix
			{
				matmul(mat1,mat2,mat5,row1,col1,col2);
				printf("matrix of multiplication is:\n");
				display(mat5,row1,col2);
			}
			else
			{
				printf("multiplication cant be done");//when column of 1st matrix and row of 2nd matrix are not equal
			}
			break;

		case 6:
			//TRANSPOSE
			printf("TRANSPOSE OF MATRIX\n");
			printf("matrix1:\n");
			display(mat1,row1,col1);
			transpose(mat1,mat6,row1,col1);
			printf("transpose of matrix 1 is:\n");
			display(mat6,col1,row1);
			break;
		case 7:
			printf("matrix1:\n");
			display(mat1,row1,col1);
			saddle(mat1,row1,col1);
			break;
		case 8:
			//exit
			key=0;
			printf("Program stopped");
			break;

		}
	}
	return EXIT_SUCCESS;
}
int valid(int lim)//validation function
{
	do
	{

		scanf("%d",&lim);
		if((lim<0)||(lim>10))//comparing the row and column
		{
			printf("invalid rows or columns\n");
			printf("enter again\n");
		}
	}
	while((lim<0)||(lim>10));//for repition of loop
	return lim;
}
void input(int *mat,int row,int col)//input function
{
	int i,j;
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			scanf("%d", (mat+i*10+j));
		}
	}
}
void display(int *mat,int row,int col)//display function
{
	int i,j;
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			printf("%d\t",*(mat+i*10+j));
		}
		printf("\n");//end of row
	}
printf("\n");
}
void add(int (*mat1)[10],int (*mat2)[10],int (*mat3)[10],int row,int col)//addition of two matrices
{
	int i,j;
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			*(*(mat3+i)+j)=*(*(mat1+i)+j)+*(*(mat2+i)+j);//addition by element by element
		}
	}
}
void substract(int (*mat1)[10],int (*mat2)[10],int (*mat4)[10],int row,int col)//substraction of two matrices
{
	int i,j;
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			*(*(mat4+i)+j)=*(*(mat1+i)+j)-*(*(mat2+i)+j);//substraction by element by element
		}
	}
}
void transpose(int (*mat1)[10],int (*mat6)[10],int row,int col)//transpose of matrix
{
	int i,j;
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			*(*(mat6+j)+i)=*(*(mat1+i)+j);//replacing element by its symmetric element
		}
	}
}
void matmul(int (*mat1)[10],int (*mat2)[10],int (*mat5)[10],int row1,int col1,int col2)//multiplication of matrices
{
	int i,j,k;
	for(i=0;i<row1;i++)
	{
		for(j=0;j<col2;j++)
		{
			mat5[i][j]=0;//initialising element of resultant matrix to zero
			for(k=0;k<col1;k++)
			{
				*(*(mat5+i)+j)=	*(*(mat5+i)+j)+(*(*(mat1+i)+k))*(*(*(mat2+k)+j));//calculating multiplication and storing in the element
			}
		}
	}
}
void saddle(int (*mat)[10],int row,int col)//function for finding saddle poin of matrix
{
	int max,min,i,j,k,l,f;
	for(i=0;i<row;i++)
	{
        for(j=0;j<col;j++)
        {
			max=*(*(mat+i)+j);//initialising max
			min=*(*(mat+i)+j);//initialising min
        for(k=0;k<row;k++)
        {
        	if((*(*(mat+k)+j))>max)//comparing element of matrix with max
            max=*(*(mat+k)+j);
        }
        for(l=0;l<col;l++)
		{
            if(min>(*(*(mat+i)+l)))//comparing element of matrix with min
            min=*(*(mat+i)+l);
        }
        if(max==*(*(mat+i)+j) && min==*(*(mat+i)+j))//comparing max and min found at the end of loop
		{
    		printf("saddle point found at %d %d and value is %d \n",i+1,j+1,*(*(mat+i)+j));
            f=1;
        }
        }
    }

      if(f==0)
      printf("No saddle points are present in the given set of numbers\n");

}
