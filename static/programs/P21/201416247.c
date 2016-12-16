#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define max INT_MAX
typedef struct node
{
	int data;
	int w;
	struct node * next;
}node;
typedef struct heapnode
{
	int ver;
	int dist;
}heapnode;
node * a[100005];
heapnode heap[1000005];
void create(int n1,int n2,int n3)
{
	node *temp;
	temp=(node *)malloc(sizeof(node));
	temp->data=n2;
	temp->w=n3;
	temp->next=NULL;
	temp->next=a[n1]->next;
	a[n1]->next=temp;
}
int size=0;
void insert(heapnode temp)
{
	size++;
	heap[size]=temp;
	int now = size;
	while(heap[now/2].dist > temp.dist)
	{
		heap[now] = heap[now/2];
		now =now/2;
	}
	heap[now] = temp;
}
heapnode delmin()
{
	heapnode min,last;
	int child,now;
	min = heap[1];
	last = heap[size--];
	for(now = 1; now*2 <= size ;now = child)
	{
		child = now*2;
		if(child != size )
		if(heap[child+1].dist < heap[child].dist )
		{
			child++;
		}
		if(last.dist > heap[child].dist)
		{
			heap[now] = heap[child];
		}
		else 
			break;
		
	}
	heap[now] = last;
	return min;
}
int main()
{
	int i,j,n,k,m,t,s,d,n1,n2,n3,distance[100000],v[100000];
	scanf("%d%d",&n,&m);
	heapnode  temp;
	for(i=0;i<10000;i++)
		v[i]=0;
	for(i=1;i<=n;i++)
	{
		a[i]=(node *)malloc(sizeof(node));
		a[i]->data=i;
		a[i]->next=NULL;
	}	
	for(i=0;i<m;i++)
	{
		scanf("%d%d%d",&n1,&n2,&n3);
		create(n1,n2,n3);
	}
	scanf("%d%d",&s,&d);
	for(i=1;i<=n;i++)
	{
		if(i==s)
		{
			if(i<n)
			{
				temp.ver=s;
				temp.dist=0;
				distance[0]=0;
			}
		}
		else
		{
			temp.dist=max;
			temp.ver=s;
			distance[i]=max;
		}
		insert(temp);
	} 
	int nowver;
	while(size)
	{		
		heapnode  temp;
		temp=delmin();
		nowver=temp.ver;
		if(!v[nowver]||nowver!=d)
		{
			v[nowver]=1;
			node  *temp1;
			temp1=a[nowver];
			while(temp1!=NULL)
			{
				int to=temp1->data;
				int weight=temp1->w;
				if(distance[to]>distance[nowver]+weight)
				{
					if(temp1!=NULL)
					{
						distance[to]=distance[nowver]+weight;
						heapnode temp2;
						temp2.ver=to;
						temp2.dist=distance[to];
						insert(temp2);
					}
				}
				if(temp1==NULL)
				{
					distance[to]=distance[nowver];
				}
				temp1=temp1->next;
			}
			
		}

	}
	if(distance[d]>800000)
	printf("NO\n");
	else
	printf("%d\n",distance[d]);
	
	return 0;
}
