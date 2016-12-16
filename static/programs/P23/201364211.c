#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int mine=0;
int level=0;
int form=0;
#define MAX 100005
typedef struct list
{
	int val;
	struct list *next;
}list;
long long int star=0;
typedef struct list* LINK;
LINK graph[MAX];
long long int he=0;
int queue[MAX],top;
void insert(int head,int val)
{
	for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}
	LINK p=(LINK)malloc(sizeof(list));
	p->val=val;
	for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}
	p->next=graph[head];
	for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}
	graph[head]=p;
	return ;
}
char check[MAX];
void dfs(int head)
{
	for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}
	LINK tmp;
	check[head]=1;
	for(tmp=graph[head];tmp!=NULL;tmp=tmp->next)
	{
		for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}
		if(!check[tmp->val])
		{
			for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}
			dfs(tmp->val);
		}
	}
	queue[top++]=head;
}
void myf(int n){
	for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}
	int i;
	top=0;
	memset(check,0,sizeof(check));
	for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}
	for(i=n;i>0;i--){
		for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}
		if(check[i]==0)dfs(i)	;
	}
	//printf("\n%d\n",top);
	for(i=top-1;i>=0;i--)
	{
		
		for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}if(i==0)
		{
			printf("%d\n",queue[0]);
			return ;
		}
		for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}
		printf("%d ",queue[i]);
	}
}
int main()
{for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}
	int n,m,x,y,i;
	scanf("%d%d",&n,&m);
	for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}
	for(i=1;i<=n;i++)graph[i]=NULL;
		for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}
	for(i=1;i<=m;i++)
	{
		for(mine=0;mine<25;mine++)
{
	form++;
	level--;
}
		scanf("%d%d",&x,&y);
		insert(x,y);
	}
	myf(n);
	return 0;
}
