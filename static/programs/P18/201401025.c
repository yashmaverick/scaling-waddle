#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int v;
	struct node* next;
}node;

node* strong[10003];
node* weak[10003];

int visited[10003];

node * insert(int v,node * root)
{
	node *temp=(node *)malloc(sizeof(node));
	temp->v=v;
	temp->next=root;
	return temp;
}

int stack[10006],top=0,start=0;

int dfs(int u,node *arr[],int n)
{
	int ans=0;
	int i;
	stack[top]=u;
	visited[u]=1;
	top++;
	node* tmp;

	while(top!=start)
	{
		int temp=stack[top-1];
		//		printf("stack%d ",temp);
		top--;
		tmp=arr[temp];
		while(tmp!=NULL)
		{
			if(visited[tmp->v]!=1)
			{
				stack[top]=tmp->v;
				top++;
				visited[tmp->v]=1;
			}
			tmp=tmp->next;
		}
	}
	for(i=1;i<=n;i++)
		if(visited[i])
			ans++;
	return ans;
}

//int check[10003];

int main()
{
	int n,i,j,m,a,temp,t,flag;
	scanf("%d",&t);
	while(t>0)
	{
		flag=1;
		t--;
		//cin>>n;
		scanf("%d",&n);
		for(j=0;j<n;j++)
		{
			scanf("%d",&m);
			for(i=0;i<m;i++)
			{
				scanf("%d",&a);
				weak[a]=insert(j+1,weak[a]);
				strong[j+1]=insert(a,strong[j+1]);
			}
		}
		int val;
		for(i=1;i<=n;i++)
		{
			temp=dfs(i,weak,n);
			//		printf("iii%d    temp%d\n",i,temp);

			if(temp==n)
			{
				val=i;
				break;
			}

			for(j=1;j<=n;j++)
				visited[j]=0;
			top=start=0;
		}

		if(i>n)
			printf("0\n");
		else
		{

			for(j=1;j<=n;j++)
				visited[j]=0;
			top=start=0;

			//	cout<<endl<<endl;

			/*	for(i=0;i<n;i++)
				{
				cout<<i+1<<"->";
				print(weak[i+1]);
				cout<<endl;
				}*/
			temp=dfs(val,strong,n);
			printf("%d\n",temp);
		}
		for(j=1;j<=n;j++)
			visited[j]=0;
		top=start=0;

		for(i=1;i<=n;i++)
		{
			if(strong[i]!=NULL)
			while(strong[i]->next!=NULL)
			{
				strong[i]->next=strong[i]->next->next;
				strong[i]->next=NULL;
			}
			strong[i]=NULL;
		}

		for(i=1;i<=n;i++)
		{
			if(weak[i]!=NULL)
				while(weak[i]->next!=NULL)
				{
					weak[i]->next=weak[i]->next->next;
					weak[i]->next=NULL;
				}
			weak[i]=NULL;
		}

	}
	return 0;
}
