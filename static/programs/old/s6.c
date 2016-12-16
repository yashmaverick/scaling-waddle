#include<stdio.h>
long long int *sort(long long int *arr, long long int n)
{
	long long int i, j;
	for(i=0;i<n;i++){
		for(j=0;j<n-i-1;j++){
			if(arr[j]>arr[j+1]){
				int temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
	return arr;
}

int main()
{
	long long int n, k, min=10000000005, i;
	scanf("%lld", &n);
	long long int arr[n];
	for(i=0;i<n;i++){
		scanf("%lld", &arr[i]);
		if(arr[i]<min)
			min=arr[i];
	}
	scanf("%lld", &k);
	sort(arr, n);
	int flag=0, count=0;
	while(k!=0)
	{
		for(i=0;i<n && arr[i]==min;i++){
			if(k==0){
				flag=1;
				break;
			}
			arr[i]++;
			k--;
			count++;
//			printf("%lld", k);
		}
		if(k==0 && flag==1)
			break;
		min++;
	}
//	printf("%d ",count);
	printf("%lld\n", min);
	return 0;
}
