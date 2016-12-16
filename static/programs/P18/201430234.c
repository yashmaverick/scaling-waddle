#include<stdio.h>
#include<stdlib.h>
int dot=0;
long long int mi=0;
int lev=0;
long long int mu=0;
int fo=0;

struct node{
	int c;
	struct node* next;
};
long long int ma=0;
int count;
long long int mb=0;
struct node* a[1001];
long long int mc=0;

struct node* b[1001];
int d[1001];
long long int md=0;

int f[1001];
long long int me=0;

int visit[1001];
void frontdfs(struct node* x)
{dot++;
	struct node* aid;dot++;dot++;dot++;dot++;dot++;dot++;dot++;dot++;
	aid=x;dot++;
	while(aid!=NULL)
	{dot++;
		if(visit[aid->c]==0)
		{dot++;
			visit[aid->c]=1;dot++;dot++;dot++;dot++;dot++;dot++;dot++;
			frontdfs(b[aid->c]);dot++;dot++;dot++;dot++;dot++;dot++;dot++;dot++;
		}dot++;
		aid=aid->next;dot++;dot++;dot++;dot++;dot++;
	}dot++;
	return;
}
void backdfs(struct node* x)
{dot++;dot++;
	struct node* aid;dot++;dot++;dot++;
	aid=x;dot++;
	while(aid!=NULL)
	{dot++;
		if(visit[aid->c]==0)
		{dot++;
			count++;dot++;dot++;dot++;dot++;dot++;dot++;dot++;
			visit[aid->c]=1;dot++;dot++;dot++;dot++;dot++;dot++;dot++;
			backdfs(a[aid->c]);dot++;dot++;dot++;dot++;dot++;dot++;dot++;
		}dot++;
		aid=aid->next;dot++;
	}
	return;
}
int main()
{dot++;
	struct node* temp;dot++;
	struct node* ans;dot++;
	struct node* help;dot++;
	struct node* var;dot++;
	struct node* fun;dot++;
	int m,n,l,p,o,u,v,k,t,r,y,z;dot++;dot++;dot++;dot++;
	scanf("%d",&t);dot++;
	for(k=0;k<t;k++)
	{dot++;
		for(v=0;v<1001;v++)
		{dot++;
			d[v]=0;dot++;
			b[v]=NULL;dot++;dot++;dot++;dot++;dot++;dot++;
		}dot++;
		for(v=0;v<1001;v++)
		{dot++;
			f[v]=0;dot++;dot++;dot++;dot++;dot++;dot++;
			a[v]=NULL;dot++;dot++;dot++;dot++;dot++;dot++;dot++;
		}dot++;
		scanf("%d",&r);dot++;dot++;dot++;dot++;dot++;dot++;dot++;
		for(m=1;m<=r;m++)
		{dot++;
			scanf("%d",&n);dot++;dot++;dot++;dot++;dot++;dot++;dot++;
			for(l=0;l<n;l++)
			{dot++;dot++;dot++;
				scanf("%d",&p);dot++;dot++;dot++;dot++;
				temp=malloc(sizeof(struct node));dot++;dot++;dot++;dot++;dot++;dot++;
				temp->c=p;dot++;dot++;dot++;dot++;
				temp->next=NULL;dot++;dot++;dot++;dot++;dot++;dot++;
				if(d[m]==0)
				{dot++;
					a[m]=temp;dot++;dot++;dot++;dot++;dot++;dot++;
					d[m]=1;dot++;dot++;dot++;dot++;
				}
				else
				{dot++;
					temp->next=a[m];dot++;dot++;dot++;dot++;dot++;
					a[m]=temp;dot++;dot++;dot++;
				}dot++;dot++;dot++;
				var=malloc(sizeof(struct node));dot++;dot++;dot++;dot++;
				var->c=m;dot++;
				var->next=NULL;dot++;
				if(f[p]==0)
				{dot++;
					b[p]=var;dot++;dot++;dot++;
					f[p]=1;dot++;dot++;dot++;dot++;
				}
				else
				{dot++;
					var->next=b[p];dot++;dot++;dot++;dot++;
					b[p]=var;dot++;dot++;dot++;dot++;
				}
			}
		}//m realms
		for(u=1;u<=r;u++)
		{dot++;
			for(o=0;o<1001;o++)
			{dot++;
				visit[o]=0;dot++;dot++;dot++;dot++;
			}
			visit[u]=1;dot++;
			frontdfs(b[u]);dot++;dot++;dot++;dot++;
			for(o=1;o<=r;o++)
			{dot++;
				if(visit[o]==1)
					continue;
				else
					break;
			}dot++;
			if(o==(r+1))
			{dot++;

				ans=a[u];dot++;dot++;dot++;dot++;
				break;dot++;dot++;dot++;dot++;dot++;
			}
		}
		if(u==r+1)
		{dot++;dot++;
			printf("0\n");dot++;dot++;dot++;dot++;dot++;
			continue;
		}
		for(o=0;o<1001;o++)
		{dot++;
			visit[o]=0;dot++;dot++;dot++;dot++;dot++;dot++;
		}
		visit[u]=1;dot++;
		count=0;dot++;
		backdfs(ans);dot++;
		printf("%d\n",count+1);dot++;dot++;dot++;dot++;dot++;
	}//testcases
	return 0;
}//main

