#include<stdio.h>
#include<stdlib.h>
typedef struct list
{
	int data;
	struct list *next;
}list;
int stack[1001],visited[1001];
int ans,cnt;
list * insert( list *p,int x,int y);
void dfs(list *p[],int i,int front);
void dfsa(list *p[],int i,int f);
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,i,j,m,no,k,flag=0;
		cnt=0,ans=0;
//		int front=0,f=0;
		scanf("%d",&n);
		list *a[1001];
		list *b[1001];
		for(i=1;i<=n;i++)
		{	
			a[i]=NULL;
			b[i]=NULL;
			visited[i]=0;
		}
		for(i=1;i<=n;i++)
		{
			scanf("%d",&m);
			if(m!=0)
			{
				for(j=1;j<=m;j++)
				{	
					scanf("%d",&no);
					a[no]=insert(a[no],no,i);
					b[i]=insert(b[i],i,no);
				}
			}
		}
		int index;
		for(i=1;i<=n;i++)
		{
			cnt=0;
			dfs(a,i,0);
//			for(k=1;k<=n;k++)
//				printf("%d ",visited[k]);
//			printf("count %d\n",cnt);
			if(cnt==n)
			{
				index=i;
				flag=1;
				break;
			}
			else
			{
				for(k=1;k<=n;k++)
					visited[k]=0;
				//cnt=1;
			}
		}
//		for(j=1;j<=n;j++)
//			visited[j]=0;
		if(flag==1)
		{
			for(j=1;j<=n;j++)
				visited[j]=0;
			dfsa(b,index,0);
			flag=0;
		}
		printf("%d\n",ans);
	}
return 0;
}
list * insert( list *p,int x,int y)
{
	list *temp;
	list *new=(list *)malloc(sizeof(list));
	new->data=y;
	if(p==NULL)
	{
		p=new;
		new->next=NULL;
	}
	else
	{
		temp=p;
		p=new;
		p->next=temp;
	}
return p;
}
void dfs(list *p[],int i,int front)
{
	list *q=p[i];
	if(visited[i]==0)
		cnt++;
	visited[i]=1;
	while(front>=0)
	{
		while(q!=NULL)
		{
			if(visited[q->data]==0)
			{
//				printf("count in func %d\n",cnt);
				visited[q->data]=1;
				cnt++;
				stack[front]=q->data;
				front++;
			}
			q=q->next;
		}
		front--;
//		if(front!=-1)
//			printf("%d ",stack[front]);
		if(front!=-1)
		dfs(p,stack[front],front);	
	
	}
}
void dfsa(list *p[],int i,int f)
{
	list *q=p[i];
	if(visited[i]==0)
		ans++;
	visited[i]=1;
	while(f>=0)
	{
		while(q!=NULL)
		{
			if(visited[q->data]==0)
			{
				visited[q->data]=1;
				ans++;
				stack[f]=q->data;
				f++;
			}
			q=q->next;
		}
		f--;
		if(f!=-1)
		dfsa(p,stack[f],f);
	}
}
