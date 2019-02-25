#include<iostream>
//#define sz 5
using namespace std;

int main()
{
	int st[16] , top = -1 , no;
	
	cout<<"\n enter the no :\n";
	cin>>no;							//for decimal to octal just replace 2 by 8
	
	while(no!=0)
	{
		
		top++;
		st[top] = no%2;
		no = no/2;
		
	}
	cout<<"\n binary equivalent is :\n";
	while(top!=-1)
	{
		cout<<"\t"<<st[top];
		top--;;	
	}
	
	return 0;
		
}
