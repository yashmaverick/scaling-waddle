#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}NODE;

NODE *a[1000001];

int vis[1000001]={},in[1000001]={},max=0,maxi;

typedef struct queue
{
	int data;
	struct queue *next;
}QUEUE;

QUEUE *head=NULL,*tail=NULL;

void enq(int data)
{
	QUEUE *temp=malloc(sizeof(QUEUE));
	temp->data=data;
	temp->next=NULL;
	if(head==tail && head==NULL)
	{
		head=temp;
		tail=head;
	}
	else
	{
		tail->next=temp;
		tail=tail->next;
	}
	return ;
}

int deq()
{
	int temp;
	if(head==tail && head!=NULL)
	{
		temp=head->data;
		head=NULL;
		tail=NULL;
	}
	else if(head!=NULL)
	{
		temp=head->data;
		head=head->next;
	}
	return temp;
}

NODE *insert(NODE *root,int data) // can be used for stack as well and obviously graph insertion
{
	NODE *temp;
	if(root==NULL)
	{
		temp=malloc(sizeof(NODE));
		temp->data=data;
		temp->next=NULL;
		return temp;
	}
	else
	{
		temp=malloc(sizeof(NODE));
		temp->data=data;
		NODE *tem=root;
		while(tem->next!=NULL)
		{
			tem=tem->next;
		}	
		tem->next=temp;
	}
	return root;
}

void print(NODE *root) //graph printing also can be used for stack printing
{
	NODE *temp=root;
	while(temp!=NULL)
	{
		printf("%d -> ",temp->data);
		temp=temp->next;
	}
	printf("NULL\n");
	return ;
}

int is_empty()
{
	if(head==NULL && head==tail)
		return 1;
	else
		return 0;
}

int dis[1000001]={};

void bfs(int src)
{
	NODE *temp=a[src];
	//printf("%d ",src);
	vis[src]=1;
	dis[src]=0;
	while(temp!=NULL)
	{	
		if(in[temp->data]!=1)
		{
			if(vis[temp->data]!=1)
			{
				dis[temp->data]=dis[src]+1;
				if(dis[temp->data]>max)
				{
					maxi=temp->data;
					max=dis[temp->data];
				}
				enq(temp->data);
				vis[temp->data]=1;
				in[temp->data]=1;
			}
		}
		temp=temp->next;
	}
	while(is_empty()!=1)
	{
		int temp1=deq();
		vis[temp1]=1;
		temp=a[temp1];
		while(temp!=NULL)
		{
			if(in[temp->data]!=1)
			{
				if(vis[temp->data]!=1)
				{
					dis[temp->data]=dis[temp1]+1;
					if(dis[temp->data]>max)
					{
						maxi=temp->data;
						max=dis[temp->data];
					}
					enq(temp->data);
					vis[temp->data]=1;
					in[temp->data]=1;
				}
			}
			temp=temp->next;
		}
		//printf("%d ",temp1);
	}
	return ;
}

int main()
{
	int b,c,d,e,f,g,h,j,i,k,l,m,n,o,p,q,r,s,t=1,u,v,w,x,y,z;
	scanf("%d",&t);
	while(t--)
	{
		max=0;
		maxi=0;
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			a[i]=NULL;
		for(i=1;i<=n-1;i++)
		{
			scanf("%d %d",&p,&q);
			a[p]=insert(a[p],q);
			a[q]=insert(a[q],p);
		}
		bfs(1);
		for(i=1;i<=n;i++)
		{
			vis[i]=0;
			in[i]=0;
		}
		max=0;
		/*for(i=1;i<=n;i++)
		printf("%d\n",dis[i]);
		printf("%d\n",maxi);*/
		bfs(maxi);
		printf("%d\n",max+1);
		for(i=1;i<=n;i++)
		{
			vis[i]=0;
			in[i]=0;
		}
	}
	return 0;
}
