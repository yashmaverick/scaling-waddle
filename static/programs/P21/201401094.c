#include<stdio.h>
#include<stdlib.h>
#define INF 1000000000000000009
typedef long long int ll;
typedef struct adj{
	int val;
	int dist;
	struct adj *next;
}node;
typedef struct heap{
	ll tdis;
	int nn;
}hp;
hp heap[500020];int pos[500020];node *adj[500020];
int vis[500020];
void print(hp *hs,int n)
{
	int i;
	for(i=1;i<n;i++)
	{
			printf("tdis:%lld: nn:%d ",hs[i].tdis,hs[i].nn);
	}
	printf("\n");
}
void pr(int *hs,int n)
{
	int i;
	for(i=1;i<n;i++)
	{
			printf("pos:%d ",hs[i]);
	}
	printf("\n");
}
void swap(int i)
{
  int t;
	hp temp;
  t=pos[heap[i].nn];
  pos[heap[i].nn]=pos[heap[i>>1].nn];
  pos[heap[i>>1].nn]=t;
	temp=heap[i];
  heap[i]=heap[i>>1];
  heap[i>>1]=temp;
}
node* insert(node *head,int val,int dist)
{
	node *temp=malloc(sizeof(node));
	temp->val=val;
	temp->dist=dist;
	temp->next=head;
	return temp;
}
void update(int i)
{
	int t;
	while(i>1 && heap[i].tdis<heap[i>>1].tdis)
  {
    swap(i);
    i=i>>1;
  }
//   printf("update\n");
//  print(heap,n+1);
//  pr(pos,s);
}
void shuldn(int n)
{
	int i=2,t;
//printf(" start shldn\n");
//		print(heap,n+1);
	while(i<n)
	{
		if(i+1<=n && heap[i+1].tdis<heap[i].tdis)
			i=i+1;
		if(heap[i].tdis<heap[i>>1].tdis)
		{
			swap(i);
		}
		i=i<<1;
	}
//  printf("end shldn\n");
//print(heap,n+1);
 // pr(pos,s);
}
ll  dij(int ch,int n)
{
	int hd;
	ll dis;
	while(n!=1 &&  heap[1].nn!=ch)
	{
		hd=heap[1].nn;
		vis[hd]=1;
		dis=heap[1].tdis;
		heap[1]=heap[n];
    pos[heap[n].nn]=1;
		n--;
		shuldn(n);
		node *head=adj[hd];
		while(head!=NULL)
		{
   //     printf("val:%d && vis:%d\n",head->val,vis[head->val]);
			if(vis[head->val]!=1)
			{
				if(heap[pos[head->val]].tdis>dis+(ll)(head->dist))
				heap[pos[head->val]].tdis=dis+(ll)(head->dist);
  //      printf("val:%d && pos:%d\n",head->val,pos[head->val]);
				update(pos[head->val]);	
			}
			head=head->next;
		}
//printf(" dij\n");
//print(heap,n+1);
//pr(pos,n+1);
	}
	if(heap[1].nn==ch && heap[1].tdis!=INF)
		return heap[1].tdis;
	else
		return -1;
}
void frp( node *head)
{
	if(head==NULL)
		return;
	frp(head->next);
	free(head);
}
void prp( node *head)
{
	if(head==NULL)
  {printf("\n");		return ;}
  printf("%d ",head->val);
	prp(head->next);
}
int main()
{
	int i,m,t,a,b,w,st,ch,n;
  ll  ans;
//	scanf("%d",&t);

	//while(t--)
//	{
		scanf("%d %d",&n,&m);
		for(i=0;i<=n;i++)
		{
			heap[i].tdis=INF;
			heap[i].nn=i;
			pos[i]=i;
			vis[i]=0;
			adj[i]=NULL;
		}
		for(i=0;i<m;i++)
		{
			scanf("%d %d %d",&a,&b,&w);
			adj[a]=insert(adj[a],b,w);
		}
		scanf("%d %d",&st,&ch);
		heap[1].tdis=0;
		heap[1].nn=st;
		heap[st].nn=1;
		pos[st]=1;
		pos[1]=st;
  //  print(heap,n+1);
  //  pr(pos,n+1);
		ans=dij(ch,n);
    if(ans!=-1)
		printf("%lld\n",ans);
    else
    printf("NO\n");
		for(i=1;i<=n;i++)
			frp(adj[i]);
//	}
	return 0;
}
