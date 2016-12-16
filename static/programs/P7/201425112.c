//Duplicates

#include <stdio.h>
#define size 1000005

long long int temp[size];

void partition(long long int array[], long long int start, long long int end);
void mergesort(long long int array[], long long int start, long long int mid, long long int end);

int main()
{
	int t;
	scanf("%d", &t);
	
	while(t!=0)
	{
		long long int n;
		scanf("%lld", &n);
		
		long long int arr[size];
		
		long long int i;
		for(i=0; i<n; i++)
		{
			scanf("%lld", &arr[i]);
		}
		
		partition(arr, 0, n-1);
		
		/*/debug
		for(i=0; i<n; i++)
		{
			printf("%lld ", temp[i]);
		}
		printf("\n");
		/*/
		
		//printf("%lld end\n", n);
		
		long long int pairs;
		pairs=0;
		
		for(i=0; i<n-1; i++)
		{
			//printf("loop1");
			
			long long int counter=0;
			
			while(arr[i]==arr[i+1])
			{
				counter++;
				i++;
			}
			counter++;
			
			//find counterC2
			pairs=pairs+(counter*(counter-1))/2;
		}
		
		printf("%lld\n", pairs);
		
		t--;
	}
	
	return 0;
}

void partition(long long int array[], long long int start, long long int end)
{
	if(start<end)
	{
		long long int mid;
		mid = (start+end)/2;
		
		partition(array, start, mid);
		partition(array, mid+1, end);
		
		mergesort(array, start, mid, end);
	}
}

void mergesort(long long int array[], long long int start, long long int mid, long long int end)
{
	//long long int temp[size];
	
	long long int low=start;
	long long int tempi=0;
	long long int high=mid+1;
	
	while(low<=mid && high<=end)
	{
		if(array[low]<=array[high])
		{
			temp[tempi]=array[low];
			low++;
			tempi++;
		}
		else
		{
			temp[tempi]=array[high];
			high++;
			tempi++;
		}
	}/*
	if(low>mid)
	{*/
		while(high<=end)
		{
			temp[tempi]=array[high];
			high++;
			tempi++;
		}
	/*}
	if(high>end)
	{*/
		while(low<=mid)
		{
			temp[tempi]=array[low];
			low++;
			tempi++;
		}
	//}
	
	long long int i,k=0;
	for(i=start; i<=end; i++)
	{
		array[i]=temp[k];
		k++;
	}
}
