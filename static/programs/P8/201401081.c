#include<stdio.h>
#define MOD 1000000007
#define ulli unsigned long long int

ulli ul;
int N;
ulli a[100];

ulli func(int num)
{
  ulli temp;
  temp=(int)ul/N;
  if(ul%N>=num)
    temp++;
  return temp;
}	 

ulli fast_expo(ulli num,ulli pow)
{
  if(num==0)
    return 0;
  else if(pow==0)
    return 1;
  else if(pow==1)
    return num;
  else
    {
      ulli temp;
      temp=(fast_expo(num,pow/2))%N;
      temp=(temp*temp)%N;
      if((pow&1)==1)
	temp=(temp*num)%N;
      return temp;
    }
}

int main()
{
  int t,m;
  int i,j,k;
  ulli d;
  ulli temp[3];
  unsigned long long int count;
  scanf("%d",&t);
  while(t--)
    {
      count=0;
      scanf("%llu",&ul);
      scanf("%lld",&d);
      scanf("%d",&m);
      scanf("%d",&N);
      m=m%N;
      //printf("ul=%lld d=%lld m=%d N=%d\n",ul,d,m,N);
      for(i=0;i<N;i++)
	a[i]=(fast_expo(i,d))%N;
      /* for(i=0;i<N;i++) */
      /* 	printf("%lld ",a[i]); */
      /* printf("\n"); */
      for(i=0;i<N&&i<=ul;i++)
	for(j=0;j<N&&j<=ul;j++)
	  for(k=0;k<N&&k<=ul;k++)
	    if(((a[i]+a[j]+a[k])%N)==m)
	      {
		//printf("%lld^%lld+%lld^%lld+%lld^%lld=%d\n",a[i],d,a[j],d,a[k],d,m);
		if(ul<=N)
		  count++;
		else
		  {
		    temp[0]=((ul-i)/N+1)%MOD;
		    temp[1]=((ul-j)/N+1)%MOD;
		    temp[2]=((ul-k)/N+1)%MOD;
		    count=(count+(((temp[0]*temp[1])%MOD)*temp[2])%MOD)%MOD;
		  /* temp=(int)func(i); */
		  /* temp=(int)(temp*func(j))%MOD; */
		  /* temp=(int)(temp*(int)func(k))%MOD; */
		  /* count+=temp%MOD; */
		    /* count+=((ul/N)*3)%MOD; */
		    /* if(temp>0&&temp>=a[i]) */
		    /*   count=(count+1)%MOD; */
		    /* if(temp>0&&temp>=a[j]) */
		    /*   count=(count+1)%MOD; */
		    /* if(temp>0&&temp>=a[k]) */
		    /*   count=(count+1)%MOD; */
		}
	      }
      printf("%llu\n",count);
    }
  return 0;  
}
