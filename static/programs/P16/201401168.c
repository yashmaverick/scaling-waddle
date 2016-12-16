#include<stdio.h>
#include<math.h>
long long int po(long long int a,long long int b,long int m)
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
  long long int t,n,i,imp1,imp2,mid,p1,p2;
  scanf("%lld",&t);
  while(t!=0)
    {
      scanf("%lld",&n);
      imp1=log2(n);
      imp2=imp1+1;
      p1=po(2,imp1,1000000100);
      p2=2*p1;
      mid=(p1+p2)/2;
      if(n<mid)
	printf("%lld\n",2*imp1-1);
      else
	printf("%lld\n",2*imp1);
      t--;
    }
  return 0;
}
      
