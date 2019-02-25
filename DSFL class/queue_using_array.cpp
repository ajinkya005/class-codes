#include<iostream>
#define sz 10
using namespace std;


class Queue
{
	int q[sz] , f , r;
	
	public:
		Queue()
		{
			f = 0;
			r = -1;		
		}
		
		void add();
		void del();
		void disp();
		
		int qFull()
		{
			if(r == sz-1)
				return 1;
			else
				return 0;	
		}
		
		int qEmpty()
		{
			if(f == r+1)
				return 1;
			else
				return 0;	
		}
};

void Queue :: add()
{
	if(qFull()==1)
		cout<<"\n queue is full....";
	else
	{	
		disp();
		r++;
		cout<<"\n enter data :\n";
		cin>>q[r];			
	}	
	
	disp();
		
}

void Queue :: del()
{
	if(qEmpty()==1)
		cout<<"\n queue is empty....";
	else
	{	
		disp();		
		cout<<"\n"<<q[f]<<"  is deleted";
		f++;			
	}	
	
	disp();	
}

void Queue :: disp()
{
	if(qEmpty()==1)
		cout<<"\n queue is empty.....";
	else
	{
	
		cout<<"\n front ->";
		for(int i = f ; i<=r; i++)
			cout<<"\t"<<q[i];
		cout<<"\t<-rear";		
		
	}	
		
}

int main()
{
	
	int ch;
	Queue q;
	
	do
	{
	
		cout<<"\n\n\t\t******************MENU*******************\n\n\t\t";
		cout<<"\n\t1.add";
		cout<<"\n\t2.delete";
		cout<<"\n\t3.display";
		cout<<"\n\t4.exit";
		cout<<"\n\n\t\t enter your choice :\n";
		cin>>ch;
		
		switch(ch)
		{
			
				case 1:
						q.add();
						break;
						
				case 2:
						q.del();
						break;
			
				case 3:
						q.disp();
						break;
			
				case 4:
						cout<<"\n coming out...";
						break;
			
				default:
						cout<<"\n enter correct choice....";			
						
		}
		
	}while(ch!=4);
	
	return 0;	
	
}
