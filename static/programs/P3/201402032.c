#include<stdio.h>
int main()
{
  int t;
  scanf("%d",&t);
  long long int n,i,arr[100007];
  long long int diff, low;
  while(t--)
  {
    
    scanf("%lld", &n);
    for(i=0;i<n;i++)
    {
      scanf("%lld", &arr[i]);
    }
    low = arr[0];
    diff = arr[1] - arr[0];
    
    for(i=1;i<n;i++)
    {
      if((arr[i]-low)> diff)
        diff = arr[i] - low;
      if(arr[i]<low)
        low = arr[i];
    }
    if(diff < 0)
      diff = 0;

    printf("%lld\n", diff);

  }
  
  return 0;
}