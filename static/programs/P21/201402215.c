#include<stdio.h>
#include<stdlib.h>
long long int distance[100001];
int visited[100001];
int end=1,flag=0;
struct node1{
	int index;
	long long int dist;
};
typedef struct node1 node1;
node1 heap[500001];
struct node{
	int val;
	int distance;
	struct node *next;
};
typedef struct node node;
node *k[100002];
node *insert(node *head,int v,int d)
{
	if(head==NULL)
	{
		head=(node*)malloc(sizeof(node));
		head->val=v;
		head->distance=d;
		head->next=NULL;
		return head;
	}
	else
	{
		head->next=insert(head->next,v,d);
		return head;
	}
}
void print(node *head)
{
	if(head==NULL)
		return ;
	else
	{	printf("%d ",head->val);
		print(head->next);
	}
}
int min(int j)
{
	if(heap[2*j].dist>heap[2*j+1].dist)
		return 2*j+1;
	else
		return 2*j;
}
void shuffledown(int j)
{
	node1 temp;
	int k;
	if(2*j+1<=end-1)
	{
		k=min(j);
		if(heap[j].dist>heap[k].dist)
		{
			temp = heap[k];
			heap[k] = heap[j];
			heap[j] = temp;
			shuffledown(k);
		}
		else
			return ;
	}
	else if(2*j==end-1)
	{
		if(heap[j].dist>heap[2*j].dist)
		{
			temp=heap[2*j];
			heap[2*j]=heap[j];
			heap[j]=temp;
			shuffledown(2*j);
		}
	}
	else
		return ;
}
int deletemin()
{
	int j;
	heap[1] = heap[end-1];
	j=1;
	end--;
	shuffledown(j);
	return end;
}

int heapinsert(int u)
{
	heap[end].index=u;
	heap[end].dist=distance[u];
	node1 temp;
	int j;	
	if(end>1)
	{
		j=end;
		while(heap[j/2].dist>heap[j].dist && j>1)
		{
			temp=heap[j];
			heap[j]=heap[j/2];
			heap[j/2]=temp;
			j=j/2;
		}
	}
	return end+1;
}
void dfs(node *head,int t)
{
	node1 temp;
	temp=heap[1];
	int i;
	if(visited[t]==1)
		return ;
	else
	{
		visited[heap[1].index]=1;
	//	for(i=1;i<=6;i++)
	//		printf("vertex is %d and visited is %d\n",i,visited[i]);
		end=deletemin();
	//	printf("after delting minimum heap is\n");
	//	for(i=1;i<end;i++)
	//		 printf("vertex is %d and distance from source is %lld and visited[heap[i].index] is  %d\n",heap[i].index,distance[heap[i].index],visited[heap[i].index]);
		while(head!=NULL)
		{

			if(distance[head->val]>temp.dist+head->distance)
			{	distance[head->val]=temp.dist+head->distance;
			if(visited[head->val]==0)
				end=heapinsert(head->val);
			}
			head=head->next;
				//	printf("heap is\n");
				//	for(i=1;i<end;i++)
				//	{
			 	//		printf("vertex is %d and distance from source is %lld and visited[heap[i].index] is  %d\n",heap[i].index,distance[heap[i].index],visited[heap[i].index]);
			 		}
				//	printf("\n");
		}

		//if(end==2)
		//	return ;
		if(end==1)
			return;
		if(visited[heap[1].index]==0)
			dfs(k[heap[1].index],t);
		else
		{	end=deletemin();
			dfs(k[heap[1].index],t);
		}
	

}
int main()
{//	int test;
//	scanf("%d",&test);
//	while(test--)
//	{
		int n,m,i,u,v,d,s,t;
		node *head;
		flag=0;
		for(i=0;i<500001;i++)
		{	if(i>=100001)
			{
				heap[i].dist=0;
				heap[i].index=0;
			}
			else
			{
				visited[i]=0;
				distance[i]=1000000000;
				k[i]=NULL;
				heap[i].dist=0;
				heap[i].index=0;
			}
		}
		//	node1 heap[100001];
		//	printf("%lld\n",distance[199]);
		scanf("%d %d",&n,&m);
		for(i=0;i<m;i++)
		{
			scanf("%d %d %d",&u,&v,&d);
			k[u]=insert(k[u],v,d);
		}
		scanf("%d %d",&s,&t);
		distance[s]=0;
		heap[1].dist=0;
		heap[1].index=s;
		end=2;
		dfs(k[s],t);
	
		//for(i=1;i<=n;i++)
			//	{		print(k[i]);
			//		printf("\n");
			//	}
			if(visited[t]==0)
				printf("NO\n");
			else
				printf("%lld\n",distance[t]);
//	}
	return 0;
}
