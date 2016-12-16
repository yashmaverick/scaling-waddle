#include<stdio.h>
#include<stdlib.h>
int array[2][1000];
char arr[1000][1000];
int n,count;
int answer;
void dfs(int k)
{
	if(count==(n-1))
		return;
	int i;
	for(i=0;i<n;i++)
	{
		if(arr[k][i]=='0')
			continue;
		if(arr[k][i]=='1')
		{
			if(array[0][i]==1)
				continue;
			array[0][i]=1;
			count++;
			if(count==n-1)
				return;
			dfs(i);
		}
	}
	return;
}
void rdfs(int k)
{
	if(answer==n)
		return;
	int i;
	for(i=0;i<n;i++)
	{
		if(arr[i][k]=='0')
			continue;
		if(arr[i][k]=='1')
		{
			if(array[1][i]==1)
				continue;
			array[1][i]=1;
			answer++;
			if(answer==n)
				return;
			rdfs(i);
		}
	}
	return;
}
int main()
{	
	int t,m,x,y,i,k;
	scanf("%d",&t);
	while(t--)
	{
		for(i=0;i<2;i++)
			for(y=0;y<1000;y++)
				array[i][y]=0;
		answer=0;
		count=0;
		scanf("%d",&n);
		for(i=0;i<1000;i++)
			for(y=0;y<1000;y++)
				arr[i][y]='0';
		for(x=0;x<n;x++)
		{
			scanf("%d",&m);
			for(y=0;y<m;y++)
			{
				scanf("%d",&i);
				arr[i-1][x]='1';
			}
		}
		for(i=0;i<n;i++)
		{
			array[0][i]=1;
			dfs(i);
			if(count!=(n-1))
			{
				count=0;
				x=0;
				for(y=0;y<1000;y++)
					array[x][y]=0;
				continue;
			}
			else
			{
				array[1][i]=1;
				answer++;
				rdfs(i);	
				break;
			}
		}
		printf("%d\n",answer);
	}
	return 0;
}
