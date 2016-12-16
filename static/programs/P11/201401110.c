#include<stdio.h>
#include<stdlib.h>

int main()
{
  long long int n,cur,next,prev,i,j,maxarea=0;
  scanf("%lld",&n);
  while(n!=0)
  {
    long long int *array=malloc(n*sizeof(long long int));
    long long int *index=malloc(n*sizeof(long long int));
    long long int *area=malloc(n*sizeof(long long int));
    for(i=0;i<n;i++)
    {
      scanf("%lld",&array[i]);
    }

/*    index[0]=-1;
    i=1;
    while(i<n)
    {
      if(array[i]<array[i-1])
        index[i]=-1;
      else if(array[i]==array[i-1])
        index[i]=index[i-1];
      else if(array[i]>array[i-1])
          index[i]=i-1;
      i++;
    }*/
    index[0]=-1;
    cur=1;
    prev=0;
    while(cur<n)
    {
      if(array[cur]>array[prev])
      {
        index[cur]=prev;
        cur++;
        prev=cur-1;
      }
      else if(array[cur]<array[prev])
      {
        prev--;
        if(prev<0)
        {
          index[cur]=-1;
          cur++;
          prev=cur-1;
        }
      }
      else if(array[cur]==array[prev])
      {
        index[cur]=index[prev];
        cur++;
        prev=cur-1;
      }
    }
/*   printf("Index array from right to left: \n");
   for(i=0;i<n;i++)
     printf("%lld : ",index[i]);
   printf("\n");*/
    //calculate the area from right to left

    i=0;
    while(i<n)
    {
      if(index[i]==-1)
        area[i]=array[i]*(i+1);
      else 
      {
        area[i]=array[i]*(i-index[i]);
      }
      i++;
    }
/*printf("Area from only one side: \n");
    for(i=0;i<n;i++)
      printf("%lld : ",area[i]);
    printf("\n");*/

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

/*   printf("Index array from left to right: \n");
   for(i=0;i<n;i++)
     printf("%lld : ",index[i]);
   printf("\n");*/

    i=0;
    while(i<n)
    {
      if(index[i]==-1)
        area[i]+=array[i]*(n-i);
      else 
        area[i]+=array[i]*(index[i]-i);
      i++;
    }

    
/*    printf("Area from only one side: \n");
    for(i=0;i<n;i++)
      printf("%lld : ",area[i]);
    printf("\n");*/

    maxarea=0;
    for(i=0;i<n;i++)
    {
      area[i]=area[i]-array[i];
      if(area[i]>maxarea)
        maxarea=area[i];
    }

    printf("%lld\n",maxarea);
    scanf("%lld",&n);
  }
  return 0;
}



