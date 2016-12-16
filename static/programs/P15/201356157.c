#include <stdio.h>
#include <stdlib.h>
int ind=0;
int i=0,K=0;
long long int minion=10000010;
long long ted=0;
int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}
long long int findminion(long long int a[] , long long int b[], int i,int N)
{
	int in;
	long int minion2=10000010;
	qsort(b, N+1, sizeof(int), cmpfunc);
	for(in=i;in<=N;in++)
	{
		if(compare(minion2,a[in]))
		{
			minion2 = a[in];
			ind = in;
		}
	}
	minion = minion2;
	//printf("minion1: %ld",minion);
	//minion=b[0];
	//printf("minion2: %ld",minion);
return minion;
}


int compare(int a, int b)
{
if(a>=b)
return 1;
else
return 0;
}
void assigN()
{

ind = i+K-1;

}
int main()
{
	 int I,T;
	scanf("%d",&T);
	while(T--)
	{
		ind = 0;
		int N,d=0,in;
		scanf("%d",&N);
		scanf("%d",&K);
		long long int a[N+1],b[N+1];
		for(i=1;i<=N;i++)
{
			scanf("%lld",&a[i]);
			b[i]=a[i];
}
		for(i=1;i<=N-K+1;i++)
		{
			if(ind==i-1)
				{		
				//qsort(b, i+K-1, sizeof(int), cmpfunc);
				//m=b[0];
				ted =findminion(a,b,i,i+K-1);
				}
			else
			{
				if(compare(minion,a[i+K-1]))
				{
				 	assigN();
					ted = a[i+K-1];
					minion=ted;
				 } 
			}
			if(i==N-K+1)
				printf("%lld\n",ted);
			if(i<N-K+1)
				printf("%lld ",ted);
			
		}
		ted=0;i=0;K=0;
	}
	return 0;
}
