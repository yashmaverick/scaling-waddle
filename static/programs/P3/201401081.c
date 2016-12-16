#include<stdio.h>

int n;
long int a[100000];

long int max_array()
{
  long int max;
  max=0;
  long int sum;
  sum=0;
  int i;
  for(i=1;i<n;i++)
    {
      sum+=a[i];
      if(sum<0)
	{
	  while(a[i]<0)
	    i++;
	  sum=a[i];
	}
      if(sum>max)
	max=sum;
    }
  return max;
}	  

int main()
{
  int t;
  scanf("%d",&t);
  while(t--)
    {
      scanf("%d",&n);
      int i;
      for(i=0;i<n;i++)
	scanf("%ld",&a[i]);
      for(i=n-1;i>0;i--)
	a[i]-=a[i-1];
      printf("%ld\n",max_array());
    }
  return 0;
}
