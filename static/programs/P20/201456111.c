#include<stdio.h>
#include<stdlib.h>
struct node{
	int c;
	struct node* next;
};
int count;
struct node* ans;
struct node* a[1000001];
int  visit[1000001];
void dfs(struct node* x,int r)
{
	r++;
	if(r>count)
	{
		count=r;
		ans=x;
	}
	struct node* help;
	help=x;
	while(help!=NULL)
	{
		if(visit[help->c]==0)
		{
			visit[help->c]=1;
		dfs(a[help->c],r);
		}
		help=help->next;
	}
	return;

}
int main()
{
	int t,l,k,m,x,y,n;
	scanf("%d",&t);
	for(l=0;l<t;l++)
	{
		count=0;
		scanf("%d",&n);
		for(m=0;m<=1000001;m++)
		{
			visit[m]=0;
			a[m]=NULL;
		}
		for(k=1;k<n;k++)
		{
			scanf("%d",&x);
			scanf("%d",&y);
			struct node* temp;
			struct node* var;
			temp=malloc(sizeof(struct node));
			var=malloc(sizeof(struct node));
			temp->c=y;
			temp->next=NULL;
			if(a[x]==NULL)
			{
				a[x]=temp;
			}
			else
			{
				temp->next=a[x];
				a[x]=temp;

			}
			var->c=x;
			var->next=NULL;
			if(a[y]==NULL)
			{
				a[y]=var;

			}
			else
			{
				var->next=a[y];
				a[y]=var;
			}

		}
		dfs(a[1],0);
		for(m=0;m<=1000001;m++)
		{
			visit[m]=0;
		}
		dfs(ans,0);
		printf("%d\n",count);

		
	}
	return 0;
}
