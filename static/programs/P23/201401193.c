#include<stdio.h>
#include<stdlib.h>
struct node{
	int val;
	struct node* next;
};
typedef struct node node;
node* head[100005]={NULL};
int deg[100005]={0},heap[300005],last=0;
void insert(int x,int y)
{
	node* t;
	t=malloc(sizeof(node));
	t->val=y;
	t->next=head[x];
	head[x]=t;
	return;
}
void ins(int n)
{
	last++;
	if(last==1)
		heap[0]=n;
	else
	{
		int r=last-1;
		while(heap[(r-1)/2]>n && r>0)
		{
			heap[r]=heap[(r-1)/2];
			r=(r-1)/2;
		}
		heap[r]=n;
	}
	return;
}
void delete()
{
	if(last==0)
		return;
	last--;
	heap[0]=heap[last];
	int temp,r=0;
	while((heap[r]>heap[2*r+1] && (2*r+1)<last) || (heap[r]>heap[2*r+2] && 2*r+2<last))
	{
		if(2*r+2<last && heap[2*r+1]>heap[2*r+2])
		{
			temp=heap[2*r+2];
			heap[2*r+2]=heap[r];
			heap[r]=temp;
			r=2*r+2;
		}
		else
		{
			temp=heap[2*r+1];
			heap[2*r+1]=heap[r];
			heap[r]=temp;
			r=2*r+1;
		}
	}
	return;
}
int main()
{
	int n,m,i,x,y,count=0;
	node* t;
	scanf("%d %d",&n,&m);
	while(m--)
	{
		scanf("%d %d",&x,&y);
		insert(x,y);
		deg[y]++;
	}
	for(i=1;i<=n;i++)
		if(deg[i]==0)
			ins(i);
	while(last!=0)
	{
		x=heap[0];
		delete();
		if(count==n-1)
			printf("%d\n",x);
		else
			printf("%d ",x);
		count++;
		t=head[x];
		while(t!=NULL)
		{
			deg[t->val]--;
			if(deg[t->val]==0)
				ins(t->val);
			t=t->next;
		}
	}
	return 0;
}
