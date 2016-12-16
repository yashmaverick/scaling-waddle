#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#define ull unsigned long long

typedef struct graph
{
	ull data;
	ull wgt;
	struct graph *next;
} gn;

typedef struct heap
{
	ull data;
	ull dist;
} hn;

gn* ig(gn *n,ull v,ull w)
{
	gn *t;
	t=(gn *)malloc(sizeof(gn));
	t->data=v;
	t->wgt=w;
	t->next=n;
	return t;
}

ull leaf=1;
ull ans=0;

void swaph(hn **a,hn **b)
{
	hn *t=*a;
	*a=*b;
	*b=t;
}

void swapp(ull *a,ull *b)
{
	ull t=*a;
	*a=*b;
	*b=t;
}

void updateh(hn **h,ull p[],ull a,ull b)
{
	h[p[a]]->dist=b;
	ull l;
	l=p[a];
	while((l/2)>=1)
	{
		if(h[l]->dist<h[l/2]->dist)
		{
			swapp(&p[h[l]->data],&p[h[l/2]->data]);
			swaph(&h[p[h[l]->data]],&h[p[h[l/2]->data]]);
			l=l/2;
		}
		else
			break;
	}
}

hn* rmin(hn **h,ull p[])
{
	hn* k=h[1];
	swapp(&p[h[leaf]->data],&p[h[1]->data]);
	swaph(&h[p[h[leaf]->data]],&h[p[h[1]->data]]);
	leaf--;
	ull l=1;
	while(l<=leaf)
	{
		if(2*l+1<=leaf)
		{
			ull q;
			q=(h[2*l]->dist<h[2*l+1]->dist)?(2*l):(2*l+1);
			if(h[l]->dist>h[q]->dist)
			{
				swapp(&p[h[l]->data],&p[h[q]->data]);
				swaph(&h[p[h[l]->data]],&h[p[h[q]->data]]);
				l=q;
				continue;
			}
		}
		else if(2*l<=leaf)
		{
			if(h[l]->dist>h[l*2]->dist)
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

void dj_algo(gn **g,hn **h,ull p[],ull t)
{
	while(leaf>0)
	{
		hn *tmp;
		tmp=rmin(h,p);
		ull i;
		i=tmp->data;
		if(i==t)
		{
			ans=tmp->dist;
			return;
		}
		gn *tn=g[i];
		while(tn!=NULL)
		{
			if(h[p[i]]->dist==ULLONG_MAX)
				break;
			ull d;
			d=h[p[i]]->dist+tn->wgt;
			if(d<h[p[tn->data]]->dist&&p[tn->data]<=leaf)
				updateh(h,p,tn->data,d);
			tn=tn->next;
		}
	}
}

int main()
{
//	ull a;scanf("%llu",&a);while(a--)
	{
	ull n,m,i,u,v,w;
	scanf("%llu %llu",&n,&m);
	gn **list;list=(gn **)calloc(n+1,sizeof(gn *));
	for(i=0;i<=n;i++) list[i]=NULL;
	for(i=1;i<=m;i++)
	{
		scanf("%llu %llu %llu",&u,&v,&w);
		list[u]=ig(list[u],v,w);
	}
	ull s,t;
	scanf("%llu %llu",&s,&t);
	hn **h;h=(hn **)calloc(n+1,sizeof(hn *));
	ull *p;p=(ull *)calloc(n+1,sizeof(ull));
	leaf=n;
	ull x=ULLONG_MAX;
	ans=x;
	for(i=1;i<=n;i++)
	{
		h[i]=(hn *)malloc(sizeof(hn));
		h[i]->data=i;
		h[i]->dist=x;
		p[i]=i;
	}
	updateh(h,p,s,0);
	dj_algo(list,h,p,t);
	if(ans!=x)
		printf("%llu\n",ans);
	else
		printf("NO\n");
	}
	return 0;
}
