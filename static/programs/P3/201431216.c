#include<stdio.h>
void swap( int *a,int *b)
{
   int t;
  t=*a;
  *a=*b;
  *b=t;
}
int main()
{
  int test;
   int n,i,j,a[100010];
  scanf("%d",&test);
  for(i=0;i<test;i++)
  {
    scanf("%d",&n);
    for(j=0;j<n;j++)
    {
      scanf("%d",&a[j]);
    }
   int  max=0;
    for(j=n-1;j>=1;j--)
    {
      if(a[j]>a[j-1])
      {
        if((a[j]-a[j-1])>max)
        {
          max=(a[j]-a[j-1]);
        //  swap(&a[j],&a[j-1]);
          
        }
      
          swap(&a[j],&a[j-1]);
      }
    }
    printf("%d\n",max);
  }
  return 0;
}

      






