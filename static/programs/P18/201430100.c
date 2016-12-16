#include<stdio.h>
#include<stdlib.h>

int count=0,n,flag=0,h=0;

typedef struct list
{
	int x;
	struct list *next;
}list;

typedef struct list *link;

void travel(int visit[],int ans[],link tree[],int x)
{
	visit[x]=1;

	if(ans[x]==1) {	 flag=n; h=1; return; }

	if(flag==n) { count++; return; }

	link temp=tree[x];

	while(temp!=NULL)
	{
		if(visit[temp->x]==0)
		{
			flag++;
			travel(visit,ans,tree,temp->x);

			if(h==1 && ans[x]==0)
			{
				ans[x]=1;
				count++;
				return;
			}
		}	

		if(flag==n) return;
		temp=temp->next;
	}
}

int main()
{
	int t;
	scanf("%d",&t);

	while(t--)
	{
		count=0;
		int i,flag1=0;
		scanf("%d",&n);

		link tree[n];
		int ans[n];

		for(i=0;i<n;i++) { tree[i]=NULL; ans[i]=0; }

		for(i=0;i<n;i++)
		{
			int m,j;
			scanf("%d",&m);
			if(m==0) flag1=1;
			for(j=0;j<m;j++)
			{
				int x;
				scanf("%d",&x);
				x--;

				link temp;
				temp=malloc(sizeof(list));
				temp->x=i;
				temp->next=tree[x];
				tree[x]=temp;
			}
		}

/*
		for(i=0;i<n;i++)
		{
			printf("%d: ",i+1);
			link temp=tree[i];
			while(temp!=NULL)
			{
				printf("%d ",temp->x+1);
				temp=temp->next;
			}
			printf("\n");
		}
*/
	
		if(flag1==0)
		for(i=0;i<n;i++)
		{
			if(ans[i]==0)
			{
				int j,visit[n],t=count;
				for(j=0;j<n;j++) visit[j]=0;

				flag=1;
				h=0;
				travel(visit,ans,tree,i);

				if(t<count) ans[i]=1;

			}
		}
		else count=1;

		printf("%d\n",count);
	}

	return 0;
}