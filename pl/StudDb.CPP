#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
class DB
  {
    public :
      void Add();
      void Mod();
      void Del();
      void Disp();
      int Ser( int);
  };
class Student
  {
     int rno;
     char *name,*cls,*div,*dob,*bg,*add,*phno;
     long dno;
     static int cnt;
     int dflag;

    public:
     ~Student()
       {
	delete(name);
	delete(dob);
	delete(cls);
	delete(div);
	delete(bg);
	delete(add);
	delete(phno);
       }
      Student()
	{
	  rno=dno=0;
	  name=new char;strcpy(name,"");
	  div=new char;strcpy(div,"");
	  cls=new char;strcpy(cls,"");
	  dob=new char;strcpy(dob,"");
	  bg=new char;strcpy(bg,"");
	  phno=new char;strcpy(phno,"");
	  add=new char;strcpy(add,"");
	}
      Student(Student &x)
	{
	  rno=x.rno;
          dno=x.dno;
	  name=new char[strlen(x.name)+1];strcpy(name,x.name);
	  cls=new char[strlen(x.cls)+1];strcpy(cls,x.cls);
	  div=new char[strlen(x.div)+1];strcpy(div,x.div);
	  dob=new char[strlen(x.dob)+1];strcpy(dob,x.dob);
	  bg=new char[strlen(x.bg)+1];strcpy(bg,x.bg);
	  phno=new char[strlen(x.phno)+1];strcpy(phno,x.phno);
	  add=new char;strcpy(add,x.add);strcpy(add,x.add);
	}
     static void showcnt()
       {
	 cout << "\nNo Of Records : "<<cnt;
       }
     friend class DB;
  }p[100];
int Student::cnt;
int DB::Ser(int no)
  {
    int i;
    for(i=0;i<p[0].cnt;i++)
      {
	if(p[i].rno==no && p[i].dflag==0)
	  return(i);
      }
    return(-1);
  }
void DB::Add()
  {
    Student *x;
    char str[80];
    int no;
    int i;
    cout<<"\nEnter Roll No : ";
    cin>>no;
    i=Ser(no);
    if(i==-1)
      {
	x=new Student;
	x->dflag=0;
        x->rno=no;
	cout<<"\nEnter Name : ";
	while(cin.get()!='\n'); gets(str);
	x->name=new char[strlen(str)+1];strcpy(x->name,str);
	cout<<"\nEnter Class : ";
	gets(str);
	x->cls=new char[strlen(str)+1];strcpy(x->cls,str);
	cout<<"\nEnter Div : ";
	gets(str);
	x->div=new char[strlen(str)+1];strcpy(x->div,str);
	cout<<"\nEnter DOB  : ";
	gets(str);
	x->dob=new char[strlen(str)+1]; strcpy(x->dob,str);
	cout<<"\nEnter blood Group  : ";
	gets(str);
	x->bg=new char[strlen(str)+1]; strcpy(x->bg,str);
	cout<<"\nEnter Address : ";
	gets(str);
	x->add=new char[strlen(str)+1]; strcpy(x->add,str);
	cout<<"\nEnter Phone No : ";
	gets(str);
	x->phno=new char[strlen(str)+1]; strcpy(x->phno,str);
	cout<<"\nEnter Driving Licence No : ";
	cin>>x->dno;
	p[x->cnt]= *x;
	x->cnt++;
      }
    else
      cout<<"\nAlready Record Present";
  }
void DB::Mod()
  {
    char str[80];
    int no;
    int i;
    cout<<"\nEnter Roll NO : ";
    cin>>no;
    i=Ser(no);
    if(i!=-1)
      {
	cout<<"\nOld Data\n";
	cout<<"\nStudent Details";
	cout<<"\nRoll No  \t\t:"<<p[i].rno;
	cout<<"\nName       \t\t:"<<p[i].name;
	cout<<"\nClass      \t\t:"<<p[i].cls;
	cout<<"\nDivision   \t\t:"<<p[i].div;
	cout<<"\nDateOfBirth\t\t:"<<p[i].dob;
	cout<<"\nBlood group\t\t:"<<p[i].bg;
	cout<<"\nAddress    \t\t:"<<p[i].add;
	cout<<"\nDriving Lno\t\t:"<<p[i].dno;
	cout<<"\nPhone No   \t\t:"<<p[i].phno;
	cout<<"\nEnter New Address : ";
	while(cin.get()!='\n');gets(str);
	delete(p[i].add);
	p[i].add=new char[strlen(str)+1]; strcpy(p[i].add,str);
	cout<<"\nModified";
      }
    else
      cout<<"\nRecord Not Present";
  }
void DB::Del()
  {
    int no;
    int i;
    cout<<"\nEnter Roll NO : ";
    cin>>no;
    i=Ser(no);
    if(i!=-1)
      {
	p[i].dflag=1;
	cout<<"\nDeleted";
      }
    else
      cout<<"\nRecord Not Present";
  }
void DB::Disp()
  {
   int i;
   for(i=0;i<p[0].cnt;i++)
    {
     if(p[i].dflag==0)
       {
	cout<<"\nStudent Details";
	cout<<"\nRoll No  \t\t:"<<p[i].rno;
	cout<<"\nName       \t\t:"<<p[i].name;
	cout<<"\nClass      \t\t:"<<p[i].cls;
	cout<<"\nDivision   \t\t:"<<p[i].div;
	cout<<"\nDateOfBirth\t\t:"<<p[i].dob;
	cout<<"\nBlood group\t\t:"<<p[i].bg;
	cout<<"\nAddress    \t\t:"<<p[i].add;
	cout<<"\nDriving Lno\t\t:"<<p[i].dno;
	cout<<"\nPhone No   \t\t:"<<p[i].phno;
	cin.get();
      }
    }
  }
int main()
  {
    int ch;
    DB D;
    do
     {
      cout<<"\n\n\t\tData Base\n\n\t1.Add\n\t2.Mod\n\t3.Del"
	  <<"\n\t4.Disp\n\t5.Exit\n\n\t\tEnter Choice : ";
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
	    cout<<"\n\nComming Out !!!";
	    break;
	  default :
	    cout<<"\nWrong Choice : ";
	}
     }while(ch!=5);
    return(1);
  }

