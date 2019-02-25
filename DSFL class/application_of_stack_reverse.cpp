#include<iostream>
using namespace std;

int main()
{
	char str[30] , st[30];
	int i , top = -1;
	
	cout<<"\n enter the string :\n";
	cin.getline(str , 29);
	for(i=0 ; str[i]!='\0' ; i++)
	{
		
		if(str[i]!=' ')
		{
			top++;
			st[top] = str[i];
		
		}	
		else
		{
			while(top!=-1)
			{
				cout<<st[top];
				top--;	
			}
			
			cout<<" ";	
		}			
		
	}
	while(top!=-1)
	{
		cout<<st[top];
		top--;
	}
	
	return 0;
		
}
