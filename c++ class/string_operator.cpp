#include<iostream>
#include<string.h>
using namespace std;

class string
{	
	char* str;
	int len;
	
	public:
	string()
	{
		len = 0;
		str = new char[len+1];
		strcpy(str , "");	
	}
	
	string(char* s)
	{
		len = strlen(s);
		str = new char[len + 1];
		strcpy(str , s);	
	}	
	
	~string()
	{
		delete(str);
	}
	
	void operator!()
	{
		strrev(str);
	}
	friend void operator-(string &);
	
	int operator==(string x)
	{
		if(len==x.len)
			return(1);
		else
			return(0);	
	}
	
	string operator+(string);
	
	
};


 string string :: operator+(string x)
{
	string t;
	t.len = len +x.len;
	delete(t.str);
	t.str = new char[t.len + 1];
	strcpy(t.str , str);
	strcat(t.str , x.str);
	return(t);
}
void operator-(string &x)
{
	strupr(x.str);
}

int main()
{
	
	string s1("click_in") , s2("comp") , s3("pune") , s4;
	
	cout<<s1<<s2<<s3;
	!s3;
	cout<<s3;
	s4 = s1+s2;
	cout<<s4;
	-s2;
	cout<<s2;
	
	if(s2==s3)
		cout<<"\nequal length objects...";
	else
		cout<<"\ndifferent length objects...";
	
	return 0;
}
