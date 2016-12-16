#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 500010

typedef struct node {
  long long x;
  long long w;
  struct node* next;
} node;

node* arr[MAX];
long long d[MAX];
long long ver;
long long f[MAX];
long long v[MAX];
long long p[MAX];
long long rp[MAX],start=1;

long long min(long long a,long long b)
{
  return a>b?b:a;
}

void swap(long long *ar,long long a,long long b)
{
  long long temp=ar[a];
  ar[a]=ar[b];
  ar[b]=temp;
}

void init(long long n)
{
  long long i,j,k;
  d[0]=LONG_MAX;
  d[1]=0;
  for(i=2;i<ver+1;i++)
	d[i]=LONG_MAX;
  for(i=1,j=2;i<=ver;i++,j++)
    {
      v[i]=0;
      f[i]=0;
      if(i==n)
	{
	  j--;
	  continue;
	}
      p[i]=j;
      rp[j]=i;
    }
  p[n]=1;
  rp[1]=n;
  start=1;
}

void shup(long long i)
{
  long long a=i,b=p[i],c,j,k;
  while(d[b/2]>d[b] && b/2>=1)
    {
      swap(d,b/2,b);
      swap(rp,b/2,b);
      swap(p,rp[b/2],rp[b]);
      b=b/2;
    }
  //p[i]=b;
  //rp[b]=i;
  /*prlong longf("arr ");
  for(j=1;j<=ver;j++)
    prlong longf("%lld ",d[j]);
    prlong longf("\n");*/
}

void delete()
{
  long long i=1,a,b,j,k;
  d[i]=LONG_MAX;
  a=min(d[2*i],d[2*i+1]);
  /* printf("delete\n");
  for(j=1;j<=ver;j++)
    printf("%lld ",p[j]);
    printf("\n");*/
  while(a<d[i] && 2*i <=ver)
    {
      //printf("swapping %lld i %lld\n",a,i);
      if(d[2*i]<d[2*i+1])
	{
	  swap(d,i,2*i);
	  swap(rp,i,2*i);
	  swap(p,rp[i],rp[2*i]);
	  //printf("swapping %lld , %lld\n",rp[i],rp[2*i]);
	  i=2*i;
	}
      else
	{
	  swap(d,i,2*i+1);
	  swap(rp,i,2*i+1);
	  swap(p,rp[i],rp[2*i+1]);
	  //printf("swapping %lld , %lld\n",rp[i],rp[2*i+1]);
	  i=2*i+1;
	}
      a=min(d[2*i],d[2*i+1]);
    }
  /*for(j=1;j<=ver;j++)
    printf("%lld ",p[j]);
    printf("\n");*/
}

void update(long long i,long long j,long long w)
{
  if(v[j]==1)
    return; 
  d[p[j]]=min(d[p[i]]+w,d[p[j]]);
  // printf("val of %lld is %lld\n",j,d[p[i]]);
  shup(j);
}

void build()
{
  if(start>ver||arr[rp[1]]==0) 
    return;
  //printf("inbuild\n");
  long long n=rp[1];
  f[n]=d[1];
  //printf("test %lld dist %lld\n",n,p[n]);
  node* tp=arr[n];
  //prlong longf("n %lld\n",n);
  tp=tp->next;
  while(tp!=NULL)
    {
      //printf("test in %lld for %lld\n",tp->x,n);
      update(n,tp->x,tp->w);
      tp=tp->next;
    }
  delete();
  v[n]=1;
  start++;
  build();
}

int main()
{
  long long i,j,k,l,test,e,a,b,c;
      scanf("%lld %lld",&ver,&e);
      for(i=1;i<=ver;i++)
	arr[i]=(node*)malloc(sizeof(node));
      node* prev;
      for(i=0;i<e;i++)
	{
	  scanf("%lld %lld %lld",&a,&b,&c);
	  node* temp=(node*)malloc(sizeof(node));
	  temp->x=b;temp->w=c;
	  temp->next=arr[a]->next;
	  arr[a]->next=temp;
	}
      scanf("%lld %lld",&a,&b);
      init(a);
      build();
      if(f[b]!=0)
	printf("%lld\n",f[b]);
      else
	printf("NO\n");
  return 0;
}
