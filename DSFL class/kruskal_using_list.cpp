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
	
	friend void Earray_Using_List(HNode*);
	friend void prims_Using_List();
		
};



class ENode
{
	int v , d;
	ENode* ep;
	
	friend class Graph;
	
	friend void Earray_Using_List(HNode*);
	friend void prims_Using_List();
		
};



class Graph
{
	
	HNode *g;
	int n;
	
	char lm[sz][30];
	
	public:
		Graph()
		{
			g = NULL;
		}
		
		void createMat();
		void createList();
		//void prims_Using_Matrix();
		//void prims_Using_List();
		void kruskal_Using_List();
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


		friend void Earray_Using_List(HNode*);
		friend void prims_Using_List();
		
		HNode* getG()
		{
			return(g);
		}
		
	
};


/*
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
*/


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

/*
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

*/

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


void Graph::kruskal_Using_List()
{
	
	int c[sz][sz] , i , j , k , pv1  ,pv2 , es , cost = 0;
	Earray_Using_List(g);
	
	for(i=1 ; i<=n ; i++)
	{
		
		for(j=1 ; j<=n ; j++)
		{
			
			if(j==1)
				c[i][j] = i;
			else
				c[i][j] = 0;	
		}
		
		
	}
	
	k = 0;
	es = 0;
	
	while(es < n-1)
	{
		
		T = E[k];
		k++;
		
		for(i=1 ; i<=n ; i++)
		{
			for(j=1 ; j<=n ; j++)
			{
				if(c[i][j] == T.v1)
					pv1 = i;
				if(c[i][j] == T.v2)
					pv2 = i;				
					
			}	
		}
		
			
		if(pv1!=pv2)
		{
			cout<<"\n"<<lm[T.v1]<<"<-->"<<lm[T.v2]<<"="<<T.d;
			es++;
			cost = cost + T.d;
			
			for(i=1 ; c[pv1][i]!=0 ; i++);
				
			for(j=1 ; c[pv1][j]!=0 ; j++ , i++)
			{
				c[pv1][i] = c[pv2][j];
				c[pv2][j] = 0;	
			}	
				
		}
			
				  
	}

	cout<<"\n cost of span tree :"<<cost;

}
int main()
{
	
	int ch;
	Graph g;
	
	do
	{
		
		cout<<"\n\n\t\tmenu\n\n\t\t";
		cout<<"\n\t1.create graph using list";
		//cout<<"\n\t2.create graph using list";
		//cout<<"\n\t3.prims algorithm using matrix ";
		cout<<"\n\t2.kruskals algorithm using list ";
		cout<<"\n\t3.exit";
		cin>>ch;
		
		switch(ch)
		{
			
			case 1:
						g.createList();
						break;
						
						
			case 2:
						g.kruskal_Using_List();
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
