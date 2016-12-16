#include<stdio.h>
#include<stdlib.h>
int prime[10001],distance[10001],end=1,visited[10001];//,vis[10001];
struct node{
	int val;
	struct node *next;
	int distance;
};
typedef struct node node;
node *k[10001]={NULL};
struct node1{
	int index;
	int dist;
};
typedef struct node1 node1;
node1 heap[100001];
node *insert(node *head,int v)
{
	if(head==NULL)
	{
		head=(node*)malloc(sizeof(node));
		head->val=v;
		head->distance=1;
		head->next=NULL;
		return head;
	}
	else
	{
		head->next=insert(head->next,v);
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
	//	printf("%d\n",heap[1].index);
	temp=heap[1];
	int i;
	if(visited[t]==1)
		return ;
	else
	{

		visited[heap[1].index]=1;
		//printf("%d\n",heap[1].index);
		end=deletemin();
		while(head!=NULL)
		{

			if(distance[head->val]>temp.dist+head->distance)
			{	distance[head->val]=temp.dist+head->distance;
				if(visited[head->val]==0)
					end=heapinsert(head->val);
				//			for(i=1;i<end;i++)
				//				printf("%d\n",heap[i].index);
				//			printf("\n");
			}
			head=head->next;
		}
	}
	if(end==1)
		return;
	if(visited[heap[1].index]==0)
		dfs(k[heap[1].index],t);
	else
	{
		end=deletemin();
		dfs(k[heap[1].index],t);
	}	

}
void mark(int p)
{
	int k=2;
	while(p*k<=9999)
	{
		prime[p*k]=1;
		k++;
	}
}
void sieve()
{
	int i;
	for(i=2;i<=100;i++)
	{
		if(prime[i]==0)
			mark(i);
	}
}
void rotate(int i,int j)
{
	int l,y;
	for(l=0;l<=9;l++)
	{
			if(l>0)
			{
				y=l*1000+i%1000;
				if(y!=i&&prime[y]==0)
				{	k[i]=insert(k[i],y);
					//		vis[y]=1;
				}
			}
			y=(i/1000)*1000+l*100+i%100;
			if(y!=i&&prime[y]==0)
			{	k[i]=insert(k[i],y);
				//		vis[y]=1;
			}
			y=(i/100)*100+l*10+i%10;
			if(y!=i&&prime[y]==0)
			{	k[i]=insert(k[i],y);
				//		vis[y]=1;
			}
			y=(i/10)*10+l;
			if(y!=i&&prime[y]==0)
			{	k[i]=insert(k[i],y);
				//		vis[y]=1;
			}
	}
}
int main()
{
	int test,c=0;
	scanf("%d",&test);
	int i,j,s,t;
	for(i=0;i<10001;i++)
		prime[i]=0;
	sieve();
	for(i=1000;i<10000;i++)
	{	//printf("%d ",prime[i]);
		if(prime[i]==0)
		{
	
				rotate(i,j);
		
		}
	}
	while(test--)
	{
		for(i=1000;i<=10001;i++)
		{
			
			
				distance[i]=1000000000;
			//	k[i]=NULL;
				visited[i]=0;
			//d/d	vis[i]=0;
			
		}
		/*	for(i=1000;i<=9999;i++)
			{
			if(prime[i]==0)
			{		printf("%d ",i);
			c++;
			}
			}
			printf("%d\n",c);*/

		/*	for(i=1000;i<9999;i++)
			{
			if(prime[i]==0)
			{	printf("%d ",i);
			print(k[i]);
			printf("\n");
			}
			}*/

		//	printf("fadf\n");
		//	print(k[1033]);
		//	printf("\n");
		scanf("%d %d",&s,&t);
		heap[1].index=s;
		heap[1].dist=0;
		distance[s]=0;
		end=2;
		//	printf("fajfadfs\n");
		dfs(k[s],t);
		//	printf("ajkjdfa\n");
		if(visited[t]==0)
			printf("Impossible\n");
		else
			printf("%d\n",distance[t]);
	}
	return 0;
}


