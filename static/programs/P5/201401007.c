#include<stdio.h>
#define MAX 1000000
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
int main()
{
    int t;
    scanf("%d",&t);
    int A[1005];
    char f[100000];
    while(t--)
    {
	int n,i,flag=0,j,l,k;
	scanf("%d %d",&n,&k);
	for(i=0;i<n;i++)
	{
	    scanf("%s",f);
	    scanf("%d",&A[i]);
	}
	partition(A,0,n-1);
	for(i=0;i<=n-3;i++)
	{
	    j=i+1;
	    l=n-1;
	    while(j<l)
	    {
		if(A[i]+A[j]+A[l]>k)
		{
		    l--;
		}
		else if(A[i]+A[j]+A[l]==k)
		{
		    flag=1;
		    printf("YES\n");
		    break;
		}
		else
		{
		    j++;
		}
	    }
	    if(flag==1)
	    {
		break;
	    }
	}
	if(flag==0)
	{
	    printf("NO\n");
	}
    }
    return 0;
}



