#include<stdio.h>
#define max 20000010
int A[max];
int main()
{
	int t,n,x,y=0;
	long long int pair;
	scanf("%d",&t);
	while(t--)
	{
		pair=0;
		scanf("%d",&n);
		for(x=0;x<n;x++)
		{
			scanf("%d",&y);
			A[y+10000000]+=1;
		}
		long long int h;
		for(x=0;x<max;x++)
		{
			h=A[x];
			pair+=(h*(h-1))/2;
			A[x]=0;
		}
		printf("%lld\n",pair);
	}
	return 0;
}
