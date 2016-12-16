#include<stdio.h>
#include<stdlib.h>
typedef struct adj{
	int val;
	struct adj *link;
}adj;
adj *list1[1006],*list2[1006];
int visited[1006];
void dfs(int i , int visited[],adj *list[])
{
	adj*temp;
	temp=list[i];
	visited[i]=1;
	while(temp!=NULL)
	{
		i=temp->val;
		if(!visited[i])
		{
			dfs(i,visited,list);
		}
		temp=temp->link;
	}
}
int main()
{
	int t,n,h,k,i,j;
	scanf("%d",&t);
	while(t--)
	{
		int count=0,element,flag;
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			list1[i]=(adj*)malloc(sizeof(adj));
			list2[i]=(adj*)malloc(sizeof(adj));
			list1[i]=NULL;
			list2[i]=NULL;
	
		}
		//adj *temp=(adj*)malloc(sizeof(adj));
		for(i=1;i<=n;i++)
		{
			scanf("%d",&h);
			for(j=0;j<h;j++)
			{
				adj *temp1=(adj*)malloc(sizeof(adj));
				adj *temp2=(adj*)malloc(sizeof(adj));
				scanf("%d",&k);
				temp1->val=i;
				temp1->link=list1[k];
				list1[k]=temp1;
				temp2->val=k;
				temp2->link=list2[i];
				list2[i]=temp2;
			}
		}
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
				visited[j]=0;
			dfs(i,visited,list1);
			flag=0;
			for(j=1;j<=n;j++)
			{
				if(visited[j]!=1)
				{
					flag=1;
					break;
				}
			}
			if(flag==0)
			{
				element=i;
				break;
			}
		}
		//printf("%d\n",element);
		for(i=1;i<=n;i++)
			visited[i]=0;
		dfs(element,visited,list2);
		for(i=1;i<=n;i++)
			if(visited[i]==1)
				count++;
		printf("%d\n",count);
		
	}
	return 0;
}
