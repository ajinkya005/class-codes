#include<stdio.h>
#include<iostream>
using namespace std;
class Complex
  {
     float real,img;
   public:
     Complex()
       {
	 real=img=0;
       }
     Complex(float r,float i=0)
       {
	 real=r;
	 img=i;
       }
     void Get()
       {
	 cout<<"\nEnter Real part : ";cin>>real;
	 cout<<"\nEnter Img part : ";cin>>img;
       }

     friend Complex operator+(Complex,Complex);
     friend Complex operator-(Complex,Complex);
     Complex operator*(Complex);
     Complex operator/(Complex);
     void Disp()
       {
	 cout.precision(2);
	 cout.setf(ios::showpoint);
	 cout.setf(ios::fixed,ios::adjustfield);

	 cout<<real;
	 if(img>0)
	   cout<<"+"<<img<<"i";
	 else
	   {
	     if(img<0)
	       cout<<img<<"i";
	   }
	 cout<<"\n";
       }
  };
Complex operator+(Complex X,Complex Y)
  {
    Complex Z;
    Z.real=X.real+Y.real;
    Z.img=X.img+Y.img;
    return(Z);
  }
Complex operator-(Complex X,Complex Y)
  {
    Complex Z;
    Z.real=X.real-Y.real;
    Z.img=X.img-Y.img;
    return(Z);
  }
Complex Complex :: operator*(Complex X)
  {
    Complex Z;
    Z.real=real * X.real - img * X.img;
    Z.img=img+X.real + real * X.img;
    return(Z);
  }
Complex Complex :: operator/(Complex X)
  {
    Complex C;
    C.real=X.real;
    C.img=-X.img;
    float r;
    r=X.real*X.real-X.img*X.img;
    C.real=(float)(real*C.real-img*C.img)/r;
    C.img=(float)(img * C.real+real*C.img)/r;
    return(C);
  }
int main()
  {
    int ch;
    Complex c1,c2,c3;
    c1.Get();c2.Get();
    do
     {
      
      cout<<"\nComplex No 1:  ";
      c1.Disp();
      cout<<"\nComplex No 2:  ";
      c2.Disp();

      cout<<"\n\n\t\tMenu\n\n\t1.Add\n\t2.Sub\n\t3.Mul\n\t4.Div"
	  <<"\n\t5.Exit\n\n\t\tEnter Choice : ";
      cin>>ch;
      switch(ch)
	{
	  case 1:
	    c3=c1+c2;
	    cout<<"\nAddition : ";
	    c3.Disp();
	    break;
	  case 2:
	    c3=c1-c2;
	    cout<<"\nSubtraction : ";
	    c3.Disp();
	    break;
	  case 3:
	    c3=c1*c2;
	    cout<<"\nMultiplication : ";
	    c3.Disp();
	    break;
	  case 4:
	    c3=c1/c2;
	    cout<<"\nDivision : ";
	    c3.Disp();
	    break;
	  case 5:
	    cout<<"\n\nComming Out !!!";
	    break;
	  default :
	    cout<<"\nWrong Choice : ";
	}
      
     }while(ch!=5);
    return(1);
  }







