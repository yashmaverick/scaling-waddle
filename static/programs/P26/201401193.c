#include<stdio.h>
#include<stdlib.h>
struct node{
	int val;
	int dis;
	struct node* next;
};
typedef struct node node;
int arr[10001]={0},vis[10001]={0},heap[10001],last=0,ver[10001],dis[10001];
node* head[10001]={NULL};
node* makenode(int n)
{
	node *t=malloc(sizeof(node));
	t->val=n;
	t->dis=1;
	t->next=NULL;
	return t;
}
void insert(int x,int y)
{
	if(x==y)
		return;
	node* t=makenode(y);
	t->next=head[x];
	head[x]=t;
	return;
}
void func(int x)
{
	int i;
	for(i=0;i<=9;i++)
	{
		if(arr[x%1000+i*1000]==0 && i!=0)
			insert(x,x%1000+i*1000);
		if(arr[(x/1000)*1000+i*100+x%100]==0)
			insert(x,(x/1000)*1000+i*100+x%100);
		if(arr[(x/100)*100+i*10+x%10]==0)
			insert(x,(x/100)*100+i*10+x%10);
		if(arr[(x/10)*10+i]==0)
			insert(x,(x/10)*10+i);
	}
	return;
}
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
int main()
{
	int t,i,j;
	arr[1]=1;
	for(i=1;i<10000;i++)
		if(arr[i]==0)
			for(j=2;i*j<10000;j++)
				arr[i*j]=1;
	for(i=1000;i<10000;i++)
		if(arr[i]==0)
			func(i);
	scanf("%d",&t);
	while(t--)
	{
		last=0;
		for(i=1000;i<10000;i++)
		{
			dis[i]=1000000000;
			vis[i]=0;
		}
		int x,y;
		node* t;
		scanf("%d %d",&x,&y);
		dis[x]=0;
		ins(x);
		while(last!=0)
		{
			x=ver[0];
			if(x==y)
			{
				vis[y]=1;
				break;
			}
			if(vis[x]==0)
			{
				t=head[x];
				while(t!=NULL)
				{
					if(dis[t->val]>dis[x]+t->dis)
					{
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
			printf("Impossible\n");
		else
			printf("%d\n",dis[y]);
	}
	return 0;
}
