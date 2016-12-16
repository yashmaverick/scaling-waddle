#include<stdio.h>
#include<stdlib.h>
int a[10005];
int top=-1;
int visited[10005]={0};
int max=0;
typedef struct dfs
{
	struct dfs *next;
	int val;
}dfs;
dfs *head[1005];
dfs *head1[1005];


void create(int n)
{
	int i;
	for(i=0;i<=n;i++)       
	{
		head[i]=(dfs*)malloc(sizeof(dfs));
		head[i]->next=NULL;
		head[i]->val=i;
	}
}
void create1(int n)
{
	int i;
	for(i=0;i<=n;i++)       
	{
		head1[i]=(dfs*)malloc(sizeof(dfs));
		head1[i]->next=NULL;
		head1[i]->val=i;
	}
}


void insert(int u,int v)
{
	dfs *temp;
	dfs *temp1;
	temp1=head[u];
	temp=temp1->next;
	temp1->next=(dfs*)malloc(sizeof(dfs));
	temp1->next->val=v;
	temp1->next->next=temp;
}
void insert1(int u,int v)
{
	dfs *temp;
	dfs *temp1;
	temp1=head1[u];
	temp=temp1->next;
	temp1->next=(dfs*)malloc(sizeof(dfs));
	temp1->next->val=v;
	temp1->next->next=temp;
}

void print(int n)
{
	int i;
	for(i=1;i<=n;i++)
	{
		dfs *temp=head[i];
		while(temp!=NULL)
		{
			printf("%d->",temp->val);
			temp=temp->next;	
		}
		printf("\n");
	}
}
void print1(int n)
{
	int i;
	for(i=1;i<=n;i++)
	{
		dfs *temp=head1[i];
		while(temp!=NULL)
		{
			printf("%d->",temp->val);
			temp=temp->next;	
		}
		printf("\n");
	}
}
int count=0;
int  depfs(int i)
{
	count++;
//	printf("%d",i);
	visited[i]=1;
	dfs *temp=head[i];
	while(temp!=NULL)
	{
		if(!visited[temp->val])
			depfs(temp->val);
		temp=temp->next;	
	}
}

int  depfs1(int i)
{count++;
//	printf("%d",i);
	visited[i]=1;
	dfs *temp=head1[i];
	while(temp!=NULL)
	{
		if(!visited[temp->val])
			depfs1(temp->val);
		temp=temp->next;	
	}
}
int main()
{
	dfs *temp;
	int m,n,u,v,i,t,x,j,c;
	int flag=0;
           scanf("%d",&t);
	while(t--)
	{

		scanf("%d",&n);
		create(n);
		create1(n);
		for(j=1;j<=n;j++)
		{ scanf("%d",&x);
			for(i=1;i<=x;i++)
			{ scanf("%d",&v);
				insert(v,j);
				insert1(j,v);
				//insert1(v,j);
			}	
		}
//		print(n);
//		print1(n);
		int c;
		int flag=0;
                 for(i=1;i<=n;i++)
		{
			count=0;
			depfs(i);
			if(count==n)
			{c=i;
			flag=1;	
                          break;
			}
			for(j=0;j<=n;j++)
				visited[j]=0;
		}
//		printf("c is %d\n",c);
		if(flag==1)
                   {count=0;
		
		for(i=0;i<=n;i++)
			visited[i]=0;
                     depfs1(c);
		printf("%d\n",count);
}
else
printf("0\n");		
for(i=0;i<=n;i++)
			visited[i]=0;
		for(i=1;i<=n;i++)
		{
			while(head[i]!=NULL)
			{
				temp=head[i];
				head[i]=head[i]->next;
				//temp=head[i];
				free(temp);
			}
			for(i=1;i<=n;i++)
			{
				while(head1[i]!=NULL)
				{
					temp=head1[i];
					head1[i]=head1[i]->next;
					//temp=head[i];
					free(temp);
				}
			}
		}

	}
	return 0;
}










