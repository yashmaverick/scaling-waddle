#include<stdio.h>
#include<stdlib.h>
int main()
{ 
  int n,test,t,j,w,list,indexj,indexw;
  int *pre=malloc(n*sizeof(int));
  int *in=malloc(n*sizeof(int));
  scanf("%d",&n);
  int i;
  for(i=0;i<n;i++)
    scanf("%d",&pre[i]);
  for(i=0;i<n;i++)
    scanf("%d",&in[i]);

/*  for(i=0;i<n;i++)
    printf("%d",pre[i]);
  for(i=0;i<n;i++)
    printf("%d",in[i]);*/
  scanf("%d",&test);
  for(t=0;t<test;t++)
  {
    int visited[1000007]={0};
    scanf("%d%d",&j,&w);
    if(j==w)
    {
      printf("%d\n",j);
      continue;
    }
    for(i=0;i<n;i++)
    {
      if(in[i]==j)
        indexj=i;
      else if(in[i]==w)
        indexw=i;
    }
//    printf("INDEX JON %d\n",indexj);
//   printf("INDEX WHITE WALKER %d\n",indexw);
    int ans,j,start,end;
    if(indexj>indexw)
    {
      start=indexw;
      end=indexj;
    }
    else
    {
      start=indexj;
      end=indexw;
    }
//    printf("START %d END %d\n",start,end);
    for(j=start;j<=end;j++)
    {
//      printf("in[j]%d\n",in[j]);
      visited[in[j]]=1;
    }

    for(i=0;i<n;i++)
    {
      if(visited[pre[i]]==1)
      {
        ans=pre[i];
        break;
      }
    }

    printf("%d\n",ans);
  }
  return 0;
}
    
