#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node * next;
}node;

int count[100009],ans[100009],vis[100009],heap[100009];
node * a[100009];

int p,y,c;
int deletemin(int i,int k)
{
	ans[i]=heap[1];
	p=1;
	heap[p]=heap[k];
	k--;
	while(2*p+1<=k)
	{
		if(heap[2*p]<heap[2*p+1])
			y=2*p;
		else
			y=2*p+1;
		if(heap[p]>heap[y])
		{
			c=heap[p];
			heap[p]=heap[y];
			heap[y]=c;
		}
		else
			break;
		p=y;
	}
	if(2*p<=k)
	{
		if(heap[2*p]<heap[p])
		{
			c=heap[2*p];
			heap[2*p]=heap[p];
			heap[p]=c;
		}
	}
	return k;
}
void insert(int i,int k)
{
	heap[k]=i;
	p=k;
	while(p>1&&heap[p/2]>heap[p])
	{
		c=heap[p];
		heap[p]=heap[p/2];
		heap[p/2]=c;
		p=p/2;
	}
	return;
}
int main()
{
	node * newnode,*cur;
	int i,j,x,y,n,m,k;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
		a[i]=(node *)malloc(sizeof(node));
	for(i=1;i<=m;i++)
	{
		scanf("%d %d",&x,&y);
		newnode=(node *)malloc(sizeof(node));
		newnode->data=y;
		newnode->next=a[x]->next;
		a[x]->next=newnode;
		count[y]++;
	}
	k=0;
	for(i=1;i<=n;i++)
	{
		if(count[i]==0)
		{
			k++;
			insert(i,k);
		}
	}
	/*for(i=1;i<=k;i++)
		printf("%d ",heap[i]);
	printf("\n");*/
	for(i=1;i<=n&&k>0;i++)
	{
		k=deletemin(i,k);
		cur=a[ans[i]]->next;
		while(cur!=NULL)
		{
			count[cur->data]--;
			if(count[cur->data]==0)
			{
				k++;
				insert(cur->data,k);
			}
			cur=cur->next;
		}
	}
	for(i=1;i<=n;i++)
	{
		if(i==n)
			printf("%d\n",ans[i]);
		else
			printf("%d ",ans[i]);
	}
	return 0;
}
