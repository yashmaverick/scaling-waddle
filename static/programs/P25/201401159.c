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
long long ver;
long long p[MAX];
long long v[MAX];
node* d[MAX];
long long start=1,end=1;
long long sum=0;

long long min(long long a,long long b)
{
  return a>b?b:a;
}

void swap(node **ar,long long a,long long b)
{
  node* temp=ar[a];
  ar[a]=ar[b];
  ar[b]=temp;
}

void nswap(long long *ar,long long a,long long b)
{
  long long temp=ar[a];
  ar[a]=ar[b];
  ar[b]=temp;
}

void update(long long i,long long y)
{
  long long b=p[i];
  long long a=min(d[b]->w,y);
  d[b]->w=a;
  while(b/2>=1 && d[b/2]->w>d[b]->w)
    {
      swap(d,b/2,b);
      nswap(p,d[b/2]->x,d[b]->x);
      b=b/2;
    }
  p[i]=b;
}

void insert(long long i,long long y)
{
  int j;
  if(p[i]==0)
    {
      node* temp=(node*)malloc(sizeof(node));
      temp->x=i;temp->w=y;
      d[end++]=temp;
      long long b=end-1;
      p[i]=b;
      while(b/2>=1 && d[b/2]->w>d[b]->w)
	{
	  swap(d,b/2,b);
	  nswap(p,d[b/2]->x,d[b]->x);
	  b=b/2;
	}
    }
  else
    update(i,y);
  /*printf("pos ");
  for(j=1;j<=ver;j++)
    printf("%lld ",p[j]);
    printf("\n");*/
}

void delete()
{
  long long i=1,a,b,j,k;
  d[i]=d[end-1];
  p[d[end-1]->x]=i;
  d[end-1]=NULL;
  end--;
  if(2*i+1 < end)
    a=min(d[2*i]->w,d[2*i+1]->w);
  while(2*i+1 < end && a<d[i]->w)
    {
      if(d[2*i]->w<d[2*i+1]->w)
	{
	  swap(d,i,2*i);
	  nswap(p,d[i]->x,d[2*i]->x);
	  i=2*i;
	}
      else
	{
	  swap(d,i,2*i+1);
	  nswap(p,d[i]->x,d[2*i+1]->x);
	  i=2*i+1;
	}
      if(2*i+1 < end)
	a=min(d[2*i]->w,d[2*i+1]->w);
    }
  if(2*i< end && d[2*i]->w<d[i]->w)
    {
      swap(d,i,2*i);
      nswap(p,d[i]->x,d[2*i]->x);
    }
}

void build()
{
  long long i;
  if(start>ver || end==1) 
    return;
  v[i=d[1]->x]=1;
  sum+=d[1]->w;
  //printf("i %lld %lld ",i,d[1]->w);
  delete();
  node* tp=arr[i];
  tp=tp->next;
  while(tp!=NULL)
    {
      if(v[tp->x]==0)
	insert(tp->x,tp->w);
      tp=tp->next;
    }
  start++;
  build();
}

long long main()
{
  long long i,j,k,l,test,e,a,b,c;
  scanf("%lld %lld",&ver,&e);
  for(i=1;i<=ver;i++)
    arr[i]=(node*)malloc(sizeof(node));
  for(i=0;i<e;i++)
    {
      scanf("%lld %lld %lld",&a,&b,&c);
      node* temp=(node*)malloc(sizeof(node));
      temp->x=b;temp->w=c;
      temp->next=arr[a]->next;
      arr[a]->next=temp;
      node* rtemp=(node*)malloc(sizeof(node));
      rtemp->x=a;rtemp->w=c;
      rtemp->next=arr[b]->next;
      arr[b]->next=rtemp;
    }
  insert(1,0);
  build();
  if(start>ver)
    printf("%lld\n",sum);
  else
    printf("-1\n");
  /*for(i=1;i<end;i++)
    printf("%lld ",d[i]->w);*/
  return 0;
}
