#include<iostream>
#include<string.h>
using namespace std;

class ExpConv
{
    char exp[20], pexp[20], prexp[20], st[20];
    int top;
    public:
        ExpConv()
        {
            top=-1;
        }
        
        void push(char ch)
        {
            top++;
            st[top]=ch;
        }
        
        char pop()
        {
            char ch;
            ch=st[top];
            top--;
            return ch;
        }
        
        void input()
        {
            cout<<"\nENTER THE INFIX EXPRESSION :: ";
            cin>>exp;
        }
        
        int isOp(char);
        int prio(char);
        void inToPost();
        void inToPost1();
        void inToPre();
        void postEval();
        void preEval();
};

int ExpConv::isOp(char ch)
{
    if(ch=='*'||ch=='/'||ch=='+'||ch=='-'||ch=='^'||ch=='$')
        return 1;
    return 0;
}

int ExpConv::prio(char ch)
{
    switch(ch)
    {
        case '^' :
        case '$' : return 3; break;
        case '/' :
        case '*' : return 2; break;
        case '+' :
        case '-' : return 1; break;
        default : return 0;
    }
}

void ExpConv::inToPost()
{
    int i,j=0;
    char ch;
    for(i=0; exp[i]!='\0'; i++)
    {
        ch=exp[i];
        
        if(ch=='(')
            push(ch);
        else if(isOp(ch)==1)
        {
            while(top!=-1 && prio(st[top])>=prio(ch))
                pexp[j++]=pop(); 
            push(ch);
        }
        else if(ch==')')
        {
            while(top!=-1 && st[top]!=')')
                pexp[j++]=pop();
            top--;
        }
        else
            pexp[j++]=ch;
    }
    
    while(top!=-1)
        pexp[j++]=pop();
    
     pexp[j]='\0';
    
    cout<<"\nTHE EQUIVALENT POSTFIX EXPRESSION IS :: "<<pexp;
}

void ExpConv::inToPost1()
{
    int i,j=0;
    char ch;
    for(i=0; exp[i]!='\0'; i++)
    {
        ch=exp[i];
        if(ch=='(')
            push(ch);
        else if(isOp(ch)==1)
        {
            while(top!=-1 && prio(st[top])>prio(ch))
                prexp[j++]=pop();
            push(ch);
        }
        else if(ch==')')
        {
            while(top!=-1 && st[top]!=')')
                prexp[j++]=pop();
            top--;
        }
        else
            prexp[j++]=ch;
    }
    while(top!=-1)
        prexp[j++]=pop();
    prexp[j]='\0';
}

void ExpConv::inToPre()
{
    int i,j=0;
    char ch;
    strrev(exp);
    for(i=0; exp[i]!='\0'; i++)
    {
        if(exp[i]=='(')
            exp[i]=')';
        else if(exp[i]==')')
            exp[i]='(';
    }
    inToPost1();
    strrev(prexp);
    cout<<"\nTHE EQUIVALENT PREFIX EXPRESSION IS :: "<<prexp;
}

int main()
{
    int ch;
    ExpConv e;
    do
    {
        cout<<"\n\tMENU\n1. INPUT EXPRESSION\n2. INFIX TO POSTFIX\n3. INFIX TO PREFIX\n4. EVALUATE POSTFIX\n5. EVALUATE PREFIX\n6. EXIT\n";
        cout<<"\nENTER YOUR CHOICE :: ";
        cin>>ch;
        switch(ch)
        {
            case 1:
                e.input();
                break;
                
            case 2:
                e.inToPost();
                break;
                
            case 3:
                e.inToPre();
                break;
                
            case 6:
                return 0;
        }
    }while(1);
    return 0;
}
