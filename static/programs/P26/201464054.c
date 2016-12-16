#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>
#define ll long long int
#define ull unsigned long long int
#define sint(n); scanf("%d",&n);
#define pint(n); printf ("%d\n",n);
#define sll(n); scanf("%lld",&n);
#define pll(n); printf("%lld\n",n);
#define pull(n); printf("%llu\n",n);
#define sst(n); scanf("%s",n);
#define pst(n); printf ("%s\n",n);
#define TEST ll test;scanf("%lld",&test);while(test--)
#define f0(i,n) for(i=0;i<n;i++)
#define f1(i,n) for(i=1;i<=n;i++)
#define f1r(i,n) for(i=n;i>=1;i--)
#define f0r(i,n) for(i=n;i>0;i--)
#define set(x,y) memset(x,y,sizeof(x));
#define MAX 10007

int n;
int visited[10005];
int check[10005];
struct node
{
	int data;
	int cost2;
	struct node* next;
};
struct node* head[20005];
void insert ( int x, int y, int z)
{
	if (check[x]==0)
	{
		head[x]=malloc(sizeof(struct node));
		head[x]->next=NULL;
		check[x]=1;
	}
	if (check[y]==0)
	{
		head[y]=malloc(sizeof(struct node));
		head[y]->next=NULL;
		check[y]=1;
	}
	if ( check[x] == 0 )
	{
		head[x]->data=y;
		head[x]->cost2=z;
		head[x]->next=NULL;
	}
	else
	{
		struct node* temp;
		temp=malloc(sizeof(struct node));
		temp->data=y;
		temp->cost2=z;
		temp->next=head[x];
		head[x]=temp;
	}
	if ( check[y] == 0 )
	{
		head[y]->data=y;
		head[y]->cost2=z;
		head[y]->next=NULL;
	}
	else
	{
		struct node* temp;
		temp=malloc(sizeof(struct node));
		temp->data=x;
		temp->cost2=z;
		temp->next=head[y];
		head[y]=temp;
	}
	return;
}
void printll()
{
	int i;
	struct node* temp2;
	temp2=malloc(sizeof(struct node));
	for (i=0;i<10005;i++)
		if (check[i] == 1)
		{
			printf ("%d :: ",i);
			temp2=head[i];
			while (temp2->next!=NULL)
			{
				printf ("%d ( %d ) -> ",temp2->data,temp2->cost2);
				temp2=temp2->next;
			}
			printf ("\n");
		}
	return;
}
int queue[100005],front,rear;
int level[10005];
void enqueue(int x)
{
	queue[++rear]=x;
	return;
}
void dequeue(){front++;}
int isempty(){if(front<=rear){return 0;}else return 1;}
void bfs(int u,int v)
{
	front=0;
	rear=-1;
	queue[++rear]=u;
	int t;
	struct node* temp;
	temp=malloc(sizeof(struct node));
	while (1)
	{
		t=queue[front];
		front++;
		if (check[t]!=0)
		{
			temp=head[t];
			while (temp->next!=NULL)
			{
				if (visited[temp->data]==0)
				{
				queue[++rear]=(temp->data);
				level[temp->data]=level[t]+1;
				visited[temp->data]=1;
				if (temp->data == v)
					return;
				}
				temp=temp->next;
			}
		}
		visited[t]=1;
		if (front>rear)
			break;
	}
	return;
}
int prime[10005];
struct number{	int n0;	int n1;	int n2;	int n3;	int val;	};
void gen_prime()
{
	int i,j;
	for (i=2;i<=100;i++)
		if (prime[i]==1)
		{
			for (j=i*i;j<=10000;j+=i)
				prime[j]=0;
		}
	return;
}
int par[10005];
int root ( int val )
{
	if (par[val]==val)
		return val;
	par[val]=root(par[val]);
	return par[val];
}
int isconnected(int u, int v){if(root(u)==root(v)){return 1;}else return 0;}
void merge (int x, int y)
{
	int a,b;
	a=root(x);
	b=root(y);
	par[b]=a;
	return;
}
int main()
{
/*	insert(1,2,1);
	insert(2,3,1);
	//insert(1,3,1);
	insert(1,4,1);
	insert(1,5,1);
	printll();
	bfs(1,3);
	int i2;
	f1(i2,5){printf ("%d >> ",level[i2]);}printf("\n");
	pint(level[5]);
	return 0;
*/	int ii;
	f0(ii,10001){prime[ii]=1;}
	gen_prime();	prime[0]=0;	prime[1]=0;
	set(check,0);
	int a;
	a=1009;
	int i,j,temp;
	f0(i,10005){par[i]=i;}
	for(j=1009;j<=9973;j++)
	{
		if (prime[j]==1)
		{
			a=j;
			struct number curr;
			curr.val=a;
			curr.n0=a/1000;	a=a%1000;	curr.n1=a/100;	a=a%100;	curr.n2=a/10;	a=a%10;	curr.n3=a;
			//thousandth place
			for(i=curr.n0+1;i<10;i++)
			{
				temp=((1000*i)+(100*curr.n1)+(10*curr.n2)+(curr.n3));
				if (i!=0 && prime[temp]==1)
				{
					insert(curr.val,temp,1);
//					merge(curr.val,temp);
				}
			}
			//hundredth place
			for(i=curr.n1+1;i<10;i++)
			{
				temp=((1000*curr.n0)+(100*i)+(10*curr.n2)+(curr.n3));
				if (prime[temp]==1)
				{
					insert(curr.val,temp,1);
//					merge(curr.val,temp);
				}
			}
			//tens place
			for(i=curr.n2+1;i<10;i++)
			{
				temp=((1000*curr.n0)+(100*curr.n1)+(10*i)+(curr.n3));
				if (prime[temp]==1)
				{
					insert(curr.val,temp,1);
//					merge(curr.val,temp);
				}
			}
			//units place
			for(i=curr.n3+1;i<10;i++)
			{
				temp=((1000*curr.n0)+(100*curr.n1)+(10*curr.n2)+(i));
				if (prime[temp]==1)
				{
					insert(curr.val,temp,1);
//					merge(curr.val,temp);
				}
			}
		}
	}
	TEST{
		int u,v;
		sint(u);	sint(v);
		if (u==v)
		{
			printf("0\n");
			continue;
		}
		for(i=1000;i<=10000;i++){	visited[i]=0;	level[i]=0;	}
		bfs(u,v);
		if (level[v]==0)
			printf("Impossible\n");
		else
			pint(level[v]);
	}
	return 0;
}
