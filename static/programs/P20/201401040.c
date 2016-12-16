#include<stdio.h>
#include<stdlib.h>
#define pu putchar_unlocked
#define lli long long int
#define ulli unsigned long long int
#define din(n) scanf("%d",&n)
#define dout(n) printf("%d\n",n)
#define lldin(n) scanf("%lld",&n)
#define lldout(n) printf("%lld\n",n)
#define test() int t;din(t);while(t--)
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)<(b)?(b):(a))
#define loop(n) for(i=0;i<n;i++)
int cmpfunc(const void *a,const void *b)
{
	return *(int *)a - *(int *)b;
}
int visited[1000005];
int max;
int max_node;
typedef struct node{
	int data;
	struct node* next;
}node;
node* vertices[1000005]={};
void dfs(int nodevalue,int distance)
{
	visited[nodevalue]=1;
	int tempdistance=distance+1;
	if(tempdistance>max)
	{
		max=tempdistance;
		max_node=nodevalue;
	}
	node* temp=vertices[nodevalue];
	while(temp!=NULL)
	{
		if(!visited[temp->data])
			dfs(temp->data,tempdistance);
		temp=temp->next;
	}
}

int main()
{
	test()
	{
		max=0;

		int n,temp1,temp2,i;
		node* temp;
		din(n);
		loop(n+1)
		{
			vertices[i]=NULL;
			visited[i]=0;
		}
		loop(n-1)
		{
			din(temp1);
			din(temp2);
			temp=(node*)malloc(sizeof(node));
			temp->data=temp1;
			temp->next=vertices[temp2];
			vertices[temp2]=temp;
			temp=(node*)malloc(sizeof(node));
			temp->data=temp2;
			temp->next=vertices[temp1];
			vertices[temp1]=temp;
		}
		dfs(1,-1);
		int last_node=max_node;
		max=0;
		loop(n+1)
			visited[i]=0;
		dfs(last_node,-1);
		dout(max+1);
		/*loop(n+1)
		{
			node* temp=vertices[i];
			while(temp!=NULL)
			{
				node* tempo=temp->next;
				free(temp);
				temp=tempo;
			}
		}
		*/
	}
			return 0;
		}
