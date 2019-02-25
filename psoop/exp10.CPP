#include<iostream>
#include<fstream>
#include<stdio.h>
#include<string.h>
using namespace std;
class Student
  {
     int rno,age;
     char name[30];
    public:
     void get();
     void disp()
       {
	 cout<<"\n"<<rno<<"\t"<<age<<"\t"<<name;
       }
  }S;

fstream f1;
int sz=sizeof(S);
void Student :: get()
  {
    cout<<"\nEnter Roll No & Age: ";
    cin>>rno>>age;
    cout<<"\nEnter Name : ";
    while(cin.get()!='\n');
    cin.getline(name,30);
  }

void Add()
  {
    f1.open("stu.dat",ios::app);
    S.get();
    f1.write((char *)&S,sz);
    f1.close();
  }
void Disp()
  {
    f1.open("stu.dat",ios::in);
    while(f1.read((char *)&S,sz))
      S.disp();
    f1.close();
  }
int main()
  {
    int cont;

    do
     {
       Add();
       cout<<"\nWant To Add More Records(1 : Yes) : ";
       cin>>cont;
     }while(cont==1);
    Disp();
  }
