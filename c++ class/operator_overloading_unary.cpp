#include<iostream>
using namespace std;

class abc
{
	
	int a , b , c;
	
	public:
		abc(int x=0 , int y=0 , int z=0)
		{
			a = x;
			b = y;
			c = z;
		}
	
		void disp()
		{
			cout<<"\na = "<<a;
			cout<<"\nb = "<<b;
			cout<<"\nc = "<<c;
		}
		
		void operator-();
};

void abc::operator-()
{
	a = -a;
	b = -b;
	c = -c;
}

int main()
{
	abc A(2 , -4 , 7) , B(-3 , 9 , 1);
	
	A.disp();
	-A;
	A.disp();
	B.disp();
	-B;
	B.disp();	

return 0;
}
