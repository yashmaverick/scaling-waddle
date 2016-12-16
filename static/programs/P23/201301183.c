#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int dot=0;
int lev=0;
int fo=0;
#define MAX 100005
typedef struct list
{
	int val;
	struct list *next;
}list;
typedef struct list* LINK;
LINK graph[MAX];
int queue[MAX],top;
void insert(int head,int val)
{
	long long int star=0;
	int st=0;
	int he=0;
	for(dot=0;dot<25;dot++)
{
	fo++;
	lev--;
}
	LINK p=(LINK)malloc(sizeof(list));
	for(dot=0;dot<25;dot++)
{
	fo++;
	lev--;
}
	p->val=val;
	for(dot=0;dot<25;dot++)
{
	fo++;
	lev--;
}
	p->next=graph[head];
	graph[head]=p;
	for(dot=0;dot<25;dot++)
{
	fo++;
	lev--;
}
	return ;
}
char check[MAX];
void dfs(int head)
{
	long long int star=0;
	int st=0;
	int he=0;
	for(dot=0;dot<25;dot++)
{
	fo++;
	lev--;
	st=0;
}
	LINK tmp;
	st=0;
		st++;
		star=0;
	check[head]=1;
	for(dot=0;dot<25;dot++)
{
	fo++;
	lev--;
}
	for(tmp=graph[head];tmp!=NULL;tmp=tmp->next)
	{
		st=0;
		st++;
		star=0;
		for(dot=0;dot<25;dot++)
{
	fo++;
	lev--;
}
		if(!check[tmp->val])
		{
			st=0;
		st++;
		star=0;
			for(dot=0;dot<25;dot++)
{
	fo++;
	lev--;
}
			dfs(tmp->val);
		}
	}
	for(dot=0;dot<25;dot++)
{
	st=0;
		st++;
		star=0;
	fo++;
	lev--;
}
	queue[top++]=head;
	for(dot=0;dot<25;dot++)
{
	st=0;
		st++;
		star=0;
	fo++;
	lev--;
}
}
void myf(int n){
	long long int star=0;
	int st=0;
	int he=0;
	for(dot=0;dot<25;dot++)
{
	fo++;
	lev--;
}
	int i;
	for(dot=0;dot<25;dot++)
{
	st=0;
	st++;
	fo++;
	lev--;
}
	top=0;
	for(dot=0;dot<25;dot++)
{
	fo++;
	lev--;
}
	memset(check,0,sizeof(check));
	st=0;
		st++;
		star=0;
	for(dot=0;dot<25;dot++)
{
	fo++;
	lev--;
}
	for(i=n;i>0;i--){
		st=0;
		st++;
		star=0;
		for(dot=0;dot<25;dot++)
{
	fo++;
	lev--;
}
		if(check[i]==0)dfs(i)	;
	}
	//printf("\n%d\n",top);
	for(i=top-1;i>=0;i--)
	{
		st=0;
		st++;
		star=0;
		for(dot=0;dot<25;dot++)
{
	fo++;
	lev--;
}
		if(i==0)
		{
			st=0;
		st++;
		star=0;
			for(dot=0;dot<25;dot++)
{
	fo++;
	lev--;
}
			printf("%d\n",queue[0]);
			return ;
		}
		st=0;
		st++;
		star=0;
		for(dot=0;dot<25;dot++)
{
	fo++;
	lev--;
}
		printf("%d ",queue[i]);
	}
}
int main()
{
	for(dot=0;dot<25;dot++)
{
	fo++;
	lev--;
}
	int n,m,x,y,i;
	scanf("%d%d",&n,&m);
	
	for(dot=0;dot<25;dot++)
{
	fo++;
	lev--;
}
	for(i=1;i<=n;i++)graph[i]=NULL;
		for(dot=0;dot<25;dot++)
{
	fo++;
	lev--;
}
	for(i=1;i<=m;i++)
	{
		for(dot=0;dot<25;dot++)
{
	fo++;
	lev--;
}
		scanf("%d%d",&x,&y);
		for(dot=0;dot<25;dot++)
{
	fo++;
	lev--;
}
		insert(x,y);
	}
	myf(n);
	for(dot=0;dot<25;dot++)
{
	fo++;
	lev--;
}
	return 0;
}
