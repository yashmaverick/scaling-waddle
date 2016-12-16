#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int seive[10007],count,ans,y,dist[10007];
typedef struct node
{
	int val;
	struct node*next;
}node;
node*a[10007];
node*temp1;
int que[100000],end,start,visited[10000];
void fun()
{
	seive[1]=0;
	seive[2]=1;
	int i,j;
	for(i=2;i<=10000;i++)
		seive[i]=1;
	for(i=2;i<=10000;i++)
	{
		if(seive[i]==1)
		{
			for(j=2;j*i<=10000;j++)
			{
				seive[j*i]=0;
			}
		}
	}
}
node*insert(node*head,int data)
{
	node*temp=(node*)malloc(sizeof(node));
	temp->val=data;
	temp->next=head->next;
	head->next=temp;
	return head;
}
void mid(int x)
{
	int k=1,z,j;
	while(k!=5)
	{
		z=x;
		if(k==1)
		{
			z=z-z%10;
		}
		else
			z=z-z%(int)(pow(10,k))+z%(int)(pow(10,k-1));
		for(j=1;j<=10;j++)
		{
			if(seive[z]==1)
			{
				if(z!=x)
				{
					a[x]=insert(a[x],z);
				}
			}
			z=z+pow(10,k-1);
		}
		k++;
	}
}
/*void dfs(int x,int count)
  {
  if(x==y)
  {
  ans=count;
  return;
  }
  visited[x]=1;
  temp1=a[x];
  if(temp1!=NULL)
  temp1=temp1->next;
  while(temp1!=NULL)
  {
  if(!visited[temp1->val])
  {
  dfs(temp1->val,count+1);
  }
  temp1=temp1->next;
  }
  }*/
void bfs()
{
	visited[que[start]]=1;
	while(start<=end)
	{
		int s;
		s=que[start];
		if(s==y)
		{
			break;
		}
		temp1=a[s];
		while(temp1!=NULL)
		{
			if(visited[temp1->val]==0)
			{
				que[++end]=temp1->val;
				visited[temp1->val]=1;
				dist[temp1->val]=dist[s]+1;
				if(temp1->val==y)
				{
					ans=count;
					return ;
				}
			}
			temp1=temp1->next;
		}
		start++;
	}
}
void print(node*head)
{
	node*zx;
	zx=head;
	while(zx!=NULL)
	{
		zx=zx->next;
	}
	printf("\n");
}
int main()
{
	fun();
	int i;
	for(i=1;i<=999;i++)
		seive[i]=0;
	for(i=1000;i<=9999;i++)
	{
		if(seive[i]==1)
		{
			a[i]=(node*)malloc(sizeof(node));
			a[i]->val=i;
			a[i]->next=NULL;
			mid(i);
		}
		visited[i]=0;
	}
	int t;
	scanf("%d",&t);
	while(t--)
	{
		start=0;
		end=-1;
		int x,z,j,k;
		scanf("%d%d",&x,&y);
		for(i=1000;i<=9999;i++)
		{
			visited[i]=0;
			dist[i]=0;
		}
		dist[x]=0;
		end++;
		que[end]=x;
		visited[x]=1;
		bfs();
		printf("%d\n",dist[y]);
	}
}
