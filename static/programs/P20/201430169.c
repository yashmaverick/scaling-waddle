#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct list{
	int val;
	struct list* next;
}list;
list* A[1000001];
int visit[1000001],dist[1000001],max,v;//node[1000001],p,k,flag,visit[1000001];
void dfs(int i,int l)
{
	visit[i]=1;//node[p++]=i;
	dist[i]=l;
	if(max<dist[i])
	{	
		max=dist[i];
		v=i;
		
	}	
	//printf("%d ",i);
	list* m=A[i];
	while(m!=NULL)
	{
		if(visit[m->val]==0)// && m->val>i)
			dfs(m->val,l+1);
		//if(flag==1)
		//	return;
		m=m->next;
	}
	
}	

void insert(int x,int y)
{
	list* new1=(list*)malloc(sizeof(list));
	list* new2=(list*)malloc(sizeof(list));
	new1->val=x;
	new2->val=y;
	if(A[x]==NULL)
	{	A[x]=new2;
		new2->next=NULL;
	}
	else
	{
		list* temp=A[x];
		A[x]=new2;
		new2->next=temp;
	}
	if(A[y]==NULL)
	{	
		A[y]=new1;
		new1->next=NULL;
	}	
	else
	{
		list* temp=A[y];
		A[y]=new1;
		new1->next=temp;
	}
}	



int main()
{

	int t,n,i,x,y,j;
	scanf("%d",&t);
	while(t--)
	{
		//int n,i,x,y,j,ans;
		scanf("%d",&n);			//n is vertices
		for(i=0;i<=n;i++)
			A[i]=NULL;
		for(i=0;i<n-1;i++)
		{
			scanf("%d%d",&x,&y);
			insert(x,y);
		}
		//ans=0;
		//for(i=1;i<=n;i++)
		//{
			max=0;//p=0;flag=0;
			memset(visit,0,sizeof(int)*(n+1));
			dfs(1,1);
			memset(visit,0,sizeof(int)*(n+1));
			dfs(v,1);
			//if(ans<max)
			//	ans=max;

			//printf("\n-----max length is %d for node%d\n",max,i);
		//}						

		/*for(i=1;i<=n;i++)
		  {
		  list* p=A[i];printf("%d->",i);		//printing adjacency list
		  while(p!=NULL)
		  {
		  printf("%d ",p->val);
		  p=p->next;
		  }printf("\n");
		  }*/	
		printf("%d\n",max);
	}
	return 0;
}	


