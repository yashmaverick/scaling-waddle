#include<stdio.h>
#include<stdlib.h>
typedef long long int lint;
int main()
{
  lint answer,nextindex;
  lint count,n,i,left,right,cur,prev,next,ind,flag=0;
  scanf("%lld",&n);
  while(n!=0)
  {
    answer=0;
    count=0;
    //  flagl=0;
    //  flagr=0;
    lint *array=malloc(n*sizeof(lint));
    lint *indexl=malloc(n*sizeof(lint));
    lint *indexr=malloc(n*sizeof(lint));

    for(i=0;i<n;i++)
      scanf("%lld",&array[i]);

    cur=n-2;
    indexl[n-1]=-1;
    next=n-1;

    while(cur>=0)
    {
      if(array[cur]==array[next])
      {
        indexl[cur]=indexl[next];
        cur--;
        next=cur+1;
      }
      else if(array[cur]<array[next])
      {
        if(indexl[next]==-1)
        {
          indexl[cur]=next;
        }
        else
        {
          indexl[cur]=indexl[next];
        }
        cur--;
        next=cur+1;
      }
      else if(array[cur]>array[next])
      {
        if(indexl[next]==-1)
        {
          indexl[cur]=-1;
          cur--;
          next=cur+1;
        }
        else
        {
          nextindex=indexl[next];
          next=nextindex;
        }
      }
    }
/*    printf("INDEX ARRAY IN -> \n");
    for(i=0;i<n;i++)
      printf("%lld ",indexl[i]);
    printf("\n");
*/
    cur=1;
    indexr[0]=-1;
    prev=0;

    while(cur<n)
    {
      if(array[cur]==array[prev])
      {
//        printf("CUR %d %d PREV %d %d\n",cur,array[cur],prev,array[prev]);
        indexr[cur]=indexr[prev];
        cur++;
        prev=cur-1;
      }
      else if(array[cur]<array[prev])
      {
        if(indexr[prev]==-1)
        {
          indexr[cur]=prev;
  //        printf("CUR %d FFF %d PREV %d %d\n",cur,array[cur],prev,array[prev]);
        }
        else
        {
    //      printf("CUR %d %d PREV %d %d\n",cur,array[cur],prev,array[prev]);
          indexr[cur]=indexr[prev];
        }
        cur++;
        prev=cur-1;
      }
      else if(array[cur]>array[prev])
      {
        if(prev==-1||prev==0||indexr[prev]==-1)
        {
          indexr[cur]=-1;
          cur++;
          prev=cur-1;
        }
        else
        {
          nextindex=indexr[prev];
          prev=nextindex;
        }

    //    printf("CUR %d %d PREV %d %d\n",cur,array[cur],prev,array[prev]);
      }
    }
/*    printf("INDEX ARRAY IN <-\n");
    for(i=0;i<n;i++)
      printf("%lld ",indexr[i]);
    printf("\n");*/
count=0;
    for(i=0;i<n;i++)
    {
      if(indexr[i]==-1&&indexl[i]==-1)
        count+=0;
      else if(indexl[i]==-1||indexr[i]==-1)
        count+=1;
      else 
        count+=2;
    }
 //  printf("Count after index array formation: %lld\n",count);
   

    cur=n-2;
    indexl[n-1]=1;
    next=n-1;
    while(cur>=0)
    {
      if(array[cur]==array[next])
      {
        indexl[cur]=indexl[next]+1;
        indexl[next]=1;
        cur--;
        next=cur+1;
      }
      else if(array[cur]<array[next])
      {
        indexl[cur]=1;
        cur--;
        next=cur+1;
      }
      else if(array[cur]>array[next])
      {
        if(next==n-1)
        {
          indexl[cur]=1;
          cur--;
          next=cur+1;
        }
        else
          next++;
      }
    }
    /*  printf("FOR NC2: \n");
        for(i=0;i<n;i++)
          printf("%lld ",indexl[i]);
        printf("\n");*/
  //  printf("%lld\n",count);
long long int value=0;
for(i=0;i<n;i++)
{
  if(indexl[i]>1)
  {
    value=indexl[i]*(indexl[i]-1);
   // printf("%lld\n",value);
    count=count+value/2;
  }
}
    
    answer=(n*(n-1)/2)-count;
    printf("%lld\n",answer);
    scanf("%lld",&n);
  }
  return 0;
}
