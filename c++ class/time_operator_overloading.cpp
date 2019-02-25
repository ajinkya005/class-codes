#include<iostream>
using namespace std;

class time
{	
	int hrs , mins;
	
	public:
	void get()
	{
		cout<<"\nenter hrs and mins :\n";
		cin>>hrs>>mins;	
	}	
	void disp()
	{
		cout<<"\nhrs :"<<hrs<<"\tmins :"<<mins;
	}
	
	time operator+(time);
	time operator+(int);
	friend time operator+(int , time);
	
};

time time :: operator+(time x)
{
	time z;
	z.mins = mins + x.mins;
	z.hrs =  hrs + x.hrs + z.mins/60;
	z.mins = z.mins%60;
	
	return(z);
}

time time :: operator+(int x)
{
	time z;
	
	z.mins = mins + x;
	z.hrs = hrs + z.mins/60;
	z.mins = z.mins%60;
	
	return(z);
}

time operator+(int x , time y)
{
	time z;
	
	z.mins = x + y.mins;
	z.hrs = y.hrs + z.mins/60;
	z.mins = z.mins%60;
	
	return(z);
}

int main()
{
	
	time t1 , t2 , t3 , t4 , t5;
	t1.get();
	t2.get();
	
	t3 = t1 +50;
	t4 = t1 +t2;
	t5 = 20 +t2;
	
	t1.disp();
	t2.disp();
	t3.disp();
	t4.disp();
	t5.disp();	
	
	return 0;	
}
