#include<stdio.h>
long long int b[10000001];
long long int temp[10000001];
void merge(long long int arr[],long long int low,long long int mid,long long int high);
void split(long long int arr[],long long int low,long long int high);
int main()
{
	int t,i;
	long long int k;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		long long int n;
		long long int count=1;
		long long int sum=0;
		int flag=0;
		scanf("%lld",&n);
		for(k=0;k<n;k++)
			scanf("%lld",&b[k]);
		split(b,0,n-1);
		for(k=0;k<n-1;k++)
		{
			if(b[k]==b[k+1])
			{
				count++;
				flag=1;
			}
			else if(b[k]!=b[k+1] && flag==1)
			{
				sum=sum+(count*(count-1))/2;
				flag=0;
				count=1;
			}
			if(k==n-2 && b[k]==b[k+1])
				sum=sum+(count*(count-1))/2;
		}
		printf("%lld\n",sum);
	}
	return 0;
}
void split(long long int arr[],long long int low,long long int high){

	long long int mid;

	if(low<high){
		mid=(low+high)/2;
		split(arr,low,mid);
		split(arr,mid+1,high);
		merge(arr,low,mid,high);
	}
}
void merge(long long int arr[],long long int low,long long int mid,long long int high){

	long long int i,m,k,l;
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
