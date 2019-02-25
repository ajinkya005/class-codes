#include<stdio.h>
#include<stdlib.h>
struct sll
  {
    int d;
    struct sll *lp;
  }; 
struct sll * getnode()
  {
     struct sll *n;
     n=(struct sll *)malloc(sizeof(struct sll));
     n->lp=NULL;
     printf("\nEnter Data : ");scanf("%d",&n->d);
     return(n);
  }

void Disp(struct sll *s)
{
 struct sll*q;
 if(s==NULL)
  printf("\nList Empty");
 else
 {
  printf("\nList is:");
  for(q=s;q!=NULL;q=q->lp)
  printf("%d\t",q->d);
 }
}
struct sll* Add(struct sll *s)
{
 struct sll *n,*q,*k;
 int cont,pos,i;
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
         n->lp=s;
         s=n;
       }
      else
       {
        for(q=s,i=1;i<pos-1 && q!=NULL;k=q,q=q->lp,i++);
        if(q==NULL)
           k->lp=n;
        else
         {
          n->lp=q->lp;
          q->lp=n;
         }
       }
     }
  Disp(s);
  printf("\nContinue(Yes:1):");
  scanf("%d",&cont);
 }while(cont==1);
  return(s);

}

struct sll* Del(struct sll*s)
{
 struct sll *q,*k;
 int cont,pos,i;
 do
 {
  if(s==NULL)
  {
   printf("\nList Empty");
   break;
  }
  else
  {
   Disp(s);
   printf("\nEnter pos:");
   scanf("%d",&pos);
   if(pos==1)
   {
    k=s;
    s=s->lp;
    k->lp=NULL;
    free(k);
   }
   else
   {
    for(q=s,i=1;i<pos-1 && q!=NULL;q=q->lp,i++);
    if(q==NULL)
     printf("\nInvalid position");
    else
    {
     k=q->lp;
     q->lp=k->lp;
     k->lp=NULL;
     free(k);
    }
   }
  }
  Disp(s);
  printf("\nContinue(Yes):");
  scanf("%d",&cont);
 }while(cont==1);
  return(s);

}
void cntnodes(struct sll *s)
{
 struct sll *q;
 int cnt=0;
 if(s==NULL)
  printf("\n0 Nodes");
 else
 {
  for(q=s;q!=NULL;q=q->lp)
    cnt++;
  printf("\n%d Nodes",cnt);
 }
}
void search(struct sll *s)
{
 struct sll *q;
 int pos,ele;
 Disp(s);
 printf("\nEnter ele:");
 scanf("%d",&ele);
 for(q=s,pos=1;q!=NULL;pos++,q=q->lp)
 {
  if(q->d==ele)
  {
   printf("\n%d found at %d pos.",ele,pos);
   break;
  }
 }
 if(q==NULL)
  printf("\n%dnot present",ele);
}

void main()
{
 struct sll*s;
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
}

































				


























