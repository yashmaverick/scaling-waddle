#include<stdio.h>
#include<stdlib.h>
int visited[1000007],n,count=0,depth=-1,maxel;
struct node
{
	int data;
	struct node* next;
};
struct node*a[1000007];
void  insert(int i,int j)
{
	struct node* p;
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->data=j;
	temp->next=NULL;
	if(a[i]==NULL)
		a[i]=temp;
	else
	{
		p=a[i];
		while(p->next!=NULL)
			p=p->next;
		p->next=temp;

	}

}
void dfs(int i)
{
	count++;
	if(count>depth)
	{
		depth=count;
		maxel=a[i]->data;
	}
	//	printf("hello ");
	//	count++;
	struct node* p;
	//	printf("%d ",i);
	p=a[i];
	visited[i]=1;
	while(p!=NULL)
	{
		i=p->data;
		if(visited[i]!=1)
		{
			dfs(i);
			count--;
		}
		p=p->next;
	}
	return;
}


int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		depth=-1;
		int i,j,p;
		scanf("%d",&n);
		int k;
		/*for(k=1;k<=n;i++)
		  {
		  visited[k]=0;
		  a[k]=(struct node*)malloc(sizeof(struct node));
		  a[k]->data=k;
		  a[k]->next=NULL;
		  }*/
		k=n-1;
		while(k--)
		{
			scanf("%d%d",&i,&j);
			insert(i,j);
			insert(j,i);
		}
		dfs(j);
		count=0;
		depth=-1;
		for(k=1;k<=n;k++)
		{
			visited[k]=0;
		}
		dfs(maxel);
		count=0;
		for(k=1;k<1000007;k++)
		{
			visited[k]=0;
		}
		printf("%d\n",depth+1);
		depth=-1;
		for(i=0;i<1000007;i++)
		{
			a[i]=NULL;
		}
	}
	return 0;
}
