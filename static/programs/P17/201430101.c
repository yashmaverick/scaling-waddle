//GABBAR STUDIOWORKS
//4 apr 2015
#include<stdio.h>
#include<stdlib.h>
int  dexp[1000000];
int dexi[1000000];
int main()
{
	int n,i;
	scanf("%d",&n);
	int*pre=(int*)malloc(sizeof(int)*n);
	int*ino=(int*)malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&pre[i]);
		dexp[pre[i]]=i;
	}
	for(i=0;i<n;i++)
	{
		scanf("%d",&ino[i]);
		dexi[ino[i]]=i;
	}
	int test,p,q,start,end,j,sinel;
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d%d",&p,&q);
		if(dexi[p]>=dexi[q])
		{
			start=dexi[q];
			end=dexi[p];
		}
		else
		{
			start=dexi[p];
			end=dexi[q];
		}
		sinel=ino[start];
		for(j=start;j<=end;j++)
		{
			if(dexp[ino[j]]<dexp[sinel])
				sinel=ino[j];
		}
		printf("%d\n",sinel);
	}
	return 0;
}
