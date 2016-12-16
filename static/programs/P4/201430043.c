#include<stdio.h>
#include<stdlib.h>
char A[100000];
long long int sum[100000];

int cmpfunc(const void * a, const void * b)
{
	return ( *( int*)a - *( int*)b );
}

int Check(char A[])
{
	long long int q,n=0;
	long long int x=1000;
	long long int y=-1;
	long long int z=-999;
	long long int tot=0;
	for(q=0;A[q]!='\0';q++)
	{
		if(A[q]=='J')
			tot=tot+x;
		else if(A[q]=='M')
			tot=tot+y;
		else if(A[q]=='R')
			tot=tot+z;
		sum[q]=tot;
		n++;
	}
	return n;
}

int main()
{
	int T,i;
	scanf("%d",&T);
	for(i=0;i<T;i++)
	{
		int q,n;
		scanf("%s",A);
		n=Check(A);
		qsort(sum, n, sizeof(long long int), cmpfunc);

		long long int now=sum[0];
		long long int count=1,zeroes=0;
		long long int total=0;
		if(sum[0]==0)
			zeroes++;
		for(q=1;q<n;q++)
		{
			if(sum[q]==0)
				zeroes++;
			if(sum[q]==now)
				count++;
			else 
			{
				total=total+(count*(count-1))/2;
				count=1;
				now=sum[q];
			}
		}
		total = total + (count*(count-1))/2;
		printf("%lld\n",(total+zeroes)); 
	}
	return 0;
}
