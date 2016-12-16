#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define sc(x) scanf("%lld",&x)

typedef struct c
{
	long long int data;
	struct c *next;
}node;
node *head[1001];
node *head1[1001];
node *top[1001];
node *rear[1001];
long long int vis[1001]={0};
long long int c[1001]={0};
long long int count=0,result=0;
long long int d[1001]={0};
long long int v[1001]={0};
/*void dfs1(node *temp)
{
	long long int a=temp->data;
	if(vis[a]==1)
		return;
	else if(temp->next==NULL)
	{
		//printf("Increasing count for %lld\n",a);
		vis[a]=1;
		count++;
		return;
	}
	else
	{
		vis[a]=1;
		count++;
		//printf("Increasing count for %lld\n",a);
		printf("Here Going for %lld\n",temp->data);
		temp=temp->next;
		dfs1(top[temp->data]);
		while(temp->next!=NULL)
		{
			printf("There Going for %lld\n",temp->data);
			temp=temp->next;
			dfs1(temp);
		}
	}
	return;
}*/
void dfs(node *temp)
{
	vis[temp->data]=1;
	count++;
	while(temp!=NULL)
	{
		if(vis[temp->data]==0)
		{
			dfs(top[temp->data]);
		}
		temp=temp->next;
	}
	return;
}
void dfs1(node *temp)
{
	v[temp->data]=1;
	result++;
	//printf("Result is %lld\n",result);
	while(temp!=NULL)
	{
		if(v[temp->data]==0)
		{
			//printf("Going for %lld\n",temp->data);
			dfs1(head[temp->data]);
		}
		temp=temp->next;
	}
	return;
}
void insert(long long int p,long long int q)
{	
	node *temp;
	temp=malloc(sizeof(node));
	temp->data=q;
	temp->next=NULL;
	head1[p]->next=temp;
	head1[p]=temp;
	return;
}
void insertnode(long long int p,long long int q)
{	
	node *temp;
	temp=malloc(sizeof(node));
	temp->data=q;
	temp->next=NULL;
	rear[p]->next=temp;
	rear[p]=temp;
	return;
}
int main()
{
	long long int t;
	sc(t);
	while(t--)
	{
		long long int n,j,i,k;
		result=0;
		count=0;
		sc(n);
		for(j=1;j<=1000;j++)
		{
			head[j]=malloc(sizeof(node));
			head[j]->data=j;
			head[j]->next=NULL;
			top[j]=malloc(sizeof(node));
			rear[j]=malloc(sizeof(node));
			head1[j]=malloc(sizeof(node));
			top[j]->data=j;
			top[j]->next=NULL;
			rear[j]=top[j];
			head1[j]=head[j];
			v[j]=0;
			vis[j]=0;
			d[j]=0;c[j]=0;
			/*for(k=1;k<=n;k++)
			  head[j]->next[k]=NULL;*/
		}
		for(j=1;j<=n;j++)
		{
			long long int m;
			sc(m);
			for(i=0;i<m;i++)
			{	long long int y;
				sc(y);
				c[y]++;
				d[y]++;
				insert(j,y);
				insertnode(y,j);
			}
		}
		for(j=1;j<=n;j++)
		{
			/*node *dp;
			dp=malloc(sizeof(node));
			printf("%lld : ",head[j]->data);
			dp=head[j]->next;
			while(dp!=NULL)
			{
				printf("%lld ",dp->data);
				dp=dp->next;
			}
			printf("\n");*/
				
				dfs(top[j]);
			//printf("%lld for %lld\n",j,count);
			//printf("%lld for %lld\n",j,count);
				if(count==n)
				{
					v[j]=1;
	//				printf("Going for %lld\n",head[j]->data);
					dfs1(head[j]);
					break;
				}
				//if(count==n)
				//	result++;
			count=0;
			for(i=1;i<=n;i++)
				vis[i]=0;
		}
		printf("%lld\n",result);
	}
	return 0;
}

