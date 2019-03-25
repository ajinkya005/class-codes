#include<iostream>
#define sz 20
using namespace std;

int cnt = 0 , i , j;

struct edge
{
	int v1 , v2 , d;
}E[50],T;

class ENode;

class HNode
{
	int v;
	HNode* hp;
	ENode* ep;
	
	friend class Graph;
	
	friend void Earray_Using_c(HNode*);
	friend void djkt();
		
};



class ENode
{
	int v , d;
	ENode* ep;
	
	friend class Graph;
	
	friend void Earray_Using_Matrix(HNode*);
	friend void djkt();
		
};



class Graph
{
	
	//HNode *g;
	int g[sz][sz];
	int n;
	
	char lm[sz][30];
	
	public:
		
		void createMat();
		//void createList();
		//void prims_Using_Matrix();
		//void prims_Using_List();
		//void kruskal_Using_Matrix();
		void djkt();
	
		ENode* getENode()
		{
			
			ENode* n;
			n = new ENode;
			n->ep = NULL;
			return(n);
		}
		
		HNode* getHNode()
		{
			
			HNode* n;
			n = new HNode;
			n->ep = NULL;
			n->hp = NULL;
			return(n);
			
		}


		friend void Earray_Using_List(HNode*);
		friend void prims_Using_List();
		
		
	
};



void Graph::createMat()
{
	
	int i , j , d;
	
	cout<<"\n enter no of vertices :\n";
	cin>>n;
	
	for(i=1 ; i<=n ;i++)
	{
		cout<<"\n enter landmark"<<i<<":";
		cin>>lm[i];
	}
	
	for(i=1 ; i<=n ; i++)
	{
		
		for(j=1 ; j<=n ; j++)
		{
			g[i][j] = 9999;
		}
		
	}
	
	while(1)
	{
		for(i=1 ; i<=n ; i++)
			cout<<"\n"<<i<<"."<<lm[i];
	
	
		cout<<"\n enter two landmark no's having edge(enter any landmark no. -1 to stop) :\n";
		cin>>i>>j;
		
		
		if(i == -1 || j == -1)
			break;
		else
		{
			
			if(i<1 || j<1 || i>n || j>n)
				cout<<"\n invalid landmark no.";
			else
			{
				cout<<"\n enter edge distance :\n";
				cin>>d;
				
				g[i][j] = g[j][i] = d;	
			}	
				
		}		
		
	
	}
	
}

void Earray_Using_Matrix(int g[sz][sz] , int n)
{
	
	
	for(i = 1 ; i<=n ; i++)		//to store all edges of graph into array E
	{
		for(j=1 ; j<=n ; j++)
		{
			
			if(g[i][j]!=9999)
			{
				E[cnt].v1 = i;
				E[cnt].v2 = j;
				E[cnt].d = g[i][j];
				cnt++;
			}
			
		}
	}// end of for loop to store all edges of graph into array E
	
	
	for(i=0 ; i<cnt-1 ; i++)		//to sort array of structure E in ascending order of distance
	{
		for(j=i+1 ; j<cnt ; j++)
		{
			if(E[i].d > E[j].d)
			{
				T = E[i];
				E[i] = E[j];
				E[j] = T;
			}
		}
	}			//end of for loop to sort array of structure E in ascending order of distance
		
}


void Graph::djkt()
{
	
	int i , cont , src , dest , count , cur , nd , dc , sd , visit[sz] , dist[sz] , prec[sz];
	
	do
	{
		cout<<"\n enter source and destination :\n";
		cin>>src>>dest;
		
		for(i=1 ; i<=n ; i++)
		{
			dist[i] = 999;
			visit[i] = 0;
		}
		dist[src] = 0;
		visit[src] = 1;
		prec[src] = src;
		cur = src;
		
		while(cur!=dest)
		{
			dc = dist[cur];
			
			for(i=1 ; i<=n ; i++)
			{
				nd = dc + g[cur][i];
				
				if(nd < dist[i])
				{
					dist[i] = nd;
					prec[i] = cur;
				}
			}
			
			sd = 999;
			
			for(i=1 ; i<=n ; i++)
			{
				if(visit[i]==0 && dist[i] < sd)
				{
					cur = i;
					sd = dist[i];
				}
			}
			
			visit[cur] = 1;
			
		}
		
		cout<<"\n shortest dis between"<<lm[src]<<"and"<<lm[dest]<<"is :"<<dist[dest];
		
		cout<<"\n path of shortest dist :\n"<<lm[dest]<<"-->";
		
		while(prec[cur]!=src)
		{
			cur = prec[cur];
			cout<<lm[cur]<<"-->";
			
		}
		
		cout<<lm[src];
		
		cout<<"\n continue (1 : yes)  :\n";
		cin>>cont;
	
	}while(cont==1);
	
	
}

int main()
{
	
	int ch;
	Graph g;
	
	do
	{
		
		cout<<"\n\n\t\tmenu\n\n\t\t";
		cout<<"\n\t1.create graph using matrix";
		//cout<<"\n\t2.create graph using list";
		//cout<<"\n\t3.prims algorithm using matrix ";
		cout<<"\n\t2.dijikstra's algorithm using matrix ";
		cout<<"\n\t3.exit";
		cin>>ch;
		
		switch(ch)
		{
			
			case 1:
						g.createMat();
						break;
						
						
			case 2:
						g.djkt();
						break;
						
			case 3:
						cout<<"\n coming out...!!!";
						break;
		
			default:
						cout<<"\n wrong choice....";
																					
			
			
			
			
		}
		
	}while(ch!=3);
	
	return 0;
}

/*


                menu


        1.create graph using matrix
        2.dijikstra's algorithm using matrix
        3.exit1

 enter no of vertices :
5

 enter landmark1:1

 enter landmark2:2

 enter landmark3:3

 enter landmark4:4

 enter landmark5:5

1.1
2.2
3.3
4.4
5.5
 enter two landmark no's having edge(enter any landmark no. -1 to stop) :
1 2

 enter edge distance :
6

1.1
2.2
3.3
4.4
5.5
 enter two landmark no's having edge(enter any landmark no. -1 to stop) :
2 3

 enter edge distance :
8

1.1
2.2
3.3
4.4
5.5
 enter two landmark no's having edge(enter any landmark no. -1 to stop) :
3 4

 enter edge distance :
2

1.1
2.2
3.3
4.4
5.5
 enter two landmark no's having edge(enter any landmark no. -1 to stop) :
4 5

 enter edge distance :
4

1.1
2.2
3.3
4.4
5.5
 enter two landmark no's having edge(enter any landmark no. -1 to stop) :
5 1

 enter edge distance :
3

1.1
2.2
3.3
4.4
5.5
 enter two landmark no's having edge(enter any landmark no. -1 to stop) :
1 4

 enter edge distance :
9

1.1
2.2
3.3
4.4
5.5
 enter two landmark no's having edge(enter any landmark no. -1 to stop) :
5 2

 enter edge distance :
5

1.1
2.2
3.3
4.4
5.5
 enter two landmark no's having edge(enter any landmark no. -1 to stop) :
-1 -1


                menu


        1.create graph using matrix
        2.dijikstra's algorithm using matrix
        3.exit2

 enter source and destination :
1 3

 shortest dis between1and3is :9
 path of shortest dist :
3-->4-->5-->1
 continue (1 : yes)  :

