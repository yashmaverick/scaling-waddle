#include<stdio.h>
#include<stdlib.h>

typedef struct ll
{
	struct ll *next;
	int data;
	int weight;
}node;

node *a[1000001];
int heapmin[3000001],distance[1000001],pinheap[1000001],mintop;



void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;

}

void pushminheap(int n)
{
	mintop++;
	heapmin[mintop]=n;

	int temp=mintop;

	while(temp > 1)
	{
		int parent=temp/2;

		if(distance[heapmin[parent]] > distance[heapmin[temp]])
		{
			swap(&heapmin[temp],&heapmin[parent]);
			pinheap[heapmin[temp]]=temp;
			temp=parent;
		}

		else
			break;
	}

	pinheap[heapmin[temp]]=temp;
}


int popminheap()
{
	int min=heapmin[1];
	heapmin[1]=heapmin[mintop];
	
	int index=1;

	while ( index <= (mintop-1)/2 && (distance[heapmin[index]] > distance[heapmin[2*index]] || distance[heapmin[index]] > distance[heapmin[2*index+1]]) )
	{
		int temp=2*index;
		if(distance[heapmin[2*index]] > distance[heapmin[2*index+1]])
			temp++;

		if(distance[heapmin[temp]] < distance[heapmin[index]])
		{
			swap(&heapmin[index],&heapmin[temp]);
			swap(&pinheap[heapmin[index]],&pinheap[heapmin[temp]]);
			index=temp;
		}

		else
		{
			mintop--;
			return min;
		}
	}

	mintop--;
	return min;
}



void dijkstra(int from,int to,int n)
{
	int i;
	
	distance[from]=0;

	pushminheap(from);

	while(mintop)
	{
		int te=popminheap();
		node *newnode=a[te];

//		if(te==to)
//			break;

		while(newnode)
		{
				if( newnode->weight + distance[te] < distance[newnode->data])
				{
					distance[newnode->data]=distance[te]+newnode->weight;
					pushminheap(newnode->data);
				}

			newnode=newnode->next;
		}
	}

}


int main()
{
//	int t;
//	scanf("%d",&t);
//	while(t--)
//	{


	int n,m,i,t1,t2,weight,from,to;

	mintop=0;
	node *newnode=NULL;

	scanf("%d %d",&n,&m);

	for(i=1;i<=1000000;i++)
	{
		a[i]=NULL;
 		heapmin[i]=pinheap[i]=0;
		distance[i]=1000000001;
	
	}

	while(m--)
	{
		scanf("%d %d %d",&t1,&t2,&weight);

		newnode=(node *)malloc(sizeof(node));
		newnode->next=a[t1];  a[t1]=newnode;
		newnode->data=t2;    newnode->weight=weight;

	}

	scanf("%d %d",&from,&to);

	dijkstra(from,to,n);

	if(distance[to]==1000000001)
		printf("NO\n");
	else
		printf("%d\n",distance[to]);



//	}
	return 0;
}

			
