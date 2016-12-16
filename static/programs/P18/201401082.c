#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct list{
	long long int val;
	struct list *p;
}g;
int main()
{
	long long int n,m,i,j,u,v,top=-1,flag=0,c,pt,t,k,flag1=0,visited;
	long long int count;
	g *x,*y,*temp,*a[100010];
	long long int s[100010],vi[100010],b[100010],r[100010];
	scanf("%lld",&t);
	while(t--)
	{
		memset(r,0,sizeof(r));
		top=-1;
		scanf("%lld",&m);
		for(i=1;i<=m;i++)
		{
			u=i;
			scanf("%lld",&n);
			//x=malloc(sizeof(g));
			//x->val=u;
			//x->p=NULL;
			for(j=0;j<n;j++)
			{
				x=malloc(sizeof(g));
				x->val=u;
				x->p=NULL;
				scanf("%lld",&v);
				if( a[v] == NULL )
					a[v]=x;
				else
				{
					x->p=a[v];
					a[v]=x;
				}
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
		flag1=0;
		count=0;
		for(i=1;i<=m;i++)
		{
			memset(vi,0,sizeof(vi));
			visited=1;
			vi[i]=-1;
			top=0;
			s[top]=i;
			k=0;
			while(1)
			{
				temp=a[s[top]];
				top--;
				while( temp!=NULL )
				{
					if(vi[temp->val]!=-1)
					{
						s[++top]=temp->val;
						vi[temp->val]=-1;
						visited++;
					}
					temp=temp->p;
				}
				if(top==-1)
				{
					break;
				}

			}
			flag=0;
			if(visited==m)
			{
				r[i]=1;
				count++;
				break;
			}
		}
		k=i+1;
		for(i=k;i<=m;i++)
		{
			memset(vi,0,sizeof(vi));
			vi[i]=-1;
			top=0;
			s[top]=i;
			k=0;
			flag=0;
			while(1)
			{
				temp=a[s[top]];
				top--;
				while(temp!=NULL)
				{
					if(vi[temp->val]!=-1)
					{
						s[++top]=temp->val;
						vi[temp->val]=-1;
					}
					temp=temp->p;
				}
				for(j=1;j<=i;j++)
				{
					if(r[j]==1 && vi[j]==-1)
					{
						r[i]=1;
						flag=1;
						count++;
						break;
					}
				}
				if(top==-1)
				{
					break;
				}
				if(flag==1)
					break;
			}
		}
		printf("%lld\n",count);
		for(i=1;i<=m;i++)
			a[i]=NULL;
	}
	return 0;
}
