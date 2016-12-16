#include<stdio.h>
int main()
{
	int test;
	scanf("%d",&test);
	while(test--)
	{
	  int a,i,j;
	  scanf("%d",&a);
	  int arr[a+1];
	  int max=0,min=0,diff=0,pdiff=0;
	  scanf("%d",&arr[0]);
	  min=arr[0];
	  max=arr[0];
	  for(i=1;i<a;i++)
	  {
	    scanf("%d",&arr[i]);
	    if(arr[i]>min)
	    {
	     max=arr[i];
	     pdiff=max-min;
	     if(pdiff>diff)
	     diff=pdiff;
	    }
	    else
	    {
	     min=arr[i];
	    }
	  }
	  printf("%d\n",diff);
	}
return 0;
}
