#include<stdio.h>
#define sz 50

struct Bucket
{
	int b[sz] , cnt;
}B[10];

void accArr(int [] , int);
void dispArr(int [] , int);
void shellsort(int [] , int);
void mergr(int [] , int , int , int);
void partition(int [] , int , int , int);
void bubble(int [] , int);
void insertion(int [] , int);
void selection(int [] , int);
void bucketsort(int [] , int);
void quicksort(int [] , int , int , int);
void arrange(int [] , int);


void accArr(int a[sz] , int n)
{	
	int i;
	printf("\nenter %d elements",n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}	
}

void dispArr(int a[sz] , int n)
{
	int i;
	printf("\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}	
}

void shellsort(int a[sz] , int n)
{
	
	int i , d , t , count=0;
	d = (n/2 +1);
	
	while(d>0)
	{
		for(i=0;(d+i)<n;i++)
		{
			if(a[i]>a[d+i])
			{
				t=a[i];
				a[i]=a[d+i];
				a[d+i]=t;
			}
		}
		
		dispArr(a,n);
		d--;
		count++;
	}	
	printf("\nno of passes : %d",count);	
	printf("\n\nsorted array is :\n");
	dispArr(a,n);
}

void merge(int a[sz] , int s , int m , int e)
{
	
	int i , j , k , b[sz] ;
	i = s;
	j = m+1;
	k = s;
	
	while(i<=m && j<=e)
	{
		if(a[i]<=a[j])
		{
			b[k] = a[i];
			i++;
		}
		
		else
		{
			b[k] = a[j];
			j++;			
		}
		
		k++;
	}
	
	while(i<=m)
	{
		b[k] = a[i];
		i++; k++;
	}
	while(j<=e)
	{
		b[k] = a[j];
		j++; k++;
	}
	
	for(i=s;i<=e;i++)
		a[i] = b[i];
}

void partition(int a[sz] , int s , int e , int n)
{
	int m;
	if(s<e)
	{
		m = (s+e)/2;
		partition(a,s,m,n);
		partition(a,m+1,e,n);
		merge(a,s,m,e);
		dispArr(a,n);
	}
	
	
}

void bubble(int a[sz] , int n)
{
	
	int i , j , t , count=0;
	
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				t = a[j];
				a[j] = a[j+1];
				a[j+1] = t;
			}
			
		}
		count++;
		dispArr(a,n);
	}
	
	printf("\npasses : %d" , count);
	printf("\nsorted array is :\n");
	dispArr(a,n);
}

void insertion(int a[sz] , int n)
{
	
	int i , j , t , count=0;
	
	for(i=1;i<n;i++)
	{
		
		t = a[i];
		 for(j=i ; j>0 && a[j-1]>t ; j-- )
		 	a[j] = a[j-1];
		 	
		 a[j] = t;	
		 dispArr(a,n);
		 count++;		
	}
	printf("\npasses : %d" , count);
	printf("\nsorted array is :\n");
	dispArr(a,n);
	
	
}

void selection(int a[sz] , int n)
{
	
	int i , j , t , count=0;
	
	for(i=0;i<n-1;i++)
	{
		
		for(j=i+1;j<n;j++)
		{
			
			if(a[i]>a[j])
			{
				t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
			
		}
		count++;
		dispArr(a,n);
	}
	
	printf("\npasses : %d" , count);
	printf("\nsorted array is :\n");
	dispArr(a,n);
	
	
}

void bucketsort(int a[sz] , int n)
{
	
	int max , i , df=1 , j , t , k , d , count=0;
	max = a[0];
	
	for(i=0;i<n;i++)
	{
		if(a[i]>max)
			max = a[i];
	}
	
	while(max!=0)
	{
		
		for(i=0;i<10;i++)
		{
			B[i].cnt = -1;
		}
		
		for(j=0;j<n;j++)
		{
			
			t = a[j];
			t = t/df;
			d = t%10;
			B[d].cnt++;
			i = B[d].cnt;
			
			B[d].b[i] = a[j];
			
		}
		
		for(i=j=0;i<10;i++)
		{
			for(k=0;k<=B[i].cnt;k++)
			{
				a[j] = B[i].b[k];
				j++;
			}
			
		}
		
	count++;	
	dispArr(a,n);
	
	df = df*10;
	max = max/10;
	
	}
	
	printf("\npasses : %d" , count);
	printf("\nsorted array is :\n");
	dispArr(a,n);
	
}

void quicksort(int a[sz] , int n , int l , int h)
{
	
	int pivot , down , up , t ;
	
	pivot = a[l];
	down = l+1;
	up = h;
	
	while(down<=up)
	{
		while(a[down]<=pivot && down<=up)
		down++;
		
		while(a[up]>pivot)
		up--;
		
		if(down<=up)
		{
			t = a[down];
			a[down] = a[up];
			a[up] = t;
			down++;
			up--;
			
		}
				
	}
	
	a[l] = a[up];
	a[up] = pivot;
	printf("\npivot : %d",pivot);
	
	dispArr(a,n);
	
	if(l<up-1)
		quicksort(a,n,l,up-1);
		
	if(down<h)
		quicksort(a,n,down,h);	
		
}

void arrange(int a[sz] , int i)
{
	int p , t;
	
	while(i>0)
	{
		if(i%2==1)
		p = i/2;
		
		else
		p = (i/2)-1;
		
		if(a[i]>a[p])
		{
			t = a[i];
			a[i] = a[p];
			a[p] = t;
			i=p;
		}
		else
		break;
	}
}


int main()
{
	
	int a[sz] , n , ch , i , j , t;
	printf("\nenter how many elements :\n");
	scanf("%d",&n);
	do
	{
		printf("\nenter the choice :\n");
		printf("\n1.shell sort");
		printf("\n2.exit");
		printf("\n3.merge sort");
		printf("\n4.bubble sort");
		printf("\n5.insertion sort");
		printf("\n6.selection sort");
		printf("\n7.bucket sort");
		printf("\n8.quick sort");
		printf("\n9.heap sort");
		scanf("%d",&ch);
		
		switch(ch)
		{
			
			case 1:
					accArr(a,n);
					printf("\ngiven array is :");
					dispArr(a,n);
					shellsort(a,n);
					break;			
			case 2:
					return 0;
					
			case 3:
					accArr(a,n);
					printf("\ngiven array is :");
					dispArr(a,n);
					partition(a,0,n-1,n);		
					break;
					
			case 4:
					accArr(a,n);
					printf("\ngiven array is :");
					dispArr(a,n);
					bubble(a,n);
					break;
					
			case 5:
					accArr(a,n);
					printf("\ngiven array is :");
					dispArr(a,n);
					insertion(a,n);
					break;
					
			case 6:
					accArr(a,n);
					printf("\ngiven array is :");
					dispArr(a,n);
					selection(a,n);
					break;				
							
							
			case 7:
					accArr(a,n);
					printf("\ngiven array is :");
					dispArr(a,n);
					bucketsort(a,n);
					break;
					
			case 8:
					accArr(a,n);
					printf("\ngiven array is :");
					dispArr(a,n);
					quicksort(a,n,0,n-1);
					break;		
								
								
			case 9:
					accArr(a,n);
					printf("\ngiven array is :");
					dispArr(a,n);
					
					for(i=1;i<n;i++)
						arrange(a,i);
						
					printf("\ndata in eap form :");
					dispArr(a,n);
					
					for(i=n-1;i>0;i--)
					{
						t = a[0];
						a[0] = a[i];
						a[i] = t;
						
						for(j=1;j<i;j++)
						arrange(a,j);		
					}
					printf("\nsorted data :");
					dispArr(a,n);
					
					break;							
									
			default:
					printf("\nenter valid choice...");		
		}
	}while(1);
	
return 0;	
}
