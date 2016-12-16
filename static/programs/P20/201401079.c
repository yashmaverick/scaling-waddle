#include<stdio.h>
#include<stdlib.h>
typedef struct graph
{
	int value;
	struct graph *next;
}node;
node *p[1001000];
node *maxnode;
int cnt;
int max;
//nodereached[100001];
void dfs (int u,int v)
{
	if(p[u]->value!=v)
	{
		//    printf("%d\n",p[u]->value);
		cnt++;
		//	printf("%d ",cnt);

	}
	else
	{
		//	    printf("%d ",cnt);
		if(cnt > max)
		{
			max=cnt;
			maxnode=p[u];
		}
		cnt--;
	}
	while(1)
	{
		if(p[u]!=NULL)
			p[u]=p[u]->next;
		if(p[u]==NULL)
		{    cnt++;
			break;
		}

		dfs(p[u]->value,u);
	}

}
node *insert(int x,node *root)
{
	node *tmp=(node*)malloc(sizeof(node));
	tmp->value=x;
	tmp->next=root;
	return tmp;
}
int main()
{
	// node *p[100001];
	int m,n,i,j,k,u,v;
	int t;
	scanf("%d",&t);
	while(t--)
	{


		scanf("%d",&n);
		if(n==1)
			printf("1\n");
		else
		{
			for(i=1;i<=n;i++)
				p[i]=NULL;
			for(i=1;i<n;i++)
			{
				scanf("%d%d",&u,&v);
				p[u]=insert(v,p[u]);
				p[v]=insert(u,p[v]);
			}
			for(i=1;i<=n;i++)
			{
				node *tmp;
				tmp=(node*)malloc(sizeof(node));
				tmp->value=i;
				tmp->next=p[i];
				p[i]=tmp;
			}
			node *start[1001000];
			for(i=1;i<=n;i++)
				start[i]=p[i];
			/*    for(i=1;i<=n;i++)
			      {
			      while(p[i]!=NULL)
			      {
			      printf("%d->",p[i]->value);
			      p[i]=p[i]->next;
			      }
			      printf("\n");
			      }*/
			cnt=0;max=0;
			dfs(1,-1);
			for(i=1;i<=n;i++)
				p[i]=start[i];
			cnt=0;max=0;
			dfs(maxnode->value,-1);
			//        if(n==1)
			//         printf("%d\n",max);
			//   else
			printf("%d\n",max);
		}
	}

	return 0;



}
