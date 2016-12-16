#include <stdio.h>
#include <stdlib.h>

int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

int main ()
{
  int i,n,t,j,k;
  int arr[1000000];
  long long count,sum;
  scanf("%d",&t);
  for(i=0;i<t;i++)
  {
	scanf("%d",&n);
	//a=(int*)malloc(n*sizeof(int));
	for(j=0;j<n;j++)
	   scanf("%d",&arr[j]);
  	qsort (arr, n, sizeof(int), compare);
  	//for(j=0;j<n;j++)
	//   printf("%d ",arr[j]);
	//printf("\n");
	count=1;
	sum=0;
	for(j=0;j<n-1;j++)
	{
		if(arr[j]==arr[j+1])
			count++;
		else
		{
			sum+=((count)*(count-1))/2;
			count=1;
		}
	}
	sum+=((count)*(count-1))/2;
	printf("%lld\n",sum);
	//free(a);
  }	
  return 0;
}
