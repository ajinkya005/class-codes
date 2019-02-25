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
		
		void add();
		void del();
		void disp();
		
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

void Cqueue :: add()
{
	int i , t;
	
	if(qFull()==1)
		cout<<"\n queue is full....";
	else
	{	
		disp();
		r = (r+1)%sz;
		cout<<"\n enter data :\n";
		cin>>q[r];
		
		t = q[r];
		
		for(i=r ; i!=f && q[i-1]>t ; i = (i-1)%sz)			// this for loop is valid for circular queue
															//if you want to to do same thing with linear queue then the
															//loop is for(i=1 ; i>f && q[i-1]>t ; i--);
			q[i] = q[i-1];
			
		q[i] = t;				
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
