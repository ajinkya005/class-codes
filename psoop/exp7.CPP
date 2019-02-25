#include<iostream>
using namespace std;
template <class Tp>
class Matrix
  {
       Tp a[3][3];
     public:
       void Accmat();
       void Dispmat();
       void Add(Matrix );
       void Sub(Matrix );
       void Mul(Matrix );
  };
template <class Tp>
void Matrix <Tp> :: Accmat()
  {
    int i,j;
    for(i=0;i<3;i++)
      {
	for(j=0;j<3;j++)
	  cin>>a[i][j];
      }
  }
template <class Tp>
void Matrix <Tp> :: Dispmat()
  {
    int i,j;
    cout.precision(2);
    cout.setf(ios::showpoint);
    for(i=0;i<3;i++)
      {
	for(j=0;j<3;j++)
	  cout<<a[i][j]<<"\t";
	cout<<"\n";
      }
  }
template <class Tp>
void Matrix <Tp> :: Add(Matrix<Tp> M)
  {
    int i,j;
    cout.precision(2);
    cout.setf(ios::showpoint);
    for(i=0;i<3;i++)
      {
	for(j=0;j<3;j++)
	  cout<<a[i][j]+M.a[i][j]<<"\t";
	cout<<"\n";
      }
  }
template <class Tp>
void Matrix <Tp> :: Sub(Matrix<Tp> M)
  {
    int i,j;
    cout.precision(2);
    cout.setf(ios::showpoint);
    for(i=0;i<3;i++)
      {
	for(j=0;j<3;j++)
	  cout<<a[i][j]-M.a[i][j]<<"\t";
	cout<<"\n";
      }
  }
template <class Tp>
void Matrix <Tp> :: Mul(Matrix<Tp> M)
  {
    int i,j,k,ele;
    cout.precision(2);
    cout.setf(ios::showpoint);
    for(i=0;i<3;i++)
      {
	for(j=0;j<3;j++)
	  {
	    ele=0;
	    for(k=0;k<3;k++)
	      ele=ele+a[i][k]*M.a[k][j];
	    cout<<ele<<"\t";
	  }
	cout<<"\n";
      }
  }
int main()
  {
    int ch;
    Matrix <int>A;
    Matrix <int>B;
    Matrix <float>C;
    Matrix <float>D;

    cout<<"\nEnter int 3*3 Matrix\n";
    A.Accmat();
    cout<<"\nEnter int 3*3 Matrix\n";
    B.Accmat();
    cout<<"\nEnter Float 3*3 Matrix\n";
    C.Accmat();
    cout<<"\nEnter Float 3*3 Matrix\n";
    D.Accmat();
    do
      {
	cout<<"\nInt Matrix1\n\n";
	A.Dispmat();
	cout<<"\nInt Matrix2\n\n";
	B.Dispmat();
	cout<<"\nFloat Matrix1\n\n";
	C.Dispmat();
	cout<<"\nFloat Matrix2\n\n";
	D.Dispmat();
	cout<<"\n\n\t\tMat Op\n\n\t1.Add\n\t2.Sub\n\t3.Mul\n\t4.Exit\n\n\t\tEnter Ch : ";
	cin>>ch;
	switch(ch)
	  {
	    case 1:
	      A.Add(B);
	      C.Add(D);
	      break;
	    case 2:
	      A.Sub(B);
	      C.Sub(D);
	      break;
	    case 3:
	      A.Mul(B);
	      C.Mul(D);
	      break;
	    case 4:
	      cout<<"\nComming Out !!!";break;
	    default:
	      cout<<"\nWrong Choice !!!";
	  }
   }while(ch!=4);
   return(1);
  }
