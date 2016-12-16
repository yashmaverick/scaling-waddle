#include<stdio.h>
#include<stdlib.h>
int maxnode,maxdepth,n;
int visited[100000];
void depthfind(int root,int depth,int array[],int index[])
{
  
//    printf("function called for root: %d\n",array[root]);
//    printf("Depth at this level: %d\n",depth);
    visited[root]=1;
    if(maxdepth<depth)
    {
      maxdepth=depth;
      maxnode=array[root];
    }
    else if(maxdepth==depth)
    {
      if(maxnode>array[root])
        maxnode=array[root];
    }
    if(root==n-1)
      return;
    int nextroot=index[root];
    if(visited[nextroot]==0&&index[root]!=-1)
    {
      depthfind(index[root],depth+1,array,index);
    }
    if(visited[root+1]==0)
          depthfind(root+1,depth+1,array,index);
}

int main()
{
int test,t,next,cur,i;
scanf("%d",&test);
for(t=0;t<test;t++)
{
  maxnode=0;
  maxdepth=0;
  scanf("%d",&n);
  for(i=0;i<n;i++)
    visited[i]=0;
  int *array=malloc(n*sizeof(int));
  int *index=malloc(n*sizeof(int));
  for(i=n-1;i>=0;i--)
    scanf("%d",&array[i]);

  next=n-1;
  cur=n-2;
  index[n-1]=-1;
  while(cur>=0)
  {
    if(array[cur]==array[next])
    {
      index[cur]=index[next];
      cur--;
      next=cur+1;
    }
    else if(array[cur]<array[next])
    {
      if(index[next]==-1)
      {
        index[cur]=-1;
        cur--;
        next=cur+1;
      }
      else
      {
        next++;
      }
    }
    else if(array[cur]>array[next])
    {
      index[cur]=next;
      cur--;
      next=cur+1;
    }
  }
  depthfind(0,0,array,index);
printf("%d %d\n",maxnode,maxdepth);  

//  for(i=0;i<n;i++)
//    printf("%d ",index[i]);
//  printf("\n");
}
return 0;
}



