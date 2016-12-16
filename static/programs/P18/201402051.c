#include<stdio.h>
#include<stdlib.h>
int dot=0;
int lev=0;
int fo=0;
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
	dot++;
lev++;
fo--;
	struct node* aid;
	dot++;
lev++;
fo--;
	aid=x;
	dot++;
lev++;
fo--;
	while(aid!=NULL)
	{
		dot++;
lev++;
fo--;
		if(visit[aid->c]==0)
		{
			dot++;
			visit[aid->c]=1;dot++;
			frontdfs(b[aid->c]);dot++;
		}dot++;
		aid=aid->next;dot++;
	}
	return;dot++;
}
void backdfs(struct node* x)
{dot++;
	struct node* aid;dot++;
	aid=x;dot++;
	while(aid!=NULL)
	{dot++;
		if(visit[aid->c]==0)
		{dot++;
			count++;dot++;
			visit[aid->c]=1;dot++;
			backdfs(a[aid->c]);dot++;
		}dot++;
		aid=aid->next;dot++;
	}
	return;dot++;
}
int main()
{
	struct node* temp;dot++;
	struct node* ans;dot++;
	struct node* help;dot++;
	struct node* var;
	struct node* fun;dot++;
	int m,n,l,p,o,u,v,k,t,r,y,z;dot++;
	scanf("%d",&t);dot++;
	for(k=0;k<t;k++)
	{lev++;
		for(v=0;v<1001;v++)
		{lev++;
			d[v]=0;lev++;
			b[v]=NULL;lev++;
		}
		for(v=0;v<1001;v++)
		{lev++;
			f[v]=0;lev++;
			a[v]=NULL;lev++;
		}lev++;
		scanf("%d",&r);lev++;
		for(m=1;m<=r;m++)
		{lev++;
			scanf("%d",&n);lev++;
			for(l=0;l<n;l++)
			{lev++;
				scanf("%d",&p);lev++;
				temp=malloc(sizeof(struct node));lev++;
				temp->c=p;lev++;
				temp->next=NULL;lev++;
				if(d[m]==0)
				{lev++;
					a[m]=temp;lev++;
					d[m]=1;lev++;
				}
				else
				{
					temp->next=a[m];lev++;
					a[m]=temp;lev++;
				}lev++;
				var=malloc(sizeof(struct node));lev++;
				var->c=m;lev++;
				var->next=NULL;lev++;lev++;
				if(f[p]==0)
				{lev++;
					b[p]=var;
					f[p]=1;lev++;
				}
				else
				{
					var->next=b[p];lev++;
					b[p]=var;lev++;
				}lev++;
			}
		}//m realms
		for(u=1;u<=r;u++)
		{lev++;
			for(o=0;o<1001;o++)
			{lev++;
				visit[o]=0;lev++;
			}
			visit[u]=1;lev++;
			frontdfs(b[u]);lev++;
			for(o=1;o<=r;o++)
			{lev++;
				if(visit[o]==1)
					continue;
				else
					break;
			}
			if(o==(r+1))
			{lev++;

				ans=a[u];lev++;
				break;
			}lev++;
		}
		if(u==r+1)
		{lev++;
			printf("0\n");lev++;
			continue;lev++;
		}
		for(o=0;o<1001;o++)
		{lev++;
			visit[o]=0;lev++;
		}
		visit[u]=1;lev++;
		count=0;lev++;
		backdfs(ans);lev++;
		printf("%d\n",count+1);lev++;
	}//testcases
	lev++;
	return 0;
}//main

