#include<stdio.h>
int main()
{
  int t;
  scanf("%d",&t);
  while(t--)
  {
    int i,n;
    long long int a[100100],b=0,max=0;
    scanf("%d",&n);
    scanf("%lld",&a[0]);
    b=a[0];
    for(i=1;i<n;i++)
    {
      scanf("%lld",&a[i]);
      a[i-1]=a[i]-b;
      if(a[i]<b)
      {
        b=a[i];
      }
    }
    max=a[0];
    for(i=0;i<n-1;i++)
    {
      if(max<a[i])
      {
        max=a[i];
      }
    }
    if(max<0)
    {
      printf("0\n");
    }
    else
      printf("%lld\n",max);
  }
  return 0;
}
