#include<iostream>
using namespace std;

class
complex
{
	private:
		int a , b;
		
		public:
			complex(){
			}
			
			complex(int k)
			{
				a=k;b=0;
			}
	void set(int x = 0, int y = 0)
	{
		a = x;
		b = y;
	}
	
	void show()
	{
		cout<<"\na = "<<a<<" b = "<<b;
	}
	
};

int main()
{								//for basic to class we use constructor.
	complex c1;					//constructor gets called when object is created . 
	int x = 5;					//if we dont create constructor compiler itself creates it and gets called
	c1 = x; 	//c1.complex(x)						//parameterized constructor gets called when we pass the value while creating the object
	c1.show();					//constructor gets called when any different type of value is assigned to the object of that class									
	return 0;					//here c1 object is assigned an integer value 
}								//hence for c1 that constructor will get called which will take one int value	
