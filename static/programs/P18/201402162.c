#include<stdio.h>
#include<stdlib.h>
typedef struct lashit{
	int val;
	struct lashit* next;
}lashit;
int n;
int flag;
int ans;
int visit[1000000];
int j;
void dfs(lashit **head,int value)
{
	lashit* itr;
	j++;
	itr=head[value];
	visit[value]=1;
	if(j==n)
	{
		ans=1;
		return;
	}
	itr=head[value];
	while(itr!=NULL)
	{
		if(visit[itr->val]==0)
			dfs(head,itr->val);
		itr=itr->next;
	}
}
void rdfs(lashit **head,int value)
{
	lashit *itr;
	ans++;
	itr=head[value];
	visit[value]=1;
	while(itr!=NULL)
	{
		if(visit[itr->val]==0)
			rdfs(head,itr->val);
		itr=itr->next;
	}
}
int main()
{
	int i,t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		lashit* lost[10000];
		lashit* won[10000];
		lashit* itr;
		for(i=1;i<=n;i++)
		{
			lost[i]=NULL;
			won[i]=NULL;
		}
		for(i=1;i<=n;i++)
		{
			int temp,total;
			scanf("%d",&total);
			while(total--)
			{
				scanf("%d",&temp);
				itr=(lashit*)malloc(sizeof(lashit));
				itr->val=temp;
				itr->next=lost[i];
				lost[i]=itr;
				itr=(lashit*)malloc(sizeof(lashit));
				itr->val=i;
				itr->next=won[temp];
				won[temp]=itr;
			}
		}
		flag=0;
		ans=0;
		int k;
		for(i=1;i<=n;i++)
		{
			for(k=1;k<=n;k++)
				visit[k]=0;
			j=0;
			dfs(won,i);
			if(ans>0)
				break;
		}
		if(ans==0)
		{
			printf("0\n");
			continue;
		}
		for(k=1;k<=n;k++)
			visit[k]=0;
		ans=0;
		rdfs(lost,i);
		printf("%d\n",ans);
	}
	return 0;
}
