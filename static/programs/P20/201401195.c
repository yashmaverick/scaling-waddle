#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *next;
}node;
node *a[1000000];
int start=0,last=0;
void push(int val,int q[])
{
	q[last]=val;
	(last)++;
}
int pop(int q[])
{
	if(last==0)
		return -1;
	else
	{
		last--;
		return q[last];
	}
}
int top(int q[])
{
	if(last==0)
		return -1;
	else
		return q[last-1];
}
void fre(int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		node *p=a[i],*r=a[i];
		a[i]=NULL;
		while(p!=NULL)
		{
			r=p;
			p=p->next;
			free(r);
			//r=NULL;

		}
	}
}
void insert(int x,int y)
{
	node *i=(node*)malloc(sizeof(node));
	i->next=NULL;
	i->data=y;
	node *j=(node*)malloc(sizeof(node));
	j->next=NULL;
	j->data=x;
	node *temp;
	if(a[x]==NULL)
		a[x]=i;
	else if(a[x]!=NULL)
	{
		temp=a[x]->next;
		a[x]->next=i;
		i->next=temp;
	}
	if(x!=y)
	{
		if(a[y]==NULL)
			a[y]=j;
		else if(a[y]!=NULL)
		{
			temp=a[y]->next;
			a[y]->next=j;
			j->next=temp;
		}
	}
}
void dfs(int x,int visited[],int dis[],int q[])
{
	node *p=a[x];
	int d;
	while(p!=NULL)
		
	{      	
	//	printf("%d",p->data);
		 if(visited[p->data]!=1)
		{
			push(p->data,q);
			dis[p->data]=dis[x]+1;
	       		visited[p->data]=1;
		}
		p=p->next;
	}
	if(top(q)!=-1)
	{
		d=pop(q);
		dfs(d,visited,dis,q);
	}
}
int main()
{
	int t,d;
	scanf("%d",&d);
	for(t=0;t<d;t++)
	{

		int n,i,x,y,p,g,max=0;
		scanf("%d",&n);
		if(n!=0){
			//		int dis[1000]={},visited[1000]={};
			int dis[n],visited[n],q[n];
			for(i=0;i<n;i++)
			{
				dis[i]=0;
				visited[i]=0;
			}
			if(n>1)
			{
				for(i=0;i<n-1;i++)
				{
					scanf("%d%d",&x,&y);
					insert(x-1,y-1);
				}
				visited[x-1]=1;
//				push(x-1,q);
         			dfs(x-1,visited,dis,q);
				start=0,last=0;
				for(i=0;i<n;i++)
					visited[i]=0;
				for(i=0;i<n;i++)
				{
					if(max<dis[i])
					{
						max=dis[i];
	         				g=i;
					}
				}
				max=0;
				for(i=0;i<n;i++)
			        	dis[i]=0;
				visited[g]=1;
//				push(g,q);
				dfs(g,visited,dis,q);
				for(i=0;i<n;i++)
				{
					if(max<dis[i])
					{
						max=dis[i];
					}
				}
				fre(1000000);
				printf("%d\n",max+1);}}
		if(n==0||n==1)
			printf("0\n");
		start=0,last=0;
	}
	return 0;
}
