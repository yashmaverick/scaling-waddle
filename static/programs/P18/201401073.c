#include<stdio.h>
#include<assert.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

int cmpfunc (const void *a , const void *b)
{
	return *(int *)a - *(int *)b ;
}

#define gi(x) scanf("%d",&x)
#define pi(x) printf("%d",x)
#define gc(x) scanf("%c",&x)
#define pc(x) printf("%c",x)
#define glli(x) scanf("%lld",&x)
#define plli(x) printf("%lld",x)
#define gllu(x) scanf("%llu",&x)
#define pllu(x) printf("%llu",x)
#define endl printf("\n")
#define tab printf("\t")
#define space printf(" ")
#define check printf("-------------")
#define max(a,b) a>b?a:b
#define min(a,b) a<b?a:b

void parr(int array[],int start,int end)
{
	int i;
	for(i=start;i<=end;i++)
	{
		pi(array[i]);
		space;
	}
	endl;
	return;
}

typedef struct vertex
{
	struct vertex *adj;
	int data;
}vertex;

vertex *head[1010];
vertex *tail[1010];

void insert(int index,int val)
{
	vertex *temp;
	temp = (vertex *)malloc(sizeof(vertex));
	temp->data = val;
	temp->adj = NULL;
	if(head[index] == NULL)
	{
		head[index] = (vertex *)malloc(sizeof(vertex));
		head[index] = temp;
	}
	else
	{
		temp->adj = head[index];
		head[index] = temp;
	}
	return ;
}

void insert2(int index,int val)
{
	vertex *temp;
	temp = (vertex *)malloc(sizeof(vertex));
	temp->data = val;
	temp->adj = NULL;
	if(tail[index] == NULL)
	{
		tail[index] = (vertex *)malloc(sizeof(vertex));
		tail[index] = temp;
	}
	else
	{
		temp->adj = tail[index];
		tail[index] = temp;
	}
	return ;
}

int vis[1001];
long long int count,count2;


void dfs(int node)
{
	vis[node] = 1;
	vertex *temp;
	temp = (vertex *)malloc(sizeof(vertex));
	temp = head[node];
	while(temp != NULL)
	{
		if(vis[(temp->data)] == 0)
			dfs(temp->data);
		temp = temp->adj;
	}
	vis[node] = 2;
	return ;
}


void dfs2(int node)
{
	count++;
	vis[node] = 1;
	vertex *temp;
	temp = (vertex *)malloc(sizeof(vertex));
	temp = tail[node];
	while(temp != NULL)
	{
		if(vis[(temp->data)] == 0)
			dfs2(temp->data);
		temp = temp->adj;
	}
	vis[node] = 2;
	return ;
}

void set_vis(int array[],int n)
{
	int i;
	for(i=0;i<=n;i++)
		array[i] = 0;
	return ;
}

/*void print(int i)
{
	vertex *temp;
	temp = malloc(sizeof(vertex));
	temp = head[i];
	printf("head : ");
	while(temp!=NULL)
	{
		pi(temp->data);
		space;
		temp = temp->adj;
	}
	endl;
	return ;
}

void print2(int i)
{
	vertex *temp;
	temp = malloc(sizeof(vertex));
	temp = tail[i];
	printf("tail : ");
	while(temp != NULL)
	{
		pi(temp->data);
		space;
		temp = temp->adj;
	}
	endl;
	return ;
}*/

int main()
{
	int t;
	gi(t);
	while(t--)
	{	int n,i,j,m,val,flag;
		gi(n);
		count = 0;
		count2 = 0;
		for(i=1;i<=n;i++)
		{
			gi(m);
			for(j=0;j<m;j++)
			{
				gi(val);
				insert(val,i);
				insert2(i,val);
			}
		}
/*		for(i=1;i<=n;i++)
		{
			print(i);
			print2(i);
		}*/
		for(i=1;i<=n;i++)
		{
			set_vis(vis,n);
			dfs(i);
			flag = 0;
			for(j=1;j<=n;j++)
			{
				if(vis[j] == 0)
				{
					flag = 1;
					break;
				}
			}
			set_vis(vis,n);
			if(flag == 0)
				break;
		}
		dfs2(i);
		for(i=1;i<=n;i++)
		{
			if(vis[i] == 2)
				count2++;
		}
		for(i=1;i<=n;i++)
		{
			head[i] = NULL;
			tail[i] = NULL;
		}
//		plli(count);
	//	endl;
		plli(count2);
		endl;
	}
	return 0;
}
