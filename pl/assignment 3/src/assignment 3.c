/*
 ============================================================================
 Name        : assignment3.c
 Author      : kunal sachdev
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
void input(char str[]);

int main(void)
{
	char str1[20],str2[20],str3[20];
	int key=1,p;
	int choice,len1,len2;
	while(key)
	{
		printf("........MENU.........\n1 for input.\n2 for display.\n3 for finding length.\n4 for copying.\n5 for concatenation.\n6 for compare.\n7 for checking palindrome \n8 for reverse\n");
		printf("enter choice:");
		scanf("%d",&choice);
		switch(choice)
		{
		
			case 1:
				//input strings
				printf("string 1:");
				while ((getchar()) != '\n');
				gets(str1);
				printf("string 2:");
				gets(str2);
				break;
			case 2:
				//display strings
				printf("string 1:");
				puts(str1);
				printf("string 2:");
				puts(str2);
				break;
			case 3:
				//calculate length
				printf("LENGTH OF STRINGS\n");
				printf("length of first string is:");
				len1=length(str1);
				printf("%d\n",len1);
				printf("length of second string is:");
				len2=length(str2);
				printf("%d\n",len2);
				break;
			case 4:
				//copy string 1 to string 3
				printf("COPYING OF STRING\n");
				printf("string 1:");
				puts(str1);
				copy(str1,str3);
				printf("after copying \n");
				printf("string 1:");
				puts(str1);
				printf("string 3:");
				puts(str3);
				break;
			case 5:
				//concatenation
				printf("CONCATENATION\n");
				printf("string 1:");
				puts(str1);
				printf("string 2:");
				puts(str2);
				concat(str1,str2,str3);
				printf("string of concatenation is:");
				puts(str3);
				break;
			case 6:
				//compare strings
				printf("COMPARING STRINGS\n");
				printf("enter string to compare\n");
				printf("string 1:");
				while ((getchar()) != '\n');
				gets(str1);
				printf("string 2:");
				gets(str2);
				len1=length(str1);
				len2=length(str2);
				p=compare(str1,str2,len1,len2);
				if(p==0)
				{
					printf("strings are equal\n");
				}
				else if(p>0)
				{
					printf("string 1 is greater than string 2\n");
				}
				else
				{
					printf("string 2 is greater than string 1\n" );
				}
				break;

			case 7:
				//palindrome
				printf("CHECKING PALINDROME\n");
				printf("enter the string to check");
				while((getchar())!='\n');
				gets(str1);
				palindrome(str1);
				break;
			case 8:
				//reverse of string
				printf("REVERSE OF STRING\n");
				printf("enter the string to reverse");
				while((getchar())!='\n');
				gets(str1);\
				reverse(str1,str3);
				printf("reversed string is:");
				puts(str3);
		}
}
	return EXIT_SUCCESS;
	
}

int length(char str[])
{
	int i,len=0;
	for(i=0;str[i]!='\0';i++)
	{
		len++;
	}
	return len;
}
void copy(char str1[],char str3[])
{
	int i;
	for(i=0;str1[i]!='\0';i++)
	{
		str3[i]=str1[i];
	}
	str3[i]='\0';
}
void concat(char str1[],char str2[],char str3[])
{
	int i,l;
	copy(str1,str3);
	l=length(str3);
	for(i=0;str2[i]!='\0';i++,l++)
	{
		str3[l]=str2[i];
	}
	str3[i]='\0';
}
void palindrome (char str1[])
{
	int len,i,j;
	len=length(str1);
	i=0;
	j=len-1;
	while(i<j)
	{
		if(str1[i]!=str1[j])
		{
			printf("not a palindrome\n");
			break;
		}
		i++;j--;
	}
	printf("palindrome\n");
}
int compare(char str1[],char str2[],int len1,int len2)
{
	int i,j;
	if(len1!=len2)
	{
		printf("string can't be compared\n");
		return -1;
	}
	for(i=0,j=0;str1[i]!='\0',str2[j]!='\0';i++,j++)
	{
		if(str1[i]!=str2[j])
		{
			return str1[i]-str2[j];
		}
	}
	return 0;
}
void reverse(char str1[],char str3[])
{
	int i,j,l;
	l=length(str1);
	for(i=0;str1[i]!='\0';i++)
	{
		str3[l-i-1]=str1[i];
	}
	str3[i]='\0';
}










