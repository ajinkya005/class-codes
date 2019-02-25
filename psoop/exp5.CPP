#include<conio.h>
#include<iomanip.h>
#include<iostream.h>
#include<fstream.h>
#include<stdio.h>
#include<string.h>
class Shape
  {
    protected:
      double a,b;
    public:
      virtual void input()
	{
	}
      virtual void compute_area()
	{
	}
  };
class Triangle : public Shape
  {
    public:
      void input()
	{
	  cout<<"\nEnter Base : ";
	  cin>>a;
	  cout<<"\nEnter Height : ";
	  cin>>b;
	}
     void compute_area()
       {
	 cout.precision(2);
	 cout.setf(ios::showpoint);

	 cout<<"\nBase   : "<<setw(10)<<a
	     <<"\nHeight : "<<setw(10)<<b
	     <<"\nArea   : "<<setw(10)<<0.5*a*b;
       }
  };
class Rectangle : public Shape
  {
    public:
      void input()
	{
	  cout<<"\nEnter Length : ";
	  cin>>a;
	  cout<<"\nEnter Breadth : ";
	  cin>>b;
	}
     void compute_area()
       {
	 cout.precision(2);
	 cout.setf(ios::showpoint);
	 cout<<"\nLength   : "<<setw(10)<<a
	     <<"\nBreadth  : "<<setw(10)<<b
	     <<"\nArea     : "<<setw(10)<<a*b;
       }
  };
void main()
  {
    int ch;
    Shape *s;
    do
     {
      clrscr();
      cout<<"\n\n\t\tMenu\n\n\t1.Triangle\n\t2.Rectangle\n\t3.Exit"
	  <<"\n\n\t\tEnter Choice : ";
      cin>>ch;
      switch(ch)
	{
	  case 1:
	    s=new Triangle();
	    s->input();
	    s->compute_area();
	    break;
	  case 2:
	    s=new Rectangle();
	    s->input();
	    s->compute_area();
	    break;
	  case 3:
	    cout<<"\n\nComming Out !!!";
	    break;
	  default :
	    cout<<"\nWrong Choice : ";
	}
      getch();
     }while(ch!=3);
  }

