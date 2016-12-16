#include<stdio.h>
#include<stdlib.h>

long long int minh[100009][2];
long long int mincount=0;
long long int dist[100005];
long long int vis[100005];
void shuffledownmin(long long int number);
long long int min(long long int a,long long int b);

typedef struct list 
{
	long long int vertex;
	long long int weight;
	struct list *next;
	long long int listflag;
}list;

list *insert(list *head,long long int ver,long long int wei)
{
	list *new=(list *)malloc(sizeof(list));
	new->listflag=0;
	new->vertex=ver;
	new->weight=wei;
	new->next=NULL;
	list *temp;
	temp=head;
	if(head==NULL)
	{
		head=new;
		return head;
	}
	else
	{
		new->next=temp;
		head=new;
		return head;
	}
}

void insertheap(long long int weight,long long int vertex)
{
	long long int x;
	x=mincount+1;
	minh[x][0]=weight;
	minh[x][1]=vertex;
	long long int parent=x/2,temp,temp1;
	while(minh[parent][0]>=minh[x][0] && x!=1 && parent!=0)
	{
		temp=minh[x][0];
		minh[x][0]=minh[parent][0];
		minh[parent][0]=temp;

		temp1=minh[x][1];
		minh[x][1]=minh[parent][1];
		minh[parent][1]=temp1;

		x=x/2;
		parent=parent/2;
	}
}

long long int deletemin()
{
	long long int tmp,tmp1;
	tmp=minh[1][0];
	minh[1][0]=minh[mincount][0];

	tmp1=minh[1][1];
	minh[1][1]=minh[mincount][1];

	mincount=mincount-1;
	shuffledownmin(minh[1][0]);
	return tmp1;
}

void shuffledownmin(long long int num)
{
	long long int i=1,mini,temp,j,mini1,temp1;
	while(i<=mincount/2 && (num >= minh[2*i][0] || num >= minh[2*i+1][0]) && (2*i+1)<=mincount)
	{
		if(2*i<mincount)
		{
			mini=min(minh[2*i][0],minh[2*i+1][0]);
			if(mini==minh[2*i][0])
			{
				mini1=minh[2*i][1];
				j=2*i;
			}

			else 
			{
				j=2*i+1;
				mini1=minh[2*i+1][1];
			}
		}
		else 
		{
			mini=minh[2*i][0];
			j=2*i;
			mini1=minh[2*i][1];
		}	

		temp=mini;
		minh[j][0]=minh[i][0];
		minh[i][0]=temp;

		temp1=mini1;
		minh[j][1]=minh[i][1];
		minh[i][1]=temp1;

		i=j;
	}
	if(2*i == mincount) 
		if(num>minh[2*i][0]) 
		{ 
			temp=minh[i][0]; 
			minh[i][0]=minh[2*i][0]; 
			minh[2*i][0]=temp;

			temp1=minh[i][1];
			minh[i][1]=minh[2*i][1]; 
			minh[2*i][1]=temp;
		}
}

long long int min(long long int a,long long int b)
{
	if(a<=b)
		return a;
	return b;
}

int main()
{
	minh[0][0]=-1;
	minh[0][1]=-1;
	mincount=0;
	list *head[100005];
	long long int n,m,u,v,weight,i,s,t;
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)
	{	
		head[i]=NULL;
		dist[i]=10000000000000009;
		vis[i]=0;
	}
	while(m--)
	{
		scanf("%lld%lld%lld",&u,&v,&weight);
		head[u]=insert(head[u],v,weight);
	}
	scanf("%lld %lld",&s,&t);
	dist[s]=0;
	vis[s]=1;
	list *temp;
	while(s!=t)
	{
		temp=head[s];
		while(temp!=NULL)
		{
			if(vis[temp->vertex]==0)
			{
				if(dist[temp->vertex] > temp->weight + dist[s])
				{
					dist[temp->vertex] = temp->weight + dist[s];
					insertheap(dist[temp->vertex],temp->vertex);
					mincount++;
				}
			}
			temp=temp->next;
		}

		long long int w,flag=0,finsrc=s;
		if(mincount==0)
		{ 
			printf("NO\n");
			return 0;
		}

		loop:
		s=deletemin();
		if(s==finsrc || vis[s]==1)
		{
			goto loop;
		}
		vis[s]=1;
		if(s==t)
		{
			printf("%lld\n",dist[s]);
			return 0;
		}
	}
	return 0;
}
