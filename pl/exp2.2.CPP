#include<stdio.h>
#define sz 20
void Accmat(int a[sz][sz],int r,int c)
  {
    int i,j;
    printf("\nEnter %d * %d Matrix\n",r,c); 
    for(i=0;i<r;i++)
      {
	for(j=0;j<c;j++)
	  scanf("%d",&a[i][j]);
      }
  }
void Dispmat(int a[sz][sz],int r,int c)
  {
    int i,j;
    for(i=0;i<r;i++)
      {
	for(j=0;j<c;j++)
	  printf("%d\t",a[i][j]);
	printf("\n");
      }
  }

void Mul(int a[sz][sz],int r1,int c1,int b[sz][sz],int r2,int c2)
  {
    int i,j,k,ele;
    if(c1==r2)
      {
	for(i=0;i<r1;i++)
	  {
	    for(j=0;j<c2;j++)
	      {
		ele=0;
		for(k=0;k<c1;k++)
		  ele=ele+a[i][k]*b[k][j];
		printf("%d\t",ele);
	      }
	    printf("\n");
	  }
       }
     else
       printf("\nNo Multiplication Posssible");
  }
void SadPoint(int a[sz][sz],int r1,int c1)
  {
    int i,j,cp,max,min,flag=0;
    for(i=0;i<r1;i++)
       {
	 max=a[i][0];cp=j;
	 for(j=1;j<c1;j++)
	    {
	      if(a[i][j]>max)
		{
		  max=a[i][j];
		  cp=j;
		}
	    }
	 min=a[0][cp];
	 for(j=1;j<r1;j++)
	    {
	      if(a[j][cp]<min)
		min=a[j][cp];
	    }
	 if(max==min)
	   {
	     printf("\nSaddle Point %d At (%d %d)",max,i,cp);
	     flag=1;
	   }
       }
     if(flag==0)
       printf("\nSaddle Point not Present");
  }

int main()
  {
    int a[sz][sz],b[sz][sz],r1,c1,r2,c2,ch;

    printf("\nEnter No Of Rows And Cols Of Matrix1 : ");
    scanf("%d %d",&r1,&c1);
    printf("\nEnter No Of Rows And Cols Of Matrix2 : ");
    scanf("%d %d",&r2,&c2);
    Accmat(a,r1,c1);
    Accmat(b,r2,c2);
    do
      {
	printf("\nMatrix1\n\n");
	Dispmat(a,r1,c1);
	printf("\nMatrix2\n\n");
	Dispmat(b,r2,c2);
	printf("\n\n\t\tMat Op\n\n\t1.Multiplication\n\t2.Saddle point\n\t3.Exit\n\n\t\tEnter Ch : ");
	scanf("%d",&ch);
	switch(ch)
	  {
	    case 1:
	      Mul(a,r1,c1,b,r2,c2);break;
	    case 2:
	      SadPoint(a,r1,c1);
	      SadPoint(b,r2,c2);
              break;
	    case 3:
	      printf("\nComming Out !!!");break;
	    default:
	      printf("\nWrong Choice !!!");
	  }
      }while(ch!=3);
  }
