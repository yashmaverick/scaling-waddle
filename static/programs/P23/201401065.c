#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define ull unsigned long long

typedef struct adlist
{
	ull data;
	struct adlist *next;
} node;

node* ig(node *g,ull v)
{
	node *t;
	t=(node *)malloc(sizeof(node));
	t->data=v;
	t->next=g;
	return t;
}

void swap(ull *a,ull *b)
{
	ull t=*a;
	*a=*b;
	*b=t;
}

ull leaf=1;

void ih(ull h[],ull v)
{
	h[leaf]=v;
	ull l;
	l=leaf;
	while((l/2)>=1)
	{
		if(h[l/2]>h[l])
		{
			swap(&h[l/2],&h[l]);
			l=l/2;
		}
		else
			break;
	}
	leaf++;
}

ull rmin(ull h[])
{
	ull k,l;
	k=h[1];
	h[1]=h[leaf-1];
	l=1;leaf--;
	while(l<leaf)
	{
		if((2*l+1)<leaf)
		{
			ull p,q;
			p=(h[2*l+1]>h[2*l])?h[2*l]:h[2*l+1];
			q=(h[2*l+1]>h[2*l])?(2*l):(2*l+1);
			if(h[l]>p)
			{
				swap(&h[l],&h[q]);
				l=q;
				continue;
			}
		}
		else if(2*l<leaf)
		{
			if(h[l]>h[2*l])
			{
				swap(&h[l],&h[2*l]);
				l=2*l;
				continue;
			}
		}
		break;
	}
	return k;
}

void print(ull h[])
{
	ull l,p=1;
	for(l=1;l<leaf;l++)
	{
		if(l%p==0)
		{
			printf("\n");
			p*=2;
		}
		printf("%llu ",h[l]);
	}
	printf("\n");
}

int main()
{
	ull n,m,i,u,v,*dc;
	scanf("%llu %llu",&n,&m);
	node **list;list=(node **)calloc(n+1,sizeof(node *));
	dc=(ull *)calloc(n+1,sizeof(ull));
	for(i=0;i<=n;i++)
	{list[i]=NULL;dc[i]=0;}
	for(i=0;i<m;i++)
	{
		scanf("%llu %llu",&u,&v);
		list[u]=ig(list[u],v);
		dc[v]++;
	}
	ull *h,k,*o,t=1;
	h=(ull *)calloc(n+3,sizeof(ull));
	o=(ull *)calloc(n+3,sizeof(ull));
	for(i=1;i<=n;i++)
		if(dc[i]==0)
			ih(h,i);
	while(leaf>1)
	{
		k=rmin(h);
		o[t++]=k;
		node *l;l=list[k];
		while(l!=NULL)
		{
			dc[l->data]--;
			if(dc[l->data]==0)
				ih(h,l->data);
			l=l->next;
		}
//		print(h);
//		if(k==5)
//			return 0;
	}
	for(i=1;i<=n;i++)
	{
		printf("%llu",o[i]);
		if(i!=n)
			printf(" ");
	}
	printf("\n");
	return 0;
}
