#include<stdio.h>
#include<stdlib.h>
int Min(int array[], int start , int end)
{
	int l,min;
	min=array[start];
	for(l=start;l<=end;l++)
	{
	//	min = array[start];
		if(array[l] < min)
			min = array[l];			
	}
	return min;
}
int main()
{
	int t;
	int n,k,m,j,tp,i,min;
	int arr[10000];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		scanf("%d",&k);
		m = n-k;
		for(j=0;j<n;j++)
			scanf("%d",&arr[j]);
//		tp = Min(arr,0,n-1);
//		printf("tp= %d\n",tp);
		for(i=0;i<=m;i++)
		{
			//min = Min(arr,i,i+k-1);
			if(i == 0 || min == arr[i-1])
			{
				min = Min(arr,i,i+k-1);
			}
			else if(min >= arr[i+k-1])
			{
				min = arr[i+k-1];
			}	

			if(i<m)
				printf("%d ",min);
			else
				printf("%d\n",min);
		}
		//printf("%d\n",arr[m]);
	}
	return 0;
}
