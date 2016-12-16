#include<stdio.h>
long long int po(long long int a,long long int b,long long int m)
{
  if(b==0)
    return 1;
  long long int x=po(a,b/2,m);
  if(b%2==0)
    return (x*x)%m;
  else
    return ((a)%m*(x)%m*(x)%m)%m;
}
int main()
{
  long long int t,ul,d,m,N,count,temp,upx,upy,upz,sum,s,var,a[50],mod=1000000007;
  int x,y,z;
  scanf("%lld",&t);
  while(t!=0)
    {
      count=0;upx=upy=upz=0;sum=0;s=0;
      scanf("%lld %lld %lld %lld",&ul,&d,&m,&N);
      temp=N-1;
      if(ul<temp)
	temp=ul;
      for(x=0;x<=N;x++)
	{
	  a[x]=po(x,d,N);
	}
      for(x=0;x<=temp;x++)
	  for(y=0;y<=temp;y++)
	    for(z=0;z<=temp;z++)
		{
		  s=(a[x]+a[y]+a[z])%N;
		  if(s==m)
		    {
		      // printf("%lld %lld %lld\n",a[x],a[y],a[z]);
		      if(N-1==temp)
			{
			  upx=(ul-x)/N+1;upy=(ul-y)/N+1;upz=(ul-z)/N+1;
			  count=((((upx%mod)*(upy%mod))%mod)*(upz%mod))%mod;
			}
		      else
			{
			  count=1;
			}
		      sum=(sum+count)%mod;
		    }
		}
      printf("%lld\n",sum%(mod));
      t--;
    }
  return 0;
}	    



