#include<stdio.h>
#include<stdlib.h>
struct p
{
	int m;
	long long int weightsum;
	int* bag;
};
int main()
{
	int n,temp,x,y;long long int mod;
	struct p gab[1000];
	scanf("%d",&n);
	scanf("%lld",&mod);
	int* c;int tem;
	int i,j;
	long long int sum;
	for(i=0;i<n;i++)
	{
		sum=0;
		scanf("%d",&gab[i].m);
		gab[i].bag=(int*)malloc(sizeof(int)*gab[i].m);
		for(j=0;j<gab[i].m;j++)
		{
			scanf("%d",&gab[i].bag[j]);
			sum+=gab[i].bag[j];
		}
		gab[i].weightsum=sum%mod;
	}
	for(x=0;x<n;x++)
	{
		for(j=0;j<n-1;j++)
		{       
			if(gab[j].weightsum>gab[j+1].weightsum)
			{       
				temp=gab[j].weightsum;
				gab[j].weightsum=gab[j+1].weightsum;
				gab[j+1].weightsum=temp;
				c=gab[j].bag;
				gab[j].bag=gab[j+1].bag;
				gab[j+1].bag=c;
				tem=gab[j].m;
				gab[j].m=gab[j+1].m;
				gab[j+1].m=tem;

			}       
		}       
	}
	for(i=0;i<n;i++)
	{
		printf("%lld\n",gab[i].weightsum);
		for(j=0;j<gab[i].m;j++)
		{
			printf("%d\n",gab[i].bag[j]);
		}
		printf("\n");
	}
	return 0;
}
