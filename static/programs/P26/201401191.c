#include<stdio.h>
#include<stdlib.h>
typedef struct node node;
struct node{
	int val;
	node* next;
};
int a[10000];
int b[1100];
node* adj[10000];
int par[10000],temp[10000];
int qu[10000];
int vis[10000];
void insert(int,int);
void create_sieve()
{
	int i,j;
	a[1]=0;
	for(i=2;i<10000;i++)
	{
		if(a[i])
		{
			for(j=2;i*j<10000;j++)
			{
				a[i*j]=0;
			}
		}
	}
}
int main()
{
	int i,j,src,dest,t;
	int count=0,k=0;
	for(i=0;i<10000;i++)
	{
		adj[i]=NULL;
		a[i]=1;
	}
	create_sieve();
	for(i=1000;i<10000;i++)
	{
		if(a[i])
		{
			b[k++]=i;
			//	printf("%d ",i);
		}
	}
	//	printf("%d\n",k);
	for(i=0;i<k;i++)
	{
		for(j=0;j<k;j++)
		{
			if(check(b[i],b[j]))
			{
				insert(b[i],b[j]);
			}
		}
	}
/*	node* nn;
	for(nn=adj[1009];nn!=NULL;nn=nn->next)
	printf("%d\n",nn->val); */
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&src,&dest);
		for(i=0;i<10000;i++)
		{
			par[i]=0;
			vis[i]=0;
			temp[i]=-1;
		}
		int tmp,st=0,end=0;
		vis[src]=1;
		qu[end++]=src;
		temp[src]=0;
		par[src]=src;
		while(st<end)
		{
			tmp=qu[st++];
			node* tt=adj[tmp];
			while(tt!=NULL)
			{
				if(!vis[tt->val])
				{
					//				printf("AFDDS\n");
					vis[tt->val]=1;
					par[tt->val]=tmp;
					qu[end++]=tt->val;
				}
				tt=tt->next;
			}
			temp[tmp]=temp[par[tmp]]+1;
			if(temp[dest]!=-1)
			{
				break;
			}  
		}
		if(temp[dest]==-1)
		{
			printf("Impossible\n");
		}
		else
		{
			printf("%d\n",temp[dest]-1);
		}
	}
	//	printf("%d\n",count);
	return 0;
}
int check(int a,int b)
{
	int a1[4],a2[4];
	int n1=a;
	int n2=b;
	int k=3;
	while(n1)
	{	
		a1[k--]=n1%10;
		n1/=10;
	}
	k=3;
	while(n2)
	{
		a2[k--]=n2%10;
		n2/=10;
	}
	k=0,n1=0,n2=0;
	while(k<4&&a1[k]==a2[k])
	{
		n1++;
		k++;
	}
	k++;
	while(k<4&&a1[k]==a2[k])
	{
		n2++;
		k++;
	}
	if(n1+n2==3)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void insert(int a,int b)
{
	node* ttmp=(node*)malloc(sizeof(node));
	ttmp->val=b;
	ttmp->next=adj[a];
	adj[a]=ttmp;
}
