#include <stdio.h>
#include <stdlib.h>
struct AdjListNode
{
	long long int d;
	struct AdjListNode* next;
};
struct AdjList
{
	struct AdjListNode* head;
};
void s(long long int *a, long long int *b)
{
	long long int t = *a;
	(*a) = (*b);
	(*b) = t;
}
void insert(long long int heap[],long long int i)
{
	if(i>1)
	{
		if(heap[i]<=heap[i/2])	
		{
			s(&heap[i],&heap[i/2]);
			insert(heap,i/2);
		}
	}
}
void AddEdge(struct AdjListNode** head,long long int d)
{
	struct AdjListNode* new = (struct AdjListNode*) malloc(sizeof(struct AdjListNode));
	new->d= d;
	new->next = (*head);
	(*head) = new;
}
void Del(long long int heap[],long long int n,long long int key)
{
	long long int i=1;
	while(1)
	{
		if((2*i)>n)
			break;
		if((2*i)==n && heap[(2*i)]>=key)
			break;
		if((2*i)<n && heap[(2*i)]>=key && heap[(2*i)+1]>=key)
			break;
		else
		{
			heap[i] = ((heap[(2*i)]>heap[(2*i)+1])?heap[(2*i)+1]:heap[(2*i)]);
			i = ((heap[(2*i)]>heap[(2*i)+1])?((2*i)+1):(2*i));
		}
	}
	heap[i]=key;
}
void initialize(long long int a[], long long int n)
{
	long long int i;
	for(i=1;i<=n;i++)
		a[i]=0;
}
void initializeList(struct AdjList* list[100010], long long int n)
{
	long long int i;
	for(i=1;i<=n;i++)
	{
		list[i] = (struct AdjList*) malloc(sizeof(struct AdjList));
		list[i]->head = NULL;
	}
}
int main()
{
	long long int m,n,i,p,q,end,ans,t;
	scanf("%lld%lld",&n,&m);
	long long int a[100010];
	long long int flag[100010];
	long long int heap[100010];
	long long int visited[100010];
	long long int print[100010];
	struct AdjList* list[100010];
	initialize(a,n);
	initialize(visited,n);
	initialize(flag,n);
	initializeList(list,n);
	end=0;
	for(i=1;i<=m;i++)
	{
		scanf("%lld%lld",&p,&q);
		AddEdge(&(list[p]->head),q);
		a[q]=a[q]+1;
	}
	for(i=1;i<=n;i++)
	{
		if(a[i]==0)
		{
			if(!visited[i])
			{
				end++;
				heap[end]=i;
				insert(heap,end);
				visited[i] = 1;
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		ans = heap[1];
		flag[ans]=1;
		if(i!=n)
			printf("%lld ",ans);
		else
			printf("%lld\n",ans);
		t = heap[end];
		end = end-1;
		Del(heap,end,t);
		struct AdjListNode* head = malloc(sizeof(struct AdjListNode));
		head = list[ans]->head;
		while (head != NULL)
		{
			if(visited[head->d]==0&&flag[head->d]==0)
			{
				(a[head->d])--;
				if(a[head->d]==0)
				{
					visited[head->d]=1;
					end++;
					heap[end]=head->d;
					insert(heap,end);
				}
			}
			head=head->next;
		}
	}
	return 0;
}
