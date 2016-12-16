#include<stdio.h>
long long int top;
int main()
{
  long long int n=5,sum,i;
  int item[500100],arr[500100];
  while(n!=0)
    {
      long long int t,f,x;
      top=-1;sum=0;
      scanf("%lld",&n);
      if(n>0)
	{
	  sum=sum+n-1;;
	  for(i=0;i<n;i++)
	    {
	      scanf("%d",&item[i]);
	      t=top;f=0;
	      if(item[i]==arr[t])
		{
		  if(t>=1)                                       
		    {
		      while(item[i]==arr[t]&&t>0)
			t--;
		      sum=sum+(top-t);
		    }
		}
	      else
		while(item[i]>=arr[top]&&top>=0)
		  {
		    if(item[i]==arr[top]&&f==0)
		      {f=1;x=top;}
		    if(top>=1)
		      {sum++;}
		      top--;
		  }
	      if(f==1)
		top=x;
	      arr[++top]=item[i];
	    }
	  sum=((n*(n-1))/2)-sum;
	  printf("%lld\n",sum);
	}
    }
  return 0;
}

