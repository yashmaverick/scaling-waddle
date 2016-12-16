#include<stdio.h>
#include<stdlib.h>

int max=0;

typedef struct list
{
	int x;
	struct list *next;
	/* data */
}list;

typedef struct list *link;

int dfs(link tree[],int visit[],int x)
{
	visit[x]=1;
	link temp=tree[x];

	int max1=0,max2=0;

	while(temp!=NULL)
	{
		int t=-1;

		if(visit[temp->x]==0) t=dfs(tree,visit,temp->x);

		if(t>max1) { max2=max1; max1=t; }
		else if(t==max1) { max2=t; }
		else if(t>max2) { max2=t; }

		temp=temp->next;
	}


	if((max1+max2)>max) max=max1+max2;

	return max1+1;
}

int main()
{
	int t;
	scanf("%d",&t);

	while(t--)
	{
		int n,i;
		max=0;
		scanf("%d",&n);

		link tree[n];
		int visit[n];
		for(i=0;i<n;i++) { tree[i]=NULL; visit[i]=0; }

		for(i=0;i<n-1;i++)
		{
			int x,y;
			scanf("%d %d",&x,&y);
			x--;
			y--;

			link temp;
			temp=malloc(sizeof(list));
			temp->x=x;
			temp->next=tree[y];
			tree[y]=temp;

			link temp1;
			temp1=malloc(sizeof(list));
			temp1->x=y;
			temp1->next=tree[x];
			tree[x]=temp1;
		}	

		int p=dfs(tree,visit,0);
		printf("%d\n",max+1);
	}
	return 0;
}