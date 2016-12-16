#include <stdio.h>
#include <stdlib.h>

int main()
{
  long long arv[1000000]={0};
  long long test,i,j,k,n;
  scanf("%lld",&test);
  for(i=0;i<test;i++)
    {
      scanf("%lld",&n);
      long long arr[n];
      for(j=0;j<n;j++)
	scanf("%lld",&arr[j]);
      long long min=arr[0];
      for(j=1;j<n;j++)
	{
	  if(arr[j]<min)
	    min=arr[j];
	}
      long long pi=-1*min;
      //printf("min %lld pi %lld\n",min,pi);
      for(j=0;j<n;j++)
	{
	  long long temp = arr[j]+pi;
	  //printf("test %lld\n",temp);
	  arv[temp]++;
	}
      //printf("test %lld\n",arv[2]);
      long long sum=0;
      for(j=0;j<1000000;j++)
	{
	  if(arv[j]!=0)
	    {
	      sum+=arv[j]*(arv[j]-1)/2;
	      arv[j]=0;
	      //printf("sum %lld\n",j);
	    }
	}
      printf("%lld\n",sum);
    }
  return 0;
}
