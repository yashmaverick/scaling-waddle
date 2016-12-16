#include<stdio.h>
#include<math.h>

int main()
{
  int i,t,k,b,c,d,count;
  float mid;
  scanf("%d",&t);
  for(i=0;i<t;i++)
    {
      scanf("%d",&k);
      if(k==1)
	{
	  printf("0\n");
	  continue;
	}
      d=1;
      count=0;
      while(d <= k)
	{
	  d=d*2;
	  count++;
	}
      mid=(float)((d-1)+(d/2))/2;
      // printf("d is:%d,count is:%d,mid is:%f\n",d,count,mid);
      if(k > mid)
	{
	  printf("%d\n",2*count-1-1);
	}
      else
	{
	  printf("%d\n",2*(count-1)-1);
	}
    }
  return 0;
}
