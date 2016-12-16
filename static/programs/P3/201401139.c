#include<stdio.h>



int main()
{
  int arr[100001],a,b,flag;
  int n,t,max,maxpos,min,minpos,profit;
  scanf("%d",&t);
  while(t>0)
    {
      scanf("%d",&n);
  
      for(a=0;a<n;a++)
	scanf("%d",&arr[a]);

   
      min=arr[0];minpos=0;
      profit=0;flag=0;

      for(a=1;a<n;a++)
	{
	  
	  if(arr[a]<min)
	    {
	      min=arr[a];
	      minpos=a;
	      flag=0;
	    }
	  if((arr[a]-min)>profit)
	    {
	      profit=arr[a]-min;
	      flag=1;
	    }
	}
      printf("%d\n",profit);
      t--;
    }
  return 0;
}

