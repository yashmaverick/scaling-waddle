#include<stdio.h>
#include<stdlib.h>
struct node{
	int val;
	int dis;
	struct node* next;
};
typedef struct node node;
int dis[100003]={0},heap[500000],vis[100004]={0},last=0,ver[500000];
node* end[100003]={NULL},*head[100003]={NULL};
void delete()
{
	if(last==0)
		return;
	heap[0]=heap[last-1];
	ver[0]=ver[last-1];
	last--;
	int temp,r=0;
	while((heap[r]>heap[2*r+1] && (2*r+1)<last) || (heap[r]>heap[2*r+2] && (2*r+2)<last))
	{
		if(2*r+2<last && heap[2*r+1]>heap[2*r+2])
		{
			temp=heap[2*r+2];
			heap[2*r+2]=heap[r];
			heap[r]=temp;
			temp=ver[2*r+2];
			ver[2*r+2]=ver[r];
			ver[r]=temp;
			r=2*r+2;
		}
		else
		{
			temp=heap[2*r+1];
			heap[2*r+1]=heap[r];
			heap[r]=temp;
			temp=ver[2*r+1];
			ver[2*r+1]=ver[r];
			ver[r]=temp;
			r=2*r+1;
		}
	}
	return;
}
void ins(int k)
{
	last++;
	if(last==1)
	{
		heap[0]=dis[k];
		ver[0]=k;
		return;
	}
	int r=last-1;
	while(heap[(r-1)/2]>dis[k] && r>0)
	{
		heap[r]=heap[(r-1)/2];
		ver[r]=ver[(r-1)/2];
		r=(r-1)/2;
	}
	heap[r]=dis[k];
	ver[r]=k;
	return;
}
node* makenode(int n,int d)
{
	node* t;
	t=malloc(sizeof(node));
	t->val=n;
	t->dis=d;
	t->next=NULL;
	return t;
}
void insert(int x,int y,int z)
{
	if(end[x]==NULL)
	{
		head[x]=makenode(y,z);
		end[x]=head[x];
	}
	else
	{
		end[x]->next=makenode(y,z);
		end[x]=end[x]->next;
	}
	return;
}
int main()
{
	int v,e,x,y,z,i;
	node* t;
	scanf("%d %d",&v,&e);
	for(i=0;i<v;i++)
		dis[i]=1000000000;
	for(i=0;i<e;i++)
	{
		scanf("%d %d %d",&x,&y,&z);
		x--;y--;
		insert(x,y,z);
	}
	scanf("%d %d",&x,&y);
	x--;y--;
	dis[x]=0;
	ins(x);
	while(last!=0)
	{
		x=ver[0];
		if(vis[x]==0)
		{
			t=head[x];
			while(t!=NULL)
			{
				if(dis[t->val]>dis[x]+t->dis)
				{
					//printf("%d %d %d\n",x,t->val,dis[x]+t->dis);
					dis[t->val]=dis[x]+t->dis;
					ins(t->val);
				}
				t=t->next;
			}
			vis[x]=1;
		}
		delete();
	}
	if(vis[y]==0)
		printf("NO\n");
	else
		printf("%d\n",dis[y]);
	return 0;
}
