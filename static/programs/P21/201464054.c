#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>
#define ll long long int
#define ull unsigned long long int
#define sint(n); scanf("%d",&n);
#define pint(n); printf ("%d\n",n);
#define sll(n); scanf("%lld",&n);
#define pll(n); printf("%lld\n",n);
#define pull(n); printf("%llu\n",n);
#define sst(n); scanf("%s",n);
#define pst(n); printf ("%s\n",n);
#define TEST ll test;scanf("%lld",&test);while(test--)
#define f0(i,n) for(i=0;i<n;i++)
#define f1(i,n) for(i=1;i<=n;i++)
#define f1r(i,n) for(i=n;i>=1;i--)
#define f0r(i,n) for(i=n;i>0;i--)
#define set(x,y) memset(x,y,sizeof(x));


ll maxend;


ll n;
int visited[200005];
ull dist[200005];
struct hp
{
	int cityno;
	ll distance;
}heap[200005];
ll end;
void insertheap(ll x, ll y)
{
	end++;
	heap[end].cityno=x;
	heap[end].distance=y;
	ll currind;
	struct hp t;
	currind=end;
	while (currind!=1)
	{
		if (heap[currind/2].distance>heap[currind].distance)
		{
			t=heap[currind/2];
			heap[currind/2]=heap[currind];
			heap[currind]=t;
			currind=currind/2;
		}
		else
			break;
	}
//	if (maxend<end)
//		maxend=end;
	return;
}
struct hp delroot()
{
	struct hp ret;
	ret=heap[1];
	heap[1]=heap[end];
	end--;
	ll currind;
	struct hp t;
	currind=1;
	while (1)
	{
		//	printf ("del\n");
		if (2*currind>end)
			break;
		if (2*currind == end)
		{
			if (heap[currind].distance>heap[2*currind].distance)
			{
				t=heap[2*currind];
				heap[2*currind]=heap[currind];
				heap[currind]=t;
				currind=2*currind;
			}
			else
				break;
		}
		else
		{
			if (heap[currind].distance<=heap[2*currind].distance && heap[currind].distance<=heap[(2*currind)+1].distance)
				break;
			else
			{
				if (heap[2*currind].distance<=heap[(2*currind)+1].distance)
				{
					t=heap[2*currind];
					heap[2*currind]=heap[currind];
					heap[currind]=t;
					currind=2*currind;
				}
				else if (heap[2*currind].distance>heap[(2*currind)+1].distance)
				{
					t=heap[(2*currind)+1];
					heap[(2*currind)+1]=heap[currind];
					heap[currind]=t;
					currind=(2*currind)+1;
				}
			}
		}
	}
//	if (maxend<end)
//		maxend=end;
	return ret;
}



int check[200005],dfscheck[200005];
struct node
{
	ll data;
	ll cost2;
	struct node* next;
};
struct node* head[200005];


void insertll ( ll x, ll y, ll z)
{
	if ( check[x] == 0 )
	{
		head[x]->data=y;
		head[x]->cost2=z;
		head[x]->next=NULL;
	}
	else
	{
		struct node* temp;
		temp=malloc(sizeof(struct node));
		temp->data=y;
		temp->cost2=z;
		temp->next=head[x];
		head[x]=temp;
	}
	return;
}
void insert ( ll x, ll y, ll z)
{
	if (check[x]==0)
	{
		head[x]=malloc(sizeof(struct node));
		head[x]->next=NULL;
		check[x]=1;
	}
	if (check[y]==0)
	{
		head[y]=malloc(sizeof(struct node));
		head[y]->next=NULL;
		check[y]=1;
	}
	insertll(x,y,z);
	//    insertll(y,x);
	return;
}
void printll()
{
	ll i;
	struct node* temp2;
	temp2=malloc(sizeof(struct node));
	for (i=0;i<100005;i++)
		if (check[i] == 1)
		{
			printf ("%lld :: ",i);
			temp2=head[i];
			while (temp2->next!=NULL)
			{
				//				        printf ("entered  ");
				printf ("%lld ( %lld ) -> ",temp2->data,temp2->cost2);
				temp2=temp2->next;
			}
			printf ("\n");
			//		printf ("%lld\n",temp2->data);
		}
//	printf ("compp\n");
	return;
}
int flag;
ll minimum(ll dist[])
{
	ll ans=INT_MAX,i;
	for (i=1;i<=n;i++)
		if (visited[i]==0 && visited[i]<ans)
			ans=i;
	return ans;
}
void printheap()
{
	ll i;
	printf ("Heap : ");
	for (i=1;i<=end;i++)
		printf ("%d (%lld) -- ",heap[i].cityno,heap[i].distance);
	printf ("\n");
	return;
}
ull mindist(ll u, ll v)
{


	ll ans,i,j;
	struct node* temp;
	struct hp tmp2;
	temp=malloc(sizeof(struct node));
	temp=head[u];
	insertheap(u,0);
	while (end>0)
	{
		if (visited[v]==1)
			break;
		while (1)
		{
			tmp2=delroot();
			u=tmp2.cityno;//check
			if (end == 0 || (visited[tmp2.cityno]==0 && tmp2.distance==dist[tmp2.cityno]))
				break;
		}
		temp=head[tmp2.cityno];
//		pint(tmp2.cityno);
		while (temp->next!=NULL)
		{
			if (dist[temp->data]>dist[u]+temp->cost2 && visited[temp->data]==0)
			{
				dist[temp->data]=dist[u]+temp->cost2;
				insertheap(temp->data,dist[temp->data]);
			}
			temp=temp->next;
		}
		visited[u]=1;
	}
	free(temp);
	return dist[v];
}
int isinstack[100005];
void dfs ( ll x )
{
	int stack[500005];
	struct node* temp;
	ll y/*,lev*/;
	temp=malloc(sizeof(struct node));
	ll top;
	top=0;
	stack[top]=x;
	dfscheck[x]=1;
	while (top>=0)
	{
		y=stack[top];
//		printf ("%lld -> ",y);
		top--;
		dfscheck[y]=1;
		if (check[y]==0)
			return;
		temp=head[y];
		while (temp->next!=NULL)
		{
			if (dfscheck[temp->data]==0 && isinstack[temp->data]==0)
			{
				stack[++top]=temp->data;
				isinstack[temp->data]=1;
			}
			temp=temp->next;
		}
	}
	return;
}


ll isconnected (ll u, ll v)
{
	dfs(u);
	return dfscheck[v];
}




int main()
{

//	maxend=-1;



	ll u,v,w,i,j,m;
	set(check,0);
	sll(n);	sll(m);
	f0(i,m){sll(u);	sll(v);	sll(w);	insert(u,v,w);	/*insert(v,u,w);*/}
//	printll();
	for (i=1;i<=n;i++)
	{
		dist[i]=ULLONG_MAX;
		visited[i]=0;
	}
//	f1(i,n){printf ("%llu\n",dist[i]);}
	sll(u);	sll(v);
	set(dfscheck,0);
	set(isinstack,0);
//	printf("hererere\n");
	if (isconnected(u,v)==1)
	{
//	printf ("returns\n");
		dist[u]=0;
		end=0;
//		printf("ttttttt\n");
		ull xyxc;
		xyxc=(mindist(u,v));
		pull(xyxc);
//		printf ("maxend = %lld\n",maxend);
	}
	else
		printf ("NO\n");
	return 0;
}
