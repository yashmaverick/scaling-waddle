#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct data{
	int val;
	struct data* next;
}data;
int cost;
int sieve[10001];
int queue[10001];
data* head[10001];
int visited[10001];
int height[10001];
void bfs(int start,int end)
{
	int i=0,level=-1,l=0;
	queue[i]=start;
	visited[start]=1;
	height[i]=l;
	data *itr;
	while(1)	
	{	
		level++;
		if(queue[level]==end)
		{
			cost=height[level];
			return ;
		}
		itr=head[queue[level]];
		l=height[level]+1;
		while(itr!=NULL)
		{
			if(visited[itr->val]==0)
			{
				i++;
				height[i]=l;
				queue[i]=itr->val;
				visited[itr->val]=1;
			}
			itr=itr->next;
		}
		if(level==i)
			return;
	}		
}
int main()
{
	int t,x,y,i,j;
	scanf("%d",&t);
	for(i=1000;i<10000;i++)
		head[i]=NULL;
	sieve[0]=1;
	sieve[1]=1;
	for(i=2;i<=5000;i++)
	{
		for(j=2;j<=10000/i;j++)
			sieve[i*j]=1;	
	}
	data *itr;
	int a,b,c;
	for(i=1000;i<10000;i++)
	{
		b=i;
		int k;
		k=1;
		c=1;
		if(sieve[i]==0)
		{
			while(k<=4)
			{
				a=i-((b%10)*c);
				for(j=0;j<10;j++)	
				{
					if(sieve[a+(j*c)]==0 && (a+(j*c))!=i && (a+(j*c))>=1000)
					{
						itr=(data*)malloc(sizeof(data));
						itr->val=a+(j*c);
						itr->next=head[i];
						head[i]=itr;
					}
				}
				k++;
				c=c*10;
				b=b/10;
			}
		}
	}
	while(t--)
	{
		scanf("%d%d",&x,&y);
		cost=-1;
		memset(visited,0,10000*sizeof(int));
		bfs(x,y);
		if(cost==-1)
			printf("Impossible\n");
		else 
			printf("%d\n",cost);
		//	printf("%d\n",height[y]);
	}
	return 0;
}
