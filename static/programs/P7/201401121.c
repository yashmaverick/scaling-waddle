#include<stdio.h>
long long int k,a[1000005];
void mergeSort(long long int arr[],int low,int mid,int high);
void partition(long long int arr[],int low,long long int high)
{

	int mid;

	if(low<high){
		mid=(low+high)/2;
		partition(arr,low,mid);
		partition(arr,mid+1,high);
		mergeSort(arr,low,mid,high);
	}
}
void mergeSort(long long int arr[],int low,int mid,int high){

	int i,m,k,l,temp[1000005];

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
		long long int n;
		scanf("%lld",&n);
		long long int i;
		for( i=0;i<n;i++)
		{

			scanf("%lld",&a[i]);
		}
		partition(a,0,n-1);
		long long cnt=1,temp=a[0],s=0;
		i=1;
		while(i<n)
		{
			if(temp==a[i])

				cnt++;
			else
			{
				s+=(cnt*(cnt-1))/2;
				cnt=1;
				temp=a[i];
				//	i++;
			}
			i++;

		}
		s+=(cnt*(cnt-1))/2;
		printf("%lld\n",s);
	}





	return 0;
}











