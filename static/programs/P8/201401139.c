#include<stdio.h>

long long int const MOD = 1000000000 +7;

int max(int a,int b,int c)
{
  if(a>=b&&a>=c)
    return a;
  else if(b>=a&&b>=c)
    return b;
  else
    return c;
}

long long int powmod(long long int a,long long int b,long long int c)
{
  if(b==0)
    return 1;
  
  if(a==0)
    return 0;

  long long int x=powmod(a,b/2,c);
  long long int y=(x*x)%c;
  
  if(b%2)
    return (a*y)%c;
  return y;    
}

int main()
{
  int a,b,c,k,t;
  long long int arr[45];
  long long int ub,d,m,N,score,temp1,temp2,temp3;
  
  scanf("%d",&t);
  while(t>0)
    {
      scanf("%lld%lld%lld%lld",&ub,&d,&m,&N);
      score=0;
      for(a=0;a<N;a++)
	{
	  arr[a]=powmod(a,d,N)%N;
	}

      m=m%N;
      for(a=0;a<N&&a<=ub;a++)
	{
	  for(b=0;b<N&&b<=ub;b++)
	    {
	      for(c=0;c<N&&c<=ub;c++)
		{
		  if((arr[a]+arr[b]+arr[c])%N==m)
		    {
		      if(ub>N)
			{
			  temp1=((ub-a)/N+1)%MOD;
			  temp2=((ub-b)/N+1)%MOD;
			  temp3=((ub-c)/N+1)%MOD;
			  score=(score+(((temp1*temp2)%MOD)*temp3)%MOD)%MOD;
			  
			}
		      else
			score++;
		    }
		  
		  //printf("%lld ",score);
		}
	    }
	}
      printf("%lld\n",score);
      t--;
    }

  
  
  return 0;
}

