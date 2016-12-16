#include<stdio.h>
void mergeSort(int arr[],int low,int mid,int high){

	int i,m,k,l,temp[100000];

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
void partition(int arr[],int low,int high){
	int mid;
	if(low<high){
		mid=(low+high)/2;
		partition(arr,low,mid);
		partition(arr,mid+1,high);
		mergeSort(arr,low,mid,high);
	}
}
int main()
{
	int test,n,i,maxpro,j;
	scanf("%d",&test);
	while(test--)
	{
		int spot=0,k;
		maxpro = 0;
		scanf("%d%d",&n,&k);
		int a[n];
		char str[1000];
		for(i=0;i<n;i++)
		{
			scanf("%s%d",str,&a[i]);
		}
		partition(a,0,n-1);	
		for(i=0;i<n-1;i++)
		{
			int min=i+1,max=n-1;
			while(min<max)
			{
				if(a[i]+a[max]+a[min]>k)
					max--;
				else if(a[i]+a[max]+a[min]<k)
					min++;
				else if(a[i]+a[min]+a[max]==k)
				{
					spot=1;
					printf("YES\n");
					break;
				}	
			}if(spot==1)
			break;		
		}
		if(spot==0)
			printf("NO\n");
	}
	return 0;
}
