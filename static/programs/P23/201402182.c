#include<stdio.h>
#include<stdlib.h>
struct node
{ 
	long long int data;
	struct node* next;
};
typedef struct node noddy;
long long int j=0,b[100007];

   int visit[100007];
noddy *a[100007];
noddy* create(long long int e)
{
	noddy* p=(noddy*)malloc(sizeof(noddy));
	p->data=e;
	p->next=NULL;
	return p;
}
insert(long long int u,long long int v)
{
	noddy *q;
        //while()
	q=a[u]->next;
	a[u]->next=create(v);
	a[u]->next->next=q;
	return;
}
void push(long long int e)
{

	b[j]=e;
	j++;
	return;
}
/*void pop()
  {
  if(j==-1)
  return;
  printf("%lld ",b[j]);
  j--;
  return;
  }*/
void dfs(long long int e)
{

	long long int i;
	noddy *w;

	if(visit[e]==1)
		return;
	visit[e]=1;
	w=a[e];

	//count=count+1;
	while(w!=NULL)
	{

		dfs(w->data);
		w=w->next;
	}
		push(e);
	//printf("yaya");
	return;
}
int main()
{
	long long int n,t,i,p,q;
	scanf("%lld%lld",&n,&t);
	for(i=1;i<=n;i++)
	{
		a[i]=create(i);
	}
	for(i=1;i<=n;i++)
	{
		visit[i]=0;
	}
	long long int sd;
	for(i=1;i<=t;i++)
	{
		scanf("%lld%lld",&p,&q);		
		insert(p,q);
	}
	i=n;
	while(i>=1)
	{
		if(!visit[i])
		dfs(i);
		i--;
	}
//	printf("%lld",j);
         i=j-1;
	while(i>=0)
	{
		if(i==0)
		printf("%lld\n",b[i]);
		else
		printf("%lld ",b[i]);
		i--;
	}
//	printf("\n");
	return 0;
}

