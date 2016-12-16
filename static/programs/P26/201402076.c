#include<stdio.h>
#include<stdlib.h>
struct node
{
	int val;
	struct node* next;
};
typedef struct node node;

node* adj[2000]={NULL};
int primes[2000];
int rp[10005];
int count=0;
int vis[10005]={0};
int dist[1100][1100]={0};
int visi[1100][1100]={0};

node* insert(node* head,int val)
{
	node* temp=(node*)malloc(sizeof(node));
	temp->val=val;
	temp->next=head;
	return temp;
}
void sieve()
{
	int i,j;
	for(i=2;i<10005;i++)
		vis[i]=1;
	for(i=2;i<10005;i++)
		if(vis[i]==1)
			for(j=2*i;j<10005;j+=i)
				vis[j]=0;
	vis[0]=0;
	vis[1]=0;
}
int func(int temp2,int temp1)
{
	int count=0;
	while(temp2>0&&temp1>0)
	{
		if(temp1%10!=temp2%10)
			count++;
		temp2/=10;
		temp1/=10;
	}
	if(count==1)
		return 1;
	else
		return 0;
}
void precompute()
{
	int i,j=0;
	for(i=1000;i<10000;i++)
		if(vis[i]==1)
		{
			primes[j]=i;
			rp[i]=j;
			j++;
		}
	count=j;
//	printf("%d\n",count);
	for(i=0;i<count;i++)
		for(j=i+1;j<count;j++)
			if(func(primes[j],primes[i]))
			{
				adj[j]=insert(adj[j],i);
				adj[i]=insert(adj[i],j);
			}
/*	for(i=0;i<count;i++)
		for(j=0;j<count;j++)
			dist[i][j]=1200;
	for(i=0;i<count;i++)
		dist[i][i]=0;
*/
}
int queue[10000];
int sp=0;
int ep=0;
void compute()
{
	int u;
	for(u=0;u<count;u++)
	{
		visi[u][u]=1;
		queue[0]=u;
		sp=0;ep=0;
		dist[u][u]=0;
		while(sp<=ep)
		{
			int curr=queue[sp];
			sp++;
			node* temp=adj[curr];
			while(temp!=NULL)
			{
				if(!visi[u][temp->val])
				{
					visi[u][temp->val]=1;
					ep++;
					queue[ep]=temp->val;
					dist[u][temp->val]=dist[u][curr]+1;
				}	
				temp=temp->next;
			}
		}
	}
}
int main()
{
	sieve();
	precompute();
	compute();
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		a=rp[a];
		b=rp[b];
		if(a==b)
			printf("0\n");
		else if(dist[a][b]==0)
			printf("Impossible\n");
		else
			printf("%d\n",dist[a][b]);
	}
	return 0;
}
