#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int val;
	struct node *next;
}node;
node *a[100005];
int sz=0,heap[100005];
void shup(int p)
{
	int t,i;
	i=p+1;
	while(i>1)
	{
		if(heap[i-1]<heap[i/2-1])
		{
			t=heap[i-1];
			heap[i-1]=heap[i/2-1];
			heap[i/2-1]=t;
			i=i/2;
		}
		else
			break;
	}
}
void heapinsert(int v)
{
	sz++;
	heap[sz-1]=v;
	shup(sz-1);
}
void shdown(int i)
{
	int min,t;
	while(i<sz/2)
	{
		min=(heap[2*i+1]>heap[2*i+2])?2*i+2:2*i+1;
		if(heap[i]>heap[min])
		{
			t=heap[min];
			heap[min]=heap[i];
			heap[i]=t;
			i=min;
		}
		else
			break;
	}

}
int deletemin()
{
	int i;
	if(sz>0)
	{
		i=heap[0];
		heap[0]=heap[sz-1];
		sz--;
		shdown(0);
	}
	return i;
}
void insert(int x,int y)
{
	node *new,*tmp;
	if(a[x]==NULL)
	{
		a[x]=(node*)malloc(sizeof(node));
		a[x]->val=y;
		a[x]->next=NULL;
	}
	else
	{
		new=(node*)malloc(sizeof(node));
		new->val=y;
		new->next=a[x];
		a[x]=new;
	}
}
int main()
{
	int i,j,k,n,m,v,u,p;
	int arr[100005];
	node *temp;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		arr[i]=0;
	for(i=0;i<m;i++)
	{
		scanf("%d%d",&u,&v);
		insert(u,v);
		arr[v]+=1;
	}
	/*for(i=1;i<=n;i++)
	  {
	  printf("%d-> ",i);
	  temp=a[i];
	  while(temp!=NULL)
	  {
	  printf("%d ",temp->val);
	  temp=temp->next;
	  }
	  printf("\n");
	  }*/
	for(i=1;i<=n;i++)
	{
		if(arr[i]==0)
			heapinsert(i);
	}
	while(sz>0)
	{
		p=deletemin();
		temp=a[p];
		while(temp!=NULL)
		{
			arr[temp->val]-=1;
			if(arr[temp->val]==0)
				heapinsert(temp->val);
			temp=temp->next;
		}
		if(sz==0)
			printf("%d\n",p);
		else
			printf("%d ",p);
	}
	return 0;
}
