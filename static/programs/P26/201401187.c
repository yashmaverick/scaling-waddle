#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int val;
	struct node* next;
}node;
node a[1000010];
int vis[10001],cost[10001],prime[100001]={0},st[10001];
void insert(int x,int v)
{
	node* new=(node*)malloc(sizeof(node));
	new->val=v;
	new->next=a[x].next;
	a[x].next=new;
	return;
}
void sieve()
{
	int i,j,c=0;
	for(i=2;i<500;i++)
	{
		if(prime[i]==0)
			for(j=i*i;j<10001;j=j+i)
				prime[j]=1;
	}
//	for(i=1009;i<=9973;i++)
//		if(prime[i]==0)
//			c++;
//	printf("c=%d\n",c);
	return ;
}
void create()
{
	int p,i,j,l,d,o,rem[5],n,x;
	sieve();
	for(i=0;i<=10001;i++)
		a[i].next=NULL;
	for(i=1009;i<=9973;i++)
	{
		for(j=0;j<10001;j++)
			vis[j]=0;
		if(prime[i]==0)
		{
			for(l=3;l>=0;l--)
			{
				p=i;
				for(d=0;d<=9;d++)
				{
					p=i;
					j=3;
					while(p>0)
					{
						rem[j]=p%10;
						p=p/10;
						j--;
					}
					rem[l]=d;
					n=0;
					x=1;
					for(j=3;j>=0;j--)
					{
						n=n+rem[j]*x;
						x=x*10;
					}
					if(prime[n]==0&&n>=1009&&n<=9973&&vis[n]!=1)
					{
						vis[n]=1;
						insert(i,n);
					}
				}
			}
		}
	}
}
int main()
{
	int i,t,x1,x2,x,flag,fr,r;
	create();
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&x1,&x2);
		for(i=0;i<=10001;i++)
		{
			vis[i]=0;
			cost[i]=-1;
		}
		fr=0;r=0;
		flag=0;
		vis[x1]=1;
		cost[x1]=0;
		st[r]=x1;
		while(fr<=r)
		{
			x=st[fr++];
			node* temp=a[x].next;
			while(temp!=NULL)
			{
				if(vis[temp->val]==0)
				{
					vis[temp->val]=1;
					st[++r]=temp->val;
					cost[temp->val]=cost[x]+1;
					if(temp->val==x2)
					{
						flag=1;
						break;
					}
				}
				temp=temp->next;
			}
			if(flag==1)
				break;
		}
		if(cost[x2]==-1)
			printf("Impossible\n");
		else
			printf("%d\n",cost[x2]);
	}

	return 0;
}

