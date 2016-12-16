#include<stdio.h>
#include<stdlib.h>
typedef struct adj{
	int val;
	struct adj *next;
}adj;
int visited[10000]={0},count=0,m,n,V[10000]={0};
adj *A[10000];
adj *B[10000];
void insert(int i,int a)
{
	adj *temp;
	temp=(adj*)malloc(sizeof(adj));
	temp->val=a;
	temp->next=A[i];
	A[i]=temp;
}
void insert1(int i,int a)
{
	adj *temp;
	temp=(adj*)malloc(sizeof(adj));
	temp->val=a;
	temp->next=B[i];
	B[i]=temp;
}
void dfs(int src)
{
	if(visited[src]==1)
		return ;
	visited[src]=1;
//	printf("%d-->",src);
	adj *temp=A[src];
	count++;
	if(temp==NULL)
		return ;
	while(temp!=NULL)
	{
		if(visited[temp->val]!=1)
			dfs(temp->val);
		temp=temp->next;
	}
}
void rdfs(int src)
{
//	if(visited[src]==1)
//		return ;
	visited[src]=1;
//	printf("%d-->",src);
	adj *temp=B[src];
	count++;
//	if(temp==NULL)
//		return ;
	while(temp!=NULL)
	{
		if(visited[temp->val]!=1)
			rdfs(temp->val);
		temp=temp->next;
	}
}
int main()
{
	int t,i,j,k,q,ans=0,m,v,u,flag;
	adj *temp;
	scanf("%d",&t);
	for(u=0;u<t;u++)
	{
		scanf("%d",&n);
		flag=0;
//		ans=0;
		count=0;
		for(k=1;k<=1000;k++)
		{
			visited[k]=0;
			V[k]=0;
		}
		for(j=1;j<=1000;j++)
		{
			B[j]=NULL;
			A[j]=NULL;
		}

		for(i=1;i<=n;i++)
		{
			scanf("%d",&m);
			for(j=1;j<=m;j++)
			{
				scanf("%d",&v);
				insert(v,i);
				insert1(i,v);
			}
		}
//		ans=0;
/*		for(q=1;q<=n;q++)
		{
			temp=B[q];
			printf("%d: ",q);
			while(temp!=NULL)
			{
//				printf("%d-->",temp->val);
				temp=temp->next;
			}
			printf("\n");
		}
		{
			temp=B[q];
			printf("%d: ",q);
			while(temp!=NULL)
			{
				printf("%d-->",temp->val);
				temp=temp->next;
			}
			printf("\n");
		}*/
		for(j=1;j<=n;j++)
		{
	//		printf("dfs\n");
			dfs(j);
	//		printf("num: %d count: %d\n",j,count);
			if(count==n)
			{
//				ans=0;
//				count=0;
				for(k=1;k<=n;k++)
					visited[k]=0;
				count=0;
				rdfs(j);
	//			printf("\ncount: %d\n",count);
//				ans=count;
//				count=0;
				flag=1;
				printf("%d\n",count);
				break;
			}
			count=0;
			for(k=1;k<=n;k++)
				visited[k]=0;
		}
		if(flag!=1)
			printf("0\n");
//		printf("%d\n",ans);
//		ans=0;
//		count=0;
		}
	return 0;
}
