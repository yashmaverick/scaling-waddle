#include <stdio.h>
#include <stdlib.h>

int ct;
int reach[10001];

struct adj
{
	int val;
	struct adj *next;
};

typedef struct adj ELEMENT;
typedef ELEMENT *LINK;

void dfs(LINK g[],int start)
{
	LINK tmp;

	tmp=g[start];
	reach[start]=1;
	ct++;

	int i;

	while(tmp!=NULL)
	{
		if(reach[tmp->val]==0)
		{
			dfs(g,tmp->val);
		}
		tmp=tmp->next;
	}
}

int main()
{
	int i,j,n,t,T,width,ver;

	scanf("%d",&T);

	for(t=1;t<=T;t++)
	{ 
		LINK g[10001];
		LINK rg[10001];

		ct=0;

		scanf("%d",&n);

		for(i=0;i<10001;i++)
		{
			rg[i]=NULL;
			g[i]=NULL;
		}

		for(i=1;i<=n;i++)
		{
			scanf("%d",&width);

			for(j=1;j<=width;j++)
			{
				int tv;

				LINK tmp;

				tmp=(LINK)malloc(sizeof(ELEMENT));

				scanf("%d",&tv);

				tmp->val=i;
				tmp->next=g[tv];

				g[tv]=tmp;

			}
		}

		/*printf("STRAIGHT GRAPH\n");

		for(i=1;i<=n;i++)
		{
			printf("%d -->",i);

			LINK tmp;

			tmp=g[i];

			while(tmp!=NULL)
			{   
				printf("%d ",tmp->val);

				tmp=tmp->next;
			}
			printf("\n");
		}*/


		int flag;

		for(i=1;i<=n;i++)
		{
			ct=0;

			for(j=0;j<=n;j++)
			{
				reach[j]=0;			
			}

			dfs(g,i);
			flag=1;

			for(j=1;j<=n;j++)
			{
				if(reach[j]==0)
				{	
					flag=0;
					break;
				}
			}

			if(flag==1)
				break;
		}

		ct=0;
		ver=i;

		for(i=1;i<=n;i++)
		{
			LINK tmp;

			tmp=g[i];

			while(tmp!=NULL)
			{
				LINK tmp2;

				tmp2=(LINK)malloc(sizeof(ELEMENT));

				tmp2->val=i;
				tmp2->next=rg[tmp->val];

				rg[tmp->val]=tmp2;	

				tmp=tmp->next;			
			}		
		}

		/*printf("REVERSED GRAPH\n");

		for(i=1;i<=n;i++)
		{
			printf("%d -->",i);

			LINK tmp;

			tmp=rg[i];

			while(tmp!=NULL)
			{
				printf("%d ",tmp->val);

				tmp=tmp->next;
			}
			printf("\n");
		}*/

		for(i=1;i<=n;i++)
			reach[i]=0;

		ct=0;
		dfs(rg,ver);

		if(ver==n+1)
			printf("0\n");
		else
			printf("%d\n",ct);

	}
	return 0;
}
