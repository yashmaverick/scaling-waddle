#include<stdio.h>
int arr[1001][1001]={0},visit[1001]={0},flag,count=0;
void dfs(int start,int realms)
{
	visit[start]=1;
	int i;
	for(i=1;i<=realms;i++)
	{
		if(arr[start][i]==1 && visit[i]==0)
		{
			count++;
			dfs(i,realms);
			if(count==realms-1)
			{
				flag=1;
				break;
			}
		}
	}
}
void dfs1(int start,int realms)
{
	visit[start]=1;
	int i;
	for(i=1;i<=realms;i++)
	{
		if(arr[i][start]==1 && visit[i]==0)
		{
			count++;
			dfs1(i,realms);
		}
	}
	return;
}
int main(){
	int test,z;
	scanf("%d",&test);
	for(z=0;z<test;z++)
	{
		int realms,b,k;
		scanf("%d",&realms);
		flag=0;
		count=0;
		for(b=1;b<=1001;b++)
		{
			visit[b]=0;
			for(k=1;k<=1001;k++)
			{
				arr[b][k]=0;
			}
		}
		for(b=1;b<=realms;b++)
		{
			int vnrs,i;
			scanf("%d",&vnrs);
			for(i=0;i<vnrs;i++)
			{
				int who;
				scanf("%d",&who);
				arr[who][b]=1;
			//	arr1[b][who]=1;
			}
		}
		int start;
		for(start=1;start<=realms;start++)
		{
			count=0;
			int a;
			for(a=1;a<=realms;a++)
			{
				visit[a]=0;
			}
			dfs(start,realms);
			if(count==realms-1)
			{
				count=0;
				flag=1;
				for(a=1;a<=realms;a++)
				{
					visit[a]=0;
				}
				break;
			}
		}
		if(flag==1)
		{
			count=0;
			dfs1(start,realms);
			printf("%d\n",count+1);
		}
		else
			printf("0\n");
		for(k=1;k<=realms;k++)
		{
			visit[k]=0;
			for(b=1;b<=realms;b++)
			{
				arr[b][k]=0;
			//	arr1[b][k]=0;
			}
		}
	}
	return 0;
}

