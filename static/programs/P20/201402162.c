#include<stdio.h>
#include<stdlib.h>
typedef struct lashit{
	int val;
	struct lashit* next;
}lashit;
int visit[1000009];
int point=0,maxum=0;
int dfs(lashit **head,int value)
{
	int height=1,max=0,k;
	lashit* itr;
	itr=head[value];
	while(itr!=NULL)
	{
		if(visit[itr->val]==0)
		{
			visit[itr->val]=1;
			k=dfs(head,itr->val);
			if(k>max)
				max=k;
		}
		itr=itr->next;
	}
	height+=max;
	return height;
}
void node(lashit **head,int value,int height)
{
	lashit *itr;
	itr=head[value];
	height++;
	int flag=0;
	while(itr!=NULL)
	{
		if(visit[itr->val]==0)
		{
			visit[itr->val]=1;
			node(head,itr->val,height);
			flag=1;
		}
		itr=itr->next;
	}
	if(flag==0)
	{
		if(height>maxum)
		{
			maxum=height;
			point=value;
		}
	}
}
int main()
{
	int t,n,i;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		lashit* head[n+1];
		lashit* itr;
		for(i=1;i<=n;i++)
		{
			head[i]=NULL;
			visit[i]=0;
		}
		for(i=1;i<n;i++)
		{
			int start,end;
			scanf("%d%d",&start,&end);
			itr=(lashit*)malloc(sizeof(lashit));
			itr->val=end;
			itr->next=head[start];
			head[start]=itr;
			itr=(lashit*)malloc(sizeof(lashit));
			itr->val=start;
			itr->next=head[end];
			head[end]=itr;
		}
		int height;
		point=0;
		maxum=0;
		visit[1]=1;
		node(head,1,0);
		for(i=1;i<=n;i++)
			visit[i]=0;
		visit[point]=1;
		height=dfs(head,point);
		printf("%d\n",height);
	}
	return 0;
}
