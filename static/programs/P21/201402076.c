#include<stdio.h>
#include<stdlib.h>
struct pii
{
	long long int f;
	int s;
};
typedef struct pii pii;
struct node
{
	pii val; 	
	struct node* next;
};
typedef struct node node;
node* insert(node* head,long long int w,int u)
{
	node* temp=(node*)malloc(sizeof(node));
	temp->val.f=w;
	temp->val.s=u;
	temp->next=head;
	return temp;
}
node* adj[100005]={NULL};
int vis[100005]={0};
long long int dist[100005]={0};
long long int inf=10000000000000000;
pii heaps[1100005];
int heapsize=0;

void insertheap(long long w,int v)
{
//	printf("%lld %dokh\n",w,v);
	heapsize++;
	pii temp;
	temp.f=w;
	temp.s=v;
	heaps[heapsize]=temp;
	int ind=heapsize;
	while(ind>1)
	{
		if(heaps[ind].f<heaps[ind/2].f)
		{
			temp=heaps[ind];
			heaps[ind]=heaps[ind/2];
			heaps[ind/2]=temp;
		}
		ind=ind/2;
	}
}


pii heappop()
{
//	printf("okp%d\n",heapsize);
	pii poop=heaps[1];
	heaps[1]=heaps[heapsize];
	heapsize--;
	int ind=1;
	if(ind>heapsize)
		return heaps[1];
	while(1)
	{
		int maxind=2*ind;
		if(maxind>heapsize)
			break;
		if(heaps[maxind].f>heaps[maxind+1].f&&maxind+1<=heapsize)
		{
			maxind++;
		}
		if(heaps[ind].f>heaps[maxind].f)
		{
			pii temp=heaps[ind];
			heaps[ind]=heaps[maxind];
			heaps[maxind]=temp;
		}
		ind=maxind;
		if(ind>heapsize)
			break;
	}
	return poop;
}
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	int i;
	for(i=0;i<m;i++)
	{
		int u,v;
		long long w;
		scanf("%d %d %lld",&u,&v,&w);
		u--;
		v--;
		adj[u]=insert(adj[u],w,v);
//		arr[u]++;
	}
	int y,z;
	scanf("%d %d",&y,&z);
	y--;z--;
	for(i=0;i<n;i++)
		dist[i]=inf;
	dist[y]=0;
	insertheap(0,y);
	while(heapsize!=0)
	{
		pii temp=heappop();
	//	printf("hp%d\n",temp.s);
		if(vis[temp.s])
			continue;
		int u=temp.s;
		dist[u]=temp.f;
		vis[u]=1;
		node* head=adj[u];
		while(head!=NULL)
		{
			int v=head->val.s;
			if(!vis[v])
			{
				long long w=head->val.f;
				if(dist[v]>dist[u]+w)
				{
					dist[v]=dist[u]+w;
					insertheap(dist[v],v);
				}
			}
			head=head->next;
		}	
	}
	if(dist[z]==inf)
		printf("NO\n");
	else
		printf("%lld\n",dist[z]);
	return 0;
}
