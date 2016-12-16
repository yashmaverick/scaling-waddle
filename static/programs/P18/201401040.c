#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<math.h>

#define gu getchar_unlocked 
#define pu putchar_unlocked
#define lli long long int
#define ulli unsigned long long int
#define din(n) scanf("%d",&n)
#define dout(n) printf("%d\n",n)
#define lldin(n) scanf("%lld",&n)
#define lldout(n) printf("%lld\n",n)
#define test() int t; din(t); while(t--)
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)<(b)?(b):(a))
#define loop(n) for(i=0;i<n;i++)

int count=1;
typedef struct node{
	int data;
	struct node* next;
}node;
int visited[1005];
node* vertices[1005]={};
node* vertices_2[1005]={};

void dfs1(int nodevalue)
{
	visited[nodevalue]=1;
	node* temp;
	temp=vertices[nodevalue];
	while(temp!=NULL)
	{
		if(!visited[temp->data])
		{
			count++;
			dfs1(temp->data);
		}
		temp=temp->next;
	}
}

void dfs2(int nodevalue)
{
	visited[nodevalue]=1;
	node* temp;
	temp=vertices_2[nodevalue];
	while(temp!=NULL)
	{
		if(!visited[temp->data])
		{
			count++;
			dfs2(temp->data);
		}
		temp=temp->next;
	}
}



int main()
{
	test()
	{

		int n,m,temp1,i,j;
		din(n);
		for(i=1;i<=n;i++)
		{
			vertices[i]=NULL;
			vertices_2[i]=NULL;
			visited[i]=0;
		}
		node* temp=NULL;
		for(i=1;i<=n;i++)
		{
			int p;
			din(m);
			for(p=0;p<m;p++)
			{
				din(temp1);
				temp=(node*)malloc(sizeof(node));
				temp->data=i;
				temp->next=vertices[temp1];
				vertices[temp1]=temp;

				temp=(node*)malloc(sizeof(node));
				temp->data=temp1;
				temp->next=vertices_2[i];
				vertices_2[i]=temp;
			}
		}
		if(n==1)
		{
			dout(1);
			continue;
		}
		int myflag=0;
		count=1;
		for(i=1;i<=n;i++)
		{
			//int flag=1;
			dfs1(i);
			if(count==n)
			{
				myflag=1;
				break;
			}
			for(j=1;j<=n;j++)
			{
		//		if(visited[j]==0)
		//			flag=0;
				visited[j]=0;
			}
		//	if(flag)
		//		break;
			count=1;
		}
		for(j=1;j<=n;j++)
			visited[j]=0;
		//dout(i);
		//dout(myflag);
		if(!myflag)
			dout(0);
		else
		{
			count=1;
			dfs2(i);
			dout(count);
		}
		
	}
	return 0;
}
