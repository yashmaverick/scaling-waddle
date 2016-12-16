#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>
#include<string.h>
#define INF 1000000000

struct list
{
	int v;
	int w;
	struct list *next;
};

struct hnode
{
	int e;
	int v;
};

struct hnode B[100002];
int hsize;
struct list* A[100002];
int vis[100002],d[100002];

void adjlist(int x,int y,int w)
{
        struct list* new=(struct list*)malloc(sizeof(struct list));
	new->v=y;
	new->w=w;
	new->next=NULL;
	new->next=A[x];
	A[x]=new;
}

void insert(int data,int vert)
{
	hsize++;
	B[hsize].e=data;
	B[hsize].v=vert;
	int n=hsize;
	while(B[n/2].e>data)
	{
		B[n].e=B[n/2].e;
		B[n].v=B[n/2].v;
		n=n/2;
	}
	B[n].e=data;
	B[n].v=vert;
}

struct hnode extract_min()
{
	int c,n;
	struct hnode min,l;
	min=B[1]; 
	l=B[hsize--];
	for(n=1; n*2<=hsize ;n=c)
        {
                c=n*2;
                if(c!=hsize&&B[c+1].e<B[c].e) 
                        c++;
                if(l.e>B[c].e)
                        B[n]=B[c];
                else
                        break;
        }
        B[n]=l;
        return min;
}

void shortest_path(int root)
{
	d[root]=0;
	
	insert(0,root);

	while(hsize>0)
	{

		struct hnode v=extract_min();
		int u=v.v;
		if(vis[u]==1)
			continue;
		vis[u]=1;
		struct list* c=A[u];
		
		while(c!=NULL)
		{
			int v=c->v;
			int nd=d[u] + c->w;
			
			if(d[v]>nd)
			{
				d[v]=nd;
				insert(d[v],v);
			}
			c=c->next;
		}
	}
}

int main()
{
	int N,M,x,y,w,i,s,t;
	scanf("%d",&N);
	scanf("%d",&M);
	for(i=0;i<M;i++)
	{
		scanf("%d %d %d",&x,&y,&w);
		adjlist(x,y,w);
	}
	for(i=1;i<100002;i++)
	{
		vis[i]=0;
		d[i]=INF;
	}
	B[0].e=-INF;
	B[0].v=0;
	hsize=0;
	scanf("%d %d",&s,&t);
	shortest_path(s);
	if(d[t]==INF)
		printf("NO\n");
	else
		printf("%d\n",d[t]);
	return 0;
}
