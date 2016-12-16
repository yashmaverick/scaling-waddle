#include<stddef.h>
#include<stdlib.h>
#include<stdio.h>

struct point
{
	int d;
	struct point *link;
};

int realm,vis[1000004];
struct point * arr1[1000004],*arr2[1000004];

void adj1(int w,int l)
{
	struct point *p;
	p=(struct point *)malloc(sizeof(struct point));
	p->d=l;
	p->link=NULL;
	if(arr1[w]!=NULL)
		p->link=arr1[w];
	arr1[w]=p;
struct point *p1;
p1=(struct point *)malloc(sizeof(struct point));
	p1->d=w;
	p1->link=NULL;
	if(arr2[l]!=NULL)
		p1->link=arr2[l];
	arr2[l]=p1;
}

void dfs(struct point *root,int tag)
{
        while(root!=NULL)
        {
		if(vis[root->d]==0)
		{
			realm++;
			vis[root->d]=1;
			if(tag==0)
				dfs(arr1[root->d],tag);
			else
				dfs(arr2[root->d],tag);
		}
		root=root->link;
	}
}

int main()
{
	int i,t,n,w,l,m;
	scanf("%d",&t);
	struct point *temp;
int k=0;
	while(k<t)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			arr1[i]=NULL;
			arr2[i]=NULL;
		}
		
		for(l=1;l<=n;l++)
		{
			scanf("%d",&m);
			while(m--)
			{
				scanf("%d",&w);
				adj1(w,l);
			}
		}
		m=0;
		int tag=0;
		for(i=1;i<=n;i++)
		{

			for(l=1;l<=n;l++)
				vis[l]=0;
			realm=0;
			temp=(struct point *)malloc(sizeof(struct point));
			temp->d=i;
			temp->link=NULL;
			dfs(temp,tag);
			if(realm==n)
			{
				m=i;
				break;
			}
		
		}

		if(m==0)
			printf("0\n");
		else
		{
		        tag=1;
			for(i=0;i<=n;i++)
				vis[i]=0;
			temp=(struct point *)malloc(sizeof(struct point));
			temp->d=m;
			temp->link=NULL;
			realm=0;
			dfs(temp,tag);
		
			printf("%d\n",realm);

		}
	k++;	
		
	}
	return 0;
}
