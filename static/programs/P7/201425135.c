#include<stdio.h>
#include<stdlib.h>
void mergeSort(long long int arr[],long long int low,long long int mid,long long int high);
void partition(long long int arr[],long long int low,long long int high);

int main(){
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long int i,n;
		long long int merge[1000000+2];
		//long long int *merge;
		//merge=malloc(sizeof(long long int)*(10^6+1));
		scanf("%lld",&n);

		for(i=0;i<n;i++){
			scanf("%lld",&merge[i]);
		}

		partition(merge,0,n-1);
		long long int sum=0,k=1;
		int flag;
		for(i=1;i<n;i++)
		{
			if(merge[i]==merge[i-1])
			{
				k++;

			}
			else if(merge[i]!=merge[i-1])
			{
				flag=1;
				sum=sum+k*(k-1)/2;
			}
			if(flag==1)
			{
				k=1;
				flag=0;
			}

		}
		sum=sum+k*(k-1)/2;
		/*k=1;
		flag=0;
		for(i=n-1;i>=0;i--)
		{
		if(merge[i]==merge[i-1])
			{
				k++;

			}
			else if(merge[i]!=merge[i-1])
			{
				flag=1;
				sum=sum+k*(k-1)/2;
				break;
			}
			if(flag==1)
			{
				k=1;
				flag=0;			}

		}
*/
		
		printf("%lld\n",sum);

	}
	return 0;
}

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

	long long int i,m,k,l;
	//long long int *temp;
	//temp=malloc(sizeof(long long int)*(10^6+1));
	long long int temp[1000002];
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


