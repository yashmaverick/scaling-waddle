#include <stdio.h>
#define MAX 10100

int main()
{
  int i,j,n,mini,k,l,arr[MAX],test,min;
  scanf("%d",&test);
  for(i=0;i<test;i++)
    {
      scanf("%d %d",&n,&k);
      //printf("%d asdf\n",n);
      for(j=0;j<n;j++)
	scanf("%d",&arr[j]);
      //printf("%d ",arr[0]);
      for(j=0;j<=n-k;j++)
	{
	  min=arr[j];
	  //printf("this %d ",min);
	  mini=j;
	  for(l=j+1;l<j+k;l++)
	    {
	      // printf("dkfj %d %d\n",arr[l],min);
	      if(arr[l]<min)
		{
		  min=arr[l];
		  mini=l;
		}
	      //printf("this %d \n",min);
	    }
	  // printf("dkj %d\n",j+k);
	  if(j+k!=n)
	    printf("%d ",min);
	  else
	    printf("%d",min);
	  while(j<mini&&j+k<n)
	    {
	      j++;
if(j+k!=n)
  {
	      if(arr[j+k-1]<min)
		{
		  min=arr[j+k-1];
		  mini=j+k-1;
		}
	      printf("%d ",min);
  }
 else
   {
 if(arr[j+k-1]<min)
   	{
		  min=arr[j+k-1];
		  mini=j+k-1;
		  }
	      printf("%d",min);
   }

	    }
	}
      
      printf("\n");
    }
  return 0;
}
