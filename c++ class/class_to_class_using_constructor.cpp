#include<iostream>
using namespace std;

class product
{
	int m , n;
	public:
		void set(int x , int y)
		{
			m = x;
			n = y;
		}
		
		int getm()
		{
			return(m);
		}
		
		int getn()
		{
			return(n);
		}
			
		
};


class item
{
	int a , b;		
	public:
		
		void show()
		{
			cout<<"\na = "<<a<<" b = "<<b;
		}
		
		item(){
		}
		item(product p)
		{
			a = p.getm();				//here m and n cannot be accessed as they are private members of other class.
			b = p.getn();				
		}
		

};

int main()
{
	
	item i1;
	product p1;
	
	p1.set(3,4);
	i1 = p1;
	i1.show();
	
	return 0;	
}







									//for class to class we can use constuctor or casting operator.
									//in case of constructor we have to create constructor in left 
									//side class.
									//in case of casting operator we have create casting operator
									// in right side class.
									
									
									
									
									
									
