#include<stdio.h>
#include<stdlib.h>
struct node{
	int c;
	struct node* next;
};
int count;
struct node* a[1001];
struct node* b[1001];
int d[1001];
int f[1001];
int visit[1001];
void frontdfs(struct node* x)
{
	struct node* aid;
	aid=x;
	while(aid!=NULL)
	{
		if(visit[aid->c]==0)
		{
			visit[aid->c]=1;
			frontdfs(b[aid->c]);
		}
		aid=aid->next;
	}
	return;
}
void backdfs(struct node* x)
{
	struct node* aid;
	aid=x;
	while(aid!=NULL)
	{
		if(visit[aid->c]==0)
		{
			count++;
			visit[aid->c]=1;
			backdfs(a[aid->c]);
		}
		aid=aid->next;
	}
	return;
}
int main()
{
	struct node* temp;
	struct node* ans;
	struct node* help;
	struct node* var;
	struct node* fun;
	int m,n,l,p,o,u,v,k,t,r,y,z;
	scanf("%d",&t);
	for(k=0;k<t;k++)
	{
		for(v=0;v<1001;v++)
		{
			d[v]=0;
			b[v]=NULL;
		}
		for(v=0;v<1001;v++)
		{
			f[v]=0;
			a[v]=NULL;
		}
		scanf("%d",&r);
		for(m=1;m<=r;m++)
		{
			scanf("%d",&n);
			for(l=0;l<n;l++)
			{
				scanf("%d",&p);
				temp=malloc(sizeof(struct node));
				temp->c=p;
				temp->next=NULL;
				if(d[m]==0)
				{
					a[m]=temp;
					d[m]=1;
				}
				else
				{
					temp->next=a[m];
					a[m]=temp;
				}
				var=malloc(sizeof(struct node));
				var->c=m;
				var->next=NULL;
				if(f[p]==0)
				{
					b[p]=var;
					f[p]=1;
				}
				else
				{
					var->next=b[p];
					b[p]=var;
				}
			}
		}//m realms
		for(u=1;u<=r;u++)
		{
			for(o=0;o<1001;o++)
			{
				visit[o]=0;
			}
			visit[u]=1;
			frontdfs(b[u]);
			for(o=1;o<=r;o++)
			{
				if(visit[o]==1)
					continue;
				else
					break;
			}
			if(o==(r+1))
			{

				ans=a[u];
				break;
			}
		}
		if(u==r+1)
		{
			printf("0\n");
			continue;
		}
		for(o=0;o<1001;o++)
		{
			visit[o]=0;
		}
		visit[u]=1;
		count=0;
		backdfs(ans);
		printf("%d\n",count+1);
	}//testcases
	return 0;
}//main

