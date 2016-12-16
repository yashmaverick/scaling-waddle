#include<stdio.h>
#include<stdlib.h>
typedef struct link
{
	int data;
	struct link *next;
}node;
node *a[1001];
node *b[1001];
int vis[1001];
int temp;
node *insert(node *x,int y)
{
	node* new=malloc(sizeof(node));
	new->data=y;
	new->next=x;
	x=new;
	return x; 
}
int count;
int temp1=0;
void dfs1(int j)
{
	node *q;
	vis[j]=1;
//	printf("%d ",temp1);
	temp1++;
	q=b[j];
	while(q!=NULL)
	{
		if(vis[q->data]!=1)
		{
			vis[q->data]=1;
			dfs1(q->data);
		}
		q=q->next;
	}
}
void dfs2(int j)
{
	node *q;
	vis[j]=1;
	temp1++;
	q=a[j];
	while(q!=NULL)
	{
		if(vis[q->data]!=1)
		{
			vis[q->data]=1;
			dfs2(q->data);
		}
		q=q->next;
	}
}
int main()
{
	int t,i,j,k,y;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		int n,def,x;
		count=0;
		scanf("%d",&n);
		for(j=0;j<1001;j++)
		{
			vis[j]=0;
			a[j]=NULL;
			b[j]=NULL;
		}
		node *p=NULL;
		for(j=1;j<=n;j++)
		{
			scanf("%d",&def);
			for(k=0;k<def;k++)
			{
				scanf("%d",&x);
				//	insert(a[x],y);
				//	insert(a[y],x);
				if(x!=0)
				{
					a[j]=insert(a[j],x);
					b[x]=insert(b[x],j);
				}
			}
		}
		/*			node *tmp;
					for(j=1;j<=n;j++)
					{
					tmp=a[j];
					while(tmp!=NULL)
					{
					printf("%d->%d\n",j,tmp->data);
					tmp=tmp->next;
					}
					printf("\n");
					}
					printf("b array\n");
					for(j=1;j<=n;j++)
					{				
					tmp=b[j];
					while(tmp!=NULL)
					{
					printf("%d->%d\n",j,tmp->data);
					tmp=tmp->next;
					}
					printf("\n");
					}*/
		//			p=a[j];
		//			while(p!=NULL)
		//			{
		//				printf("%d ",p->data);
		//				p=p->next;
		//			}
		//		}
		int k;
		int flag=0;
		for(j=1;j<=n;j++)
		{
			int l;
			//			printf("3333\n");
			for(l=0;l<1001;l++)
				vis[l]=0;
			//			printf("%d ",dfs(a[j],j));
			temp=0;
			temp1=0;
			dfs1(j);
			if(temp1==n)
			{
				flag=1;
				k=j;
				break;
			}
			//			printf("done\n");
		}
		if(flag==0)
		{
			printf("0\n");
		}
		else
		{
			int count1,l;
			temp=0;
			temp1=0;
			//		printf("%d %d\n",k,j);
			for(l=0;l<1001;l++)
				vis[l]=0;
			dfs2(j);
			printf("%d\n",temp1);
		}
	}
return 0;
}
