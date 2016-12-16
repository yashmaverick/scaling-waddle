#include<stdio.h>
#include<stdlib.h>
typedef struct tnode
{
	struct tnode *next;
	int data;
}node;

int count=0;

node *a[1001];
node *b[1001];
int v[1001];

node *insert(int u,int v)
{
	node *tm;
	tm=(node*)malloc(sizeof(node));
	tm->data=v;
	tm->next=a[u];
	a[u]=tm;
	return a[u];
}

node *insert1(int u,int v)
{
	node *tmp;
	tmp=(node*)malloc(sizeof(node));
	tmp->data=v;
	tmp->next=b[u];
	b[u]=tmp;
	return b[u];
}

void dfs(node* g)
{
	while(g!=NULL)
	{
		if(v[g->data]==0)
		{
			//	printf("%d ",g->data);
			count++;
			//		printf("count is %d\n",count);
			v[g->data]=1;
			dfs(a[g->data]);
		}	
		g=g->next;
	}
}

void dfs1(node* g)
{
	while(g!=NULL)
	{
		//		printf("in dfs1 %d \n",g->data);
		if(v[g->data]==0)
		{
			count++;
			//		printf("count is %d\n",count);
			v[g->data]=1;
			dfs1(b[g->data]);
		}	
		g=g->next;
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		count=0;
		int q,flag=0;
		for(q=1;q<=1000;q++)
		{
			a[q]=NULL;
			b[q]=NULL;
		}
		int n,i,j,m,x,k=1,r=0;
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d",&m);
			for(j=1;j<=m;j++)
			{
				scanf("%d",&x);
				a[x]=insert(x,k);
				b[k]=insert1(k,x);
			}
			k++;
		}

/*		for(i=1;i<=n;i++)
		{
			while(a[i]!=NULL)
			{
				printf("for %d list %d\n",i,a[i]->data);
				a[i]=a[i]->next;
			}
			printf("\n"); 
		}
*/
		for(i=1;i<=n;i++)
		{
			count=0;
			for(j=0;j<=n;j++)
				v[j]=0;
			v[i]=1;
			//	printf("i is %d\n",i);
			dfs(a[i]);

			if(count+1==n)
			{
				count=0;
				for(j=0;j<=n;j++)
					v[j]=0;
				v[i]=1;
				dfs1(b[i]);
				printf("%d\n",count+1);
				flag=1;
				break;
			}
		}
		if(flag==0)
			printf("0\n");
	}
	return 0;
}
