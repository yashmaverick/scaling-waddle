#include<stdio.h>
struct node{
	int sum1;
	int start;
	int end;
};
w[1000001];
int main()
{
	int N,m,i,k=0,j,l,p,s=0;
	scanf("%d",&N);
	scanf("%d",&m);
	struct node sree[N];
	for(i=0;i<N;i++)
	{
		int n;
		int sum=0;
		scanf("%d",&n);
		l=k;
		for(j=0;j<n;j++)
		{
			scanf("%d",&w[s]);
			sum=(sum%m+w[s]%m)%m;
			s++;
		}
		
		sree[i].sum1=sum;
		sree[i].end=s-1;
		if(i==0)
			sree[i].start=0;
		if(i!=0)
		sree[i].start=sree[i-1].end+1;
	}
/*	for(i=0;i<N;i++)
	{
		printf("%d ",sree[i].sum1);
		printf("%d ",sree[i].start);
		printf("%d ",sree[i].end);
		printf("\n");
	}*/
	for(i=0;i<N;i++)
	{
		for(j=i+1;j<N;j++)
		{
			if(sree[i].sum1>sree[j].sum1)
			{
				struct node temp;
				temp=sree[i];
				sree[i]=sree[j];
				sree[j]=temp;
			}
		}
	}
	for(i=0;i<N;i++)
	{
		printf("%d\n",sree[i].sum1);
		for(j=sree[i].start;j<=sree[i].end;j++)
		{
			printf("%d\n",w[j]);
		}
		printf("\n");
	}
	return 0;
}
