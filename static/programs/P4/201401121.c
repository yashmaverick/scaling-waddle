#include<stdio.h>
#include<string.h>
int c[100];
void mergeSort(long long int arr[],int low,int mid,int high);
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

	int i,m,k,l,temp[100005];

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
/*int partition(int start,int end,long long int a[])
{
	int i=start;
	int wall=start;
	long long int temp;
	for(;i<end;i++)
	{
		if(a[i]<=a[end])
		{
			temp=a[i];
			a[i]=a[wall];
			a[wall]=temp;
			wall++;
		}
	}
	temp=a[wall];
	a[wall]=a[end];
	a[end]=temp;
	return wall;
}*/
/*void quicksort(int start,int end,long long int a[])
{
	if(start<end)
	{
		int pivot=partition(start,end,a);
		quicksort(start,pivot-1,a);
		quicksort(pivot+1,end,a);
	}
}*/
int main()
{
	int t;
	scanf("%d",&t);
	char str[100005];
	long long int arr[100005];
	while(t--)
	{
		scanf("%s",str);
		int i=0;
		for(;str[i]!='\0';i++)
		{
			if(str[i]=='J')
				arr[i]=1-1000000;
			else if(str[i]=='M')
				arr[i]=1000001;
			else
				arr[i]=-2;
		}
		int n=strlen(str);
		//	quicksort(0,n-1,arr);
		//	for(i=0;str[i]!='\0';i++)
		//		printf("%lld\n",arr[i]);
		for(i=1;str[i]!='\0';i++)
			arr[i]+=arr[i-1];
		partition(arr,0,n-1);

		//	for(i=0;str[i]!='\0';i++)
		//	printf("%lld\n",arr[i]);
		long long int s=0,cnt,temp=arr[0];
		if(temp==0)
			cnt=2;
		else cnt=1;
		for(i=1;str[i]!='\0';i++)
		{
			if(temp==arr[i])
			{
				cnt++;
			}
			else
			{
				s+=(cnt*(cnt-1))/2;
				if(arr[i]==0)
					cnt=2;
				else
					cnt=1;
				temp=arr[i];
			}
		}
		s+=(cnt*(cnt-1))/2;
		printf("%lld\n",s);
	}
	return 0;
}






