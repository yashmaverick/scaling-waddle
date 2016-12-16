#include<stdio.h>
#define size 1000000
long long int temp[size];
long long int a[size];
void sort(long long int,long long int);
void merge(long long int,long long int,long long int,long long int);
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		long long int n,i;
		scanf("%lld",&n);
		for(i=0;i<n;i++)
			scanf("%lld",&a[i]);
		sort(0,n-1);
		long long int sum=0;
		long long int d,temp;
		d=1;
		for(i=1;i<n;i++){
			if(a[i]==a[i-1]){
				d++;
			}
			else{
				temp=d*(d-1);
				temp/=2;
				sum+=temp;
				d=1;
			}
		}
		temp=d*(d-1);
		temp/=2;
		sum+=temp;
		printf("%lld\n",sum);
	}
	return 0;
}
void sort(long long int low,long long int high){
	int mid=(low+high)/2;
	if(low>=high)
		return;
	sort(low,mid);
	sort(mid+1,high);
	merge(low,mid,mid+1,high);
}
void merge(long long int l1,long long int h1,long long int l2,long long int h2){

	int k=0;
	int i=l1,j=l2;
	while(i<=h1 && j<=h2){
		if(a[i]>a[j])
			temp[k++]=a[j++];
		else
			temp[k++]=a[i++];
	}
	while(i<=h1)
		temp[k++]=a[i++];
	while(j<=h2)
		temp[k++]=a[j++];
	k=0;
	for(i=l1;i<=h2;i++)
		a[i]=temp[k++];
}
