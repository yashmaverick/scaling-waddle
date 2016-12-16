#include<stdio.h>
#define MAX 1000010
long long int B[MAX+10]={0};
int main()
{
	long long int tc,i,j,k,n,min,max,cnt;
	long long int A[MAX];
	scanf("%lld",&tc);
	while(tc--)
	{
		scanf("%lld",&n);
		min=10000000;
		max=-10000000;
		cnt=0;
		for(i=0;i<MAX+10;i++)
			B[i]=0;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&A[i]);
			if(A[i]>max)
				max=A[i];
			if(A[i]<min)
				min=A[i];
		}
		for(i=0;i<n;i++)
		{
			A[i]=A[i]-min;
			B[A[i]]++;
		}
		for(i=0;i<=max-min;i++)
		{
			if(B[i]>1)
				cnt=cnt+(B[i]*(B[i]-1))/2;
		}
		printf("%lld\n",cnt);
	}
	return 0;
}
