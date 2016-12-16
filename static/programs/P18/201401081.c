#include<stdio.h>
#include<string.h>

int graph[1005][1005];
int size[1005];
int visited[1005];
int path_exists[1005];
int no_of_visited;
int n,count;

void print_graph()
{
  printf("%d\n",n);
  int i,j;
  for(i=1;i<=n;i++)
	{
	  printf("%d[%d]: ",i,size[i]);
	  for(j=0;j<size[i];j++)
		printf("%d ",graph[i][j]);
	  printf("\n");
	}
}

void dfs(int node)
{
  if(visited[node]==1)
	return;
  visited[node]=1;
  no_of_visited++;
  int i;
  for(i=0;i<size[node];i++)
	dfs(graph[node][i]);
}

int search_path(int node)
{
  if(path_exists[node]==1)
	return 0;
  if(visited[node]==1)
	return -1;
  int i;
  visited[node]=1;
  for(i=0;i<size[node];i++)
	if(search_path(graph[node][i])==0)
	  {
		path_exists[node]=1;
		return 0;
	  }
  return -1;
}

int main()
{
  int t;
  scanf("%d",&t);
  while(t--)
	{
	  count=0;
	  no_of_visited=0;
	  memset(size,0,sizeof(int)*1005);
	  scanf("%d",&n);
	  int i,j;
	  for(i=1;i<=n;i++)
		{
		  scanf("%d",&j);
		  while(j--)
			{
			  int temp;
			  scanf("%d",&temp);
			  graph[temp][size[temp]++]=i;
			}
		}
	  //print_graph();
	  memset(path_exists,0,sizeof(int)*1005);
	  for(i=1;i<=n;i++)
		{
		  memset(visited,0,sizeof(int)*1005);
		  no_of_visited=0;
		  dfs(i);
		  if(no_of_visited==n)
			{
			  memset(visited,0,sizeof(int)*1005);
			  visited[i]=1;
			  path_exists[i]=1;
			  count=0;
			  for(i=1;i<=n;i++)
			  {
				  search_path(i);
				  if(path_exists[i]==1)
					  count++;
			  }
			  break;
			}
		}
	  printf("%d\n",count);
	}
  return 0;
}
