#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void merge(int l, int mid1, int mid2, int r, int a[]);
void print(int b[], int len)
{
	int i;
	for(i=0; i<len; i++)
		printf("%d ", b[i]);
	printf("\n");
}
long long int comb(int x)
{
	return (long long int)(x*(x-1)/2);
}
void mergesort(int a[], int l, int r) // left and right ends of array
{
	if(l<r)
	{

	int mid = l+ (r-l)/2;
	mergesort(a,l,mid);
	mergesort(a, mid+1, r);
	merge(l, mid, mid+1, r, a);
	}
}
void merge(int l, int mid1, int mid2, int r, int a[])
{
	int i=l, j=mid2, k=0 ,c[100010]={0};

	while(i<=mid1 && j<=r)
	{
		if(a[i]<a[j])
			c[k++]=a[i++];
		else
			c[k++]=a[j++];
	}

	while(i<=mid1)
		c[k++]=a[i++];
	while(j<=r)
		c[k++]=a[j++];
         
	k=0;
	for(i=l; i<=mid1; i++)
		a[i]=c[k++];
	for(i=mid2; i<=r; i++)
		a[i]=c[k++];
}
int cmpfunc (const void * a, const void * b)
{
       return ( *(int*)a - *(int*)b );
}
int main()
{
	int b[1000000], i,j,T, length;
	char a[1000001];
	scanf("%d", &T);
	while(T--)
	{
		scanf("%s", a);
		length=strlen(a);

		if(a[0]=='J')
			b[0]=-1000000;
		else if(a[0]=='M')
			b[0]=1000001;
		else if(a[0]=='R')
			b[0]=-1;
                
		
		
		for(i=1; a[i]!='\0'; i++)
		{
			if(a[i]=='J')
				b[i]=b[i-1]-1000000;
			else if(a[i]=='M') 
				b[i]=b[i-1]+1000001;
			else if(a[i]=='R')
			        b[i]=b[i-1]-1;
		}
	//print(b, length);
			
//	mergesort(b, 0, length-1);
        qsort(b, length, sizeof(int), cmpfunc);
	//print(b, length);
	long long int count=0;
       long long int countzero=0;
	long long int sum=0;
	for(i=0; i<length; i++)
	{
		if(b[i]==0)
		  countzero++;
	         if(b[i]==b[i+1] && i<length-1) /*(b[i]==-3 || b[i]==1 ||b[i]==2 || b[i]==0 ) && */ 
			count++;
		else if((b[i]!=b[i+1] && i<length-1) || i==length-1 ) /* (b[i]==-3 || b[i]==1 || b[i]==2 || b[i]== 0) */ 
		{
			//count++;
			//if(count>=1)
				sum=sum+((count+1)*count)/2;
			count=0;
		}

	}
	printf("%lld\n", sum+countzero);
	}
	return 0;
}





