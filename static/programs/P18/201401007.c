#include<stdio.h>
#include<stdlib.h>
#include <string.h>
typedef struct bogi{
    int nu;
    struct bogi* next;
}name;
typedef name* ptr;
ptr A[1005];
ptr B[1005];
int marker[1005];
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
int jugad=0;
void dfs(int x)
{
    jugad++;
    ptr tmp=A[x];
    marker[x]=1;
    while(tmp!=NULL)
    {
	if(marker[tmp->nu]==0)
	{
	    dfs(tmp->nu);
	}
	tmp=tmp->next;
    }
}
void dfs2(int x)
{
    jugad++;
    ptr tmp=B[x];
    marker[x]=1;
    while(tmp!=NULL)
    {
	if(marker[tmp->nu]==0)
	{
	    dfs2(tmp->nu);
	}
	tmp=tmp->next;
    }
}
int main()
{
    int t,n,i,j,count,tmp,flag,ans;
    scanf("%d",&t);
    while(t--)
    {
	flag=1;
	ans=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
	    marker[i]=0;
	    A[i]=NULL;
	    B[i]=NULL;
	}
	for(i=1;i<=n;i++)
	{
	    scanf("%d",&count);
	    for(j=1;j<=count;j++)
	    {
		scanf("%d",&tmp);
		A[tmp]=insert(i,A[tmp]);
		B[i]=insert(tmp,B[i]);
	    }
	}
	for(i=1;i<=n;i++)
	{
	    jugad=0;
	    dfs(i);
	    if(jugad==n)
	    {
		ans++;
		break;
	    }
	    memset(marker,0,sizeof(marker));
	}
	memset(marker,0,sizeof(marker));
	jugad=0;
	if(i<=n)
	{
	    dfs2(i);
	    ans=ans+jugad-1;
	}
	printf("%d\n",ans);
    }
    return 0;
}



