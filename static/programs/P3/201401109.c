#include<stdio.h>
int main()
{
  int i,j,k,n,t,small,small1,diff,diff1,max,a[100010];
  scanf("%d",&t);
  while(t--)
  {
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
      scanf("%d",&a[i]);
    }
    small=a[0];small1=a[0];
    diff=0;diff1=0;
    for(i=1;i<n;i++)
    {
      if(a[i]<small)
      {
        small1=small;
        small=a[i];
        diff1=diff;
      }
      if((a[i]-small)>=diff)
      {
        diff=a[i]-small;
       }
      if((a[i]-small1)>=diff1)
      {
        diff1=a[i]-small1;
      }
    }
    if(diff>diff1)
      max=diff;
    else
      max=diff1;

    printf("%d\n",max);
  }
  return 0;
}
    
    
