#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int value;
	struct node *next;
}node;
int max;
node *head[1000003];

int visited[1000003];
int ans;
void insert(int y,int x)
{
	node *p;
	p=(node *)(malloc(sizeof(node)));
	p->value=x;
	p->next=NULL;
	if(head[y]==NULL)
	{
		head[y]=p;
		return;
	}
	else
	{
	p->next=head[y];
	head[y]=p;
	}
}

void empty(node *head)
{
	node *p,*temp;
	p=head;
	while(p!=NULL)
	{
		temp=p;
		p=p->next;
		free(temp);
	}

}
void dfs(node *p,int count)
{
	int x;
	if(p==NULL)
	{
		return;
	}
	if(max<count)
	{
		max=count;
		ans=p->value;
	}
//	printf("%d,count:%d ",p->value,count);
//	ans=p->value;
	while(p->next!=NULL)
	{
		p=p->next;
		x=p->value;
		if(visited[x]!=1)		
		{
			visited[x]=1;

			dfs(head[x],count+1);
		}
	}
}

int main()
{
	int x,y,m,n,test;
	int i,j;
	node *temp;
	scanf("%d",&test);
	while(test--)
	{
		max=0;
	scanf("%d",&n);
	if(n==0)
	{
		continue;
	}
	for(i=0;i<n-1;i++)
	{
		scanf("%d %d",&x,&y);
		insert(x,y);
		insert(y,x);
	}

	for(i=1;i<=n;i++)
	{
		insert(i,i);
	}
	for(i=1;i<=n;i++)
	{
		visited[i]=0;
	}
	dfs(head[1],0);
//	printf("\n");
	y=ans;
	max=0;
	for(i=1;i<=n;i++)
	{
		visited[i]=0;
	}
		visited[y]=1;
		dfs(head[y],0);
//		printf("\n");
		for(i=1;i<=n;i++)
		{
				visited[i]=0;
		}
	printf("%d\n",max+1);
	for(i=1;i<=n;i++)
	{
		empty(head[i]);
		head[i]=NULL;
	}
	}
	return 0;
}
	
