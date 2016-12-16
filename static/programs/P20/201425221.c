#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int val;
    struct node* next;
}node;
node *a[1000001];
int maxl,maxi;
dfs(int i,int p, int l , int m)
{
    if(a[i]->next==NULL && m!=0)
    {
	if(l>maxl)
	{
	    maxl=l;
	    maxi=i;
	}
	    return;
    }
    else
    {
	node *temp=a[i];
	while(temp!=NULL)
	{
	    if(temp->val!=p)
		dfs(temp->val,i,l+1,1);
	    temp=temp->next;
	}
    }
}
int main()
{
    int n,i,j,x,y;
    int t;
    node *temp;
    scanf("%d",&t);
    while(t--)
    {
    scanf("%d",&n);
    for(i=1;i<=n;i++)
	a[i]=NULL;
    for(i=1;i<n;i++)
    {
	scanf("%d %d",&x,&y);
	temp=malloc(sizeof(node));
	temp->val=x;
	temp->next=a[y];
	a[y]=temp;
	temp=malloc(sizeof(node));
	temp->val=y;
	temp->next=a[x];
	a[x]=temp;
    }
    maxl=0;
    dfs(1,0,0,0);
    maxl=0;
    dfs(maxi,0,0,0);
    printf("%d\n",maxl+1);
    }
    return 0;
}
