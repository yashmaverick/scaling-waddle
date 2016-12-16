#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define oo 10000000000000007
#define ll long long int
ll min(ll x,ll y)
{
	//printf("X=%lld and Y=%lld\n",x,y);
	return x<y?x:y;
}

ll distance[100001]={oo};
typedef struct c
{
	int v;
	ll weight;
}heap;
heap *h[1000001];
int end=-1;
typedef struct d
{
	int data;
	struct d *next;
	ll dis;
}list;
list *e[100001];


void insert(int a,ll b,int x)
{
	list *temp;
	temp=malloc(sizeof(list));
	temp->data=a;
	temp->dis=b;
	temp->next=e[x];
	e[x]=temp;
	return;
}
/*h[0]=malloc(sizeof(heap));
h[0]->weight=-1;
h[0]->v=-1;*/

void insertmin(int a,ll b)
{
	heap *f;
	f=malloc(sizeof(heap));
	f->weight=b;
	f->v=a;
	end++;
	h[end]=f;
	int last=end;
	//int j=last/2;
	while(b<h[last/2]->weight&&last/2!=0)
	{
		h[last]->weight=h[last/2]->weight;
		h[last]->v=h[last/2]->v;
		last=last/2;
	}
	h[last]->weight=b;
	h[last]->v=a;
	return;
}

int deletemin()
{
	//printf("333333333\n");
	ll x=h[end]->weight;
	int er=h[1]->v,child;
	int man=h[end]->v;
	//printf("Removing vertex %d\n",er);
	end--;
	ll w=h[1]->weight;
	h[1]->weight=x;
	h[1]->v=man;
	int j=1;
	for(j=1;j*2<=end;j=child)
	{ //printf("5");
		//printf("%intd\n",heap[j*2]);
		child=j*2;
		if(child!=end&&h[child+1]->weight<h[child]->weight)
			child++;
		if(x>h[child]->weight)
		{	h[j]->weight=h[child]->weight;
			h[j]->v=h[child]->v;
		}
		else
			break;
	}
	h[j]->weight=x;
	h[j]->v=man;
	return er;
}
int visi[100001]={0},n;
int flag=1;
void dijkstra(int s,int dest)
{
	insertmin(-1,-1);
	insertmin(s,0);
	distance[s]=0;
	int i;
	for(i=1;i<=n;i++)
	{
		if(i!=s)
		insertmin(i,oo);
	}
	while(visi[dest]!=1){

	int asd=deletemin();
	//printf("Asd=%d\n",asd);
	if(visi[asd]!=1)
	{
	while(e[asd]->next!=NULL)
	{
		//printf("In here\n");
		ll ty=e[asd]->dis;
		int vert=e[asd]->data;
		//printf("For vertex %d : Distance from %d is %lld\n",vert,asd,ty);
		//printf("Distance of ASD is %lld\n",distance[asd]);
		distance[vert]=min(distance[vert],ty+distance[asd]);
		//printf("Updated distance of %d with %lld\n",vert,distance[vert]);
		//h[vert]->weight=distance[vert];
		insertmin(vert,distance[vert]);
	/*for(i=1;i<=n;i++)
		printf("%d %lld\n",h[i]->v,h[i]->weight);*/
		e[asd]=e[asd]->next;
	}
		visi[asd]=1;
	}
	/*for(i=1;i<=n;i++)
		if(visi[i]!=1)
			flag=0;
	if(flag==1)
		break;}*/
	}
	/*for(i=1;i<=n;i++)
		printf("Distance from source is %lld\n",distance[i]);*/
	if(distance[dest]!=oo)
	printf("%lld\n",distance[dest]);
	else
	printf("NO\n");
	return;	
}

int main()
{
	int m,q,p,i;
	scanf("%d %d",&n,&m);
	for(i=0;i<=n;i++)
	{
		e[i]=malloc(sizeof(list));
		e[i]->data=i;
		e[i]->dis=0;
		distance[i]=oo;
	}
	while(m--)
	{
		int u,ve;
		ll w;
		scanf("%d %d %lld",&u,&ve,&w);
		insert(ve,w,u);
		//insert(u,w,ve);
	}
	/*for(i=1;i<=n;i++)
	{
		list *te=e[i];
		while(te->next!=NULL)
		{
			printf("Node: %d at Distance: %lld from %d\n",te->data,te->dis,i);
			te=te->next;
		}
	}*/
	scanf("%d %d",&q,&p);
	dijkstra(q,p);	
	return 0;
}
