#include<iostream>
using namespace std;

class complex
{
	int a , b;
	
	public:
		void set(int x , int y)
		{
			a=x;
			b=y;
		}
		void show()
		{
			cout<<"\na = "<<a<<" b = "<<b;
		}
		
		operator int()
		{
			return(a);			//value of a will be assigned to x;	
		}
};

int main()
{
	
	complex c1;						//for class to basic we need casting operator.
	c1.set(3,4);					//
	c1.show();
	int x;
	x = c1;	//x = c1.operator int()
	cout<<"\n x ="<<x;
	
}
