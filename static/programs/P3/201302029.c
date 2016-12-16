#include<stdio.h>

int max(int a,int b)
{
	if(a>=b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

int min(int a,int b)
{
	if (a<=b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

int find(int na,int np[100000])
{
	int i,j,k;
	int minvalue=np[0];
	int maxprofit=0;
	for (i=0;i<na;i++)
	{
		maxprofit=max(np[i]-minvalue,maxprofit);
		minvalue=min(minvalue,np[i]);
	}
	return maxprofit;
}
		


int main()
{
	int test,i,j,na,np[100000],price,k,th,tl;
	scanf("%d",&test);
	for(i=0;i<test;i++)
	{
		scanf("%d",&na);
		for(j=0;j<na;j++)
		{
			scanf("%d",&np[j]);
		}
		k=find(na,np);
		printf("%d\n",k);
	}
return 0;
}
