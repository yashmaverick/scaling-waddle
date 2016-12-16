#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct node
{
	long long int value;
	long long int length;
	struct node *next;
}node;

node * arr[1000001];

node * insert(long long int value,node* root,long long int length)
{
	node* temp=(node *)malloc(sizeof(node));
	temp->value=value;
	temp->length=length;
	temp->next=root;
	return temp;
}

typedef struct heap
{
	long long int value;
	long long int dist;
}heap;

heap min_heap[1000001];

long long int min_end=0;
long long int checked[1000001];


void min_insert(long long int value,long long int dist)
{
	min_end++;

	min_heap[min_end].value=value;
	min_heap[min_end].dist=dist;

	long long int c,f;
	heap temp;

	c=min_end;
	f=c/2;
	while(min_heap[f].dist>min_heap[c].dist)
	{
		if(f<1)
			break;

		temp=min_heap[f];
		min_heap[f]=min_heap[c];
		min_heap[c]=temp;

		c=f;
		f=c/2;
	}
}


void insert_new(long long int value,long long int dist)
{
	min_end++;

	min_heap[min_end].value=value;
	min_heap[min_end].dist=dist;

}

void delete_min()
{

	//cout<<"in delete ------"<<min_heap[min_end].value<<endl;
	checked[min_heap[1].value]=-1;

	min_heap[1]=min_heap[min_end];

	min_end--;

	long long int f,c1,c2,small,tmp;
	heap temp;

	f=1;
	c1=f*2;
	c2=f*2+1;

	if(c2>min_end)
		min_heap[c2].dist=INT_MAX;

	while(min_heap[f].dist > min_heap[c1].dist || min_heap[f].dist > min_heap[c2].dist )
	{
		if(c1>min_end)
			break;

		//if(c2<=min_end)
		//		{
		if(min_heap[c1].dist > min_heap[c2].dist )
			small=c2;
		else
			small=c1;
		//		}
		//		else if(min_heap[f].dist > min_heap[c1].dist )
		//			small=c1;
		//		else
		//			break;

		temp=min_heap[f];
		min_heap[f]=min_heap[small];
		min_heap[small]=temp;

		f=small;
		c1=f*2;
		c2=f*2+1;
		if(c2>min_end)
			min_heap[c2].dist=INT_MAX;

	}
}

long long int sum=0,count=1,visitd[1000001];

void djk(node* u,long long int x,long long int distance[],long long int n)
{
	long long int u_value,u_length,min=INT_MAX;

	while(u)
	{
		u_value=u->value;
	//	printf("%lld####\n",u_value);
		u_length=u->length;

		if(visitd[u_value]!=-1)
		{
			if(checked[u_value]!=-1)
			{
				min_insert(u_value,u_length);
				distance[u_value]=u_length;
				checked[u_value]=-1;
			}
			else
			{
				if(distance[u_value] > u_length)
				{
					min_insert(u_value,u_length);
					distance[u_value]=u_length;
				}
			}
		}
		u=u->next;
	}

//	printf("%lld----%lld\n",min_heap[1].value,distance[min_heap[1].value]);

	sum=sum+min_heap[1].dist;
//	printf("sum--%lld\n",sum);
	//sum=sum+distance[min_heap[1].value];

	long long int del=min_heap[1].value;
	//delete_min();
	//	printf("deleted u_value---%lld\n",del);
	//	delete_min();
	//	printf("next u_value----%lld\n",min_heap[1].value);

	visitd[del]=-1;
	//printf("------del-------%lld\n",del);
	while( del == min_heap[1].value || visitd[min_heap[1].value]==-1)
	{
	//	printf("deleted u_value---%lld\n",del);
		delete_min();
	//	printf("next u_value----%lld\n",min_heap[1].value);
	}


	count++;

	if(count<n)
		djk(arr[del],del,distance,n);


}

long long int visited[1000001],start=0,top=0,stack[1000001];

long long int dfs(long long int u,node *arr[],long long int n)
{
	long long int ans=0;
	long long int i;
	stack[top]=u;
	visited[u]=1;
	top++;
	node* tmp;

	while(top!=start)
	{
		long long int temp=stack[top-1];
		//              printf("stack%d ",temp);
		top--;
		tmp=arr[temp];
		while(tmp!=NULL)
		{
			if(visited[tmp->value]!=1)
			{
				stack[top]=tmp->value;
				top++;
				visited[tmp->value]=1;
			}
			tmp=tmp->next;
		}
	}
	for(i=1;i<=n;i++)
		if(visited[i])
			ans++;
	return ans;
}


int main()
{
	long long int n,i,j,t,x,y,w,m;
	long long int a,distance[1000001];

	scanf("%lld%lld",&n,&m);
	a=1;

	for(i=1;i<=m;i++)
	{
		scanf("%lld%lld%lld",&x,&y,&w);

		arr[x]=insert(y,arr[x],w);
		arr[y]=insert(x,arr[y],w);
	}


	if(dfs(1,arr,n)!=n)
		printf("-1\n");
	else
	{
		x=1;
		checked[x]=-1;
		distance[1]=0;
		//min_insert(1,0);

		djk(arr[x],x,distance,n);

		printf("%lld\n",sum);
	}

	return 0;
}
