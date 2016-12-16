#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int values[100001];
int stack[100001];
int childrenl[100001];
int childrenr[100001];
int marked[100001]={0};

int head=-1;
int max=-1;
int thing;

void dfs(int a, int count)
{
	marked[a]=1;
	if(count>max && marked[a]!=0)
	{
		max=count;
		thing=a;
	//	printf("%d %d\n", max, thing);
	}
	if(childrenl[a]!=0 && marked[childrenl[a]]==0)
	{
		dfs(childrenl[a],count+1);
		//printf("Left");
	}
	if(childrenr[a]!=0 && marked[childrenr[a]]==0)
	{
		dfs(childrenr[a],count+1);
		//printf("Right");
	}
}

int main()
{
	int tc,i,j,k,a,b,c,n,m;
	scanf("%d", &tc);
	for(k=0;k<tc;k++)
	{
		head=-1;
		scanf("%d", &n);
		for(i=1;i<=n;i++)
		{
			scanf("%d", &values[i]);
			marked[i]=0;
			childrenr[i]=0;
			childrenl[i]=0;
		}
		for(i=1;i<=n;i++)
		{
			while(head!=-1 && stack[head]>values[i])
				head--;
			if(head==-1)
				childrenl[values[i]]=0;
			else
			{
				childrenl[values[i]]=stack[head];	
			}
			head++;
			stack[head]=values[i];
		}
		childrenr[values[1]]=0;
		for(i=n;i>=2;i--)
		{
			if(values[i-1]>values[i])
				childrenr[values[i]]=values[i-1];
		}
	//printf("%d\n", childrenl[9]);
		max=0;
		thing=values[n];
		dfs(thing,0);
	//printf("%d %d\n%d %d\n%d %d\n", childrenl[1], childrenr[1], childrenl[2], childrenr[2], childrenl[3], childrenr[3]);
		printf("%d %d\n", thing, max);
	}
	return 0;
}
