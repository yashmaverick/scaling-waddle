#include<stdio.h>
#include<stdlib.h>
int mine=0;
int level=0;
int form=0;
struct node{
	int c;
	struct node* next;
};
int count;
struct node* a[1001];
int my=0;
struct node* b[1001];
int fore=0;
int d[1001];
long long int ho=0;
int f[1001];
long long int star=0;
long long int st=0;
int visit[1001];
void frontdfs(struct node* x)
{
	for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}
	struct node* aid;
	aid=x;
	while(aid!=NULL)
	{
		for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}
		if(visit[aid->c]==0)
		{
			for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}
			visit[aid->c]=1;
			frontdfs(b[aid->c]);
		}
		aid=aid->next;
	}
	return;
}
void backdfs(struct node* x)
{
	for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}
	struct node* aid;
	aid=x;
	while(aid!=NULL)
	{
		for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}
		if(visit[aid->c]==0)
		{
			for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}
			count++;
			for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}
			visit[aid->c]=1;
			for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}
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
	for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}
	struct node* help;
	for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}
	struct node* var;
	struct node* fun;
	for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}
	int m,n,l,p,o,u,v,k,t,r,y,z;
	for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}
	scanf("%d",&t);
	for(k=0;k<t;k++)
	{
		for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}
		for(v=0;v<1001;v++)
		{
			for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}
			d[v]=0;
			b[v]=NULL;
		}
		for(v=0;v<1001;v++)
		{

			for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}
			f[v]=0;
			a[v]=NULL;
		}
		scanf("%d",&r);
		for(m=1;m<=r;m++)
		{
			for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}
			scanf("%d",&n);
			for(l=0;l<n;l++)
			{
				for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}
				scanf("%d",&p);
				temp=malloc(sizeof(struct node));
				temp->c=p;
				temp->next=NULL;
				if(d[m]==0)
				{
					for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}
					a[m]=temp;
					d[m]=1;
				}
				else
				{
					for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}
					temp->next=a[m];
					a[m]=temp;
				}
				var=malloc(sizeof(struct node));
				var->c=m;
				var->next=NULL;
				if(f[p]==0)
				{
					for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}
					b[p]=var;
					f[p]=1;
				}
				else
				{
					for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}
					var->next=b[p];
					b[p]=var;
				}
			}
		}//m realms
		for(u=1;u<=r;u++)
		{
			for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}
			for(o=0;o<1001;o++)
			{

				for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}
				visit[o]=0;
			}
			visit[u]=1;
			frontdfs(b[u]);
			for(o=1;o<=r;o++)
			{
				for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}
				if(visit[o]==1)
					continue;
				else
					break;
			}
			if(o==(r+1))
			{
				for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}

				ans=a[u];
				break;
			}
		}
		if(u==r+1)
		{
			for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}
			printf("0\n");
			continue;
		}
		for(o=0;o<1001;o++)
		{
			for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}
			visit[o]=0;
		}
		for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}
		visit[u]=1;
		count=0;
		backdfs(ans);
		for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}
		printf("%d\n",count+1);
	}//testcases
	return 0;
}//main

