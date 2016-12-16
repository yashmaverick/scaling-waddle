#include<stdio.h>
#include<stdlib.h>
typedef struct link
{
	int data;
	struct link *next;
}node;
node *a[3000001];
int vis[3000001];
node *insert(node *x,int y)
{
	node* new=malloc(sizeof(node));
	new->data=y;
	new->next=x;
	x=new;
	return x;
}
int count;
node *c;
int b,max=-9999;
int level;
void dfs1(int j,int level1)
{
//		printf("%d ",a[j]->data);
		node *q;
		q=a[j];
		vis[j]=1;
		level=level1;
		if(level > max)
		{
			max=level1;
			b=j;
		}
		while(q!=NULL)
		{
			if(vis[q->data]!=1)
			{
				dfs1(q->data,level1+1);
			}
			q=q->next;
		}
}	
int main()
{
	int t,i;
	scanf("%d",&t);
	while(t--)
	{
		int n,j,x,y;
		scanf("%d",&n);
		for(i=0;i<3000001;i++)
		{
			vis[i]=0;
			a[i]=NULL;
		}
		int k;
		for(j=0;j<n-1;j++)
		{
			scanf("%d %d",&x,&y);
			a[x]=insert(a[x],y);
			a[y]=insert(a[y],x);
			k=x;	
		}
		node *tmp;
/*		for(j=1;j<=n;j++)
		{
			tmp=a[j];
			while(tmp!=NULL)
			{
				printf("%d->%d\n",j,tmp->data);
				tmp=tmp->next;
			}
			printf("\n");
		}*/
		level=0;
		max=0;
		dfs1(k,0);
		for(i=0;i<3000001;i++)
			vis[i]=0;
		max=-9999;
		level=0;
		dfs1(b,0);
		printf("%d\n",max+1);
	}
	return 0;
}
