#include<stdio.h>
#include<stdlib.h>

typedef struct adj{
	int val;
	struct adj *link;
}adj;
int maxheight=0,element;

adj *list[1000006];
int visited[1000006];
void dfs(int i,int visited[],int h,adj* list[])
{
	h++;
	if(h>maxheight)
	{

		maxheight=h;
		element=i;
	}
	//printf("at %d the level is%d\n",i,h);
	int flag=0;
	adj *temp=list[i];
	visited[i]=1;
	while(temp!=NULL)
	{
		i=temp->val;
		if(!visited[i])
		{
			dfs(i,visited,h,list);
			
		}
		//if(flag==1)
		//	h--;
		
		temp=temp->link;
		
	}
}
int main()
{
	int m,n,i,v2,v1;
	maxheight=0;
	scanf("%d",&m);
	while(m)
	{
		maxheight=0;
		scanf("%d",&n);
		//adj *list[1000006];
		//int visited[1000006];
		for(i=1;i<=n;i++)
			visited[i]=0;
		for(i=1;i<=n;i++)
		{
			list[i]=(adj*)malloc(sizeof(adj));
			list[i]=NULL;
		}
		adj *temp1,*temp2;

		for(i=1;i<n;i++)
		{
			scanf("%d %d",&v1,&v2);
			temp1=(adj*)malloc(sizeof(adj));
			temp2=(adj*)malloc(sizeof(adj));
			temp1->val=v2;
			temp1->link=list[v1];
			list[v1]=temp1;
			temp2->val=v1;
			temp2->link=list[v2];
			list[v2]=temp2;
		}
		dfs(1,visited,0,list);
		//printf("%d %d\n",element,maxheight);
		for(i=1;i<=n;i++)
			visited[i]=0;
		maxheight=0;
		dfs(element,visited,0,list);
		printf("%d\n",maxheight);
		m--;
	}
	
	return 0;

}
