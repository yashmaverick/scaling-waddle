#include<stdio.h>
#define MAX 1000005
void mergeSort(int arr[],int low,int mid,int high);
void partition(int arr[],int low,int high);
void partition(int arr[],int low,int high){

    int mid;
    if(low<high){
	mid=(low+high)/2;
	partition(arr,low,mid);
	partition(arr,mid+1,high);
	mergeSort(arr,low,mid,high);
    }
}

void mergeSort(int arr[],int low,int mid,int high){

    int i,m,k,l,temp[MAX];

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
int A[1000005];
int main()
{
    int t,i,n;
    scanf("%d",&t);
    while(t--)
    {
	long long int ans=0,count=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
	    scanf("%d",&A[i]);
	}
	partition(A,0,n-1);
	for(i=0;i<(n);i++)
	{
	    if(A[i]==A[i+1])
	    {
		count++;
	    }
	    else
	    {
		ans=ans+((count+1)*(count))/2;
		count=0;
	    }
	}
	printf("%lld\n",ans);
    }
    return 0;
}




