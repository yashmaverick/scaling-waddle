#include<stdio.h>

int main()
{
  long long int n,q;
  scanf("%lld",&n);
  while(n--)
    {
      scanf("%lld",&q);
      long long int h,temp;
      temp=q;
      h=-1;
      while(temp)
	{
	  temp=temp>>1;
	  h++;
	}
      //printf("%lld\n",h);
      long long int loc,dist;
      temp=1<<h;
      loc=temp+(1<<(h-1));
      //printf("%lld\n",loc);
      if(q<loc)
      	{
	  dist=2*h-1;
      	}
      else
      	{
	  dist=2*h;
      	}
      printf("%lld\n",dist);
    }
  return 0;
}
