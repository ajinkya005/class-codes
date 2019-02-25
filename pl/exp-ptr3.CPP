#include<conio.h>
#include<stdio.h>
//#include<string.h>
void strrev(char *str)
  {
    int i,j;
    char t;
    for(i=0;*(str+i)!='\0';i++);
    for(j=0,i--;j<=i;j++,i--)
      {
	t=*(str+i);
	*(str+i)=*(str+j);
	*(str+j)=t;
      }
  }
void pallchk(char *str)
  {
    int i,j;
    char t;
    for(i=0;*(str+i)!='\0';i++);
    for(j=0,i--;j<=i;j++,i--)
      {
	if(*(str+i)!=*(str+j))
	  break;
      }
    if(j>i)
      printf("\nPallaindrome");
    else
      printf("\nNot Pallaindrome");
  }
void strcpy(char *str2,char *str1)
  {
    int i;
    for(i=0;*(str1+i)!='\0';i++)
      *(str2+i)=*(str1+i);
    *(str2+i)='\0';
  }
int strstr(char *str1,char *str2)
  {
    int i,j;
    for(i=0;*(str1+i)!='\0';i++)
      {
	for(j=0;*(str2+j)!='\0';j++,i++)
	  {
	    if(*(str1+i)!=*(str2+j))
	      break;
	  }
	if(*(str2+j)=='\0')
	  return(1);
	if(j>0)
	  i=i-j;
      }
    return(0);
  }
int strcmp(char *str1,char *str2)
  {
    int i;
    for(i=0;*(str1+i)!='\0'&&*(str2+i)!='\0';i++)
      {
	if(*(str1+i)!=*(str2+i))
	  return(1);
      }
    return(*(str1+i)  -  *(str2+i));
  }
void main()
  {
    int ch;char str1[80],str2[80];
    clrscr();
    do
      {
	clrscr();
	printf("\nEnter String : ");
	fflush(stdin);gets(str1);
	printf("\n\n\t\tMenu\n\n\t1.Reverse\n\t2.Pallaindrome\n\t3.Copy\n\t"
	       "4.Substring\n\t5.Compare\n\t6.Exit\n\n\t\tEnter Choice : ");
	scanf("%d",&ch);
	switch(ch)
	  {
	    case 1:
	      strrev(str1);
	      printf("\nRev Is : %s",str1);
	      break;
	    case 2:
	      pallchk(str1);
	      break;
	    case 3:
	      strcpy(str2,str1);
	      printf("\nCopied String :  %s",str2);
	      break;
	    case 4:
	      printf("\nEnter String : ");
	      fflush(stdin);gets(str2);
	      if(strstr(str1,str2))
		printf("\n\"%s\" Is Substring Of \"%s\"",str2,str1);
	      else
		printf("\n\"%s\" Is Not Substring Of \"%s\"",str2,str1);
	      break;
	    case 5:
	      printf("\nEnter String : ");
	      fflush(stdin);gets(str2);
	      if(strcmp(str1,str2)==0)
		printf("\nEqual Strings");
	      else
		printf("\nNot Equal Strings");
	      break;
	    case 6:
	      printf("\nComming Out !!!");
	      break;
	    default:
	      printf("\nWrong Choice !!!");
	  }
	getch();
      }while(ch!=6);
  }
