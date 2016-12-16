#include<stdio.h>
#include<stdlib.h>
struct node{
	int c;
	struct node* next;
};
struct node* a[1000000];
int visit[1000000];
int stack[1000000];
int top;
void push(int x)
{
	top++;
	stack[top]=x;
	return;
}
void dfs(int x)
{
	struct node* aid;
	aid=a[x];
	while(aid!=NULL)
	{
		if(visit[aid->c]==0)
		{
			visit[aid->c]=1;
			dfs(aid->c);
		}
		aid=aid->next;
	}
	//printf("pushing %d\n",x);
	push(x);
	return;
}

int main()
{
	int n,m,k,l,x,y,h,s;
	scanf("%d",&n);
	scanf("%d",&m);
	//printf("n is %d   m is %d  \n",n,m);
	top=-1;
	for(k=0;k<=1000000;k++)
	{
		a[k]=NULL;
		visit[k]=0;
	}
	for(l=0;l<m;l++)
	{
		//printf("for loop %d\n",l);
		scanf("%d",&x);
		scanf("%d",&y);
		struct node* temp;
		temp=malloc(sizeof(struct node));
		temp->c=y;
		temp->next=NULL;
		if(a[x]==NULL)
		{
			a[x]=temp;
		}
		else
		{
			temp->next=a[x];
			a[x]=temp;
		}
	}
	for(h=n;h>0;h--)
	{
		//printf("entf h loop\n");
		if(visit[h]==0)
		{
			//printf("enter if\n");
			visit[h]=1;
			dfs(h);
		}

	}
	for(s=top;s>=0;s--)
	{
		if(s==0)
		{
			printf("%d\n",stack[s]);
		}
		else{
		printf("%d ",stack[s]);
		}
	}
	return 0;
}


