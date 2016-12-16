#include<stddef.h>
#include<stdlib.h>
#include<stdio.h>

typedef struct point{
	int d;
	struct point *link;
}point;

int count,vis[1000005];
point * arr1[1000005],*arr2[1000005];


void adj2(int l,int w)
{
	point *p;
	p=(point *)malloc(sizeof(point));
	p->d=w;
	p->link=NULL;
	if(arr2[l]!=NULL)
		p->link=arr2[l];
	arr2[l]=p;
}


void adj1(int w,int l)
{
	point *p;
	p=(point *)malloc(sizeof(point));
	p->d=l;
	p->link=NULL;
	if(arr1[w]!=NULL)
		p->link=arr1[w];
	arr1[w]=p;
}

void dfs(point *root,int demo)
{
        while(root!=NULL)
        {
		if(vis[root->d]==0)
		{
			count++;
			vis[root->d]=1;
			if(demo==0)
				dfs(arr1[root->d],demo);
			else
				dfs(arr2[root->d],demo);
		}
		root=root->link;
	}
}

int main()
{
	int i,test,n,w,l,m;
	scanf("%d",&test);
	point *temp;
	while(test--)
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
				adj2(l,w);
			}
		}
		m=0;
		int demo=0;
		for(i=1;i<=n;i++)
		{

			for(l=1;l<=n;l++)
				vis[l]=0;
			count=0;
			temp=(point *)malloc(sizeof(point));
			temp->d=i;
			temp->link=NULL;
			dfs(temp,demo);
			if(count==n)
			{
				m=i;
				break;
			}
		
		}

		if(m==0)
			printf("0\n");
		else
		{
		        demo=1;
			for(i=0;i<=n;i++)
				vis[i]=0;
			temp=(point *)malloc(sizeof(point));
			temp->d=m;
			temp->link=NULL;
			count=0;
			dfs(temp,demo);
		
			printf("%d\n",count);

		}
		
		
	}
	return 0;
}
