#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>

typedef struct point{
	struct point *next;
	int d;
}point;

int max=0,vis[1000005],r,count;
point * q[1000005];


void path(point *head)
{
        while(head!=NULL)
        {
		if(vis[head->d]==0)
		{
			count++;
			if(count>max)
			{
				max=count;
				r=head->d;
			}
			vis[head->d]=1;
			path(q[head->d]);
		}
		head=head->next;
	}
	count--;
}

void dfs(int x,int y)
{
	point *p;
	p=(point *)malloc(sizeof(point));
	p->d=y;
	p->next=NULL;
	if(q[x]!=NULL)
		p->next=q[x];
	q[x]=p;

	p=(point *)malloc(sizeof(point));
	p->d=x;
	p->next=NULL;
	if(q[y]!=NULL)
		p->next=q[y];
	q[y]=p;
}


int main()
{
	int i,test,n,x,y,f;
	scanf("%d",&test);
	point *temp;
	while(test--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			q[i]=NULL;
		if((n==0)||(n==1))
			printf("%d\n",n);
		else
		{
		for(i=1;i<n;i++)
		{
			scanf("%d %d",&x,&y);
			dfs(x,y);
		}
		for(i=1;i<=n;i++)
			vis[i]=0;
		temp=(point *)malloc(sizeof(point));
		temp->d=x;
		temp->next=NULL;
		max=0;
		count=0;
		path(temp);
		for(i=0;i<=n;i++)
			vis[i]=0;
		temp=(point *)malloc(sizeof(point));
		temp->d=r;
		temp->next=NULL;
		max=0;
		count=0;
		path(temp);
		printf("%d\n",max);
		}
		
	}
	return 0;
}
