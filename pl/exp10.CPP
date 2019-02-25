#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<alloc.h>
#define sz 50
struct poly
{
int c,e;
struct poly *lp;
};
struct poly *getnode()
{
struct poly *n;
n=(struct poly *)malloc(sizeof(struct poly));
n->lp=NULL;
return(n);
}
void disp(struct poly *p)
{
struct poly *q;
printf("\n\n%dx^%d",p->c,p->e);
for(q=p->lp;q!=p;q=q->lp)
{
if(q->c>0)
printf("+");
printf("%dx^%d",q->c,q->e);
}
}

struct poly *create()
{
struct poly *s,*last,*n;
int d,coeff;
clrscr();
printf("\nEnter degree of poly:");
scanf("%d",&d);
s=NULL;
while(d>=0)
     {
     printf("\nEnter coefficient of x^%d:",d);
     scanf("%d",&coeff);
     if(coeff!=0)
     {
     n=getnode();
     n->c=coeff;
     n->e=d;
     if(s==NULL)
     s=last=n;
     else
     {
     last->lp=n;
     last=n;
     }
     }
     d--;
     }
     last->lp=s;
     return(s);
     }
     struct poly *Add(struct poly *p1,struct poly *p2)
     {
     struct poly *s,*n,*last,*x,*y;
     int f1=0,f2=0;
     s=NULL;
     x=p1;
     y=p2;
     while((x!=p1||f1==0)&&(y!=p2||f2==0))
      {
      n=getnode();
      if(x->e==y->e)
       {
       n->c=x->c+y->c;
       n->e=x->e;
       x=x->lp;
       f1=1;
       y=y->lp;
       f2=1;
       }
       else

       {
       if(x->e>y->e)
	 {
	 n->c=x->c;
	 n->e=x->e;
	 x=x->lp;
	 f1=1;
	 }
	 else
	 {
	 n->c=y->c;
	 n->e=y->e;
	 y=y->lp;
	 f2=1;
	 }
       }
       if(s==NULL)
       s=last=n;
       else
       {
       last->lp=n;
       last=n;
       }
     }
     while(x!=p1||f1==0)
     {
     n=getnode();
     n->c=x->c;
     n->e=x->e;
     x=x->lp;
     f1=1;
     last->lp=n;
     last=n;
     }
     while(y!=p2||f2==0)
     {
     n=getnode();
     n->c=y->c;
     n->e=y->e;
     y=y->lp;
     f2=1;
     last->lp=n;
     last=n;
     }
     last->lp=s;
     return(s);
     }
struct poly *Mul(struct poly *p1,struct poly *p2)
{
struct poly *s,*n,*last,*x,*y;
int f1,f2,d;
s=NULL;
d=p1->e+p2->e;
while(d>=0)
{
n=getnode();
n->e=d;
n->c=0;
for(x=p1,f1=0;x!=p1||f1==0;x=x->lp,f1=1)
   {
   for(y=p2,f2=0;y!=p2||f2==0;y=y->lp,f2=1)
      {
      if(x->e+y->e==d)
      n->c=n->c+x->c*y->c;
      }
   }
if(s==NULL)
s=last=n;
else
{
if(n->c!=0)
   {
   last->lp=n;
   last=n;
   }
else
free(n);
}
d--;
}
last->lp=s;
return(s);
}
void peval(struct poly *p)
{
struct poly *q;
int x;
long  res;
disp(p);
printf("\n\nEnter value of x:");
scanf("%d",&x);
res=p->c*pow(x,p->e);
for(q=p->lp;q!=p;q=q->lp)
res=res+q->c*pow(x,q->e);
printf("\nResult is %ld",res);
}
void main()
{
struct poly *p1,*p2,*p3,*p4;
p1=create();
p2=create();
clrscr();
p3=Add(p1,p2);
p4=Mul(p1,p2);
disp(p1);
disp(p2);
disp(p3);
disp(p4);
peval(p1);
getch();
}



