#include<stdio.h>
long long max[200100],ron=0,maxf=0;
void maxup(long long crow)
{
  if(crow/2>0&&max[crow/2]<max[crow])
    {
      long long temp=max[crow];
      max[crow]=max[crow/2];
      max[crow/2]=temp;
      maxup(crow/2);
    }
}  

void maxdown(long long crow)
{
  if(maxf==0 && crow<=ron)
    {
      long long t;
      if(crow*2+1<=ron)
	{
	  t=max[crow*2] > max[crow*2+1]?crow*2:(crow*2+1);
	}
      else
	{
	  t=crow*2;
	}
      if(t<=ron && max[t]>max[crow])
	{
	  long long temp=max[crow];
	  max[crow]=max[t];
	  max[t]=temp;
	  //      printf("exchange( %c )  max[%lld]=%lld and max[%lld]=%lld\n",c,crow,max[crow],t,max[t]);
	  maxdown(t);
	}
      else
	if(t<=ron)
	  maxf=1;
    }
}

void maxdel()
{
  if(ron>0)
    {
      long long i,imp=1;
      maxf=0;
      max[imp]=max[ron];
      ron=ron-1;
      maxup(imp);
      maxdown(imp);
    }
}

void maxins(long long val)
{
  max[++ron]=val;
  maxup(ron);
}


long long min[200100],pos=0,minf=0;
void shuffleup(long long crow)
{
  if(crow/2>0&&min[crow/2]>min[crow])
    {
      long long temp=min[crow];
      min[crow]=min[crow/2];
      min[crow/2]=temp;
      shuffleup(crow/2);
    }
}  

void shuffledown(long long crow)
{
  if(minf==0 && crow<=pos)
    {
      long long t;
      if(crow*2+1<=pos)
	{
	  t=min[crow*2]<min[crow*2+1]?crow*2:(crow*2+1);
	}
      else
	{
	  t=crow*2;
	}
      if(t<=pos && min[t]<min[crow])
	{
	  long long temp=min[crow];
	  min[crow]=min[t];
	  min[t]=temp;
	  //      printf("exchange( %c )  min[%lld]=%lld and min[%lld]=%lld\n",c,crow,min[crow],t,min[t]);
	  shuffledown(t);
	}
      else
	if(t<=pos)
	  minf=1;
    }
}

void mindel()
{
  if(pos>0)
    {
      long long i,imp=1;
      minf=0;
      min[imp]=min[pos];
      pos=pos-1;
      shuffleup(imp);
      shuffledown(imp);
    }
}

void minins(long long val)
{
  min[++pos]=val;
  shuffleup(pos);
}


int main()
{
  long long t,a,b,c,n,i,sum,f,mod=1000000007,mid;
  scanf("%lld",&t);
  while(t!=0)
    {
      scanf("%lld %lld %lld %lld",&a,&b,&c,&n);
      sum=1;f=1;pos=0;ron=0;
      maxins(f);
      if(n>1)
	{
	  f=(((a)) + ((b)*2) +c)%mod;
	  if(f > max[1])
	    minins(f);
	  else
	    maxins(f);
	  sum=sum+f;
      
	  for(i=2;i<n;i++)
	    {
	      if(pos>=0 && ron>=0 && pos-ron >=2)
		{
		  maxins(min[1]);
		  mindel();
		}
	      if(pos>=0 && ron>=0 && ron-pos >=2)
		{
		  minins(max[1]);
		  maxdel();
		}
	      if(pos>=0 && ron>=0 && pos-ron ==1)
		mid=min[1];
	      else
		if(pos>=0 && ron>=0 && (ron-pos ==1||ron-pos==0))
		  mid=max[1];

	      f=(((a)*(mid)) + ((b)*(i+1)) +c)%mod;
	      if(f < min[1])
		maxins(f);
	      else
		if(f >= min[1])
		  minins(f);
	      sum=sum+f;
	    }
	}
      printf("%lld\n",sum);
      t--;
    }
  return 0;
}
