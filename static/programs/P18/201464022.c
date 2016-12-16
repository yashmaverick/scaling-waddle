#include<stdio.h>
#include<stdlib.h>
int *visited;
void dfs(int v,int vert,int **a)
{
	int i;
	if(visited[v]==1)
		return;
	visited[v]=1;
	for(i=1;i<=vert;i++)
	{
		if(visited[i]!=1 && a[v][i]!=0)
			dfs(i,vert,a);
	}
}
int check(int v1,int vert)
{
	int i;
	for(i=1;i<=vert;i++)
	{
//		if(i==v1)
//			continue;

		if(visited[i]!=1)
			return 0;
	}
	return 1;
}
int main()
{
	int n,t,i,j,vert,vertex,count,v1,m,temp;
	scanf("%d",&t);
	while(t--)
	{
		int **a,**b;
		count=0;
		scanf("%d",&vert);
		a=malloc(sizeof(int *)*(vert+1));
		for(i=0;i<=vert;i++)
			a[i]=malloc(sizeof(int)*(vert+1));
		b=malloc(sizeof(int *)*(vert+1));
		for(i=0;i<=vert;i++)
			b[i]=malloc(sizeof(int)*(vert+1));
		visited=malloc(sizeof(int)*(vert+1));
		for(i=1;i<=vert;i++)
		{
			scanf("%d",&m);
			for(j=0;j<m;j++)
			{
				scanf("%d",&v1);
				a[v1][i]=1;
			}
		}
/*		for(i=1;i<=vert;i++)
		{
			for(j=1;j<=vert;j++)
			{
				printf("%d ",a[i][j]);
			}
			printf("\n");
		}*/
		for(i=1;i<=vert;i++)
		{
			dfs(i,vert,a);
			if(check(i,vert)==1)
			{
				vertex=i;
				break;
			}
			for(j=1;j<=vert;j++)
				visited[j]=0;
		}
		for(j=1;j<=vert;j++)
			visited[j]=0;
//		printf("vertex=%d\n",vertex);
		for(i=1;i<=vert;i++)
		{
			for(j=1;j<=vert;j++)
			{
				
				b[i][j]=a[j][i];
				//a[j][i]=temp;
			}
		}
		/*for(i=1;i<=vert;i++)
		{
			for(j=1;j<=vert;j++)
			{
				printf("%d ",b[i][j]);
			}
			printf("\n");
		}*/
		for(i=0;i<=vert;i++)
			visited[i]=0;
		dfs(vertex,vert,b);
		for(i=1;i<=vert;i++)
		{
			//if(i==vertex)
			//	continue;
			if(visited[i]==1)
				count++;
		}
		printf("%d\n",count);
		free(a);
		free(visited);
		free(b);
	}
	return 0;
}


					
