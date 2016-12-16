#include<stdio.h>
#include<stdio.h>
typedef struct cross
{
  long long parent;
  long long rank;
}cross;

typedef struct spike
{
  long long weight;
  long long x;
  long long y;
}spike;

long long found;
long long onion(cross arr[100010],long long x)
{
  long long y=x;
  if(found==0)
    {
      if(arr[x].parent > 0 && arr[x].parent!=x)
	{
	  if(arr[arr[x].parent].rank < arr[x].rank + 1)
	    arr[arr[x].parent].rank=arr[x].rank + 1;	    
	  x=onion(arr,arr[x].parent);
	  arr[y].parent=x;
	}
      if(arr[x].parent==x && found==0)
	{
	  found=1;
	}
    }
  return x;
}

long long same(cross arr[100010],long long x)
{
  long long y=x;
  if(found==0)
    {
      if(arr[x].parent==x)
	{
	  found=1;
	}
      else
	{
	  x=same(arr,arr[x].parent);
	  arr[y].parent=x;
	}
    }
  return x;
}

spike min[1000010];
long long pos=0,minf=0;
void shuffleup(long long crow)
{
  if(crow/2>0 && min[crow/2].weight > min[crow].weight)
    {
      spike temp=min[crow];
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
	  t=min[crow*2].weight < min[crow*2+1].weight ? crow*2:(crow*2+1);
	}
      else
	{
	  t=crow*2;
	}
      if(t<=pos && min[t].weight < min[crow].weight)
	{
	  spike temp=min[crow];
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

void hprint() 
{
  long long i;
  for(i=1;i<=pos;i++)
    printf("%lld ",min[i].weight);
  printf("\n");
}

void delete()
{
  long long i,imp=1;
  minf=0;
  min[imp]=min[pos];
  pos=pos-1;
  shuffleup(imp);
  shuffledown(imp);
      
}

void insert(long long a,long long b,long long w)
{
  pos=pos+1;
  min[pos].x=a;
  min[pos].y=b;
  min[pos].weight=w;
  shuffleup(pos);
}

int main()
{
  long long n,m,q,x,y,w,i,sum;
  cross arr[100010];
  scanf("%lld %lld",&n,&q);
  m=q;
  for(i=0;i<=n;i++)
    {
      arr[i].parent=i;
      arr[i].rank=0;
    }
  for(i=0;i<q;i++)
    {
      scanf("%lld %lld %lld",&x,&y,&w);
      insert(x,y,w);
    }
  sum=0;
  while(q>0)
    {
      found=0;
      x=min[1].x;
      y=min[1].y;
      w=min[1].weight;
      delete();
      
      x=same(arr,x);
      found=0;
      y=same(arr,y);
      found=0;
      if(x!=y)
	{
	  sum=sum+w;
	  x=onion(arr,x);
	  found=0;
	  y=onion(arr,y);
	  if(arr[y].rank > arr[x].rank)
	    {
	      arr[x].parent=y;
	      if(arr[y].rank < arr[x].rank+1)
		arr[y].rank=arr[x].rank + 1;
	    }
	  else
	    {
	      arr[y].parent=x;
	      if(arr[x].rank < arr[y].rank+1)
		arr[x].rank=arr[y].rank + 1;
	    }
	}
      q--;
    }
  found=0;
  x=same(arr,1);
  for(i=2;i<=n;i++)
    {
      found=0;
      same(arr,i);
      if(arr[i].parent!=x)
	sum=-1;
    }
  printf("%lld\n",sum);
      
  return 0;
}
