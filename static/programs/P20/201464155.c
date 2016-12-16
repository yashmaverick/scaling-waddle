#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define sc(x) scanf("%lld",&x);
#define ll long long int
typedef struct c
{
	long long int data;
	struct c *next;
	ll dis;
}node;
node *top[1000001];
node *rear[1000001];
node *r;
long long int vis[1000001]={0},max=0,stack[1000001];
ll top1=-1;
ll rear1=0;

void push(ll x)
{
	top1++;
	stack[top1]=x;
	return;
}

ll pop()
{
	ll y=stack[top1];
	top1--;
	return y;
}
void display()
{
		ll z=top1;
		while(z>=0&&stack[z]!=0)
		{	printf("%lld ",stack[z]);
			z--;
		}
		printf("\n");
		return;
}


void dfs()
{
	while(top1!=-1)
	{
			ll he=top[stack[top1]]->dis;
			//printf("he is %lld\n",he);
			ll re=pop();
			vis[re]=1;
			node *tem=top[re];
			//printf("At height %lld for %lld\n",tem->dis,tem->data);
			//if(tem->next==NULL)
			//{
				//printf("IF\n");
				if(tem->dis>max)
				{
					max=tem->dis;
					r=tem;
				}
			//}
			while(tem->next!=NULL)
			{
				tem=tem->next;
				tem->dis=he+1;
				top[tem->data]->dis=he+1;
				if(vis[tem->data]!=1)
					push(tem->data);
			}
			//printf("Displaying:\n");
			//display();
	}
	return;
}


/*void insert(long long int p,long long int q)
  {
  node *temp;
  temp=malloc(sizeof(node));
  temp->data=q;
  temp->next=NULL;
  head1[p]->next=temp;
  head1[p]=temp;
  return;
  }*/
void insertnode(long long int p,long long int q)
{
	node *temp;
	temp=malloc(sizeof(node));
	temp->data=q;
	temp->next=NULL;
	rear[p]->next=temp;
	rear[p]=temp;
	return;
}


int main()
{
	ll t;
	sc(t);
	while(t--)
	{
		ll j;
		ll n,k;
		sc(n);
		int m=n;
		for(j=0;j<=n;j++)
		{
			top[j]=malloc(sizeof(node));
			top[j]->next=NULL;
			top[j]->data=j;
			rear[j]=malloc(sizeof(node));
			rear[j]=top[j];
			r=malloc(sizeof(node));
			vis[j]=0;
		}
		r=NULL;
		n--;
		int i=0,y;
		while(n--)
		{
			ll u,v;
			sc(u);
			sc(v);
			if(i==0)
			{
				y=u;
				i=1;
			}
	//		printf("For %lld and %lld\n",u,v);
			insertnode(u,v);
			insertnode(v,u);
		}
		//printf("In\n");
		push(y);
		top[y]->dis=1;
		dfs();
		//printf("Out\n");
		//printf("Kept: %lld\n",r->data);
		//printf("Max: %lld\n",max);
		max=0;
		for(j=0;j<=m;j++)
			vis[j]=0;
		top1=-1;
		rear1=0;
		push(r->data);
		top[r->data]->dis=1;
		dfs();
		//printf("Kept: %lld\n",r->data);
		//printf("Max: %lld\n",max);
		//printf("Kept: %lld\n",r->data);
		printf("%lld\n",max);
		//		count=0;
		max=0;
		for(j=0;j<=m;j++)
			vis[j]=0;
		top1=-1;
		rear1=0;
	}
	return 0;
}

