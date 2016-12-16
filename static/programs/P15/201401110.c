#include<stdio.h>
#include<stdlib.h>
typedef long long int ll;
int main()
{
  ll j,n,i,min,k,test,t,minindex,flag=0;
  scanf("%lld",&test);
  for(t=0;t<test;t++)
  {
    flag=0;
    scanf("%lld",&n);
    scanf("%lld",&k);
    ll *array=malloc(n*sizeof(ll));
    for(i=0;i<n;i++)
    {
      scanf("%lld",&array[i]);
    }
    min=array[0];
    minindex=0;
    for(i=0;i<k;i++)
    {
      if(array[i]<min)
      {
        min=array[i];
        minindex=i;
      }
    }
    if(k!=n)
    {
      printf("%lld ",min);
    }
    else 
    {
      printf("%lld",min);
    }

    for(i=k;i<n;i++)
    {
      if(array[i]>min)
      {
        if((minindex>=i-k+1)&&minindex<=i)
        {
          flag=0;
        }
        else
        {
          min=1000000001;
          for(j=i-k+1;j<=i;j++)
          {
            if(array[j]<min)
            {
              min=array[j];
              minindex=j;
            }
          }
        }
        if(i!=n-1)
          printf("%lld ",min);
        else
          printf("%lld",min);

      }
      else
      {
        if(array[i]<=min)
        {
          minindex=i;
          min=array[i];
          if(i!=n-1)
          {
            printf("%lld ",min);
          }
          else
          {
            printf("%lld",min);
          }
        }
      }
    }
    printf("\n");
  }
  return 0;
}



