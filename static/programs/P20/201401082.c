#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct list{
	int val;
	struct list *p;
}g;
int p[1000005],s[1000005],vi[1000005],dist[1000005];
g *a[1000005];
int main()
{
	int n,m,i,j,u,v,top=-1,flag=0,c,pt,t,parent,z,min;
//	long long int p[100010],s[100010],vi[100010],dist[100010];
	g *x,*y,*temp;
	scanf("%d",&t);
	while(t--)
	{
		memset(dist,0,sizeof(dist));
		memset(vi,0,sizeof(vi));
		scanf("%d",&m);
		for(i=1;i<m;i++)
		{
			scanf("%d%d",&u,&v);
			x=malloc(sizeof(g));
			y=malloc(sizeof(g));
			x->val=u;
			x->p=NULL;
			y->val=v;
			y->p=NULL;
			if( a[u] == NULL )
				a[u]=y;
			else
			{
				y->p=a[u];
				a[u]=y;
			}
			if( a[v] == NULL )
				a[v]=x;
			else
			{
				x->p=a[v];
				a[v]=x;
			}
		}
		/*for(i=1;i<=m;i++){            
			temp=a[i];                
			while(temp!=NULL)       
			{                
				printf("i->%lld ",temp->val); 
				temp=temp->p;
			}
			printf("\n");           
		}*/
		vi[u]=-1;
		dist[u]=1;
		top=0;
		s[top]=u;
		i=0;
		while(1)
		{
			temp=a[s[top]];
			parent=s[top--];
			while(temp!=NULL)
			{
				if(vi[temp->val]!=-1)
				{
					p[temp->val]=parent;
					dist[temp->val]=dist[p[temp->val]]+1;
					s[++top]=temp->val;
					vi[temp->val]=-1;
				}
				temp=temp->p;
			}
			if(top==-1)
			{
				break;
			}
		}
		min = 0;
		for(i=1;i<=m;i++)
			if(dist[i]>min)
			{
				min = dist[i];
				z=i;
				//printf("%lld ",dist[i]);
			}
		//printf("\n");
		//printf("%lld\n",z);
		memset(vi,0,sizeof(vi));
		memset(dist,0,sizeof(dist));
		vi[z]=-1;
		dist[z]=1;
		top=0;
		s[top]=z;
		i=0;
		while(1)
		{
			temp=a[s[top]];
			parent=s[top--];
			while(temp!=NULL)
			{
				if(vi[temp->val]!=-1)
				{
					p[temp->val]=parent;
					dist[temp->val]=dist[p[temp->val]]+1;
					s[++top]=temp->val;
					vi[temp->val]=-1;
				}
				temp=temp->p;
			}
			if(top==-1)
			{
				break;
			}
		}
		for(i=1;i<=m;i++)
			if(dist[i]>min)
			{
				min = dist[i];
				z=i;
				//printf("%lld ",dist[i]);
			}
		//printf("\n");
		printf("%d\n",min);
		for(i=1;i<=m;i++)
			a[i]=NULL;
	}
	return 0;
}

