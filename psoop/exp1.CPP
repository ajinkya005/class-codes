#include<iostream>
#include<iomanip> // to use manipulator Functions
using namespace std;


class WR
  {
      int dom;
      float htemp,ltemp,amtrain,amtsnow;
    public :
      WR()
	{
	}
      WR(int d,float ht=29.00,float lt=25.00,float ar= 0.00,float as=0.00)
	{
	  dom=d;
	  htemp=ht;
	  ltemp=lt;
	  amtrain=ar;
	  amtsnow=as;
	}
      WR(WR &X)
	{
	  dom=X.dom;
	  htemp=X.htemp;
	  ltemp=X.ltemp;
	  amtrain=X.amtrain;
	  amtsnow=X.amtsnow;
	}
      void disp()
	{
	  cout<<"\n"<<setw(8)<<dom;
	  cout<<"  "<<setw(8)<<setprecision(2)<<setiosflags(ios::showpoint)<<htemp;
	  cout<<"  "<<setw(8)<<setprecision(2)<<setiosflags(ios::showpoint)<<ltemp;
	  cout<<"  "<<setw(8)<<setprecision(2)<<setiosflags(ios::showpoint)<<amtrain;
	  cout<<"  "<<setw(8)<<setprecision(2)<<setiosflags(ios::showpoint)<<amtsnow;
	}
      void change()
	{
	  cout<<"\nEnter New High Temp : ";
	  cin>>htemp;
	  cout<<"\nEnter New Low Temp : ";
	  cin>>ltemp;
	  cout<<"\nEnter New Rain Fall Amount : ";
	  cin>>amtrain;
	  cout<<"\nEnter New Snow Fall Amount : ";
	  cin>>amtsnow;
	}
      void report();
 }*W;
int n;//Global Variable
void WR :: report()
  {
    int i;
    float aht=0,alt=0,arf=0,asf=0;
    cout<<"\n------------------------------------------------";
    cout<<"\n     Day  HighTemp  Low Temp  RainFall  SnowFall";
    cout<<"\n------------------------------------------------";
    for(i=0;i<n;i++)
      {
	W[i].disp();
	aht=aht+W[i].htemp;
	alt=alt+W[i].ltemp;
	arf=arf+W[i].amtrain;
	asf=asf+W[i].amtsnow;
      }
    cout<<"\n------------------------------------------------";
    cout<<"\nAvrage    "<<setw(8)<<setprecision(2)<<setiosflags(ios::showpoint)<<aht/n;
    cout<<setw(10)<<setprecision(2)<<setiosflags(ios::showpoint)<<alt/n;
    cout<<setw(10)<<setprecision(2)<<setiosflags(ios::showpoint)<<arf/n;
    cout<<setw(10)<<setprecision(2)<<setiosflags(ios::showpoint)<<asf/n;
  }
int main()
  {
    int i,cont,ch;
    WR T;
    cout<<"\nEnter No Of Days in Month : ";
    cin>>n;
    W=new WR[n];
    for(i=0;i<n;i++)
      W[i]= WR(i+1);
    do
      {
	cout<<"\n\n\t\tMenu\n\n\t1.Enter Data\n\t2.Report\n\t3.Exit\n\n\t\tEnter Ch : ";
	cin>>ch;
	switch(ch)
	  {
	    case 1:
	      do
		{
		  cout<<"\nEnter Day Of Month : ";
		  cin>>i;
		  W[i-1].change();
		  cout<<"\nContinue(1 Yes) : ";
		  cin>>cont;
		}while(cont==1);
	      break;
	    case 2:
	      T.report();
	      break;
	    case 3:
	      cout<<"\nComming Out !!!";
	      break;
	    default:
	      cout<<"\nWrong Choice !!!";
	  }
      }while(ch!=3);
  
  return 0;
  
  }
