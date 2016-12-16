#include<stdio.h>
#include<stdlib.h>
struct node{
	long long int val;
	long long int dis;
	struct node* next;
};
typedef struct node node;
node* head[100005];
long long int heap[3][1000005],last=0,par[100005],size[100005];
node* makenode(long long int x,long long int z)
{
	node* t;
	t=malloc(sizeof(node));
	t->val=x;
	t->dis=z;
	return t;
}
void insert(long long int x,long long int y,long long int z)
{
	node* t=makenode(y,z);
	t->next=head[x];
	head[x]=t;
	t=makenode(x,z);
	t->next=head[y];
	head[y]=t;
	return;
}
long long int root(long long int n)
{
	if(par[n]==n)
		return n;
	par[n]=root(par[n]);
	return par[n];
}
void add_edge(long long int x,long long int y)
{
	if(size[x]<size[y])
	{
		par[root(x)]=root(y);
		size[y]+=size[x];
	}
	else
	{
		par[root(y)]=root(x);
		size[x]+=size[y];
	}
}
void delete()
{
	if(last==0)
		return;
	last--;
	heap[0][0]=heap[0][last];
	heap[1][0]=heap[1][last];
	heap[2][0]=heap[2][last];
	long long int temp,r=0;
	while((heap[0][r]>heap[0][2*r+1] && (2*r+1)<last) || (heap[0][r]>heap[0][2*r+2] && (2*r+2)<last))
	{
		if(2*r+2<last && heap[0][2*r+1]>heap[0][2*r+2])
		{
			temp=heap[0][2*r+2];
			heap[0][2*r+2]=heap[0][r];
			heap[0][r]=temp;
			temp=heap[1][2*r+2];
			heap[1][2*r+2]=heap[1][r];
			heap[1][r]=temp;
			temp=heap[2][2*r+2];
			heap[2][2*r+2]=heap[2][r];
			heap[2][r]=temp;
			r=2*r+2;
		}
		else
		{
			temp=heap[0][2*r+1];
			heap[0][2*r+1]=heap[0][r];
			heap[0][r]=temp;
			temp=heap[1][2*r+1];
			heap[1][2*r+1]=heap[1][r];
			heap[1][r]=temp;
			temp=heap[2][2*r+1];
			heap[2][2*r+1]=heap[2][r];
			heap[2][r]=temp;
			r=2*r+1;
		}
	}
	return;
}
void ins(long long int x,long long int y,long long int z)
{
	last++;
	if(last==1)
	{
		heap[0][0]=z;
		heap[1][0]=x;
		heap[2][0]=y;
		return;
	}
	long long int r=last-1;
	while(heap[0][(r-1)/2]>z && r>0)
	{
		heap[0][r]=heap[0][(r-1)/2];
		heap[1][r]=heap[1][(r-1)/2];
		heap[2][r]=heap[2][(r-1)/2];
		r=(r-1)/2;
	}
	heap[0][r]=z;
	heap[1][r]=x;
	heap[2][r]=y;
	return;
}
int main()
{
	long long int v,e,i,ans=0,x,y,z,count=0;
	scanf("%lld %lld",&v,&e);
	for(i=0;i<e;i++)
	{
		scanf("%lld %lld %lld",&x,&y,&z);
		insert(x,y,z);
		ins(x,y,z);
	}
	for(i=1;i<=v;i++)
	{
		par[i]=i;
		size[i]=1;
	}
	while(last!=0)
	{
		x=heap[1][0];
		y=heap[2][0];
		z=heap[0][0];
		if(root(x)!=root(y))
		{
			count++;
			add_edge(x,y);
			ans+=z;
		}
		delete();
	}
	if(count==v-1)
		printf("%lld\n",ans);
	else
		printf("-1\n");
	return 0;
}
