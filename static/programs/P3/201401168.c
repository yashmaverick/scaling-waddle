#include<stdio.h>
int main()
{
  int te,n,i,a[1000000];
  scanf("%d",&te);
  while(te>0)
    {
      int md=0,s=0,t=0;
      scanf("%d",&n);
      for(i=0;i<n;i++)
	scanf("%d",&a[i]);
      for(i=0;i<(n-1);i++)
	{
	  t=a[i]-a[i+1];
	  s=s+t;
	  if(s>0)
	    s=0;
	  if(s<md)
	    md=s;
	}
      printf("%d\n",-md);
      te--;
    }
}
	  
      
