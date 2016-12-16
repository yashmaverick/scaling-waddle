#include<stdio.h>
#include<stdlib.h>
#define gu getchar_unlocked 
#define pu putchar_unlocked
#define lli long long int
#define ulli unsigned long long int
#define din(n) scanf("%d",&n)
#define dout(n) printf("%d\n",n)
#define lldin(n) scanf("%lld",&n)
#define lldout(n) printf("%lld\n",n)
#define INF 100000000000000000
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)<(b)?(b):(a))
#define loop(n) for(i=0;i<n;i++)
typedef struct node{
	int data;
	struct node* next;
	int wt;
}node;
node* vertices[100005]={};
typedef struct heap_node{
	lli distance;
	int node_value;
}heap_node;

heap_node heap[100005];
int indx=1;
lli dist[100005];
int visited[100005];
int removed[100005];

void insert(int value,int node)
{

	int temp_index=indx;
	heap[temp_index].node_value=node;
	heap[temp_index].distance=value;
	while(heap[temp_index].distance<heap[temp_index/2].distance)
	{
		int swap_value=heap[temp_index].distance;
		int swap_node=heap[temp_index].node_value;
		heap[temp_index].distance=heap[temp_index/2].distance;
		heap[temp_index].node_value=heap[temp_index/2].node_value;
		heap[temp_index/2].distance=swap_value;
		heap[temp_index/2].node_value=swap_node;
		temp_index=temp_index/2;
		if(temp_index/2==0)
			break;
	}
	indx++;
}
void heapify()
{
	int node,flag1,flag2;
	node=flag1=flag2=1;
	int to_swap;
	while(1)
	{
		int tempflag=0;
		if(node*2>=indx)
			flag1=0;
		if(node*2+1>=indx)
			flag2=0;
		if(flag1==0 && flag2==0)
			break;

		if(flag1 && flag2 && heap[node].distance>heap[node*2].distance && heap[node].distance>heap[node*2+1].distance)
		{
			to_swap=(heap[node*2].distance<=heap[node*2+1].distance)?node*2:node*2+1;
			tempflag=1;
		}
		else if(flag1 && heap[node].distance>heap[node*2].distance)
		{
			tempflag=1;
			to_swap=node*2;
		}
		else if(flag2 && heap[node].distance>heap[node*2+1].distance)
		{
			tempflag=1;
			to_swap=node*2+1;
		}
		if(!tempflag)
			break;
		//printf("flag1 %d and flag2 %d \n",flag1,flag2);
		//printf("node  is %d \n",node);
		//printf("Index is %d \n",indx);
		//printf("node at 1 %d & node at 2 %d & node at 3 %d \n",heap[1].node_value,heap[2].node_value,heap[3].node_value);
		//printf("to_swap %d\n",to_swap);
		int swap_value=heap[node].distance;
		int swap_node=heap[node].node_value;
		heap[node].distance=heap[to_swap].distance;
		heap[node].node_value=heap[to_swap].node_value;
		heap[to_swap].distance=swap_value;
		heap[to_swap].node_value=swap_node;
		node=to_swap;
		flag1=flag2=1;
	}
}
void delete_min()
{

	heap[1].distance=heap[indx-1].distance;
	heap[1].node_value=heap[indx-1].node_value;
	indx--;
	heapify();
}

int main()
{
	int n,m,temp1,temp2,weight,node1,node2,i;
	din(n); 
	din(m);
	loop(n+1)
		dist[i]=INF;
	node *temp;
	loop(m)
	{
		scanf("%d %d %d",&temp1,&temp2,&weight);
		temp=(node*)malloc(sizeof(node));
		temp->data=temp2;
		temp->wt=weight;
		temp->next=vertices[temp1];
		vertices[temp1]=temp;

		temp=(node*)malloc(sizeof(node));
		temp->data=temp1;
		temp->next=vertices[temp2];
		vertices[temp2]=temp;
		temp->wt=weight;

	}
	//for(i=1;i<=n;i++)
	//{
//		printf("%d :",i);
//		node* tempp=vertices[i];
//		while(tempp!=NULL)
//		{
//			printf(" %d w(%d)",tempp->data,tempp->wt);
//			tempp=tempp->next;
//		}
//		pu(10);
//	}
	int q;
	node1=1;
	//din(node1);
	//din(node2);
	heap[indx].distance=0;
	heap[indx].node_value=node1;
	indx++;
	dist[node1]=0;
	//for(int q=1;q<=3;q++)
	//	printf("%lld ",dist[q]);
	//pu(10);
	while(indx>1)
	{
		if(visited[heap[1].node_value])
		{
			delete_min();
			//printf("Delete\n");
			//for(q=1;q<indx;q++)
		//		printf("%lld.node(%d) ",heap[q].distance,heap[q].node_value);
		//	pu(10);

			continue;
		}
		temp=vertices[heap[1].node_value];
		visited[heap[1].node_value]=1;
		//if(visited[heap[1].node_value])
		//	printf("node(%d) is visited\n",heap[1].node_value);
		while(temp!=NULL)
		{
			if(dist[temp->data]>temp->wt && !visited[temp->data])
			{
				dist[temp->data]=temp->wt;
				insert(temp->wt,temp->data);
				//printf("Inserted vertex(%d)",heap[1]
				//printf("Insert\n");
				//for(q=1;q<indx;q++)
				//	printf("%lld.node(%d) ",heap[q].distance,heap[q].node_value);
				//pu(10);

			}
			temp=temp->next;
		}
		//printf("out of insert loop\n");
		//printf("visited is %d\n",heap[1].node_value);
	}

	lli ans=0;
	for(i=1;i<=n;i++)
	{
		if(dist[i]==INF)
		{
			printf("-1\n");
			return 0;
		}
		ans+=dist[i];
	}
	lldout(ans);
	return 0;
}
