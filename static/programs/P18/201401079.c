#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct graph
{
	int value;
	struct graph *next;

}node;
node *p[1001];
node *start[1001];
int visited[1001];
int sahiwalanode[1001];
int n;
int cnt;
int fl;
int g;
int ans;
int flag;
int z;
node *insert(int x,node *root)
{
	node* tmp=malloc(sizeof(node));
	tmp->value=x;
	tmp->next=root;
	return tmp;
}
void dfs(int x)
{      if(p[x]!=NULL)           
	{
	       	if(visited[p[x]->value]==0)
      {
	      cnt++;
	     // if(sahiwalanode[p[x]->value]==1)
	//	      ans=ans+1;
	      visited[p[x]->value]=1;
      }
	}
	
      while(1)
      {
	      if(p[x]!=NULL)
		      p[x]=p[x]->next;
	      if(p[x]==NULL)
		      break;
	      dfs(p[x]->value);
      }

}

void dfsagain(int x)
{      // if(flag!=1)
//	{	
	if(p[x]!=NULL)
	{
	if(visited[p[x]->value]==0)
      {
//	      printf("Aa gya:%d ",p[x]->value);
	      
	            if (sahiwalanode[p[x]->value]==1)
		    {
			    ans=ans+1;
			    sahiwalanode[z]=1;
			    flag=1;
		    }
	      visited[p[x]->value]=1;
      }
	}
//	}
	
      while(1)
      {
	      if(flag==1)
		      break;
	      if(p[x]!=NULL)
		      p[x]=p[x]->next;
	      if(p[x]==NULL)
		      break;
	      dfsagain(p[x]->value);
	    //  if(flag==1)
		  //    break;
	      

      }

}
int main()
{
	int t,i,j,k,l,m,u,v;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<=n;i++)
			p[i]=NULL;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&m);
			for(j=0;j<m;j++)
			{
				scanf("%d",&u);
				p[u]=insert(i,p[u]);

			}

		}
		for(i=1;i<=n;i++)
		{
                     node *tmp=(node*)malloc(sizeof(node));
		     tmp->value=i;
		     tmp->next=p[i];
		     p[i]=tmp;
		}
		for(i=1;i<=n;i++)
			start[i]=p[i];
		memset(sahiwalanode, 0 , sizeof(int)*1001);
		ans=0;
		fl=0;
		
		for(i=1;i<=n;i++)
		{
			cnt=0;
			memset(visited , 0 , sizeof(int)*1001);
			for(j=1;j<=n;j++)
				p[j]=start[j];
			
			dfs(i);
	//		printf("%d ",cnt);
			if(cnt==n)
			{
				g=i;
				sahiwalanode[i]=1;
				fl=1;
				break;
			}
		}
	//	if(fl==1)
//		printf("g is:%d\n",g);
		if(fl==1)
		{for(i=g+1;i<=n;i++)
		{
			flag=0;
			z=i;
			memset(visited , 0 , sizeof(int)*1001);
			for(j=1;j<=n;j++)
				p[j]=start[j];
			dfsagain(i);
		}

		}
		if(fl==1)
		
		printf("%d\n",ans+1);
		else
			printf("0\n");
	}
	return 0;
}
