#include <stdio.h>
#include <stdlib.h>

int d[1000001],reach[1000001],vis,max;

struct adj
{
	int val;
	struct adj *next;
};

typedef struct adj ELEMENT;
typedef ELEMENT *LINK;

int q[1000001];
int f=0,r=-1;

void enq(int n)
{
	r++;
	q[r]=n;
}

int deq()
{
	int n;
	n=q[f];
	f++;
	return n;
}


void bfs(LINK g[],int start)
{
	vis=start;
	int i,loc,n;
	LINK tmp;

	reach[start]=1;
	tmp=g[start];

	while(tmp!=NULL)
	{
		if(reach[tmp->val]==0)
		{
			reach[tmp->val]=1;
			enq(tmp->val);
		}

		tmp=tmp->next;
	}

	if(f<=r)
	{
		n=deq();
		bfs(g,n);	
	}
}

void sbfs(LINK g[],int start,int dis)
{
	vis=start;
	int i,loc,n;
	LINK tmp;

	if(max<dis)
		max=dis;

	reach[start]=1;
	tmp=g[start];

	while(tmp!=NULL)
	{
		if(reach[tmp->val]==0)
		{
			d[tmp->val]=dis+1;
			reach[tmp->val]=1;
			enq(tmp->val);
		}

		tmp=tmp->next;
	}

	if(f<=r)
	{
		n=deq();
		sbfs(g,n,d[n]); 
	}
}


int main()
{
	int t,T,i,j,n,a,b;

	scanf("%d",&T);

	for(t=1;t<=T;t++)
	{
		max=0;
		vis=0;
		f=0;
		r=-1;

		scanf("%d",&n);

		LINK g[1000001];

		for(i=0;i<=1000000;i++)
		{
			d[i]=0;
			reach[i]=0;
			g[i]=NULL;
		}

		for(i=1;i<n;i++)
		{
			LINK tmp,tmp2;
			scanf("%d %d",&a,&b);

			tmp=(LINK)malloc(sizeof(ELEMENT));
			tmp->val=b;
			tmp->next=g[a];

			g[a]=tmp;

			//free(tmp);

			tmp2=(LINK)malloc(sizeof(ELEMENT));
			tmp2->val=a;

			tmp2->next=g[b];

			g[b]=tmp2;

			//free(tmp2);
		}

		/*for(i=1;i<=n;i++)
		{
			LINK tmp;
			tmp=g[i];
			printf("%d-->",i);

			while(tmp!=NULL)
			{	
				printf("%d ",tmp->val);
				tmp=tmp->next;
			}
			printf("\n");

		}*/

		bfs(g,1);

		for(i=0;i<=1000000;i++)
			reach[i]=0;
		
		d[vis]=1;

		sbfs(g,vis,1);

		printf("%d\n",max);
	}

	return 0;
}
