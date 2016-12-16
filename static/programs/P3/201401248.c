#include<stdio.h>

int main()
{
  int i,t;
  scanf("%d",&t);
  for(i=0;i<t;i++)
    {
      int n,a[100000],j;
      scanf("%d",&n);
      for(j=0;j<n;j++)
	scanf("%d",&a[j]);
      int max,min,maxj=0,minj=0,k;
      max=min=0;
      int diff=0;
      for(j=0;j<n-1;j++)
	{
	  diff+=a[j]-a[j+1];
	  if(diff>=0)
	    {
	      diff=0;
	    }
	  else if(diff<min)
	    {
	      min=diff;
	    }
	}
      printf("%d\n",(-min));
      
    }
  return 0;
}
