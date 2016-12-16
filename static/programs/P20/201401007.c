#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct bogi{
    int nu;
    struct bogi* next;
}name;
typedef name* ptr;
ptr A[1000005];
int marker[1000005];
ptr insert(int n,ptr root)
{
    ptr tmp=(ptr)malloc(sizeof(name));
    tmp->nu=n;
    tmp->next=root;
    return tmp;
}
void print(ptr root)
{
    ptr tmp=root;
    while(tmp!=NULL)
    {
	printf("%d ",tmp->nu);
	tmp=tmp->next;
    }
    printf("\n");
}
int v;
int exlarge=0;
void dfs1(int x,int t)
{
    t++;
    ptr tmp=A[x];
    marker[x]=1;
    while(tmp!=NULL)
    {
	if(marker[tmp->nu]==0)
	{
	    if(t>exlarge)
	    {
		exlarge=t;
		v=tmp->nu;
	    }
	    dfs1(tmp->nu,t);
	}
	tmp=tmp->next;
    }
}
void dfs2(int x,int t)
{
    t++;
    ptr tmp=A[x];
    marker[x]=1;
    while(tmp!=NULL)
    {
	if(marker[tmp->nu]==0)
	{
	    if(t>exlarge)
	    {
		exlarge=t;
	    }
	    dfs2(tmp->nu,t);
	}
	tmp=tmp->next;
    }
}
int main()
{
    int n,i,x,y,test;
    scanf("%d",&test);
    while(test--)
    {
	exlarge=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
	    marker[i]=0;
	    A[i]=NULL;
	}
	for(i=0;i<(n-1);i++)
	{
	    scanf("%d %d",&x,&y);
	    A[x]=insert(y,A[x]);
	    A[y]=insert(x,A[y]);
	}
	dfs1(1,1);
	for(i=1;i<=n;i++)
	{
	    marker[i]=0;
	}
	exlarge=0;
	dfs2(v,1);	
	printf("%d\n",exlarge);
    }
    return 0;
}
