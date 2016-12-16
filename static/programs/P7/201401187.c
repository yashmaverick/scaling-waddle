#include<stdio.h>
#define MAX 1000010
long long int merge[1000010],temp[1000010];
void mergeSort(long long int arr[],int low,int mid,int high);
void partition(long long int arr[],int low,int high);
int main()
{
	 int n,t;
	 long long int c,i,j;
	scanf("%d",&t);
	while(t--)
	{
		c=0;
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%lld",&merge[i]);
		partition(merge,0,n-1);
		for(i=0;i<n;i++)
		{
			j=i;
			while(merge[j]==merge[j+1]&&j!=n-1)
				j++;
			c=c+(j-i)*(j-i+1)/2;
			i=j;
		}
		printf("%lld\n",c);
	}

	return 0;
}
void partition(long long int arr[],int low,int high){

	int mid;
	if(low<high){
		mid=(low+high)/2;
		partition(arr,low,mid);
		partition(arr,mid+1,high);
		mergeSort(arr,low,mid,high);
	}
}

void mergeSort(long long int arr[],int low,int mid,int high){

	int i,m,k,l;
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
