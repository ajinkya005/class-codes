#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
class Personal
  {
    protected:
      char *name,*dob,*phno,*add;
  };
class Professional
  {
    protected:
      char *exp;
  };
class Academic
  {
    protected:
     char *quali;
     float per;
  };
class BioData : public Personal,public Professional,public Academic
  {
    public:
      void Add();
      void Disp();
   };
void BioData :: Disp()
  {
	cout<<"\n                  Bio-Data";
	cout<<"\nName           :   "<<name;
	cout<<"\nDate Of Birth  :   "<<dob;
        cout<<"\nAddress        :   "<<add;
       	cout<<"\nPhone No       :   "<<phno;
	cout<<"\nQualification  :   "<<quali;
        cout.precision(2);
        cout.setf(ios::showpoint);
	cout<<"\nPercentage     :   "<<per;
	cout<<"\nExperience     :   "<<exp;
  }
void BioData::Add()
  {
    char str[80];
    cout<<"\nEnter Name : ";
    cin.getline(str,80);
    name=new char[strlen(str)+1];
    strcpy(name,str);
    cout<<"\nEnter DOB  : ";
    cin.getline(str,80);
    dob=new char[strlen(str)+1]; strcpy(dob,str);
    cout<<"\nEnter Address : ";
    cin.getline(str,80);
    add=new char[strlen(str)+1]; strcpy(add,str);
    cout<<"\nEnter Phone No : ";
    cin.getline(str,80);
    phno=new char[strlen(str)+1]; strcpy(phno,str);
    cout<<"\nEnter Qualification : ";
    cin.getline(str,80);
    quali=new char[strlen(str)+1]; strcpy(quali,str);
    cout<<"\nEnter Percentage : ";
    cin>>per;
    cout<<"\nEnter Experience : ";
    while(cin.get()!='\n');
    cin.getline(str,80);
    exp=new char[strlen(str)+1]; strcpy(exp,str);
  }
int main()
  {
    BioData B;
    B.Add();
    B.Disp();
    return(1);
  }

