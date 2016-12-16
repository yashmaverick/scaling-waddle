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
#define max(a,b) a>b?a:b
#define min(a,b) a<b?a:b

typedef struct vertex
{
	struct vertex *adj;
	int data;
}vertex;

vertex *head[1000000];

vertex* insert(vertex *index,int val)
{
	vertex *temp;
	temp = (vertex *)malloc(sizeof(vertex));
	temp->data = val;
	temp->adj = NULL;
	if(index == NULL)
	{
		index = (vertex *)malloc(sizeof(vertex));
		index = temp;
	}
	else
	{
		temp->adj = index;
		index = temp;
	}
	return index;
}

/*void print(int index)						//function to print the adjacency list
{
	vertex *temp;
	temp = (vertex *)malloc(sizeof(vertex));
	int i;
	i = 0;
	temp = head[index];;
	while(temp != NULL)
	{
		pi(temp->data);
		tab;
		temp = temp->adj;
	}
	endl;
	i++;
	return ;
}*/

int maxdepth=0;
int start;
int vis[1000000];					//to check if a node has been visited or not

void dfs(int node,int depth)				//finding the deepest node in the tree
{	
	if(depth > maxdepth)
	{
		start = node;
		maxdepth = depth;
	}
	vis[node-1] = 1;
	vertex *temp;
	temp = (vertex *)malloc(sizeof(vertex));
	temp = head[node -1];
	++depth;
	while(temp != NULL)
	{
		if(vis[(temp->data)-1] == 0)
			dfs(temp->data,depth);
		temp = temp->adj;
	}
	vis[node-1] = 2;
	return ;
}

int main()
{
	int t;
	gi(t);
	while(t--)					//t <= 10
	{
		int n,i,node1,node2,j;     		//n<10^6
		gi(n);
		memset(vis,0,1000000);
		for( i=0 ; i<n-1; i++ )
		{
			gi(node1);
			gi(node2);
			head[node1-1]=insert(head[node1-1],node2);
			head[node2-1]=insert(head[node2-1],node1);
		}
		start = 1;				//defining the maxdistance node to be root at the start of every test case 
		maxdepth= 0;				//defining maxdepth to be 0 at start of every test case
		dfs(1,0);
		maxdepth = 0;
		memset(vis,0,1000000);
		dfs(start,1);				//start is the farthermost point of the graph
		pi(maxdepth);			
		endl;		
/*		for (i=0 ; i<=n ; i++)			print the adjacency list
			print(i);*/
		for(i=0;i<=n;i++)			//initialize the head variable to 0 every time the test case starts.
			head[i]=NULL;
	}
	return 0;
} 
