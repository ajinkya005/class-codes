#include<iostream>
#define sz 20
using namespace std;

int cnt = 0 , i , j;

struct edge
{
	int v1 , v2 , d;
}E[50],T;

class ENode
{
	int v , d;
	ENode* ep;
	friend class Graph;
};

class HNode
{
	int v;
	HNode* hp;
	ENode* ep;
	friend class Graph;
};


class Graph
{
	
	//HNode *g;
	int g[sz][sz];
	int n;
	
	char lm[sz][30];
	
	public:
		
		void createMat();
		void createList();
		void prims_Using_Matrix();
		//void prims_Using_List();
		//void kruskals();
		//void djkt();
	
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
/*
void Graph::createList()
{
	
	HNode* hp , *hn , *lhn , *hq;
	ENode* en , *len , *es;
	int i , v;
	cout<<"\n enter no. of landmarks :\n";
	cin>>n;
	
	for(i=1 ; i<=n ; i++)
	{
		cout<<"\n enter landmark"<<i<<":";
		cin>>lm[i];
	}
	
	for(i=1 ; i<=n ; i++)
	{
		hn = getHNode();
		hn->v = i;
		
		if(g == NULL)
			g = lhn = hn;
		else
		{
			lhn->hp = hn;
			lhn = hn;	
		}	
		
	}
	
	
	for(hq = g ; hq!=NULL ; hq=hq->hp)
	{
		
		es = NULL;
		
		while(1)
		{
			for(i=1 ; i<=n ; i++)
				cout<<"\n"<<i<<"."<<lm[i];
			
			cout<<"\n enter -1 to stop :\n";
			cout<<"\n ente edge "<<hq->v<<"<-->";
			cin>>v;
			
			
			if(v == -1)
				break;	
			else
			{
				
				if(v == hq->v || v<1 || v>n)
					cout<<"\n invalid edge...";
				else
				{
					
					en = getENode();
					en->v = v;
					
					cout<<"\n enter edge distance :\n";
					cin>>en->d;
					
					if(es == NULL)
						hq->ep = es = len = en;
					else
					{
						len->ep = en;
						len = en;	
					}	
						
				}	
				
			}	
		}
				
	}
		
}

*/

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

/*
void Earray_Using_List(HNode* g)
{
	
	HNode* hq;
	ENode* eq;
	
	for(hq = g ; hq!=NULL ; hq = hq->hp)	//to store all edges of graph into array E
	{
		for(eq=hq->ep ; eq!=NULL ; eq = eq->ep)
		{
			if(eq->v > hq->v)
			{
				E[cnt].v1 = hq->v;
				E[cnt].v2 = eq->v;
				E[cnt].d = eq->d;
				cnt++;
			}
		}
	}			// end of for loop to store all edges of graph into array E
	
	for(i=0 ; i<cnt-1 ; i++)	//to sort array of structure E in ascending order of distance
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
	}		//end of for loop to sort array of structure E in ascending order of distance
		
}

*/

void Graph::prims_Using_Matrix()
{
	
	int es = 0 , cost = 0 , visit[sz];	
	Earray_Using_Matrix(g,n);
	T = E[0];
	
	cout<<"\n minimum spannig tree \n\n";
	cout<<"\n"<<lm[T.v1]<<"<-->"<<lm[T.v2]<<"="<<T.d;
	
	es = 1;
	cost = T.d;
	
	for(i = 1 ; i<=n ; i++)
		visit[i] = 0;
		
	visit[T.v1] = visit[T.v2] = 1;
	
	while(es < n-1)
	{
		
		for(i=1 ; i<cnt ; i++)
		{
			T = E[i];
			if(visit[T.v1]!=visit[T.v2])
			{
				cout<<"\n"<<lm[T.v1]<<"<-->"<<lm[T.v2]<<"="<<T.d;
				es++;
				cost = cost + T.d;
				
				if(visit[T.v1] == 0)
					visit[T.v1] = 1;
				else
					visit[T.v2] = 1;
					break;	
				
			}
		}
			
	}	
	
	cout<<"\n cost of span tree :"<<cost;
	
}

/*
void Graph::prims_Using_List()
{
	
	int es = 0 , cost = 0 , visit[sz];
	Earray_Using_List(g);
	T = E[0];
	
	cout<<"\n minimum spannig tree \n\n";
	cout<<"\n"<<lm[T.v1]<<"<-->"<<lm[T.v2]<<"="<<T.d;
	
	es = 1;
	cost = T.d;
	
	for(i = 1 ; i<=n ; i++)
		visit[i] = 0;
		
	visit[T.v1] = visit[T.v2] = 1;
	
	while(es < n-1)
	{
		
		for(i=1 ; i<cnt ; i++)
		{
			T = E[i];
			if(visit[T.v1]!=visit[T.v2])
			{
				cout<<"\n"<<lm[T.v1]<<"<-->"<<lm[T.v2]<<"="<<T.d;
				es++;
				cost = cost + T.d;
				
				if(visit[T.v1] == 0)
					visit[T.v1] = 1;
				else
					visit[T.v2] = 1;
					break;	
				
			}
		}
			
	}	
	
	cout<<"\n cost of span tree :"<<cost;
	
}

*/

int main()
{
	
	int ch;
	Graph g;
	
	do
	{
		
		cout<<"\n\n\t\tmenu\n\n\t\t";
		cout<<"\n\t1.create graph using matrix ";
		//cout<<"\n\t2.create graph using list";
		cout<<"\n\t2.prims algorithm using matrix ";
		//cout<<"\n\t4.prims algorithm using list ";
		cout<<"\n\t3.exit";
		cin>>ch;
		
		switch(ch)
		{
			
			case 1:
						g.createMat();
						break;
						
			case 2:
						g.prims_Using_Matrix();
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
        2.prims algorithm using matrix
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
1 3

 enter edge distance :
5

1.1
2.2
3.3
4.4
5.5
 enter two landmark no's having edge(enter any landmark no. -1 to stop) :
1 5

 enter edge distance :
3

1.1
2.2
3.3
4.4
5.5
 enter two landmark no's having edge(enter any landmark no. -1 to stop) :
4

5

 enter edge distance :
9

1.1
2.2
3.3
4.4
5.5
 enter two landmark no's having edge(enter any landmark no. -1 to stop) :
2 4

 enter edge distance :
7

1.1
2.2
3.3
4.4
5.5
 enter two landmark no's having edge(enter any landmark no. -1 to stop) :
3 5

 enter edge distance :
6

1.1
2.2
3.3
4.4
5.5
 enter two landmark no's having edge(enter any landmark no. -1 to stop) :
1 4

 enter edge distance :
2

1.1
2.2
3.3
4.4
5.5
 enter two landmark no's having edge(enter any landmark no. -1 to stop) :
-1 -1


                menu


        1.create graph using matrix
        2.prims algorithm using matrix
        3.exit2

 minimum spannig tree


1<-->4=2
1<-->5=3
1<-->3=5
2<-->4=7
 cost of span tree :17

                menu


        1.create graph using matrix
        2.prims algorithm using matrix
        3.exit*/
