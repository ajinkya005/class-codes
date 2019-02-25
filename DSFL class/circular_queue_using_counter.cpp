#include<iostream>
#define sz 10
using namespace std;


class Cqueue
{
	int q[sz] , f , r , cnt;
	
	public:
		Cqueue()
		{
			f = 0;
			r = -1;	
			cnt = 0;	
		}
		
		void add();
		void del();
		void disp();
		
		int qFull()
		{
			if(cnt == sz)
				return 1;
			else
				return 0;	
		}
		
		int qEmpty()
		{
			if(cnt == 0)
				return 1;
			else
				return 0;	
		}
};

void Cqueue :: add()
{
	if(qFull()==1)
		cout<<"\n queue is full....";
	else
	{	
		disp();
		r = (r+1)%sz;
		cout<<"\n enter data :\n";
		cin>>q[r];
		cnt++;			
	}	
	
	disp();
		
}

void Cqueue :: del()
{
	if(qEmpty()==1)
		cout<<"\n queue is empty....";
	else
	{	
		disp();		
		cout<<"\n"<<q[f]<<"  is deleted";
		f = (f+1)%sz;
		cnt--;			
	}	
	
	disp();	
}

void Cqueue :: disp()
{
	int i;
	if(qEmpty()==1)
		cout<<"\n queue is empty.....";
	else
	{
	
		cout<<"\n front ->";
		for(i = f ; i!=r ; i = (i+1)%sz)
			cout<<"\t"<<q[i];
						
		cout<<"\t"<<q[i]<<"\t<-rear";		
		
	}	
		
}

int main()
{
	
	int ch;
	Cqueue q;
	
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
