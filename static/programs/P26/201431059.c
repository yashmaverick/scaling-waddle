#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int val;
	int weight;
	struct node* next;
}node;
typedef node* ptr;

ptr insert(ptr head,node elem)
{
	node* p = (ptr)malloc(sizeof(node));
	*p = elem;
	return p->next = head,p;
}
node mp(int val,int weight)
{
	node temp;
	temp.val = val;
	temp.weight = weight;
	temp.next = NULL;
	return temp;
}
ptr erase(ptr head)
{
	ptr temp = head;
	while(head)
		head = head->next,free(temp),temp = head;
	return NULL;
}


int prime[10000];
int dist[10000];
int queue[100000];
int front,end;
int visited[10000];
int A[2000];
int len;
ptr graph[10000];
int bfs(int s,int d)
{
	front = end = 0;
	queue[end++] = s;
	int i;
	for(i = 0;i<len;i++)
	{
		visited[A[i]]=0;
		dist[A[i]]=-1;
	}
	dist[s]=0;
	visited[s]=1;
	int flag = 0;
	while(front < end)
	{
		int u =queue[front++];
		node* it;
		for(it = graph[u];it!=NULL;it=it->next)
			if(!visited[it->val])
			{
				dist[it->val] = dist[u] + 1;
				queue[end++] = it->val;
				visited[it->val]=1;
				if(it->val == d)
				{
					flag=1;
					break;
				}
			}
		if(flag)
			break;
	}
	return dist[d];
}

int diff(int a,int b)
{
	int ndiff=0;
	while(a)
	{
		if(a%10!=b%10)
			ndiff++;
		a = a/10;
		b = b/10;
	}
	if(ndiff==1)
		return 1;
	return 0;

}
int main()
{
	int i,j;
	for(i=2;i*i<10000;i++)
		if(!prime[i])
			for(j=i*i;j<10000;j+=i)
				prime[j]=1;
	for(i=1000;i<=9999;i++)
		if(!prime[i])
			A[len++]=i;
	for(i=0;i<len;i++)
		for(j=i+1;j<len;j++)
			if(diff(A[i],A[j]))
			{
				graph[A[i]] = insert(graph[A[i]],mp(A[j],0));
				graph[A[j]] = insert(graph[A[j]],mp(A[i],0));
			}
//	printf("len : %d\n",len);
	int q;
	scanf("%d",&q);
	while(q--)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		int ret = bfs(a,b);
		if(ret == -1)
			printf("Impossible\n");
		else
			printf("%d\n",ret);

	}
	return 0;
}
