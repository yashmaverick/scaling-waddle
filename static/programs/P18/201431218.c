#include<stdio.h>
#include<stdlib.h>
struct node
{
	struct node *next;
	int vertex;
};
struct node* A[1008];
struct node* B[1008];
int visited[1008];
int max,maxvertex,count;
void dfs(int,int);
void insert(int,int,int);
int main()
{
	int i,n,j;
	int a,b;
	int test;
	scanf("%d",&test);
	while(test)
	{
		scanf("%d",&n);
		for(i=0;i<=n;B[i]=NULL,A[i++]=NULL);
		for(i=0;i<n;i++)
		{
			scanf("%d",&j);
			while(j--)
			{
				scanf("%d",&a);
				a--;
				insert(a,i,0);
				insert(i,a,1);
			}
		}
		for(i=0;i<n;i++){
			count=0;
			for(j=0;j<n;j++)
				visited[j]=0;
			dfs(i,0);
			if(count==n)
				break;
		}
		if(i==n)
			printf("0\n");
		else{
			count=0;
			for(j=0;j<n;j++)
				visited[j]=0;
			dfs(i,1);
			printf("%d\n",count);
		}
		test--;
	}
	
	return 0;
}
void insert(int a,int b,int f)
{
	struct node *m,*n;
	n=(struct node*)malloc(sizeof(struct node));
	n->vertex=b;
	if(f==0){
		n->next=A[a];
		A[a]=n;
	}
	else{
		n->next=B[a];
		B[a]=n;
	}
}
void dfs(int i,int f)
{
	struct node *m;
	if(f==0)
		m=A[i];
	else
		m=B[i];
	count++;
	//printf("%d\n",i);
	visited[i]=1;
	while(m!=NULL)
	{
		i=m->vertex;
		if(!visited[i])
			dfs(i,f);
		m=m->next;
	}
}
