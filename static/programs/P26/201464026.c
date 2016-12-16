#include <stdio.h>
#include <stdlib.h>
#define MAX 10010
typedef struct qs
{
    int n;
    int w;
}qs;
typedef struct ll
{
    int node;
    struct ll *next;
}ll;
int sieve[MAX];
qs queue[100000];
int qst,qf,qr;
qs dequeue()
{
	qst--;
    qf++;
    return queue[qf-1];
}
void enqueue(qs element)
{
    qst++;
    qr++; 
    queue[qr] = element;
    return;
}
void csieve()
{
	int i,j;
	for(i=2;i<MAX;i++)
		sieve[i]=1;
	for(i=2;i<MAX;i++)
		if(sieve[i])
		{
			for(j=i;i*j<MAX;j++)
				sieve[i*j]=0;
		}
}
ll* create(ll *g, int a)
{
	ll *ne = (ll *)malloc(sizeof(ll));
	ne->node = a;
	ne->next = g;
	return ne;
}
void creategraph(ll **g)
{
	int i;
	for(i=1000;i<9999;i++)
	{
		if(sieve[i]==0)
			continue;
		else
		{
			int tmp,mod,j,qw;


			//Part 1
			tmp = i/10;
			for(j=0;j<10;j++)
			{
				qw = tmp*10+j;
				if(sieve[qw] && qw!=i)
					g[i] = create(g[i],qw);
			}
			//End



			//Part 2
			tmp=i/100;
			mod = i%10;
			for(j=0;j<10;j++)
			{
				qw = ((tmp*10)+j)*10 + mod;
				if(sieve[qw] && qw!=i)
					g[i] = create(g[i],qw);
			}
			//End



			//Part 3
			tmp = i/1000;
			mod = i%100;
			for(j=0;j<10;j++)
			{
				qw = ((tmp*10)+j)*100 + mod;
				if(sieve[qw] && qw!=i)
					g[i] = create(g[i],qw);
			}
			//End


			//Part 4
			mod = i%1000;
			for(j=1;j<10;j++)
			{
				qw = j*1000 + mod;
				if(sieve[qw] && qw!=i)
					g[i] = create(g[i],qw);
			}
			//End
		}
	}
}
int bfs(ll **g, int a, int b)
{
	int i;
	int visited[MAX];
	for(i=0;i<MAX;i++)
		visited[i]=0;
	qs temp;
	temp.n = a;
	temp.w = 0;
	visited[a]=1;
	enqueue(temp);
	while(qst != 0)
	{
		qs wa = dequeue();
//		printf("%d   %d\n",wa.n,wa.w);
		if(wa.n == b)
		{
//			printf("Found Match!\n");
			return wa.w;
		}
		else
		{
			ll *e;
			for(e = g[wa.n];e!=NULL;e=e->next)
			{
				if(visited[e->node]==0)
				{
					visited[e->node]=1;
					temp.n = e->node;
					temp.w = wa.w + 1;
					enqueue(temp);
				}
			}
		}
	}
	return -1;
}
int main()
{
	int i;
	ll **g;
	g = (ll **)malloc(sizeof(ll *)*MAX);
	for(i=0;i<MAX;i++)
		g[i] = NULL;
	csieve();
	creategraph(g);
//	ll *temp = g[8779];
//	while(temp!=NULL)
//	{
//		printf("%d->",temp->node);
//		temp = temp->next;
//	}
//	printf("\n");
	int t;
	scanf("%d",&t);
	while(t--)
	{
		qf=0;
		qr=-1;
		qst=0;
		int a,b;
		scanf("%d %d",&a,&b);
		int ans = bfs(g,a,b);
		if(ans==-1)
			printf("Impossible\n");
		else
			printf("%d\n",ans);
	}
	return 0;
}