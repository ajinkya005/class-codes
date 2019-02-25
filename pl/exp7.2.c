#define sz 50
#include<stdio.h>

void accarr(int a[sz],int n)
{
 int i;
 printf("\nEnter %d ele:",n);
 for(i=0;i<n;i++)
 scanf("%d",&a[i]);
}
void disparr(int a[sz],int n)
{
 int i;
 printf("\n");
 for(i=0;i<n;i++)
 printf("%d\t",a[i]);
}
void qsort(int a[sz],int l,int h,int n)
{
 int pivot,down,up,t,i;
 pivot=a[l];
 down=l+1;
 up=h;
 while(down<=up)
 {
  while(a[down]<=pivot && down<=up)
  down++;
  while(a[up]>pivot)
  up--;
  if(down<=up)
  {
   t=a[down];
   a[down]=a[up];
   a[up]=t;
   down++;
   up--;
  }
 }
 a[l]=a[up];
 a[up]=pivot;
 printf("\nPivot:%d",pivot);
 disparr(a,n);
 if(i<up-1)
  qsort(a,l,up-1,n);
 if(down<h)
  qsort(a,down,h,n);
}
void merge(int a[sz],int s,int m,int e)
{
 int i,j,k,b[sz];
 i=s;
 j=m+1;
 k=s;
 while(i<=m && j<=e)
 {
  if(a[i]<=a[j])
  {
   b[k]=a[i];
   i++;
  }
  else
  {
   b[k]=a[j];
   j++;
  }
  k++; 
 }
 while(i<=m)
 {
  b[k]=a[i];
  i++;
  k++;
 }
 while(j<=e)
 {
  b[k]=a[j];
  j++;
  k++;
 }
 for(i=s;i<=e;i++)
 a[i]=b[i];
}
void part(int a[sz],int s,int e,int n)
{
 int m;
 if(s<e)
 {
  m=(s+2)/2;
  part(a,s,m,n);
  part(a,m+1,e,n);
  merge(a,s,m,e);
  disparr(a,n);
 }
}
void main()
{
 int t[sz],a[sz],n,ch,i;
 printf("\nEnter no. of ele:");
 scanf("%d",&n);
 accarr(a,n);
 do
 {
  for(i=0;i<n;i++)
  t[i]=a[i];
  disparr(a,n);
  printf("\n\n\t\tMenu\n\n\t1)Quick\n\t2)Merge\n\t3)Exit\n\n\t\tEnter ch:");
  scanf("%d",&ch);
  switch(ch)
  {
   case 1:qsort(a,0,n-1,n);
   break;
   case 2:
   part(a,0,n-1,n);
   break;
   case 3:
   printf("\nComming Out!!!");
   break;
   default:
   printf("\nWrong ch!!!");
  }
 }while(ch!=3);
}










































