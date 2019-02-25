#include<iostream>
using namespace std;

class abc
{
	int a , b , c;
	public:
	abc(int x=0 , int y=0 , int z=0)
	{
		a=x;b=y;c=z;
	}
	void disp()
	{
		cout<<"\n a = "<<a;
		cout<<"\n b = "<<b;
		cout<<"\n c = "<<c;
	}
	
	abc operator pqr();
	friend pqr :: pqr(abc);
	
};

class pqr
{
	int p , q , r;
	
	public:
		void disp()
		{
			cout<<"\n p = "<<p;
			cout<<"\n q = "<<q;
			cout<<"\n r = "<<r;			
		}
		
		pqr(abc);
		friend abc :: operator pqr(); 
};

abc :: operator pqr()
{
	pqr p;
	p.p = a;
	p.q = b;
	p.r = c;
	
	return(p);
}
pqr :: pqr(abc x)
{
	p = x.a;
	q = x.b;
	r = x.c;
}

int main()
{
	
	abc A(1 , 2 , 3);
	pqr p;
	p = A;
	
	return 0;
	
}
