#include<stdio.h>
typedef long long int ll;



int main()
{
  
  ll arr[1000005],arr2[1000005];
  ll a,b,c,min,score;
  int n,t;
  
  scanf("%d",&t);
  while(t>0)
    {
      scanf("%d",&n);
      min=99999999;
      for(a=0;a<n;a++)
	{
	  scanf("%lld",&arr[a]);
	  min=arr[a]>min?min:arr[a];
	}
      
      
      for(a=0;a<n;a++)
	{
	  b=arr[a]-min;
	  arr2[b]++;
	}
      score=0;
      for(a=0;a<1000001;a++)
	{
	  if(arr2[a]>1)
	    score+=(arr2[a]*(arr2[a]-1))/2;
	  arr2[a]=0;
	}
      printf("%lld\n",score);
      t--;
    }
  
  
  return 0;
}
