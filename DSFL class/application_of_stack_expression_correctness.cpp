#include<iostream>
using namespace std;

int main()
{
	char exp[80] , st[20];
	int i , flag = 0 , top = -1;
	
	cout<<"\n enter the expression :\n";
	cin.getline(exp , 79);
	
	for(i=0 ; exp[i]!='\0' ; i++)
	{
		
		if(exp[i]=='(' || exp[i]=='[' || exp[i]=='}')
		{
			top++;
			st[top] = exp[i];
		}
		else
		{
			
			if(exp[i]==')' || exp[i]==']' || exp[i]=='}')
			{
				
				if(top==-1)
				{
					flag = 1;
					break;
				}
				else
				{
					if((exp[i]==')' && st[top]=='(') || (exp[i]==']' && st[top]=='[') || (exp[i]=='}' && st[top]=='{'))
						top--;
					else
					{
						flag = 1;
						break;	
					}	
				}
							
			}	
			
		}
				
	}
	
	if(top!=-1)
		flag = 1;
	if(flag==0)
		cout<<"\n expression is valid!!!\n";
	else
		cout<<"\n expression is INVALID...\n";		
	
	return 0;	
	
}
