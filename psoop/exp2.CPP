#include<iostream>
#include<iomanip> // to use manipulator Functions
#include<string.h>
using namespace std;

class Books
  {
      char *title,*author,*pub;
      float pr;
      int stock;
      static int cnt,scnt,uscnt;
    public :
      void add();
      void update();
      int search(char *);
      void purchase();
      static void tran()
	{
	  cout<<"\nSucessful Transactions : "<<scnt
	      <<"\nUn-Sucessful Transactions : "<<uscnt;
	}
      void disp();
      void dispall();
 }B[100];
int Books :: cnt;  // imp stat dont mis
int Books :: scnt;
int Books :: uscnt;

int i;
void Books :: disp()
  {
	cout<<"\n"<<setw(22)<<setiosflags(ios::left)<<title;
	cout<<setw(22)<<setiosflags(ios::left)<<author;
	cout<<setw(22)<<setiosflags(ios::left)<<pub;
	cout<<setw(6)<<setiosflags(ios::right)<<setprecision(2)<<setiosflags(ios::fixed)<<pr;
	cout<<setw(6)<<stock;
  }
void Books :: dispall()
  {
    cout<<"\n------------------------------------------------------------------------------";
    cout<<"\nTitle                 Author                Publisher             Price  Stock";
    cout<<"\n------------------------------------------------------------------------------";
    for(i=0;i<cnt;i++)
      B[i].disp();
  }

int Books :: search(char *t)
  {
    for(i=0;i<cnt;i++)
      {
	if(strcmp(title,t)==0)
	  return(i);
      }
    return(-1);
  }
void Books :: add()
  {
    char str[80];
    cout << "\nEnter Book Title : ";
    while(cin.get()!='\n');
    cin.getline(str,80);
    i=search(str);
    if(i==-1)
      {
	title = new char[strlen(str)+1];
	strcpy(title,str);
	cout << "\nEnter Book Author : ";
	cin.getline(str,80);
	//while(cin.get()!='\n');
	author = new char[strlen(str)+1];
	strcpy(author,str);
	cout << "\nEnter Book Publication : ";
	cin.getline(str,80);
	//while(cin.get()!='\n');
	pub = new char[strlen(str)+1];
	strcpy(pub,str);
	cout<<"\nEnter Price Per Book : ";
	cin>>pr;
	cout<<"\nEnter Initial Book Stock : ";
	cin>>stock;
	B[cnt]=*this;
	cnt++;
	scnt++;
      }
    else
      {
	cout<<"\nBook Already Present";
	uscnt++;
      }
  }
void Books :: update()
  {
    char str[80];
    float p;
    cout << "\nEnter Book Title : ";
    while(cin.get()!='\n');
    cin.getline(str,80);
    i=search(str);
    if(i!=-1)
      {
	title = new char[strlen(str)+1];
	strcpy(title,str);
	cout << "\nEnter New Book Author : ";
	cin.getline(str,80);
	//while(cin.get()!='\n');
	delete(B[i].author);
	author = new char[strlen(str)+1];
	strcpy(B[i].author,str);
	cout << "\nEnter Book Publication : ";
	cin.getline(str,80);
	//while(cin.get()!='\n');
	delete(B[i].pub);
	pub = new char[strlen(str)+1];
	strcpy(B[i].pub,str);
	cout<<"\nEnter Price Per Book : ";
	cin>>p;
	B[i].pr=p;
	cout<<"\nEnter Initial Book Stock : ";
	cin>>B[i].stock;
	scnt++;
      }
    else
      {
	cout<<"\nBook Not Present";
	uscnt++;
      }
  }
void Books :: purchase()
  {
    char str[80];
    long tot;
    int qty;
    cout << "\nEnter Book Title : ";
    while(cin.get()!='\n');
    cin.getline(str,80);
    i=search(str);
    if(i!=-1)
      {
	cout<<"\nEnter Book Quntity To Purchase  : ";
	cin>>qty;
	B[i].stock=B[i].stock-qty;
	tot=B[i].stock*B[i].pr;
	cout<<"\ntotal Cost Of Available Stock : "<<tot;
	scnt++;
      }
    else
      {
	cout<<"\nBook Not Present";
	uscnt++;
      }
  }


int main()
  {
    int ch;
    char str[80];
    Books T;
    do
      {
	cout<<"\n\n\t\tMenu\n\n\t1.Add\n\t2.Update\n\t3.Search\n\t4.Purchase\n\t5.Transactions\n\t6.Display\n\t7.Exit\n\n\t\tEnter Ch : ";
	cin>>ch;
	switch(ch)
	  {
	    case 1:					//add
	      T.add();break;
	    case 2:					//update
	      T.update();break;
	    case 3:					//search
	      cout << "\nEnter Book Title : ";
	      while(cin.get()!='\n');
	      cin.getline(str,80);
	      i=T.search(str);
	      if(i!=-1)
		B[i].disp();
	      else
		cout<<"\nBook Not Present !!!";
	      break;
	    case 4:					//purchase
	      T.purchase();break;
	    case 5:					//transactions
	      Books::tran();break; //Note calling of Static function
	    case 6:					//display
	      T.dispall();break;
	    case 7:					//exit
	      cout<<"\nComming Out !!!";break;
	    default:				//default condition
	      cout<<"\nWrong Choice !!!";
	  }
      }while(ch!=7);
  }
