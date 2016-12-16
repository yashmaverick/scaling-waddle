#include<stdio.h>
long long int area[1000000],h[1000000],n,i,temp,temp1;
void function(long long int num)
{
  long long int k,flag=0;
  long long int x,val,j;
  val=num;
  if(num!=0)
  {
    if(h[num]==h[num-1])
    {
      area[num]=area[num-1];
      flag=1;
    }
  }
  if(flag==0)
  {
    if(num!=0&&(h[num]<h[num-1]))
    {
      for(j=temp;j>=0;j--)
      {
        if(h[j]<h[val])
        {
          break;
        }
      }
      temp=j;
    }
    else
    {
      for(j=val-1;j>=0;j--)
      {
        if(h[j]<h[val])
        {
          break;
        }
      }
      temp=j;
    }
    for(k=val+1;k<n;k++)
    {
      if(h[k]<h[val])
      {
        break;
      }
    }
    temp1=k;
  }
  x=temp1-temp-1;
  area[i]=x*h[i];
  return ;
}
int main()
{
  while(1)
  {
    long long int max=-99999;
    scanf("%lld",&n);
    if(n==0)
      break;
    else
    {
      for(i=0;i<n;i++)
        scanf("%lld",&h[i]);
      for(i=0;i<n;i++)
        function(i);
      for(i=0;i<n;i++)
      {
        if(area[i]>max)
          max=area[i];
      }
      printf("%lld\n",max);
    }
  }
  return 0;
}
