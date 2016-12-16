#include<stdio.h>
int main()
{
  long long int t,n,i,sum,min;
  long long int a[1000001];
  scanf("%lld",&t);
  while(t--)
    {
      long long int b[1000000]={0};
      sum=0;min=10000000;
      scanf("%lld",&n);
      for(i=0;i<n;i++)
	{	  
	  scanf("%lld",&a[i]);
	  if(a[i]<min)
	    min=a[i];
	}
      for(i=0;i<n;i++)
	{
	  a[i]=a[i]-min;
	  b[(a[i])]+=1;
	}
      for(i=0;i<n;i++)
	{
	  if(b[a[i]]>1)
	    {
	      sum=sum+(((b[a[i]])*(b[a[i]]-1))/2);
	      b[a[i]]=0;
	    }
	}
      printf("%lld\n",sum);
    }
}

      
      
