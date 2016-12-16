#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
int max(int a,int b)
{	
if(a>b)
	return a;
	else
	return b;
	}
struct node
{
	int v;
	struct node* next;
};
struct node *a[1000000];
void insert(int i,int j)
{
	struct node* n=(struct node*)malloc(sizeof(struct node));
	n->next=a[i];
	n->v=j;
	a[i]=n;
	return;
}
int visited[1000000];
//int count=0;
int d[1000000];

void dfs( int i)
{
		struct node* temp;
		temp=a[i];
		visited[i]=1;
	//	count++;

		while(temp!=NULL)
		{
		int j;
			j=temp->v;
		if(visited[j]!=1)
		{
			d[j]=d[i]+1;
			dfs(j);
		}
		temp=temp->next;
	}

}
/*	int  dfs(int i)
{
	int s,b=-1,c=-1;
	visited[i]=1;
	struct node *tmp=a[i];
	while(tmp!=NULL)
	{
		if(!visited[tmp->v])
		{
			s=dfs(tmp->v);
			if(s>=b)
			{
				c=b;
				b=s;
			}
			else if(s>c)
				c=s;			
		}
		tmp=tmp->next;	
	}
	count=max(count,b+c+2);
	return (b+1);
}*/

int main()
{
	int tc,n,u,v;
	scanf("%d",&tc);
	while(tc--)
	{
		
//		count=0;
		scanf("%d",&n);
		int i;
		for(i=1;i<=n;i++)
			a[i]=NULL;
		for(i=0;i<n-1;i++)
		{
			scanf("%d %d",&u,&v);
			insert(u,v);
			insert(v,u);
		}
		for(i=1;i<=n;i++)
			visited[i]=0;
		for(i=1;i<=n;i++)
			d[i]=0;
		dfs(1);
		for(i=1;i<=n;i++)
			visited[i]=0;
		 int temp=INT_MIN;int index;
		for(i=1;i<=n;i++)
		{
			if(d[i]>temp)
			{
				temp=d[i];
				index=i;
			}
		}
		d[index]=0;
		dfs(index);
		for(i=1;i<=n;i++)
		{
			if(d[i]>temp)
			{
				temp=d[i];
				index=i;
			}
		}
			printf("%d\n",temp+1);
	}
	return 0;
}
