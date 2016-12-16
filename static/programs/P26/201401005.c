#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>

int que[10001];
int pri[10001];
int vis[10001];
int lev[10001];

void sieve()
{
	int i, j;
	memset(pri, 0, sizeof(pri));
	pri[0] = -1;
	pri[1] = -1;
	for(i=2; i*i<10001; i++)
		if(pri[i] == 0)
			for(j=i*i; j<10001 ; j+=i)
				pri[j] = -1;
}

int bfs(int src, int dest)
{
	memset(vis, 0, sizeof(vis));
	memset(lev, 0, sizeof(lev));
	int front=0, rear=0;
	int i;
	que[rear++] = src;
	vis[src] = 1;

	while(front != rear)
	{
		int fl = que[front];	
		front++;
		int a, b, c, d, x;
		a = fl%10;
		b = (fl/10)%10;
		c = (fl/100)%10;
		d = fl/1000;
		for(i=0; i<10; i++)
		{
			x = 1000*d+100*c+10*b+i;
			if(!vis[x] && pri[x]==0)
			{
				que[rear++] = x;
				vis[x] = 1;
				lev[x] = lev[fl]+1;
				if(vis[dest] == 1)
					return lev[dest];
			}
		}
		for(i=0; i<10; i++)
		{
			x = 1000*d+100*c+10*i+a;
			if(!vis[x] && pri[x]==0)
			{
				que[rear++] = x;
				vis[x] = 1;
				lev[x] = lev[fl]+1;
				if(vis[dest] == 1)
					return lev[dest];
			}
		}
		for(i=0; i<10; i++)
		{
			x = 1000*d+100*i+10*b+a;
			if(!vis[x] && pri[x]==0)
			{
				que[rear++] = x;
				vis[x] = 1;
				lev[x] = lev[fl]+1;
				if(vis[dest] == 1)
					return lev[dest];
			}
		}
		for(i=1; i<10; i++)
		{
			x = 1000*i+100*c+10*b+a;
			if(!vis[x] && pri[x]==0)
			{
				que[rear++] = x;
				vis[x] = 1;
				lev[x] = lev[fl]+1;
				if(vis[dest] == 1)
					return lev[dest];
			}
		}
	}
}

int main()
{
	int t, x, y;
	scanf("%d", &t);
	sieve();
	while(t--)
	{
		scanf("%d%d", &x, &y);
		printf("%d\n", bfs(x, y));
	}

	return 0;
}









