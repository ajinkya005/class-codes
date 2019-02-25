#define sz 50
#include<stdio.h>
#include<stdlib.h>

void Accarr(int a[sz],int n)
{
 int i,j;
 printf("\nEnter %d elements:",n);
 for(i=0;i<n;i++)
 {
  scanf("%d",&a[i]);
  for(j=0;j<i;j++)
  {
   if(a[j]==a[i])
   {
    printf("\nDuplicate element please re-enter");
    i--;
    break;
   }
  }
 }
}
void Disparr(int a[sz],int n)
{
 int i;
 printf("\n\n");
 for(i=0;i<n;i++)
 printf("%d\t",a[i]);
}
void Union(int a[sz],int n1,int b[sz],int n2)
{
 int i,j,flag;
 printf("\nUnion:");
 Disparr(a,n1);
 for(j=0;j<n2;j++)
 {
  flag=0;
  for(i=0;i<n1;i++)
  {
   if(b[j]==a[i])
   {
    flag=1;
    break;
   }
  }
  if(flag==0)
  printf("%d\t",b[j]);
 }
}
void Int(int a[sz],int n1,int b[sz],int n2)
{
 int i,j,flag;
 printf("\nIntersection");
 for(j=0;j<n2;j++)
 {
  flag=0;
  for(i=0;i<n1;i++)
  {
   if(b[j]==a[i])
   {
    flag=1;
    break;
   }
  }
  if(flag==1)
  printf("%d\t",b[j]);
 }
}
void Diff(int a[sz],int n1,int b[sz],int n2)
{
 int i,j,flag;
 for(j=0;j<n2;j++)
 {
  flag=0;
  for(i=0;i<n1;i++)
  {
   if(b[j]==a[i])
   {
    flag=1;
    break;
   }
  }
  if(flag==0)
  printf("%d\t",b[j]);
 }
}
void SymDiff(int a[sz],int n1,int b[sz],int n2)
{ 
 Diff(a,n1,b,n2);
 Diff(b,n2,a,n1);
}

int main()
{
 int a[sz],n1,b[sz],n2,ch;
 printf("\nEnter no. of elements in set 1 & set 2:");
 scanf("%d%d",&n1,&n2);
 Accarr(a,n1);
 Accarr(b,n2);
 do
 {
  Disparr(a,n1);
  Disparr(b,n2);
  printf("\n\n\t\tMenu\n\n\t1)Union\n\t2)Intersection\n\t3)Difference\n\t4)Sym. Diff.\n\t5)Exit\n\n\t\tEnter choice:");
  scanf("%d",&ch);
  switch(ch)
  {
   case 1:
   Union(a,n1,b,n2);
   break;
   case 2:
   Int(a,n1,b,n2);
   break;
   case 3:
   printf("\nDifference : ");
   Diff(a,n1,b,n2);
   break;
   case 4:
   SymDiff(a,n1,b,n2);
   break;
   case 5:
   printf("\nComming Out");
   break;
   default:
   printf("\nWrong choice entered");
  }
 }while(ch!=5);
 return(1);
}
