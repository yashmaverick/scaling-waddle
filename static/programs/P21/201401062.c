#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int val;
	int weight;
	struct node* next;
}node;
typedef node* ptr;

typedef struct node2{
	long long int val;
	int vertex;
	int prior;
	struct node2 *l,*r;
}node2;
typedef node2* pnode;

void split(pnode t,pnode *l,pnode *r,int key)
{
	if(!t)
		*l = *r = NULL;
	else if(t->val <= key)	//<= key will be in left subtree
		split(t->r,&(t->r),r,key) , *l = t;
	else
		split(t->l,l,&(t->l),key) , *r = t;
}
void merge(pnode *t,pnode l,pnode r)
{
	if(!l || !r)
		*t = l?l:r;
	else if(l->prior < r->prior)
		merge(&(r->l) , l ,r->l) , *t = r ;
	else
		merge(&(l->r) , l->r,r) , *t = l;
}

void insert2(pnode *t,pnode it)
{
	if(!(*t))
		*t = it;
	else if((*t)->prior < it->prior)
		split(*t , &(it->l) , &(it->r) , it->val) , *t = it;
	else if((*t)->val >= it->val)
		insert2(&((*t)->l) , it);
	else
		insert2(&((*t)->r) , it);
}
pnode mp2(int weight,int vertex)
{
	pnode t = (pnode)malloc(sizeof(node2));
	t->val = weight;
	t->vertex = vertex;
	t->l = t->r = NULL;
	t->prior = rand();
	return t;
}
node2 findMin(pnode t)
{
	while(t->l)
		t = t->l;
	return *t;
}
void deleteMin(pnode *t)
{
	pnode del;
	if(!(*t)->l)
	{
		del = *t , *t = (*t)->r;
		free(del);
		return;
	}
	pnode temp = *t;
	while((temp->l->l))
		temp = temp->l;
	del = temp->l;
	temp->l = temp->l->r;
	free(del);
}

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
ptr delete(ptr head)
{
	ptr temp = head;
	while(head)
		head = head->next,free(temp),temp = head;
	return NULL;
}

int q[2000000];
int visited[200000];
int front,end;
ptr graph[200000];
long long int dist[200000];
long long int INF = 1000000000000000000;
pnode treap;
int main()
{
	int n,m,i;
	scanf("%d %d",&n,&m);
	for(i=0;i<m;i++)
	{
		int u,v,w;
		scanf("%d %d %d",&u,&v,&w);
		graph[u] = insert(graph[u],mp(v,w));
		//graph[v] = insert(graph[v],mp(u,w));
	}
	int s,t;
	scanf("%d %d",&s,&t);
	insert2(&treap,mp2(0,s));
	long long int ans=-1;
	while(treap)
	{
		//print(treap);
		node2 top = findMin(treap);
		deleteMin(&treap);
		if(visited[top.vertex])continue;
		int u = top.vertex;
		int weight = top.val;
		if(u == t)
		{
			ans = weight;
			break;
		}
		visited[u]=1;
		node* it;
		for(it = graph[u];it!=NULL;it = it->next)
			if(!visited[it->val])
				insert2(&treap,mp2(it->weight + weight,it->val));
	}
	if(ans == -1)printf("NO\n");
	else printf("%lld\n",ans);
	return 0;
}
