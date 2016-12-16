#define MAX 1
#define MIN 0
#include<stdio.h>
#include<stdlib.h>
void bucketsort(long long int Z[],long long int n);
int main()
{
	int test;
	scanf("%d",&test);
	while(test--)
	{
		long long int n,x,y;
		scanf("%lld",&n);
		long long int min=(10000002),Z[n];
		for(x=0;x<n;x++)
		{
			scanf("%lld",&Z[x]);
			if(min>Z[x])
				min=Z[x];
		}
		for(x=0;x<n;x++)
			Z[x]-=min;
		bucketsort(Z,n);
	}
	return 0;
}
void bucketsort(long long int Z[],long long int n)
{
	long long int val=0,i,*Y;
	Y=(long long int *)malloc(sizeof(long long int)*(10000002));
	for(i=0;i<(10000002);i++)
		Y[i]=0;
	for(i=0;i<n;i++)
		(Y[Z[i]])++;
	for(i=0;i<1000002;i++)
		val+=(Y[i]*(Y[i]-1))/2;
	printf("%lld\n",val);
}

int gcd(a,b)
{
	if(b==0)
		return a;
	else
		return gcd(b,a%b);
}
      
