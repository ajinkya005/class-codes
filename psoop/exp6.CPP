#include<iomanip>
#include<iostream>
using namespace std;
class Excp
  {
      double a,b;
    public:
      void input()
	{
	  cout<<"\nEnter No1 :  ";
	  cin>>a;
	  cout<<"\nEnter No2 : ";
	  cin>>b;
	}
     void div()
       {
	 try
	    {
	      cout.precision(2);
	      cout.setf(ios::showpoint);
	      if(b!=0)
		{
		   cout<<"\nNo1       : "<<setw(10)<<a
		       <<"\nNo2       : "<<setw(10)<<b
		       <<"\nDivision  : "<<setw(10)<<a/b;
		}
	      else
		throw(b);
	    }
	  catch(double d)
	    {
	      cout<<"\nDiv Not Possible !!!";
	    }
       }
  };
int main()
  {
    Excp E;
    E.input();
    E.div();
    return(1);
  }
