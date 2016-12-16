#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define INF 1000000000000000
typedef struct heap_node
{
	long long int vertex;
	long long int weight;
}hnode;
typedef struct list
{
	long long int ver;
	struct list* next;
	long long int weight;
}list;
list* adj[500009];
hnode h[500009];
long long int a[500009],len=0,d[500009];
void shuffle_up(long long x)
{
	hnode temp;
	long long int temp1;
	while(h[x/2].weight>h[x].weight)
	{
		temp=h[x/2];
		h[x/2]=h[x];
		h[x]=temp;
		temp1=a[h[x/2].vertex];
		a[h[x/2].vertex]=a[h[x].vertex];
		a[h[x].vertex]=temp1;
		x=x/2;
	}
	return ;
}
void shuffle_down(long long int x)
{
	hnode temp;
	long long int p,temp1;
	while((2*x<=len && h[2*x].weight<h[x].weight) || (((2*x)+1)<=len && h[(2*x)+1].weight<h[x].weight))
	{
		if(h[2*x].weight<h[(2*x)+1].weight)
		{
			p=2*x;
		}
		else
		{
			p=(2*x)+1;
		}
		temp=h[p];
		h[p]=h[x];
		h[x]=temp;
		temp1=a[h[p].vertex];
		a[h[p].vertex]=a[h[x].vertex];
		a[h[x].vertex]=temp1;
		x=p;
	}
	return ;
}
void ins(long long int u,long long int v,long long int p)
{
	list* temp=(list *)malloc(sizeof(list));
	temp->ver=v;
	temp->weight=p;
	temp->next=adj[u];
	adj[u]=temp;
	return ;
}
void insert(long long x,long long q)
{
	len++;
	h[len].vertex=x;
	h[len].weight=q;
	a[x]=len;
	shuffle_up(len);
	return ;
}
hnode find_min()
{
	return h[1];
}
hnode delete_min()
{
	hnode p=h[1];
	h[1]=h[len];
	a[h[len].vertex]=1;
	len--;
	shuffle_down(1);
	return p;
}
int is_empty()
{
	if(len>0)
		return 0;
	else
		return 1;
}
void update(long long int x,long long int p)
{
	h[x].weight=p;
	shuffle_up(x);
	return ;
}
int main()
{
	long long int n,m,i,u,v,p,k,test;
	list* t;
	for(i=0;i<500009;i++)
	{
		adj[i]=NULL;
	}
	h[0].weight=-INF;
	h[0].vertex=-1;
	len=0;
	scanf("%lld %lld",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%lld %lld %lld",&u,&v,&p);
		ins(u-1,v-1,p);
	}
	/*	for(i=0;i<n;i++)
		{
		printf("%lld:",i);
		t=adj[i];
		while(t)
		{
		printf("%lld %lld\n",t->ver,t->weight);
		t=t->next;
		}
		}*/
	scanf("%lld %lld",&u,&v);
	for(i=0;i<n;i++)
	{
		d[i]=INF;
	}
	d[u-1]=0;
	for(i=0;i<n;i++)
	{
		insert(i,d[i]);
	}
	while(!is_empty())
	{
		hnode r=find_min();
		t=adj[r.vertex];
//		printf("#############%lld###########\n",r.vertex);
		while(t)
		{
			k=t->ver;
		/*	printf("********%lld*******\n",k);
			for(i=1;i<=len;i++)
			{
				printf("%lld:%lld\n",h[i].vertex,h[i].weight);
			}
			printf("-----------------\n");*/
			if(h[a[k]].weight>(r.weight+t->weight))
			{
				update(a[k],r.weight+t->weight);
				d[k]=r.weight+t->weight;
			}
			t=t->next;
			/*for(i=1;i<=len;i++)
			{
				printf("%lld:%lld\n",h[i].vertex,h[i].weight);
			}
			printf("&&&&&&&&&&&&&&&&&&&&&&&\n");*/
		}
		delete_min();
	}
	if(d[v-1]!=INF)
		printf("%lld\n",d[v-1]);
	else
		printf("NO\n");

	return 0;
}
