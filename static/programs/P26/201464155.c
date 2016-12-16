#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define oo 10000000000000007
#define ll long long int
int arr[10001]={0};
ll di[1061][1061]={oo};
int prime[10001],b[10001],v[10001],vim[10001];
void sieve()
{
	int i,j;
	/*for(i=2;i<10000;i++)
	  arr[i]=0;*/
	for(i=2;i<=100;i++)
	{	if(arr[i]==0)
		for(j=i;i*j<=10000;j++)
			arr[i*j]=1;
	}
	return;
}
ll min(ll x,ll y)
{
	//printf("X=%lld and Y=%lld\n",x,y);
	return x<y?x:y;
}

ll distance[10001]={oo};
typedef struct c
{
	int v;
	ll weight;
}heap;
heap *h[10001];
int end=-1;
typedef struct d
{
	int data;
	struct d *next;
	ll dis;
}list;
list *e[10001];
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
int visi[10001]={0},n;
int flag=1,po;
void dijkstra(int s,int des)
{
		insertmin(s,0);
		distance[s]=0;
		int i,asd;
		while(end>=1)
		{
			asd=deletemin();
			//printf("Asd=%d and end=%d\n",asd,end);
			if(visi[asd]!=1)
			{
				list *tem=e[asd];
				while(tem->next!=NULL)
				{
					ll ty=tem->dis;
					int vert=tem->data;
					distance[vert]=min(distance[vert],ty+distance[asd]);
					insertmin(vert,distance[vert]);
					tem=tem->next;
				}
		//printf("S=%d and ASD=%d and Distance=%lld\n",s,asd,distance[asd]);
				di[prime[s]][prime[asd]]=distance[asd];
				di[prime[asd]][prime[s]]=distance[asd];
				visi[asd]=1;
			}	

		}
			if(di[prime[s]][prime[des]]==oo)
				printf("Impossible\n");
			else
				printf("%lld\n",di[prime[s]][prime[des]]);
		int k;
		vim[s]=1;
		for(k=0;k<po;k++)
		{
			visi[b[k]]=0;
			distance[b[k]]=oo;
		}
		end=0;
return;	
}

int main()
{	sieve();
	arr[0]=1;
	arr[1]=1;
	int u,count=0,j;
	for(u=1000;u<=10000;u++)
	{	if(arr[u]==0)
		{
			b[po]=u;
			prime[u]=po;
			po++;
		}
	}
	//printf("%d\n",count);
	int m,q,p,i,k;
	for(i=0;i<po;i++)
	{
		e[b[i]]=malloc(sizeof(list));
		e[b[i]]->data=i;
		e[b[i]]->dis=0;
		distance[b[i]]=oo;
	}
	for(k=0;k<po;k++)
	{
		int y=4,c=1;
		while(y--)
		{
			int l=0;
			int temp=b[k],hell=b[k];
			temp=temp/c;
			temp=temp%10;
			hell=hell-temp*c;
			if(c==1000)
				l++;
			//printf("Hell=%d for %d\n",hell,k);
			for(l;l<=9;l++)
			{
				int pop=hell+l*c;
				//printf("Pop=%d for hell=%d\n",pop,hell);
				if(v[b[k]]!=1&&arr[pop]==0)
				{
				//	printf("Inserting edge between %d and %d\n",b[k],pop);
					insert(b[k],1,pop);
					insert(pop,1,b[k]);
				}
			}
			c=c*10;
		}
		v[b[k]]=1;
	}

	//dijkstra();
	int t;
	scanf("%d",&t);
		insertmin(-1,-1);
	while(t--)
	{
		int p,q;
		scanf("%d %d",&p,&q);
		if(vim[p]==1)
		{
			if(di[prime[p]][prime[q]]==oo)
				printf("Impossible\n");
			else
				printf("%lld\n",di[prime[p]][prime[q]]);
		}
		else if(vim[q]==1)
		{
			if(di[prime[q]][prime[p]]==oo)
				printf("Impossible\n");
			else
				printf("%lld\n",di[prime[q]][prime[p]]);
		}
		else
			dijkstra(p,q);

	}
	return 0;
}
