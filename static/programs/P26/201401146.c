#include<stdio.h>
#include<stdlib.h>
typedef struct node node;
struct node
{
	int val;
	int w;
	node *down;
};
node *insert(node *head,int val)
{
	node *tmp;
	tmp=(node*)malloc(sizeof(node));
	tmp->val=val;
	tmp->w=1;
	tmp->down=head;
	return tmp;
}
node *adj[10000]={NULL};
int vis[10001],pri[10000],num[10001],f,e,k=0;
int que[10000],dis[10001]={0};
void reset()
{
	int i;
	for(i=0;i<=10000;i++)	
	{
		vis[i]=0;
		dis[i]=0;
	}
	f=0;
	e=0;
	return;
}
void sieve_Ert()
{
	int i,j;
	num[1]=1;
	num[0]=1;
	for(i=2;i<10000;i++)
	{
		if(!num[i])
		{
			j=i*i;
			while(j<10000)
			{
				num[j]=1;
				j+=i;
			}
			if(i/1000)
			{
				if(!(i/10000))
					pri[k++]=i;
			}
		}

	}
	return;
}
int dig_chg(int a,int b)
{
	int t=0,o=4;
	while(o--)
	{
		if(a%10==b%10)
			t++;
		a/=10;
		b/=10;
	}
	if(t==3)
		return 1;
	else 
		return 0;
}
void make_graph()
{
	int i,j;
	for(i=0;i<k;i++)
	{
		for(j=i+1;j<k;j++)
		{
			if(dig_chg(pri[i],pri[j]))
			{
				//printf("%d %d\n",pri[i],pri[j]);
				adj[pri[i]]=insert(adj[pri[i]],pri[j]);
				adj[pri[j]]=insert(adj[pri[j]],pri[i]);
			}
		}
	}
}
int BFS(int a,int b)
{
	int d=1,flag=0,l=0;
	while(f<e)
	{
		node *tmp;
		tmp=adj[que[f]];
		while(tmp)
		{
			if(!vis[tmp->val])
			{
				dis[tmp->val]=dis[que[f]]+1;;
				if(tmp->val==b)
				{
					flag=1;
					break;
				}
				vis[tmp->val]=1;
				que[e++]=tmp->val;
				l++;
			}
			tmp=tmp->down;
		}
		if(flag)
			break;
		f++;
	}
	return dis[b];
}
void printG()
{
	int a;
	while(1)
	{
		scanf("%d",&a);
		if(!a)
			break;
		node *tmp;
		tmp=adj[a];
		while(tmp)
		{
			printf("%d ",tmp->val);
			tmp=tmp->down;
		}
		printf("\n");
	}
}
int main()
{
	int t,a,b,d;
	scanf("%d",&t);
	sieve_Ert();
	make_graph();
	//printG();
	while(t--)
	{
		scanf("%d%d",&a,&b);
		if(a==b)
		{
			printf("0\n");
			continue;
		}
		reset();
		que[e++]=a;
		d=BFS(a,b);
		printf("%d\n",d);
	}
	return 0;
}
