#include<stdio.h>

int main()
{
  int stack[500005];
  long long int n,val,count,top,a,total,stand,flag;
  scanf("%lld",&n);
  while(n!=0)
    {
      scanf("%lld",&val);
      stack[0]=val;
      total=count=top=0;
      
      for(a=1;a<n;a++)
	{
	  scanf("%lld",&val);
	  flag=0;
	  
	  while(top>=0 && val>=stack[top])
	    {
	      if(val==stack[top] && flag==0)
		{
		  stand=top;
		  flag=1;
		}
	      top--;
	      count++;
	    }
	  if(top!=-1)
	    count++;
	  if(flag==1)
	    top=stand;
	          
	  top++;
	  stack[top]=val;
	}
      //printf("%d\n",total);
      //printf("%d\n",count);
      total=(n*(n-1))/2;
      total=total-count;
      printf("%lld\n",total);
      scanf("%lld",&n);
    }  

  return 0;
}
