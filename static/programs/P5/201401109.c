#include<stdio.h>
#include <stdlib.h>
void qsort( void *buf, size_t num, size_t size, int (*cmpfunc)(const void *, const void *) );
int cmpfunc (const void * a, const void * b)
{
     return ( *(int*)a - *(int*)b );
}
int main()
{
  int i,j,k,n,m,t,p,p1,flag,sum,low,high;
  scanf("%d",&t);
  while(t--)
  {
    flag=0;sum=0;
    scanf("%d%d",&n,&k);
    int a[n];
    char b[100];
    for(i=0;i<n;i++)
      scanf("%s%d",b,&a[i]);
     //will sort the array
      qsort(a,n, sizeof(int), cmpfunc);
/*      for(i=0;i<n;i++)
        printf("%d ",a[i]);
      printf("\n");*/

     for(i=0;i<n-2;i++)
      {
          sum=0;
          sum=sum+a[i];
          low=i+1;high=n-1;
          for(j=i+1;j<n;j++)
          {
              sum=sum+a[low]+a[high];
              if(sum==k)
              {
                  flag=1;
                  printf("YES\n");
                  break;
              }
              else 
              {
                 // if(low<high)
                 // {
                  if(sum<k)
                  {
                      if(low<high-1)
                          low=low+1;
                              else
                              break;
                  }
                  else
                  {
                     if (high>low+1)
                      high=high-1;
                      else
                          break;
                  }
                  sum=0;
                  sum=sum+a[i];

              }
           }
              if(flag==1)
                  break;
       }
       if(flag==0)
           printf("NO\n");
      }
      return 0;
  }
                 


       
