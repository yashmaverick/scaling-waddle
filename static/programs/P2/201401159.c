#include <stdio.h>
#include <stdlib.h>

long long binary(long long arr[],long long low,long long high,long long k)
{
  if(low<high)
    {
      int mid=(low+high)/2;
      //if(arr[mid]==k)
      //return mid;
      if(arr[mid]<=k)
	binary(arr,mid+1,high,k);
      else 
	binary(arr,low,mid-1,k);
    }
  else
    {
      if(arr[high]<=k)
	return high;
      else
	return high-1;
    }
}


long long arr1[100001],arr2[100001],arr3[100001];

int main()
{
  long long i,k,j1,j2,j3,l,a,b,c,test,sum=0,temp;
  scanf("%lld",&test);
  for(i=0;i<test;i++)
    {
      long long a1v[100001]={0},a2v[100001]={0};
      scanf("%lld",&j1);
      for(k=0;k<j1;k++)
	scanf("%lld",&arr1[k]);
      scanf("%lld",&j2);
      for(k=0;k<j2;k++)
	scanf("%lld",&arr2[k]);
      scanf("%lld",&j3);
      for(k=0;k<j3;k++)
	scanf("%lld",&arr3[k]);
      sum=0;
		
      for(a=j3-1;a>=0;a--)
	{
	  b=j2-1>a?a:j2-1;
	  /* while(arr2[b]>arr3[a]&&b>0)
	      b--;
	  if(b!=0)
	    a2v[b]++;
	  else if(arr2[b]<=arr3[a])
	  a2v[0]++;*/
	  temp=binary(arr2,0,b,arr3[a]);
	  a2v[temp]++;
	}
      // printf("%lld\n",a2v[0]);
      for(a=j2-1;a>=0;a--)
	{
	  sum+=a2v[a];
	  a2v[a]=sum;
	}
      //printf("%lld\n",a2v[0]);
      for(a=j2-1;a>=0;a--)
	{
	  b=j1-1>a?a:j1-1;
	  /*while(arr1[b]>arr2[a]&&b>0)
	      b--;
	  if(b!=0)
	    a1v[b]+=a2v[a];
	  else if(arr1[b]<=arr2[a])
	  a1v[0]+=a2v[a];*/
	  //	  printf("%lld\n",a2v[0]);
	  temp = binary(arr1,0,b,arr2[a]);
	  a1v[temp]+=a2v[a];
	}
      // printf("%lld\n",a2v[0]);
      sum=0;
      for(a=j1-1;a>=0;a--)
	{ sum+=a1v[a];
	  a1v[a]=sum;
	}
      sum=0;
  for(a=j1-1;a>=0;a--)
	 sum+=a1v[a];
  // printf("%lld %lld %lld\n",a1v[0],a1v[1],a1v[2]);
      printf("%lld\n",sum);
    }
  return 0;
}
		
		
