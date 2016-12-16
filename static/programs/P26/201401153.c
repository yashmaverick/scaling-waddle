#include<stdio.h>
#include<stdlib.h>
typedef struct tnode
{
	struct tnode *next;
	int data;
}node;

node *a[100000];
int vis[100000], b[1000000], dist[100000], arr[100000];
int front=0, rear=1, first, l;

void enqueue(int x)
{
	front++;
	b[front]=x;
}

void dequeue()
{
	first=b[rear];
	rear++;
}

void print()
{
	int q;
	for(q=rear;q<=front;q++)
		printf("%d ",b[q]);
	printf("\n");
}

node *insert(int c, int d)
{
	node *temp;
	temp=(node*)malloc(sizeof(node));
	temp->data=d;
	temp->next=a[c];
	a[c]=temp;
	return a[c];
}

void bfs(node *g)
{
	while(rear<=front)
	{
		while(g!=NULL)
		{
			if(vis[g->data]==0)
			{
				enqueue(g->data);
				dist[g->data]=l+1;
				vis[g->data]=1;
			}
			g=g->next;
		}
		dequeue();
		//		printf("%d ",first);

		l=dist[b[rear]];
		bfs(a[b[rear]]);
	}
}

void sieve()
{
	int i,j;
	for(i=2;i<=100;i++)
	{
		for(j=2;i*j<=9999;j++)
		{
			if(arr[i*j]==0)
			{
				arr[i*j]=1;
			}
		}
	}
}

int main()
{
	int n,m,i,j,k,q,l,h,l1,h1,c,t;
	int p[100000];
	sieve();
	q=0;
	for(i=1000;i<=9999;i++)
	{
		if(arr[i]==0)
		{
			p[q]=i;
			q++;
		}
	}
	for(i=0;i<=9999;i++)
		a[i]=NULL;

	for(i=0;i<q-1;i++)
	{
		for(j=i+1;j<q;j++)
		{
			c=0;
			l=p[i];
			h=p[j];
			for(k=0;k<4;k++)
			{
				l1=l%10;
				h1=h%10;
				if(l1==h1)
					c++;
				l=l/10;
				h=h/10;
			}
			if(c==3)
			{
				a[p[i]]=insert(p[i],p[j]);
				a[p[j]]=insert(p[j],p[i]);
			}
		}
	}

	scanf("%d",&t);
	while(t--)
	{
		l=0;
		rear=1;
		front=0;
		
		scanf("%d %d",&n,&m);
		
		for(j=0;j<=9999;j++)
			vis[j]=0;
		enqueue(n);
		vis[n]=1;
		dist[n]=0;
		bfs(a[n]);
		printf("%d\n",dist[m]);
	}
	return 0;
}
