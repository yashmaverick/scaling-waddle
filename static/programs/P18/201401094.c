#include<stdio.h>
#include<stdlib.h>
typedef struct adj{
	int val;
	struct adj* next;
}node;
node* insert(node* head,int val)
{
	node *temp;
	temp=malloc(sizeof(node));
	temp->val=val;
	temp->next=head;
	return temp;
}
int dfs(node *head,int  *vis,node* *adj)
{
	int q=0;
	while(head!=NULL)
	{
		if(vis[head->val]!=1)
		{
	//	printf("nxt:%d\n",head->val);
			vis[head->val]=1;
			q+=dfs(adj[head->val],vis,adj);
		}
		head=head->next;
	}
	return (q+1);
}
void frp(node *head)
{
	if(head!=NULL)
	{
			frp(head->next);
			free(head);
	}
}
int main()
{
	int t,j,w,q,n,m,i,wins,min,pos,s=0;
	int *vis;
	node* winhd[10005];
	node* losehd[10005];
	scanf("%d",&t);
	while(t--)
	{
    min=100005;
    s=0;
		scanf("%d",&n);
		for(i=0;i<=n;i++)
		{
			winhd[i]=NULL;
			losehd[i]=NULL;
		}
		for(i=1;i<=n;i++)
		{
			scanf("%d",&m);
      if(m<min)
      {
        min=m;
        s=1;
        pos=i;
      }
			for(j=0;j<m;j++)
			{
				scanf("%d",&w);
        if(i==w)
          continue;
				winhd[w]=insert(winhd[w],i);
				losehd[i]=insert(losehd[i],w);
			}
		}
	//	for(i=0;i<s;i++)	{	
			vis=(int *)calloc(n+1,sizeof(int));
			vis[pos]=1;
			wins=dfs(winhd[pos],vis,winhd);
		//	printf("wins:%d\n",wins);
	  //  if(wins==n)
      //  break;
   // }
	if(wins==n)
	{
		vis=(int *)calloc(n+1,sizeof(int));
		vis[pos]=1;
		q=dfs(losehd[pos],vis,losehd);
	}
	printf("%d\n",q);
		for(i=1;i<=n;i++)
		{
			frp(winhd[i]);
			frp(losehd[i]);
		}
	}
	return 0;
}
