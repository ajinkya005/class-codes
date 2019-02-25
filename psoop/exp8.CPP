#include<iostream>
#include<fstream>
#include<stdio.h>
#include<string.h>
using namespace std;
class Base
  {
    protected:
     int rno;
     char name[30],sub[20];
    public:
     virtual void get()
       {
       }
     virtual void disp()
       {
       }
  };
class Derived : public Base
  {
    protected:
     int scd,iass, em;
    public:
     void get()
       {
	 cout<<"\nEnter Roll No : ";
	 cin>>rno;
	 cout<<"\nEnter Name : ";
	 while(cin.get()!='\n');
         cin.getline(name,30);
	 cout<<"\nEnter Sub Name : ";
	 cin.getline(sub,20);
	 cout<<"\nEnter Sub Code, Internal Assesment & Univ Marks  : ";
	 cin>>scd>>iass>>em;
       }
     void disp()
       {
	 cout<<"\n"<<rno<<"\t"<<name<<"\t"<<sub<<"\t"<<scd
	     <<"\t"<<iass<<"\t"<<em;
       }
     int getrno()
       {
	 return(rno);
       }
     void moddata()
       {
	 disp();
	 cout <<"\nEnter New Univ Marks : ";
	 cin>>em;
       }
    }s;
fstream f1,f2;
int flag,sz=sizeof(s),no;
void Ser(int no)
  {
    f1.open("stu.dat",ios::in);
    flag=0;
    while(f1.read((char *)&s,sz))
      {
	if(s.getrno()==no)
	  {
	    cout<<"\nRecord Found";
	    s.disp();flag=1;break;
	  }
      }
    f1.close();
    if(flag==0)
      cout<<"\nrecord Not Present";
  }
void Add()
  {
    f1.open("stu.dat",ios::app);
    s.get();
    f1.write((char *)&s,sz);
    f1.close();
  }
void Mod()
  {
    f1.open("stu.dat",ios::in|ios::out);
    int pos;
    cout<<"\nEnter Roll No  : ";
    cin>>no;
    flag=0;
    while(f1.read((char *)&s,sz))
      {
	if(s.getrno()==no)
	  {
	   s.moddata();
	   pos=f1.tellg();
	   pos=pos-sz;
	   f1.seekp(pos,ios::beg);
	   f1.write((char *)&s,sz);
	   flag=1;break;
	  }
      }
    f1.close();
    if(flag==1)
      cout<<"\nRecord Modified";
    else
      cout<<"\nRecord Not Present";
  }
void Del()
  {
    f1.open("stu.dat",ios::in);
    f2.open("tstu.dat",ios::out);
    int pos;
    cout<<"\nEnter Roll No  : ";
    cin>>no;
    flag=0;
    while(f1.read((char *)&s,sz))
      {
	if(s.getrno()==no)
	  flag=1;
	else
	  f2.write((char *)&s,sz);
      }
    f1.close();f2.close();
    remove("stu.dat");
    rename("tstu.dat","stu.dat");
    if(flag==1)
      cout<<"\nRecord Deleted";
    else
      cout<<"\nRecord Not Present";
  }
void Disp()
  {
   // clrscr();
    f1.open("stu.dat",ios::in);
    while(f1.read((char *)&s,sz))
      s.disp();
    f1.close();
  }
int main()
  {
    int ch;
    do
     {
      cout<<"\n\n\t\tData Base\n\n\t1.Add\n\t2.Mod\n\t3.Del"
	  <<"\n\t4.Disp\n\t5.Serach\n\t6.Exit\n\n\t\tEnter Choice : ";
      cin>>ch;
      switch(ch)
	{
	  case 1:
	    Add();break;
	  case 2:
	    Mod();break;
	  case 3:
	    Del();break;
	  case 4:
	    Disp();break;
	  case 5:
	    cout<<"\nEnter Roll No : ";
	    cin>>no;
	    Ser(no);
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

