#include <stdio.h>
#include <stdlib.h>

int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

void possible(int arr[],int n,int k)
{
	int low,high,to=0,i;
	for(i=0;i<n-2;i++)
	{
		low=i+1;
		high=n-1;
		while(low<high)
		{
			if(arr[i]+arr[low]+arr[high]==k)
			{
				printf("YES\n");
				to=1;
				break;
			}
			else if(arr[i]+arr[low]+arr[high]>k)
			high--;
			else
			low++;
		}
		if(to==1)
		break;
	}
	if(to==0)
	printf("NO\n");
}
			

int main()
{
	int test,i,j,k,n;
	char c;
	scanf("%d",&test);
	for(i=0;i<test;i++)
	{
		scanf("%d %d",&n,&k);
		int *arr=(int*)malloc(n*sizeof(int));
		for(j=0;j<n;j++)
		{
			c=getchar();
			while(c!=' ')
				c=getchar();
			scanf("%d",&arr[j]);
		}
		qsort(arr,n,sizeof(int),cmpfunc);
		possible(arr,n,k);
		free(arr);
	}
	return 0;
}
			
			
