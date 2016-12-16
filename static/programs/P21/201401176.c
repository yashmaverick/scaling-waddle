#include<stdio.h>
#include<stdlib.h>
long long int sz=0,ind[100005];
typedef struct node
{
	long long int val;
	long long int weight;
	struct node *next;
}node;
typedef struct st
{
	long long int val;
	long long int weight;
}st;
node *a[100005];
long long int visited[100005],k,v;
long long int dis[100005];
st heap[100005];
void adjlinsert(long long int x,long long int y,long long int w)
{
	node *new;
	if(a[x]==NULL)
	{
		a[x]=(node*)malloc(sizeof(node));
		a[x]->val=y;
		a[x]->next=NULL;
		a[x]->weight=w;
	}
	else
	{
		new=(node*)malloc(sizeof(node));
		new->val=y;
		new->weight=w;
		new->next=a[x];
		a[x]=new;
	}
}
void shup(st heap[],long long int p)
{
	long long int i,x;
	st t;
	/*i=p+1;
	while(i>1)
	{
		if(heap[i-1].weight<heap[i/2-1].weight)
		{
			t=heap[i-1];
			heap[i-1]=heap[i/2-1];
			heap[i/2-1]=t;
			x=ind[i-1];
			ind[i-1]=ind[i/2-1];
			ind[i/2-1]=x;
			i=i/2;
		}
		else
			break;
	}*/
	i=p;
	while(i>0)
	{
		if(heap[i].weight<heap[(i-1)/2].weight)
		{
			t=heap[i];
			heap[i]=heap[(i-1)/2];
			heap[(i-1)/2]=t;
			/*x=ind[i];
			ind[i]=ind[(i-1)/2];
			ind[(i-1)/2]=x;*/
			ind[heap[i].val]=i;
			ind[heap[(i-1)/2].val]=(i-1)/2;
			i=(i-1)/2;
		}
		else
			break;
	}
}
void heapinsert(st heap[],long long int v,long long int w)
{
	long long int i;
	sz++;
	heap[sz-1].weight=w;
	heap[sz-1].val=v;
	ind[v]=sz-1;
	shup(heap,sz-1);
}
void shdown(st heap[],long long int i)
{
	long long int min,p,c;
	st t;
	while(i<sz)
	{
		/*min=(heap[2*i+1].weight>heap[2*i+2].weight)?2*i+2:2*i+1;
		  if(heap[i].weight>heap[min].weight)
		  {
		  t=heap[min];
		  heap[min]=heap[i];
		  heap[i]=t;
		  p=ind[min];
		  ind[min]=ind[i];
		  ind[i]=p;
		  i=min;
		  }*/
		c=2*i+1;
		if(c>=sz)
			break;
		if(c+1<sz && heap[c].weight>heap[c+1].weight)
			c+=1;
		if(heap[i].weight>heap[c].weight)
		{
			t=heap[c];
			heap[c]=heap[i];
			heap[i]=t;
			ind[heap[i].val]=i;
			ind[heap[c].val]=c;
			i=c;
		}
		else
			break;
	}

}
long long int deletemin(st heap[])
{
	long long int x;
	x=heap[0].val;
	heap[0]=heap[sz-1];
	ind[heap[0].val]=0;
	sz--;
	shdown(heap,0);
	return x;
}
void dijk(long long int src,long long int dest)
{
	long long int i,x,p;
	node *temp;
	for(i=1;i<=v;i++)
	{
		visited[i]=0;
		dis[i]=10000000000000;
	}
	visited[src]=1;
	heapinsert(heap,src,0);
	dis[src]=0;
	while(sz>0)
	{
		p=deletemin(heap);
		visited[p]=1;
		temp=a[p];
		x=p;
		while(temp!=NULL)
		{
			if(visited[temp->val]!=1)
			{
				if(ind[temp->val]==-1114)
				{   
					dis[temp->val]=dis[x]+temp->weight;
					heapinsert(heap,temp->val,dis[temp->val]);
				//for(i=0;i<sz;i++)
				//	printf("%lld %lld an ",heap[i].val,heap[i].weight);
		//printf("\n");
				}
				else if(dis[temp->val]>dis[x]+temp->weight)
				{
					dis[temp->val]=dis[x]+temp->weight;
					heap[ind[temp->val]].weight=dis[temp->val];
					//shdown(heap,ind[temp->val]);
					shup(heap,ind[temp->val]);
				}
				//	printf("%lld %lld\n",temp->val,dis[temp->val]);
			}
			temp=temp->next;
		}
	}
}
int main()
{
	long long int arr[100005],r,o,i,v1,v2,w;
	//node *temp;
	scanf("%lld%lld",&v,&k);
	for(i=0;i<k;i++)
	{
		scanf("%lld%lld%lld",&v1,&v2,&w);
		adjlinsert(v1,v2,w);
	}
	for(i=1;i<=v;i++)
		ind[i]=-1114;
			/*for(i=1;i<=v;i++)
			{
			printf("%lld-> ",i);
			temp=a[i];
			while(temp!=NULL)
			{
			printf("%lld %lld and ",temp->val,temp->weight);
			temp=temp->next;
			}
			printf("\n");
			}*/
	scanf("%lld%lld",&r,&o);
	dijk(r,o);
	if(dis[o]==10000000000000)
		printf("NO\n");
	else
		printf("%lld\n",dis[o]);

	return 0;
}
