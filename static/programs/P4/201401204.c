#include<stdio.h>
#include<string.h>
long long int a[100003],temp[100003];
void merge(long long int,long long int,long long int,long long int);
void sort(long long int low,long long int high){
	long long int mid=(low+high)/2;
	if(low>=high)
		return;
	sort(low,mid);
	sort(mid+1,high);
	merge(low,mid,mid+1,high);
}
void merge(long long int l1,long long int h1,long long int l2,long long int h2){

	long long int k=0;
	long long int i=l1,j=l2;
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
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		char s[100003];
		scanf("%s",s);
		long long int i,l=strlen(s);
		for(i=0;i<l;i++){
			if(s[i]=='J')
				a[i]=100001;
			else if(s[i]=='M')
				a[i]=1;
			else
				a[i]=-100002;
		}/*
		for(i=0;i<l;i++){
			printf("%lld ",a[i]);
		}

		printf("\n");*/
		for(i=1;i<=l-1;i++){
			a[i]=a[i]+a[i-1];
		}/*
		for(i=0;i<l;i++){
			printf("%lld ",a[i]);
		}
		printf("\n");*/
		sort(0,l-1); 				//Merge Sort
/*
		for(i=0;i<l;i++){
			printf("%lld ",a[i]);
		}
		printf("\n");*/
		long long int sum=0;
		long long int d,temp,zero=0;
		d=1;
		for(i=1;i<l;i++){
			if(a[i]==0)
				zero++;
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
		//printf("zero = %lld\n",zero);
		if(a[0]==0)
			zero++;
		temp=d*(d-1);
		temp/=2;
		sum+=temp;
		printf("%lld\n",sum+zero);
	}
	return 0;
}
