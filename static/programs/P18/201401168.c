#include<stdio.h>
int node,count,n;
int visit[1005]={0};

void dfs(int a[][1010],int row)
{
  visit[row]=1;
  if(count < n-1)
    {
      int j;
      for(j=1;j<=n && count < n-1;j++)
	{
	  //	  printf("a[%d][%d]=%d, visit[%d] = %d\n",row,j,a[row][j],j,visit[j]);
	  if(a[row][j]==1 && visit[j]==0)
	    {
	      //	      printf("%d : %d is in, count=%d\n\n",row,j,count);
	      ++count;
	      dfs(a,j);
	      //	      printf("%d : %d is out, count=%d\n\n",row,j,count);
	    }
	}
    }
  //  visit[row]=0;
}

void reverse(int a[][1010],int col)
{
  visit[col]=1;
  int i;
  for(i=1;i<=n;i++)
    {
      if(a[i][col]==1 && visit[i]==0)
	{
	  ++count;
	  reverse(a,i);
	}
    }
}

int main()
{
  int t,i,j,m,x,k;
  scanf("%d",&t);
  while(t!=0)
    {
      node=-1;count=0;
      for(i=0;i<=n;i++)
	visit[i]=0;
      scanf("%d",&n);
      int a[1010][1010]={0};
      for(i=1;i<=n;i++)
	{
	  scanf("%d",&m);
	  for(j=1;j<=m;j++)
	    {
	      scanf("%d",&x);
	      a[x][i]=1;
	    }
	}
      for(i=1;i<=n && count < n-1;i++)
	{
	  count=0;
	  dfs(a,i);
	  node=i;
	  for(k=0;k<=n;k++)
	    visit[k]=0;
	}
       if(count != n-1 || node==-1)
	count=0;
      else
	{
	  count=0;
	  reverse(a,node);
	  if(n>0)
	      count++;
	}
      if(n!=1)
        printf("%d\n",count);
      else
        printf("1\n");
      t--;
    }
}
