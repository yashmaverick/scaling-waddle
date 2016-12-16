#include<stdio.h>
#include<stdlib.h>
typedef struct node node;
struct node
{
	struct node *next;
	int vertex;
};
node *a[1000000],*b[100000];
int vis[1000000],count=0,m;
void  dfs(int i,int c)
{	
	//	printf("\n%d\n",i);
	node *p;
	if(c==1)
		p=a[i];
	else
		p=b[i];
	vis[i]=1;
	//	printf("count : %d\n",count);
	/*if(count>l)
	  {
	  l=count;
	  m=i;
	  }*/
	count++;
	while(p!=NULL)
	{
		i=p->vertex;
		if(vis[i]==0)
		{			
			dfs(i,c);
		}
		p=p->next;
	}
}
void *insert1(node *x,int y)
{	
	node *q;
	q=(node*)malloc(sizeof(node));
	q->vertex=y;
	q->next=x;
	x=q;
	return x;
	/*if(a[x]==NULL)
		a[x]=q;
	else
	{
		p=a[x];
		while(p->next!=NULL)
			p=p->next;
		p->next=q;
	}
	//printf("x\n");*/
}
void *insert2(node *x,int y)
{
	node *q;
	q=(node*)malloc(sizeof(node));
	q->vertex=y;
	q->next=x;
	x=q;
	return x;
	//printf("y\n");

}
int main()
{	int test;
	scanf("%d",&test);
	while(test--)
	{	
		count=0;		
		int i,nodes,x,y,z,n,j,k;
		scanf("%d",&nodes);
		for(i=0;i<=nodes;i++)
		{
			vis[i]=0;
			a[i]=NULL;
			b[i]=NULL;
		}
		for(i=1;i<=nodes;i++)
		{	scanf("%d",&n);
			for(j=1;j<=n;j++)
			{		
				scanf("%d",&y);
				a[i]=insert1(a[i],y);
				b[y]=insert2(b[y],i);
			}
		}
		for(i=1;i<=nodes;i++)
		{
			count=0;
			for(j=0;j<=nodes;j++)	
				vis[j]=0;
			dfs(i,0);
		//	printf("n(%d)=%d\n",i,count);
			if(count==nodes)
			{	
				//			printf("i=%d\n",i);
		//		printf("breaking");
				break;
			}		
		}
		if(i>nodes)
			printf("0\n");
		else
		{
			z=i;
			count=0;
			for(i=0;i<=nodes;i++)	
				vis[i]=0;
			//	printf("%d\n",z);
			dfs(z,1);
			printf("%d\n",count);
		}
	}
	return 0;
}
