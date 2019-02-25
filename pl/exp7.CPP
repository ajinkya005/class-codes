#include<iostream>
#include<stdio.h>
#define sz 50
using namespace std;


void accarr(int a[sz],int n)
  {
    int i;
    printf("\nEnter %d Elements : ",n);
    for(i=0;i<n;i++)
      scanf("%d",&a[i]);
  }
void disparr(int a[sz],int n)
  {
    int i;
    for(i=0;i<n;i++)
      printf(" %d ",a[i]);
  }
void Qsort(int a[sz],int n,int l,int h)
{
  int pivot,down,up,t;
  pivot=a[l];
  down=l+1;
  up=h;
  while(down<=up)
    {
      while(a[down]<=pivot&&down<=up)
	down++;
      while(a[up]>pivot)
	up--;
      if(down<=up)
	{
	  t=a[down];
	  a[down]=a[up];
	  a[up]=t;down++;up--;
	}
    }
   a[l]=a[up];
   a[up]=pivot;
   printf("\nPivot : = %d      ",pivot);
   disparr(a,n);
   if(l<up-1)
     Qsort(a,n,l,up-1);
   if(down<h)
     Qsort(a,n,down,h);
 }
int main()
  {
    int a[sz],n;
    printf("\nEnter No Of Elements : ");
    scanf("%d",&n);
    accarr(a,n);
    disparr(a,n);
    Qsort(a,n,0,n-1);
    return(1);
  }




























