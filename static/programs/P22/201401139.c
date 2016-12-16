#include <stdio.h>
#include <stdlib.h>
#define sc(n) scanf("%lld",&n)

const long long int MOD=1000000007;

long long int minheap[200005];
long long int maxheap[200005];
long long int minheapsize=0,maxheapsize=0;

long long int swap(long long int arr[],long long int a,long long int b)
{
  long long int tempn=arr[a];
  arr[a]=arr[b];
  arr[b]=tempn;
}

void minshuffledown(long long int i)
{
  long long int minpos=-2;
  long long int li;
  long long int ri;

  while(minpos!=i)
    {
      li=i*2;
      ri=i*2+1;
      if(li<=minheapsize && minheap[li]<minheap[i])
	minpos=li;
      else
	minpos=i;
      
      if(ri<=minheapsize && minheap[ri]<minheap[minpos])
	minpos=ri;
      
      if(i==minpos)
	break;
      else
	{
	  swap(minheap,minpos,i);
	  i=minpos;
	  minpos=-2;
	}
    }
}

void minify(long long int i,long long int num)
{
  minheap[i]=num;
  while(i>1 && minheap[i]<minheap[i/2])
    {
      swap(minheap,i,i/2);
      i=i/2;
    }
}

void mininsert(long long int num)
{
  minheapsize++;
  minify(minheapsize,num);
}

long long int getmin()
{
  long long int min=minheap[1];
  swap(minheap,1,minheapsize);
  minheapsize--;
  minshuffledown(1);
  return min;
}

void maxshuffledown(long long int i)
{
  long long int maxpos=-2;
  long long int li;
  long long int ri;

  while(maxpos!=i)
    {
      li=i*2;
      ri=i*2+1;
      if(li<=maxheapsize && maxheap[li]>maxheap[i])
	maxpos=li;
      else
	maxpos=i;
      
      if(ri<=maxheapsize && maxheap[ri]>maxheap[maxpos])
	maxpos=ri;
      
      if(i==maxpos)
	break;
      else
	{
	  swap(maxheap,maxpos,i);
	  i=maxpos;
	  maxpos=-2;
	}
    }
}

void maxify(long long int i,long long int num)
{
  maxheap[i]=num;
  while(i>1 && maxheap[i]>maxheap[i/2])
    {
      swap(maxheap,i,i/2);
      i=i/2;
    }
}

void maxinsert(long long int num)
{
  maxheapsize++;
  maxify(maxheapsize,num);
}

long long int getmax()
{
  long long int max=maxheap[1];
  swap(maxheap,1,maxheapsize);
  maxheapsize--;
  maxshuffledown(1);
  return max;
}

long long int getmed()
{
  long long int temp;
  if(maxheapsize-minheapsize==2)
    {
      temp=getmax();
      mininsert(temp);
    }
  else if(maxheapsize-minheapsize==-2)
    {
      temp=getmin();
      maxinsert(temp);
    }

  if(maxheapsize-minheapsize==0 || maxheapsize-minheapsize==1)
    {
      return maxheap[1];
    }
  else if(maxheapsize-minheapsize==-1)
    {
      return minheap[1];
    }
}

int main()
{
  long long int a,b,c,i,j,sum;
  long long int n,t,fnum,median;
  sc(t);
  while(t)
    {
      scanf("%lld%lld%lld%lld",&a,&b,&c,&n);
      minheapsize=maxheapsize=0;
      maxinsert(1);
      sum=1;
      
  
      if(n>=2)
	{
	  median=1;
	  fnum=((a*(median%MOD))%MOD+(b*2)%MOD+c)%MOD;
	  
	  mininsert(fnum);
	  sum=sum+fnum;
	}
  
      for(i=3;i<=n;i++)
	{
	  median=getmed();
      
	  fnum=((a*(median%MOD))%MOD+(b*i)%MOD+c)%MOD;
	  
	  if(fnum<minheap[1])
	    maxinsert(fnum);
	  else
	    mininsert(fnum);
	  sum=sum+fnum;
	}
      printf("%lld\n",sum);
      t--;
    }
  return 0;
}
