#include<iostream>
#define sz 5
using namespace std;


class Cqueue
{
	int q[sz] , f , r;
	
	public:
		Cqueue()
		{
			f = 0;
			r = -1;		
		}
		
		void addr();
		void delf();
		void disp();
		void addf();
		void delr();
		
		int qFull()
		{
			if(((f == r+1) && r!=-1) || (f ==0 && (r == sz-1)))
				return 1;
			else
				return 0;	
		}
		
		int qEmpty()
		{
			if(r == -1)
				return 1;
			else
				return 0;	
		}
};

void Cqueue :: addr()
{
	if(qFull()==1)
		cout<<"\n queue is full....";
	else
	{	
		disp();
		r = (r+1)%sz;
		cout<<"\n enter data :\n";
		cin>>q[r];			
	}	
	
	disp();
		
}

void Cqueue :: addf()
{
	
	if(f==0)
		cout<<"\n addition not possible";
	else
	{
		disp();
		f = (f-1)%sz;
		cout<<"\n enter element :\n";
		cin>>q[f];
		
	}
	disp();
	
}

void Cqueue :: delf()
{
	if(qEmpty()==1)
		cout<<"\n queue is empty....";
	else
	{	
		disp();
		cout<<"\n"<<q[f]<<"  is deleted";	
		if(f == r)
		{
			f = 0;
			r = -1;	
		}
		else
		{
			f = (f+1)%sz;	
		}	
					
	}	
	
	disp();	
}


void Cqueue :: delr()
{
	
	if(f == r+1)
		cout<<"\n queue is empty ...";
	else
	{
		
		cout<<"\n"<<q[r]<<"\t is deleted";
		r = (r-1)%sz;
		
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
		cout<<"\n\t1.add at rear";
		cout<<"\n\t2.delete at front";
		cout<<"\n\t3.display";
		cout<<"\n\t4.add at front";
		cout<<"\n\t5.delete at rear";
		cout<<"\n\t6.exit";
		cout<<"\n\n\t\t enter your choice :\n";
		cin>>ch;
		
		switch(ch)
		{
			
				case 1:
						q.addr();
						break;
						
				case 2:
						q.delf();
						break;
			
				case 3:
						q.disp();
						break;
			
				case 4:
						q.addf();
						break;
						
				case 5:
						q.delr();
						break;
														
				case 6:
						cout<<"\n coming out...";
						break;
					
				default:
						cout<<"\n enter correct choice....";			
						
		}
		
	}while(ch!=6);
	
	return 0;	
	
}
