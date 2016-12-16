#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<math.h>

#define gu getchar_unlocked 
#define pu putchar_unlocked
#define lli long long int
#define ulli unsigned long long int
#define din(n) scanf("%d",&n)
#define dout(n) printf("%d\n",n)
#define lldin(n) scanf("%lld",&n)
#define lldout(n) printf("%lld\n",n)

#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)<(b)?(b):(a))
#define loop(n) for(i=0;i<n;i++)
int cmpfunc(const void *a,const void *b)
{
	return *(int *)a - *(int *)b;
}

typedef struct node{
	int data;
	struct node* next;
}node;
node* vertices[100005];
int deg[100005]={0};
int heap[100005];
int indx=1;


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

		if(flag1 && flag2 && heap[node]>heap[node*2] && heap[node]>heap[node*2+1])
		{
			to_swap=(heap[node*2]<=heap[node*2+1])?node*2:node*2+1; 
			tempflag=1;
		}
		else if(flag1 && heap[node]>heap[node*2])
		{
			tempflag=1;
			to_swap=node*2;
		}
		else if(flag2 && heap[node]>heap[node*2+1])
		{
			tempflag=1;
			to_swap=node*2+1;
		}
		if(!tempflag)
			break;
		int swap_value=heap[node];
		heap[node]=heap[to_swap];
		heap[to_swap]=swap_value;
		node=to_swap;
		flag1=flag2=1;
	}
}


void delete_min()
{
	heap[1]=heap[indx-1];
	indx--;
	if(indx==1)
		return;
	heapify();
}
void insert(int value)
{
	if(heap[1]==0 && indx==1)
	{
		heap[1]=value;
		indx++;
		return;
	}

	int temp_index=indx;
	heap[temp_index]=value;
	while(heap[temp_index]<heap[temp_index/2])
	{
		int swap_value=heap[temp_index];
		heap[temp_index]=heap[temp_index/2];
		heap[temp_index/2]=swap_value;
		temp_index=temp_index/2;
		if(temp_index/2==0)
			break;
	}
	indx++;
}

int main()
{
	int n,m,temp1,temp2,i,j;
	node* temp;
	din(n);
	din(m);
	loop(m)
	{
		din(temp1);
		din(temp2);
		deg[temp2]++;
		temp=(node*)malloc(sizeof(node));
		temp->data=temp2;
		temp->next=vertices[temp1];
		vertices[temp1]=temp;
	}
	for(j=1;j<=n;j++)
	{
		if(deg[j]==0)
			insert(j);
	}
	int counter=0;

		while(indx>1)
		{
			if(counter==0)
				printf("%d",heap[1]);
			else printf(" %d",heap[1]);
			counter++;
			temp=vertices[heap[1]];
			delete_min();
			if(indx==1)
				heap[1]=0;
			while(temp!=NULL)
			{
				deg[temp->data]--;
				if(deg[temp->data]==0)
				{
					insert(temp->data);
				}
				temp=temp->next;
			}
		}
		pu(10);
	
	return 0;
}
