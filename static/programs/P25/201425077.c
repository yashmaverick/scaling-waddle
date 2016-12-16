#include<stdio.h>
#include<stdlib.h>

typedef struct kruskal
{
	long long int from,to,weight;
}node;

typedef struct ll
{
	long long int data;
	struct ll *next;
	
}node1;



int cmp(const void *a,const void *b)
{
	const node *e1 =a;
	const node *e2 =b;

	return e1->weight - e2->weight;
}


long long int findparent(long long int parent[],long long int vertex)
{

	if(parent[vertex]==vertex)
		return vertex;
	else
		return parent[vertex]=findparent(parent,parent[vertex]);
}


void dfs(long long int visited[],node1 *a[],long long int index,int depth)
{
	visited[index]=depth;
	node1 *temp=a[index];

	while(temp)
	{
		if(visited[temp->data]==0)
			dfs(visited,a,temp->data,depth+1);
		
		temp=temp->next;
	}


}
int main()
{
	long long int n,m,i,ans=0;

	node1 *a[100001];
	node b[100001];
	long long int parent[100001],visited[100001];

	scanf("%lld %lld",&n,&m);

	for(i=1;i<=n;i++)
	{
		parent[i]=i;
		a[i]=NULL;
		visited[i]=0;
	}

	for(i=0;i<m;i++)
	{
		long long int t1,t2,weight;

		scanf("%lld %lld %lld",&t1,&t2,&weight);

		b[i].from=t1;
		b[i].to=t2;
		b[i].weight=weight;	


		// make adj list	
		node1 *temp=(node1 *)malloc(sizeof(node1));
	       	temp->next=a[t1];
		a[t1]=temp;
		temp->data=t2;	

		temp=(node1 *)malloc(sizeof(node1));
	       	temp->next=a[t2];
		a[t2]=temp;
		temp->data=t1;	

	}

	qsort(b,m,sizeof(node),cmp);

	dfs(visited,a,1,1);

	long long int flag=0;

	for(i=1;i<=n;i++)
		if(visited[i]==0)
			flag=1;

	if(flag==1)
	{
		printf("-1\n");
		return 0;
	
	}

	//	printf("%lld %lld %lld\n",b[i].from,b[i].to,b[i].weight);
	long long int c=0;
	ans=0;

	for(i=0;i<m;i++)
	{
		if(c==n-1)
			break;

		long long int p1,p2;

		p1=findparent(parent,b[i].from);
		p2=findparent(parent,b[i].to);

		if(p1!=p2)
		{
			c++;
			ans+=b[i].weight;
			parent[p1]=p2;

		}
	
	}


	
	printf("%lld\n",ans);



	return 0;
}
