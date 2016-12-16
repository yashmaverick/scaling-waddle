#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int value;
	struct node *next;
}node;
node *head[10003];
node *headr[10003];
int visited[10003],xvisited[10003];

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

void insertrev(int y,int x)
{
	node *p;
	p=(node *)(malloc(sizeof(node)));
	p->value=x;
	p->next=NULL;
	if(headr[y]==NULL)
	{
		headr[y]=p;
		return;
	}
	else
	{
		p->next=headr[y];
		headr[y]=p;
	}
}
int count=0;
void dfs(node *p)
{
	int x;
	if(p==NULL)
	{
		return;
	}
	count++;
//	printf("%d ",p->value);//
	while(p->next!=NULL)
	{
		p=p->next;
		x=p->value;
		if(visited[x]!=1)		
		{
			visited[x]=1;
			xvisited[x]=1;
			dfs(head[x]);
		}
	}
}
void dfsr(node *p)
{
	int x;
	if(p==NULL)
	{
		return;
	}
	count++;
//	printf("%d ",p->value);//
	while(p->next!=NULL)
	{
		p=p->next;
		x=p->value;
		if(visited[x]!=1)		
		{
			visited[x]=1;
			xvisited[x]=1;
			dfsr(headr[x]);
		}
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
void display(node *head)
{
	node *p;
	p=head;
	while(p!=NULL)
	{
//		printf("%d ",p->value);
		p=p->next;
	}
}

int main()
{
	int x,y,m,n,flag;
	int i,j,t,a;
	node *temp;
	scanf("%d",&t);
	while(t--)
	{
		flag=0;
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			visited[i]=0;
			xvisited[i]=0;
		}
		for(i=1;i<=n;i++)
		{
			scanf("%d",&m);
			while(m--)
			{
				scanf("%d",&y);
			//	printf("here1");
				insert(y,i);
				insertrev(i,y);
			}		
		}

		for(i=1;i<=n;i++)
		{
			insert(i,i);
			insertrev(i,i);
		}
/*printf("f:");
for(i=1;i<=n;i++)
	{
//		printf("%d->",i);
		display(head[i]);
	//	insert(i,i);
		printf("\n");
	}
printf("b:");
for(i=1;i<=n;i++)
	{
//		printf("%d->",i);
		display(headr[i]);
//		insert(i,i);
		printf("\n");
	}*/
		for(i=1;i<=n;i++)
		{
			if(xvisited[i]!=1)
			{
				for(j=1;j<=n;j++)
				{
					visited[j]=0;
				}
				count=0;
				visited[i]=1;
				xvisited[i]=1;
//				printf("l:");//
				dfs(head[i]);//
//				printf("\n");//
				if(count==n)
				{
					a=i;
					flag=1;
					break;
				}
			}
		}
		count=0;
		for(i=1;i<=n;i++)
		{
			visited[i]=0;
			xvisited[i]=0;
		}
//		printf("baad vala:");
		if(flag==1)
		{
	//		printf("l:");
			visited[a]=1;
			dfsr(headr[a]);
//			printf("\n");//
		}
		printf("%d\n",count);

		for(i=1;i<=n;i++)
		{
			empty(head[i]);
			empty(headr[i]);
			head[i]=NULL;
			headr[i]=NULL;
		}		
	}
	return 0;
}
