#include<stdio.h>
#include<stdlib.h>
#define INF 1000000007 
typedef long long int ll;
void print(int *a,int n)
{
  int i;
  for(i=1;i<=n ;i++)
    printf("%d ",a[i]);
  printf("\n");
}
void swap(ll i,ll *heap)
{
  int temp;
  temp=heap[i];
  heap[i]=heap[i>>1];
  heap[i>>1]=temp;
}
void update(ll i,ll *heap)
{
  int t;
  while(i>1 && heap[i]<heap[i>>1])
  {
    swap(i,heap);
    i=i>>1;
  }
}
void shuldn(ll n,ll *heap)
{
  int i=2,t;
  while(i<n)
  {
    if(i+1<=n && heap[i+1]<heap[i])
      i=i+1;
    if(heap[i]<heap[i>>1])
    {
      swap(i,heap);
    }
    else
     break;
    i=i<<1;
  }
}
int main()
{
  ll t,n,a,i,b,c,hpmin[100005],hpmax[100005],median;
  ll val,sum;
  scanf("%lld",&t);
  while(t--)
  {
    scanf("%lld %lld %lld %lld",&a,&b,&c,&n);
    for(i=0;i<(n>>1)+2;i++)
    {
      hpmin[i]=INF;
      hpmax[i]=INF;
    }
    sum=1;
    median=1;
    hpmax[1]=-1;
    int h1sz=2,h2sz=1;
    for(i=2;i<=n;i++)
    {
      val=(((ll)(a*median)%INF)+((ll)(b*i)%INF)+c)%INF;
      sum+=val;
 //     printf("val:%lld\n",val);
      if(i%2==0)
      {
        if(val<median)
        {
          hpmax[1]=hpmax[h1sz-1];
          shuldn(h1sz,hpmax);
          h1sz--;
          hpmax[h1sz]=-val;
          update(h1sz,hpmax);
          h1sz++;
          hpmin[h2sz]=median;
          update(h2sz,hpmin);
          h2sz++;
        }
        else
        {
          hpmin[h2sz]=val;
          update(h2sz++,hpmin);
        }
      }
      else
      {
        if(val>median) 
        {
          hpmin[h2sz]=val;
          update(h2sz,hpmin);
          h2sz++;
//          print(hpmin,h2sz);
          hpmax[h1sz]=-hpmin[1];
          update(h1sz,hpmax);
          h1sz++;
          hpmin[1]=hpmin[h2sz-1];
          shuldn(h2sz,hpmin);
          h2sz--;
        } 
        else
        {
          hpmax[h1sz]=-val;
          update(h1sz++,hpmax);
        }
      }
//      print(hpmin,h2sz);
 //     print(hpmax,h1sz);
      median=-hpmax[1];
   //   printf("medain:%d\n",median);

    }
    printf("%lld\n",sum);
  }
  return 0;
}
