#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
struct node{
	int data;
	int wgt;
	struct node *next;
};
struct node *arr[100004];
struct node *insert(int v,int w,struct node *root)
{
	struct node *temp=(struct node*)(malloc(sizeof(struct node)));
	temp->data=v;
	temp->wgt=w;
	temp->next=root;
	return temp;
}
int par[100004];
int fun(int key[],int vis[],int n)
{
		int i,min_i;
		int min=INT_MAX;
		for(i=1;i<=n;i++)
		{
			if(key[i]<min && vis[i]==0)
			{
				min=key[i];
				min_i=i;
			}
		}
		return min_i;
}
int main()
{
	int c1,s,x,c,n,m,u,v,w,i;
	int key[100004],vis[100004];
	scanf("%d %d",&n,&m);
	for(i=0;i<100004;i++)
	{
		arr[i]=NULL;
		key[i]=INT_MAX;
	}
	for(i=0;i<m;i++)
	{
		scanf("%d %d %d",&u,&v,&w);
		arr[u]=insert(v,w,arr[u]);
		arr[v]=insert(u,w,arr[v]);
	}
	memset(vis,0,sizeof(vis));
	memset(par,0,sizeof(par));
	key[1]=0;
	par[1]=0;
	c=0;
//	printf("%d",key[fun(n)]);
	while(c<=n)
	{
		x=fun(key,vis,n);
		//printf("%d\n",x);
		struct node *itr=arr[x];
		vis[x]=1;
		while(itr!=NULL)
		{
			if(vis[itr->data]==0 && itr->wgt<key[itr->data])
			{
				//puts("SS");
				key[itr->data]=itr->wgt;
				//vis[itr->data]=1;
			//	printf("%d ",itr->wgt);
				//printf("%d",key[itr->data]);
			}
			itr=itr->next;
		}
	
		c++;
	}
	s=0;c1=0;
	for(i=1;i<=n;i++)
	{
		if(vis[i]==1)
			c1++;
		s=s+key[i];
	}
	if(c1!=n || s<=0)
		printf("-1\n");
	else
		printf("%d\n",s);
	return 0;
}	
			
		


	







