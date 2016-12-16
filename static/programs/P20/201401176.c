#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int val;
	struct node *next;
}node;
int visited[1000005],maxl,max;
node *a[1000005];
void insert(int x,int y)
{
	node *new,*tmp,*new2;
	if(x==y)
		return;
	if(a[x]==NULL)
	{a[x]=(node*)malloc(sizeof(node));
		a[x]->val=y;
		a[x]->next=NULL;}
	else
	{
		new=(node*)malloc(sizeof(node));
		new->val=y;
		new->next=a[x];
		a[x]=new;
	}
	if(a[y]==NULL){a[y]=(node*)malloc(sizeof(node));a[y]->val=x;
		a[y]->next=NULL;}
	else{new2=(node*)malloc(sizeof(node));
		new2->val=x;
		new2->next=a[y];
		a[y]=new2;
	}
}
void dfs(node *head,int l,int i)
{
	node *temp=head;
	if(l>maxl)
	{
		maxl=l;
		max=i;
	}
	//	printf("len=%d ver=%d\n",maxl,max);
	if(temp==NULL)
		return ;
	visited[i]=1;
	while(temp!=NULL)
	{
		if(visited[temp->val]!=1)
		{
			dfs(a[temp->val],l+1,temp->val);
		}
		temp=temp->next;
	}
}
int main()
{
	int i,j,k;
	int t,n,u,v;
	node *temp;
	scanf("%d",&t);
	while(t--)
	{
		maxl=0;
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			a[i]=NULL;
		for(i=0;i<n-1;i++)
		{
			scanf("%d%d",&u,&v);
			insert(u,v);
		}
		/*for(i=1;i<=n;i++)
		  {
		  printf("%d-> ",i);
		  temp=a[i];
		  while(temp!=NULL)
		  {
		  printf("%d ",temp->val);
		  temp=temp->next;
		  }
		  printf("\n");
		  }*/
		for(i=1;i<=n;i++)
			visited[i]=0;
		dfs(a[1],0,1);
		for(i=1;i<=n;i++)
			visited[i]=0;
		dfs(a[max],0,max);
		if(n==0)
			printf("0\n");
		else
			printf("%d\n",maxl+1);
	}
	return 0;
}
