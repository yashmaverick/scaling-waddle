#include<stdio.h>
#include<stdlib.h>
struct node
{
	int val;
	struct node* next;
};
typedef struct node node;
int ans,vis[10001];
void bdf(node* x,node ** loose,node ** win)
{
	node* temp;
	temp=x;
	while(temp!=NULL)
	{
		if(vis[temp->val]==0)
		{
			ans++;
			vis[temp->val]=1;
			bdf(loose[temp->val],loose,win);
		}
		temp=temp->next;
	}
	return;
}
int main()
{
	node *trash,*found;
	node *loose[10001],*win[10001];
	int i,j,n,p,k,v,t,r;
	scanf("%d",&t);
	while(t--)
	{
		for(i=0;i<10001;i++)
		{
			win[i]=NULL;
			loose[i]=NULL;
		}
		scanf("%d",&r);
		for(i=1;i<=r;i++)
		{
			scanf("%d",&n);
			while(n--)
			{
				scanf("%d",&p);
				trash=malloc(sizeof(struct node));
				trash->val=p;
				trash->next=NULL;
				if(loose[i]==NULL)
				{
					loose[i]=trash;
				}
				else
				{
					trash->next=loose[i];
					loose[i]=trash;
				}
				trash=malloc(sizeof(struct node));
				trash->val=i;
				trash->next=NULL;
				if(win[p]==NULL)
				{
					win[p]=trash;
				}
				else
				{
					trash->next=win[p];
					win[p]=trash;
				}
			}
		}
		for(k=1;k<=r;k++)
		{
			for(j=0;j<10001;j++)
			{
				vis[j]=0;
			}
			vis[k]=1;
			bdf(win[k],win,loose);
			for(j=1;j<=r;j++)
			{
				if(vis[j]==0)
					break;
			}
			if(j==(r+1))
			{
				found=loose[k];
				break;
			}
		}
		int flag1=0;
		if(k==r+1)
		{
			flag1=1;
			printf("0\n");
		}
		if(flag1==0)
		{
			for(j=0;j<10001;j++)
			{
				vis[j]=0;
			}
			vis[k]=1;
			ans=0;
			bdf(found,loose,win);
			printf("%d\n",ans+1);
		}
	}
	return 0;
}

