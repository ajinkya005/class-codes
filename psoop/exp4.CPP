#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
class Base1
  {
    protected:
     char *name,*dob,*bg;
  };
class Base2
  {
    protected:
     float ht,wt;
  };
class Base3
  {
    protected:
     char *pno,*add;
  };
class Derived : public Base1,public Base2,public Base3
  {
    protected:
      char *phno;
      long dno;
      static int cnt;
      int dflag;
    public:
      void Add();
      void Mod();
      void Del();
      int  Ser(char no[20]);
      void Disp();
      void DispRec();
   }p[100];
int Derived::cnt;
void Derived::DispRec()
  {
	
	cout<<"\nPolicy Details";
	cout<<"\nPolicy No  \t\t:"<<pno;
	cout<<"\nName       \t\t:"<<name;
	cout<<"\nDateOfBirth\t\t:"<<dob;
	cout<<"\nBlood group\t\t:"<<bg;
	cout<<"\nAddress    \t\t:"<<add;
	cout<<"\nDriving Lno\t\t:"<<dno;
	cout<<"\nPhone No   \t\t:"<<phno;
	cout<<"\nWeight     \t\t:"<<wt;
	cout<<"\nHeight     \t\t:"<<ht;
  }
int Derived::Ser(char no[20])
  {
    int i;
    for(i=0;i<p[0].cnt;i++)
      {
	if(strcmp(p[i].pno,no)==0&&p[i].dflag==0)
	  return(i);
      }
    return(-1);
  }
void Derived::Add()
  {
    Derived  *x;
    char str[80],no[20];
    int i;
    cout<<"\nEnter Policy  NO : ";
    while(cin.get()!='\n');
    cin.getline(no,80);
    i=Ser(no);
    if(i==-1)
      {
	x=new Derived;
	x->dflag=0;
	x->pno=new char[strlen(no)+1];
	strcpy(x->pno,no);
	cout<<"\nEnter Name : ";
	fflush(stdin); cin.getline(str,80);
	x->name=new char[strlen(str)+1];strcpy(x->name,str);
	cout<<"\nEnter DOB  : ";
	fflush(stdin);cin.getline(str,80);
	x->dob=new char[strlen(str)+1]; strcpy(x->dob,str);
	cout<<"\nEnter blood Group  : ";
	fflush(stdin);cin.getline(str,80);
	x->bg=new char[strlen(str)+1]; strcpy(x->bg,str);
	cout<<"\nEnter Address : ";
	fflush(stdin);cin.getline(str,80);
	x->add=new char[strlen(str)+1]; strcpy(x->add,str);
	cout<<"\nEnter Phone No : ";
	fflush(stdin);cin.getline(str,80);
	x->phno=new char[strlen(str)+1]; strcpy(x->phno,str);
	cout<<"\nEnter Driving Licence No, Weight And Height : ";
	cin>>x->dno>>x->wt>>x->ht;
	p[x->cnt]= *x;
	x->cnt++;
      }
    else
      cout<<"\nAlready Record Present";
  }
void Derived::Mod()
  {
    char str[80],no[20];
    int i;
    cout<<"\nEnter Policy  NO : ";
    while(cin.get()!='\n');
    cin.getline(no,20);
    i=Ser(no);
    if(i!=-1)
      {
	cout<<"\nOld Data\n";
	cout<<"\nEnter New Address : ";
	fflush(stdin);cin.getline(str,80);
	delete(p[i].add);
	p[i].add=new char[strlen(str)+1]; strcpy(p[i].add,str);
	cout<<"\nModified";
      }
    else
      cout<<"\nRecord Not Present";
  }
void Derived::Del()
  {
    char str[80],no[20];
    int i;
    cout<<"\nEnter Policy  NO : ";
    while(cin.get()!='\n');
    cin.getline(no,20);
    i=Ser(no);
    if(i!=-1)
      {
	p[i].dflag=1;
	cout<<"\nDeleted";
      }
    else
      cout<<"\nRecord Not Present";
  }
void Derived::Disp()
  {
   int i;
   for(i=0;i<p[0].cnt;i++)
    {
     if(p[i].dflag==0)
       {
	cout<<"\nPolicy Details";
	cout<<"\nPolicy No  \t\t:"<<p[i].pno;
	cout<<"\nName       \t\t:"<<p[i].name;
	cout<<"\nDateOfBirth\t\t:"<<p[i].dob;
	cout<<"\nBlood group\t\t:"<<p[i].bg;
	cout<<"\nAddress    \t\t:"<<p[i].add;
	cout<<"\nDriving Lno\t\t:"<<p[i].dno;
	cout<<"\nPhone No   \t\t:"<<p[i].phno;
	cout<<"\nWeight     \t\t:"<<p[i].wt;
	cout<<"\nHeight     \t\t:"<<p[i].ht;
      }
    }
  }
int main()
  {
    int ch,i;
    char pno[20];
    Derived D;
    do
     {
      cout<<"\n\n\t\tData Base\n\n\t1.Add\n\t2.Mod\n\t3.Del"
	  <<"\n\t4.Disp\n\t5.Search\n\t6.Exit\n\n\t\tEnter Choice : ";
      cin>>ch;
      switch(ch)
	{
	  case 1:
	    D.Add();break;
	  case 2:
	    D.Mod();break;
	  case 3:
	    D.Del();break;
	  case 4:
	    D.Disp();break;
	  case 5:
	    cout<<"\nEnetr Policy No : ";
	    while(cin.get()!='\n');
            cin.getline(pno,20);
	    i=D.Ser(pno);
	    if(i==-1)
	      cout<<"\nRecord No Found !!!!";
	    else
	      p[i].DispRec();
	    break;
	  case 6:
	    cout<<"\n\nComming Out !!!";
	    break;
	  default :
	    cout<<"\nWrong Choice : ";
	}
     }while(ch!=6);
    return(1);
  }

