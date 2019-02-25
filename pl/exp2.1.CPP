#include<stdio.h>
#include<stdlib.h>
#define sz 20
void Accmat(int **a,int r,int c)
  {
    int i,j;
    printf("\nEnter %d * %d Matrix",r,c); 
    for(i=0;i<r;i++)
      {
	for(j=0;j<c;j++)
	  scanf("%d",(*(a+i)+j));
      }
  }
void Dispmat(int **a,int r,int c)
  {
    int i,j;
    for(i=0;i<r;i++)
      {
	for(j=0;j<c;j++)
	  printf("%d\t",*(*(a+i)+j));
	printf("\n");
      }
  }
void Tran(int **a,int r,int c)
  {
    int i,j,t;
    for(i=0;i<r;i++)
      {
	for(j=i+1;j<c;j++)
	  {
	    t=*(*(a+i)+j);
	    *(*(a+i)+j)=*(*(a+j)+i);
	    *(*(a+j)+i)=t;
	  }
      }
    Dispmat(a,i,j);
  }

void Add(int **a,int r1,int c1,int **b,int r2,int c2)
  {
    int i,j,k,ele;
    if(r1==r2&&c1==c2)
      {
	for(i=0;i<r1;i++)
	  {
	    for(j=0;j<c2;j++)
	      printf("%d\t",*(*(a+i)+j) + *(*(b+i)+j));
	    printf("\n");
	  }
       }
     else
       printf("\nNo Add Posssible");
  }

int main()
  {
    int **a,**b,r1,c1,r2,c2,ch,i;

    printf("\nEnter No Of Rows And Cols Of Matrix1 : ");
    scanf("%d %d",&r1,&c1);
    a=(int **) malloc(r1*sizeof(int *));
    for(i=0;i<r1;i++)
      *(a+i)=(int *)malloc(c1*sizeof(int ));
    printf("\nEnter No Of Rows And Cols Of Matrix2 : ");
    scanf("%d %d",&r2,&c2);
    b=(int **) malloc(r2*sizeof(int *));
    for(i=0;i<r2;i++)
      *(b+i)=(int *)malloc(c2*sizeof(int ));

    Accmat(a,r1,c1);
    Accmat(b,r2,c2);
    do
      {
	printf("\nMatrix1\n\n");
	Dispmat(a,r1,c1);
	printf("\nMatrix2\n\n");
	Dispmat(b,r2,c2);
	printf("\n\n\t\tMat Op\n\n\t1.Add\n\t2.Tranpose\n\t3.Exit\n\n\t\tEnter Ch : ");
	scanf("%d",&ch);
	switch(ch)
	  {
	    case 1:
	      Add(a,r1,c1,b,r2,c2);break;
	    case 2:
	      Tran(a,r1,c1);break;
	    case 3:
	      printf("\nComming Out !!!");break;
	    default:
	      printf("\nWrong Choice !!!");
	  }
      }while(ch!=3);
  }
