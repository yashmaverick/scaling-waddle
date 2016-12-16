#include<stdio.h>
int main()
{
  int i,t;
  scanf("%d",&t);
  for(i=0;i<t;i++)
    {
      long long int n,j,max=-10000000,min=10000000,a[1000000],b[1000000]={0};
      scanf("%lld",&n);
      for(j=0;j<n;j++)
	{
	  scanf("%lld",&a[j]);
	  if(a[j]>max)
	    {
	      max=a[j];
	    }
	  if(a[j]<min)
	    {
	      min=a[j];
	    }
	}
      for(j=0;j<n;j++)
	{
	  b[a[j]-min]++;
	}
      long long int sum=0;
      for(j=0;j<=max-min;j++)
	{
	  if(b[j]>1)
	    {
	      sum+=(b[j]*(b[j]-1))/2;
	    }
	}
      printf("%lld\n",sum);
    }
  return 0;
}
