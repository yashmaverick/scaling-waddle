//GABBAR studioworks
//aim:use bfs to find the shortest path in a weighted graph

#include<stdio.h>
#include<stdlib.h>
typedef struct link{
	long long int wg;
	int a;
	struct link*next;
}node;
typedef long long int ll;
node*arr[100009];
node*pnt[100009];
int flag;
ll dis[100009];
ll vis[100009];
ll queue[300009];
ll end=0;
ll head=0;
ll ans;
void push(ll r)
{
	queue[end++]=r;
}
int pop()
{
	head++;
	return queue[head-1];
}
//function to create an adjacency list
//absolutely fine
void insert(ll p,ll q,ll w)
{
	node*obj=(node*)malloc(sizeof(node));
	obj->a=q;
	obj->wg=w;
	obj->next=NULL;
	if(arr[p]==NULL)
	{
		arr[p]=obj;
		pnt[p]=arr[p];
	}
	else
	{
		pnt[p]->next=obj;
		pnt[p]=pnt[p]->next;
	}
}
void bfs(ll n,ll m)
{
	flag=0;
	//int dis[100000]={0};
	push(n);
	node*w;
	while(head!=end)
	{ 
		ll x=pop();
		w=arr[x];
		vis[x]=1;
		while(w!=NULL)
		{
			if(vis[w->a]==1)
			{
				if(dis[x]+(w->wg)<dis[w->a])
				{
					dis[w->a]=dis[x]+(w->wg);
					push(w->a);
				}
			}
			if(vis[w->a]!=1)
			{    
				dis[w->a]=dis[x]+(w->wg);
				push(w->a);
				vis[w->a]=1;
			}
			if(w->a==m)
			{
				
				ans=dis[w->a];
				
			}
			w=w->next;

		}
		
	}
}
int main()
{
	ll p,q,test=1,v,e,i;
//	scanf("%d",&test);
	//    printf("enter the vertices and the distance between them and press -1 to exit\n");
	while(test--)
	{
		for(i=0;i<100009;i++)
		{
			
			arr[i]=0;
			pnt[i]=0;
			flag=0;
			vis[i]=0;
			queue[i]=0;
			dis[i]=0;
			end=0;
			head=0;
			ans=0;
		}
		scanf("%lld%lld",&v,&e);
		while(e--)
		{
			scanf("%lld%lld",&p,&q);
			ll d;
			scanf("%lld",&d);
			insert(p,q,d);
			//insert(q,p,d);
		}

		//printf("enter the two vertices\n");
		scanf("%lld%lld",&p,&q);
		if(p==q)
			printf("0\n");
		else
		{
			bfs(p,q);
			if(ans!=0)
			printf("%lld\n",ans);
			else
			printf("NO\n");
		}
	}
	return 0;
}

