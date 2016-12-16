#include <stdio.h>
#include <stdlib.h>
#define MAX 200100
#define mod 1000000007

typedef struct heap {
  long long arr[MAX];
  long long end;
} heap;

heap min,max;
long long m,n,sum;

long long nmin(long long a,long long b)
{
  return a>b?b:a;
}

long long nmax(long long a,long long b)
{
  return a>b?a:b;
}

void swap(long long *ar,long long a,long long b)
{
  long long temp=ar[a];
  ar[a]=ar[b];
  ar[b]=temp;
}

void imin(long long i)
{
  min.arr[min.end++]=i;
  long long b=min.end-1;
  long long *d=&(min.arr[0]);
  while(d[b/2]>d[b] && b/2>=1)
    {
      swap(d,b/2,b);
      b=b/2;
    }
  /*printf("imin ");
  for(i=1;i<min.end;i++)
    printf("%lld ",min.arr[i]);
    printf("\n");*/
}

void imax(long long i)
{
  max.arr[max.end]=i;
  max.end++;
  long long b=max.end-1;
  long long *d=&(max.arr[0]);
  while(d[b/2]<d[b] && b/2>=1)
    {
      swap(d,b/2,b);
      b=b/2;
    }
  /*printf("imax ");
  for(i=1;i<max.end;i++)
    printf("%lld ",max.arr[i]);
    printf("\n");*/
}

void dmin()
{
  long long i=1;
  /*printf("dmini ");
  for(i=1;i<min.end;i++)
    printf("%lld ",min.arr[i]);
  printf("\n");*/
  i=1;
  long long *d=&(min.arr[0]);
  d[1]=d[min.end-1];
  d[min.end-1];
  min.end--;
  long long a,b,j,k;
  a=nmin(d[2*i],d[2*i+1]);
  while(a<d[i] && 2*i+1<min.end)
    {
      if(d[2*i]<d[2*i+1])
	{
	  swap(d,i,2*i);
	  i=2*i;
	}
      else
	{
	  swap(d,i,2*i+1);
	  i=2*i+1;
	}
      a=nmin(d[2*i],d[2*i+1]);
    }
  //printf("i %lld\n",i);
  if(d[2*i]<d[i] && 2*i <min.end)
    {
      // printf("in \n");
      swap(d,i,2*i);
    }
  /*printf("dmine ");
  for(i=1;i<min.end;i++)
    printf("%lld ",min.arr[i]);
    printf("\n");*/
}

void dmax()
{
  long long *d=&(max.arr[0]);
  d[1]=d[max.end-1];
  d[max.end-1]=0;
  max.end--;
  long long i=1,a,b,j,k;
  a=nmax(d[2*i],d[2*i+1]);
  while(a>d[i] && 2*i < max.end)
    {
      if(d[2*i]>d[2*i+1])
	{
	  swap(d,i,2*i);
	  i=2*i;
	}
      else
	{
	  swap(d,i,2*i+1);
	  i=2*i+1;
	}
      a=nmax(d[2*i],d[2*i+1]);
    }
}

void init(long long a,long long b,long long c)
{
  long long two=(a+2*b+c)%mod;
  sum+=two;
  if(two>1)
    {
      imax(1);
      imin(two);
      m=1;
    }
  else
    {
      imin(1);
      imax(two);
      m=two;
    }
}

void doit(long long a,long long b,long long c)
{
  long long i,j,k,l;
  for(i=3;i<=n;i++)
    {
      j=((a*m)%mod+(b*i)%mod+c)%mod;
      //printf("i %lld m %lld j %lld\n",i,m,j);
      sum+=j;
      if(j>max.arr[1])
	imin(j);
      else
	imax(j);
      k=min.end-max.end;
      if(abs(k)<2)
	{
	  if(k<=0)
	    m=max.arr[1];
	  else
	    m=min.arr[1];
	}
      else
	{
	  if(k<0)
	    {
	      l=max.arr[1];
	      dmax();
	      imin(l);
	      m=max.arr[1];
	    }
	  else
	    {
	      l=min.arr[1];
	      dmin();
	      imax(l);
	      m=max.arr[1];
	    }
	}
    }
}
  
long long main()
{
  long long i,j,k,test,a,b,c;
  scanf("%lld",&test);
  for(k=0;k<test;k++)
    {
      sum=1;min.end=max.end=1;
      scanf("%lld %lld %lld %lld",&a,&b,&c,&n);
      init(a,b,c);
      doit(a,b,c);
      printf("%lld\n",sum);
      /*printf("min ");
      for(i=1;i<min.end;i++)
	printf("%lld ",min.arr[i]);
      printf("\n");
      printf("max ");
      for(i=1;i<max.end;i++)
	printf("%lld ",max.arr[i]);
	printf("\n");*/
    }
  return 0;
}
