#include<stdio.h>
#include<stdlib.h>
int a[1000001];
typedef struct box
{
	int begin;
	int end;
	long long int weight;
}box;
int main()
{
	int n,i,m,j;
	long long int mod;
	scanf("%d%lld",&n,&mod);
	box b[n];
	for(i=0;i<n;i++)
	{
		b[i].weight=0;
		scanf("%d",&m);
		if(i==0)
		{
			b[i].begin=0;
		}
		else 
		{
			b[i].begin=(b[i-1].end)+1;
		}
		b[i].end=(b[i].begin)+m-1;
		for(j=b[i].begin;j<=b[i].end;j++)
		{
			scanf("%d",&a[j]);
			b[i].weight=((b[i].weight)%mod+(a[j])%mod)%mod;
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-1;j++)
		{
			if(b[j].weight>b[j+1].weight)
			{
				int temp=b[j].weight;
				b[j].weight=b[j+1].weight;
				b[j+1].weight=temp;
				int temp1=b[j].begin;
				b[j].begin=b[j+1].begin;
				b[j+1].begin=temp1;
				int temp2=b[j].end;
				b[j].end=b[j+1].end;
				b[j+1].end=temp2;
			}
		}
	}    
	for(i=0;i<n;i++)
	{
		printf("%lld\n",b[i].weight);
		for(j=b[i].begin;j<=b[i].end;j++)
			printf("%d\n",a[j]);
		printf("\n");
	}
	return 0;
}
