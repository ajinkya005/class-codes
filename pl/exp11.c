#include<stdio.h>
#include<stdlib.h>
//#include<alloc.h>
struct Dll
{
 int d;
 struct Dll *pp,*np;
};
struct Dll *getnode()
{
 struct Dll *n;
 n=(struct Dll*) malloc(sizeof(struct Dll));
 n->pp=n->np=NULL;
 printf("\nEnter Data:");
 scanf("%d",&n->d);
 return(n);
}
void Disp(struct Dll *s)
{
 struct Dll *q;
 if(s==NULL)
  printf("\nList is Empty");
 else
 {
  printf("\nList is:");
  for(q=s;q!=NULL;q=q->np)
  printf("%d\t",q->d);
 }
}
struct Dll *Add(struct Dll *s)
{
 struct Dll *n,*q,*k;
 int i,pos,cont;
 do
 {
  n=getnode();
  if(s==NULL)
   s=n;
  else
  {
   Disp(s);
   printf("\nEnter pos:");
   scanf("%d",&pos);
   if(pos==1)
   {
    n->np=s;
    s->pp=n;
    s=n;
   }
   else
   {
    for(q=s,i=1;i<pos-1 && q!=NULL;k=q,q=q->np,i++);
    if(q==NULL)
    {
     n->pp=k;
     k->np=n;
    }
    else
      {
        if(q->np==NULL)
          {
            n->pp=q;
            q->np=n;
          }
        else
          {
            n->np=q->np;
            n->pp=q;
           (n->pp)->np=n;
           (n->np)->pp=n;
          }
      }


   }
  }
  Disp(s);
  printf("\nContinue(1:Yes):");
  scanf("%d",&cont);
 }while(cont==1);
  return(s);
}
struct Dll *Del(struct Dll *s)
{
 struct Dll *q,*k;
 int cont,pos,i;
 do
 {
  if(s==NULL)
  {
   printf("\nList is Empty");
   break;
  }
  else
  {
   Disp(s);
   printf("\nEnter pos:");
   scanf("%d",&pos);
   if(pos==1)
   {
    k=s;s=s->np;
    k->np=s->pp=NULL;
    free(k);
   }
   else
   {
    for(q=s,i=1;i<pos-1 && q!=NULL;q=q->np,i++);
    if(q==NULL&&q->np==NULL)
     printf("\nInvalid pos");
    else
    {
     k=q->np;
     (k->pp)->np=k->np;
     (k->np)->pp=k->pp;
     k->np=k->pp=NULL;
     free(k);
    }
   }
  }
  printf("\nContinue(1:Yes):");
  scanf("%d",&cont);
 }while(cont==1);
  return(s);
}
void DllRev(struct Dll *s)
{
 struct Dll *q;
 for(q=s;q->np!=NULL;q=q->np);
 printf("\nReverse:");
 while(q!=NULL)
 {
  printf("%d\t",q->d);
  q=q->pp;
 }
}

int main()
{
 struct Dll*s;
 int ch;
 s=NULL;
 do
 {
  printf("\n\n\t\tMenu\n\n\t1)Add\n\t2)Delete\n\t3)Display\n\t4)Exit\n\n\t\tEnter choice:");
  scanf("%d",&ch);
  switch(ch)
  {
   case 1:
   s=Add(s);
   break;
   case 2:
   s=Del(s);
   break;
   case 3:
   Disp(s);
   break;
   case 4:
   printf("\nComming Out!!!");
   break;
   default:
   printf("\nWrong Choice!!!");
  }
 }while(ch!=4);
 return(1);
}



































































