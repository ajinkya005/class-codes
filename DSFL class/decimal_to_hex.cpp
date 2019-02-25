#include<iostream>
#include<iomanip>
#include<stdlib.h>
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
		st[top] = no%16;
		no = no/16;
		
	}
	cout<<"\n hex equivalent is :\n";
	while(top!=-1)
	{
		if(st[top]<10)
			cout<<st[top];
		else
			cout.put(st[top]+55);
		
		top--;	
	}
	
	return 0;
		
}
