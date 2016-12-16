#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>

typedef struct graph
{
	int data;
	int wgt;
	struct graph *next;
} gn;

typedef struct heap
{
	int data;
	int wgt;
} hn;

gn* ig(gn *n,int v,int w)
{
	gn *t;
	t=(gn *)malloc(sizeof(gn));
	t->data=v;
	t->wgt=w;
	t->next=n;
	return t;
}

int leaf=1;

void swaph(hn **a,hn **b)
{
	hn *t=*a;
	*a=*b;
	*b=t;
}

void swapp(int *a,int *b)
{
	int t=*a;
	*a=*b;
	*b=t;
}

void updateh(hn **h,int p[],int a,int b)
{
	h[p[a]]->wgt=b;
	int l;
	l=p[a];
	while((l/2)>=1)
	{
		if(h[l]->wgt<h[l/2]->wgt)
		{
			swapp(&p[h[l]->data],&p[h[l/2]->data]);
			swaph(&h[p[h[l]->data]],&h[p[h[l/2]->data]]);
			l=l/2;
		}
		else
			break;
	}
}

hn* rmin(hn **h,int p[])
{
	hn* k=h[1];
	swapp(&p[h[leaf]->data],&p[h[1]->data]);
	swaph(&h[p[h[leaf]->data]],&h[p[h[1]->data]]);
	leaf--;
	int l=1;
	while(l<=leaf)
	{
		if(2*l+1<=leaf)
		{
			int q;
			q=(h[2*l]->wgt<h[2*l+1]->wgt)?(2*l):(2*l+1);
			if(h[l]->wgt>h[q]->wgt)
			{
				swapp(&p[h[l]->data],&p[h[q]->data]);
				swaph(&h[p[h[l]->data]],&h[p[h[q]->data]]);
				l=q;
				continue;
			}
		}
		else if(2*l<=leaf)
		{
			if(h[l]->wgt>h[l*2]->wgt)
			{
				swapp(&p[h[l]->data],&p[h[2*l]->data]);
				swaph(&h[p[h[l]->data]],&h[p[h[2*l]->data]]);
				l=2*l;
				continue;
			}
		}
		break;
	}
	return k;
}

int gfl=1;
int ans=0;

void prims(gn **g,hn **h,int p[])
{
	int bv[10001]={0};
	while(leaf>0)
	{
		hn *tmp;
		tmp=rmin(h,p);
		int i;
		i=tmp->data;
		bv[i]=1;
		if(tmp->wgt==INT_MAX)
		{
			gfl=0;
			break;
		}
		else
		{
			ans+=tmp->wgt;
		}
		gn *t=g[i];
		while(t!=NULL)
		{
			if(bv[t->data]==1);
			else
			{
				int d;
				d=t->wgt;
				if(d<h[p[t->data]]->wgt&&p[t->data]<=leaf)
					updateh(h,p,t->data,d);
			}
			t=t->next;
		}
	}
}

int main()
{
	int n,m,i,u,v,w;
	scanf("%d %d",&n,&m);
	gn **list;list=(gn **)calloc(n+1,sizeof(gn *));
	for(i=1;i<=n;i++) list[i]=NULL;
	while(m--)
	{
		scanf("%d%d%d",&u,&v,&w);
		list[u]=ig(list[u],v,w);
		list[v]=ig(list[v],u,w);
	}
	hn **h;h=(hn **)calloc(n+1,sizeof(hn *));
	int *p;p=(int *)calloc(n+1,sizeof(int));
	leaf=n;
	for(i=1;i<=n;i++)
	{
		h[i]=(hn *)malloc(sizeof(hn));
		h[i]->data=i;
		h[i]->wgt=INT_MAX;
		p[i]=i;
	}
	updateh(h,p,u,0);
	prims(list,h,p);
	if(gfl)
		printf("%d\n",ans);
	else
		printf("-1\n");
	return 0;
}
