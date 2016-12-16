#include <stdio.h>
#include <stdlib.h>


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

void dfs(struct node* x, int lasya)
{
	struct node* abc;
	abc=x;
	while(abc!=NULL)
	{
		if(visit[abc->c]==0)
		{
			if(lasya==0)
			{
				visit[abc->c]=1;
				dfs( b[abc->c], 0);
			}
			else if (lasya==1)
			{
				count++;
				visit[abc->c]=1;
				dfs( a[abc->c], 1);
			}

		}
		abc=abc->next;
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
	int m; 
int n;
 int l;
 int p;
 int o; 
int u;
 int v;
 int k;
 int t;
 int r;
 int y;
 int z;
 int tra;
	scanf("%d",&t);
	while(t--)
	{
		
		scanf("%d",&r);
		for(m=1;m<=r;m++)
		{
			scanf("%d",&n);
			while(n--)
			{
				scanf("%d",&p);
				temp=malloc(sizeof(struct node));
				temp->c=p;
				temp->next=NULL;
				tra = tra+tra;
				if(d[m]==0)
				{
					a[m]=temp;
					d[m]=1;
					tra = tra+1;
				}
				else
				{
					temp->next=a[m];
					a[m]=temp;
					tra = tra-1;
				}
				var=malloc(sizeof(struct node));
				var->c=m;
				var->next=NULL;
				if(f[p]==0)
				{
					b[p]=var;
					tra=tra+1;
					f[p]=1;
					tra = tra+1;
				}
				else
				{
					var->next=b[p];
					tra=tra+1;
					b[p]=var;
					tra=tra-1;
				}
			}
		}//m realms
		for(u=1;u<=r;u++)
		{
			tra=tra+1;
			for(o=0;o<1001;o++)
			{
				tra=tra+1;
				visit[o]=0;
			}
			visit[u]=1;
			tra=tra+1;
			dfs(b[u], 0);
			for(o=1;o<=r;o++)
			{
				if(visit[o]==1)
				{
					tra=tra+1;
					continue;
				}
				else
				{
					tra=tra+1;
					break;
				}
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
			tra=tra+1;
			continue;
		}
		for(o=0;o<1001;o++)
		{
			visit[o]=0;
		}
		visit[u]=1;
		count=0;
		dfs(ans,1);
		printf("%d\n",count+1);
		for(v=0;v<1001;v++)
		{
			tra=tra+1;
			d[v]=0;
			b[v]=NULL;
			f[v]=0;
			a[v]=NULL;
		}
	}//testcases
	return 0;
}//main

