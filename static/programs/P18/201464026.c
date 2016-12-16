#include <stdio.h>
#include <stdlib.h>
typedef struct ll
{
	int node;
	struct ll *next;
}ll;
ll* insert(ll *g, int value)
{
	ll *h = (ll *)malloc(sizeof(ll));
	h->node = value;
	h->next = g;
	return h;
}
void dfs(ll **g, int start, int n, int *visited)
{
	visited[start]=1;
	ll* i;
	for(i=g[start];i!=NULL;i=i->next)
	{
		if(visited[i->node])
			continue;
		else
			dfs(g,i->node,n,visited);
	}
}
int dfscall(ll **g,int start,int n)
{
	int i,count=0;
	int *visited = (int *)malloc(sizeof(int)*(n+1));
	for(i=1;i<=n;i++)
		visited[i]=0;
	dfs(g,start,n,visited);
	for(i=1;i<=n;i++)
		if(visited[i])
			count++;
	free(visited);
	return count;
}
void printgraph(ll **g,int n)
{
    int i;
    for(i=1;i<=n;i++)
    {
        ll* temphead;
        temphead = g[i];;
        while(temphead!=NULL)
        {
            printf("Node: %d ,Link: %d\n",temphead->node,i);
            temphead = temphead->next;
        }
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,i;
        ll **gwin,**glose;
        scanf("%d",&n);
        gwin = (ll **)malloc(sizeof(ll *)*(n+1));
        glose = (ll **)malloc(sizeof(ll *)*(n+1));
        for(i=1;i<=n;i++)
        {
        	gwin[i]=NULL;
        	glose[i]=NULL;
        }
        for(i=1;i<=n;i++)
        {
        	int m;
        	scanf("%d",&m);
        	while(m--)
        	{
        		int temp;
        		scanf("%d",&temp);
        		gwin[temp] = insert(gwin[temp],i);
        		glose[i] = insert(glose[i],temp);
        	}
        }
        int flag=0;
        for(i=1;i<=n;i++)
        {
        	int ans = dfscall(gwin,i,n);
        	if(ans == n)
        		break;
        }
        if(i>n)
        	printf("0\n");
        else
        {
        	int ans = dfscall(glose,i,n);
        	printf("%d\n",ans);
        }
    }
    return 0;
}
