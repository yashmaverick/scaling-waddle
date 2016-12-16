#include<stdio.h>
void mergeSort(long long int arr[],long long int low,long long int mid,long long int high);
void partition(long long int arr[],long long int low,long long int high);

void partition(long long int arr[],long long int low,long long int high){

	long long int mid;

	if(low<high){
		mid=(low+high)/2;
		partition(arr,low,mid);
		partition(arr,mid+1,high);
		mergeSort(arr,low,mid,high);
	}
}

void mergeSort(long long int arr[],long long int low,long long int mid,long long int high){

	long long int i,m,k,l,temp[10000001];

	l=low;
	i=low;
	m=mid+1;

	while((l<=mid)&&(m<=high)){

		if(arr[l]<=arr[m]){
			temp[i]=arr[l];
			l++;
		}
		else{
			temp[i]=arr[m];
			m++;
		}
		i++;
	}

	if(l>mid){
		for(k=m;k<=high;k++){
			temp[i]=arr[k];
			i++;
		}
	}
	else{
		for(k=l;k<=mid;k++){
			temp[i]=arr[k];
			i++;
		}
	}

	for(k=low;k<=high;k++){
		arr[k]=temp[k];
	}
}
int main()
{
	long long int t;
	scanf("%lld",&t);
	while(t--)
	{
		long long int a[10000001],n,c,s,i,j;
		scanf("%lld",&n);
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
		}
		partition(a,0,n-1);
		s=0;
		for(j=0;j<n;j++)
		{
			c=1;
			while(a[j]==a[j+1])
			{
				c++;
				j++;
			}
			s=s+((c*(c-1))/2);
		}
		printf("%lld\n",s);

	}
	return 0;
}
