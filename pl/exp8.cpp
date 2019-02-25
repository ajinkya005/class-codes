#include<iostream>
using namespace std;
#define sz 50
class Sparse
  {
    int r,c,val;
    public:
      void create(Sparse A[sz]);
      void sTrans(Sparse S[sz],Sparse T[sz]);
      void fTrans(Sparse S[sz],Sparse T[sz]);
      void Add(Sparse A[sz],Sparse B[sz],Sparse C[100]);
      void disp(Sparse X[100]);
  };
void Sparse::create(Sparse A[sz])
  {
    int i,j,row,col,ele,k,m[sz][sz],cnt=0;
    cout<<"\nEnter NO. of Rows & cols: ";
    cin>>row>>col;
    for(i=0;i<row;i++)
      {
        for(j=0;j<col;j++)
          {
            m[i][j]=0;            //initialize all ele to 0
          }
      }    
        while(1)
	  {
	    cout<<"\n Enter non zero element(Enter 0 to stop): ";
	    cin>>ele;
	    if(ele==0)
	      break;              //Enter 0 to stop inserting element       
	    else
	      { 
	        cout<<"\n Enter row and col subscript: ";
	        cin>>i>>j;
	        if(i<0||i>=row||j<0||j>=col)                //check position
	          cout<<"\n Invalid position!!!";
	        else
	          {
	            m[i][j]=ele;                //Insert valid element only
	            cnt++;
	          }  
	      }  
	  }      
	  A[0].r=row;
	  A[0].c=col;
	  A[0].val=cnt;
	  k=1;
	  for(i=0;i<row;i++)
	    {
	      for(j=0;j<col;j++)
	        {
	          if(m[i][j]!=0)
	            {
	              A[k].r=i;
	              A[k].c=j;
	              A[k].val=m[i][j];
	              k++;
	            }
	        }
	    }
      
  }
void Sparse::sTrans(Sparse A[sz],Sparse T[sz])
  {  
    int i,j,k;
    T[0].r=A[0].c;
    T[0].c=A[0].r;
    T[0].val=A[0].val;
    k=1;
    for(i=0;i<A[0].c;i++)
      {
        for(j=1;j<=A[0].val;j++)
          {
            if(A[j].c==i)
              {
                T[k].r=A[j].c;
                T[k].c=A[j].r;
                T[k].val=A[j].val;
                k++;
              }
          }
      }
      cout<<"\n Matrix\n";
      disp(A);
      cout<<"\n Transpose\n";
      disp(T);
  }
void Sparse::fTrans(Sparse A[sz],Sparse T[sz])
  {
    int i,j,k,cnt[sz],pos[sz];
    T[0].r=A[0].c;
    T[0].c=A[0].r;
    T[0].val=A[0].val;
    for(i=0;i<A[0].c;i++)
      cnt[i]=0;
    for(i=1;i<=A[0].val;i++)
      cnt[A[i].c]++;			//To count element in each col
      
    pos[0]=1;
    for(i=1;i<A[0].c;i++)
      pos[i]=pos[i-1]+cnt[i-1];
        
    for(i=1;i<=A[0].val;i++)
        {
          j=A[i].c;
          k=pos[j];
          T[k].r=A[i].c;
          T[k].c=A[i].r;
          T[k].val=A[i].val;
          pos[j]++;
        }    
      cout<<"\n Matrix\n";
      disp(A);
      cout<<"\n Transpose\n";
      disp(T);
        
  }
void Sparse::Add(Sparse A[sz],Sparse B[sz],Sparse C[100])
  {
    int i,j,k;
    if(A[0].r!=B[0].r||A[0].c!=B[0].c)
      cout<<"\n Add not possible!!!";
    else
      {
        for(i=j=k=1;i<=A[0].val&&j<=B[0].val;k++)
          {
             if(A[i].r==B[j].r)
               {
                 if(A[i].c==B[j].c)
                   {
                     C[k]=A[i];
                     C[k].val=C[k].val+B[j].val;
                     i++,j++;
                   }
                 else
                   {
                     if(A[i].c<B[j].c)
                       {
                         C[k]=A[i];
                         i++;
                       }
                     else
                       {
                         C[k]=B[j];
                         j++;
                       }  
                   }  
               } 
             else
               {
                 if(A[i].r<B[j].r)
                   {
                     C[k]=A[i];
                     i++;
                   }
                 else
                   {
                   C[k]=B[j];
                   j++;
                   }  
               }  
          }
          while(i<=A[0].val)
            {
              C[k]=A[i];
              i++;k++;
            }
          while(j<=B[0].val)
            {
              C[k]=B[j];
              j++;k++;
            }  
          C[0].r=A[0].r;
          C[0].c=A[0].c;
          C[0].val=k-1;
          cout<<"\n matrix A\n";
          disp(A);
          cout<<"\n matrix B\n";
          disp(B);
          cout<<"\n Added Matrix\n";
          disp(C);  
      }  
  } 
void Sparse::disp(Sparse X[100])
  {
    int i;
    for(i=0;i<=X[0].val;i++)
      cout<<"\n"<<X[i].r
      <<"\t"<<X[i].c
      <<"\t"<<X[i].val;
  }       
int main()
  {
    Sparse x,A[sz],B[sz],C[100],T[sz];
    x.create(A);
    x.create(B);
    x.disp(A);
    x.sTrans(A,T);
    x.fTrans(A,T);
    x.Add(A,B,C);
    return 0;
  }	    
