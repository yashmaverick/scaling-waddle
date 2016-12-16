#include<stdio.h>
#include<stdlib.h>

typedef struct heap{
	long long int ind;
	long long int w;
}heap;

typedef struct ll{
	long long int ind;
	long long int we;
		struct ll* next;
}ll;

ll *arr[500005];

void add(long long int x,long long int y,long long int w)
{

	ll *temp;
	temp=(ll *)malloc(sizeof(ll));
	temp->we=w;
	temp->ind=y;
	temp->next=arr[x];
	arr[x]=temp;
}


heap h[5000005];
long long int head;
long long int vis[500005];
long long int d[500005];
long long int xy[500005];

void insert(long long int in,long long int w)
{
	head++;
	xy[in]=head;
	h[head].ind=in;
	h[head].w=w;
	long long int i=head,p;
	while(i>1)
	{
		p=i/2;
		if(h[p].w>h[i].w)
		{
			heap temp=h[p];
			h[p]=h[i];
			h[i]=temp;
			i=p;

		}
		else
			break;

	}
	
}

long long int min()
{
	long long int res=h[1].ind;
	h[1]=h[head];
	head--;
	long long int i=1,p;
	while(2*i<=head)
	{
		p=2*i;
		if(2*i+1<head)
		{if(h[2*i+1].w<h[2*i].w)
			p=2*i+1;
		}
		if(h[p].w<h[i].w)
		{
			heap tmp=h[p];
			h[p]=h[i];
			h[i]=tmp;
			i=p;
		}
		else if(h[p].w>=h[i].w)
		{
			break;
		}
		}
	

return res;
}
void dij(long long int e)
{
	insert(e,d[e]);
	while(head!=0)
	{
		long long int v=min();
		if(vis[v]==0)
		{
			vis[v]=1;
			ll * temp=arr[v];
			while(temp!=NULL)
			{
				if(d[temp->ind]==-1)
					d[temp->ind]=temp->we+d[v];

				else if(temp->we+d[v]<d[temp->ind])
				{
					d[temp->ind]=temp->we+d[v];
				}
				insert(temp->ind,d[temp->ind]);
				temp=temp->next;
			}
		}
	}
}

int main()
{

	long long int n,m,i,x,y,x0,y0,w;

	scanf("%lld%lld",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld%lld",&x,&y,&w);
		add(x,y,w);
	}
	scanf("%lld%lld",&x0,&y0);
	d[x0]=0;
	long long int k;

	for(k=0;k<=n;k++)
	{
		xy[k]=0;
		vis[k]=0;
		d[k]=-1;
	}
head=0;
d[x0]=0;
	dij(x0);
	if(d[y0]==-1)
		printf("NO\n");
	else
		printf("%lld\n",d[y0]);


return 0;
}
