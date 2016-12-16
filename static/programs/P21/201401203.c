#include<stdio.h>
#include<stdlib.h>
#define ll unsigned long long int
typedef struct node
{
	int data;
	ll wt;
	struct node * next;
}node;

node * a[100010];
ll d[100010];
int vis[100010],pos[100010];
node heap[100010],c;
ll min=1000000000000000;

int deletemin(int k)
{
	int p,y;
	p=1;
	heap[p]=heap[k];
//	printf("in %d\n",heap[1].data);
	pos[heap[p].data]=p;
	k--;
	while(2*p+1<=k)
	{

		if(heap[2*p].wt<heap[2*p+1].wt)
			y=2*p;
		else
			y=2*p+1;
		pos[heap[p].data]=y;
		pos[heap[y].data]=p;
		c=heap[p];
		heap[p]=heap[y];
		heap[y]=c;
		p=y;
	}
	if(2*p<=k)
	{
		//printf("1 %d\n",heap[1].data);
		if(heap[2*p].wt<heap[p].wt)
		{
			pos[heap[p].data]=2*p;
			pos[heap[2*p].data]=p;
			c=heap[2*p];
			heap[2*p]=heap[p];
			heap[p]=c;
		}
	}
	return k;
}
/*
void insert(int i,int k)
{
	int p;

	heap[k].data=i;
	pos[i]=k;
	p=k;
	while(p>1&&heap[p/2].wt>heap[p].wt)
	{
		pos[heap[p].data]=p/2;
		pos[heap[p/2].data]=p;
		c=heap[p];
		heap[p]=heap[p/2];
		heap[p/2]=c;
		p=p/2;
	}
	return;
}
*/
int main()
{
	node * cur,*newnode;
	int i,j,n,v,k,t,x,e,y,w,z,p;
	ll sum;
	//scanf("%d",&t);
	//while(t--)
	{
		scanf("%d %d",&v,&e);
		for(i=1;i<=v;i++)
		{
			a[i]=(node *)malloc(sizeof(node));
		//	a[i]->data=i;
		//	a[i]->wt=0;
		}
		for(i=1;i<=e;i++)
		{
			//create adjacency list
			scanf("%d %d %d",&x,&y,&w);
			newnode=(node *)malloc(sizeof(node));
			newnode->data=y;
			newnode->wt=w;
			newnode->next=a[x]->next;
			a[x]->next=newnode;
			/*	newnode=(node *)malloc(sizeof(node));
				newnode->data=x;
				newnode->wt=w;
				newnode->next=a[y]->next;
				a[y]->next=newnode;
		*/}
		scanf("%d %d",&x,&z);
		for(i=1;i<=v;i++)
		{
			if(i==x)
				d[i]=0;
			else
				d[i]=min;
			heap[i].data=i;
			heap[i].wt=min;
			pos[i]=i;
		}
		heap[1].data=x;
		heap[1].wt=0;
		pos[x]=1;
		pos[1]=x;
		int m=v;
//			for(j=1;j<=m;j++)
//				printf("%d ",pos[j]);
//			printf("\n");
		while(v>=1)
		{
			newnode=a[heap[1].data]->next;
			{
				while(newnode!=NULL)
				{
					if(vis[newnode->data]==0&&d[heap[1].data]!=min)
					{
						sum=newnode->wt+d[heap[1].data];//dt of parent + dt of child
						if(sum<d[newnode->data])
						{
							d[newnode->data]=sum;
							j=pos[newnode->data];
							p=j;
							heap[j].wt=sum;
							while(p>1&&heap[p].wt<heap[p/2].wt)
							{
								pos[heap[p/2].data]=p;
								pos[heap[p].data]=p;
								c=heap[p];
								heap[p]=heap[p/2];
								heap[p/2]=c;
								p=p/2;
							}
						}
					}
					newnode=newnode->next;
				}
			}
			vis[heap[1].data]=1;
			if(heap[1].data==z)
				break;
			//del
			p=1;
			/*while(2*p+1<=v)
			{
				if(heap[2*p].wt<heap[2*p+1].wt)
					y=2*p;
				else
					y=2*p+1;
				heap[p]=heap[y];
				pos[heap[p].data]=p;
				p=y;
			}
			while(p<v)
			{
				heap[p]=heap[p+1];
				pos[heap[p].data]=p;
				p++;
			}*/
			v=deletemin(v);
	/*		for(j=1;j<=m;j++)
				printf("%d ",pos[j]);
			printf("\n");
	*/	}
		if(d[z]==min)
			printf("NO\n");
		else
			printf("%llu\n",d[z]);
	/*	for(i=1;i<=m;i++)
			vis[i]=0;*/
	}
	return 0;
}
