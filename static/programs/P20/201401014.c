#include<stdio.h>
#include<stdlib.h>
struct node
{
	long long int data;
	struct node *next;
};
typedef struct node node;
node *A[1000010];
void adj_list(long long int vi,long long int vj)
{
	node *temp;
	temp=(node *)malloc(sizeof(node));
	temp->data=vj;
	temp->next=NULL;
	if(A[vi]==NULL)
		A[vi]=temp;
	else
	{
		temp->next=A[vi];
		A[vi]=temp;
	}
}

void print(int i)
{
	node *pointer,*curr;
	if(A[i]==NULL)
		return;
	else
	{
		pointer=A[i];
		curr=A[i];
		while(pointer!=NULL)
		{
			curr=pointer;
			pointer=pointer->next;
			curr=NULL;
		}
		pointer=NULL;
	}
}


long long int visited[1000010],pathlen[1000010],max_depth,vertex,len,front;
void dfs(long long int v,long long int depth)
{
//	printf("%lld -->max\n",max_depth);
	node *curr;
	visited[v]=1;
	curr=A[v];
	if(max_depth<depth)
	{
		max_depth=depth;
		vertex=v;
	}
	while(curr!=NULL)
	{
		len=0;
		if(visited[curr->data]==0)
		{	
			len++;
			dfs(curr->data,depth+1);
		}
			curr=curr->next;
	}
}
int main()
{
	long long int n,m,vi,vj,i,a,b,t,k,index;
	scanf("%lld",&t);
	while(t--)
	{
		for(i=0;i<1000010;i++)
		{
			visited[i]=0;
			pathlen[i]=0;
		}
		scanf("%lld",&n);
		max_depth=0;
		if(n!=1)
		{for(i=0;i<1000010;i++)
			A[i]=NULL;
		for(i=0;i<n-1;i++)
		{
			scanf("%lld%lld",&vi,&vj);
			adj_list(vi,vj);
			adj_list(vj,vi);
		}
		vertex=1;
		dfs(1,0);
		a=vertex;
		for(i=0;i<=n;i++)
			visited[i]=0;
		dfs(a,0);
		printf("%lld\n",max_depth+1);
		}
		else
			printf("1\n");
		for(i=0;i<1000010;i++)
			A[i]=NULL;
	//	for(index=1;index<=n;index++)
	//		print(index);
	}
	return 0;
}
