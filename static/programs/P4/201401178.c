#include<stdio.h>
#include<string.h>
typedef long long int in;
void merge(in left[],in right[],in c[],in m,in u)
{
	in i=0,j=0,k=0;
	while(i<m && j<u)
	{
		if(left[i]<right[j])
		{
			c[k++]=left[i++];
		}
		else if(left[i]>right[j])
		{
			c[k++]=right[j++];
		}
		else
		{
			c[k++]=left[i++];
			c[k++]=right[j++];
		}
	}
	while(i<m)
	{
		c[k++]=left[i++];
	}
	while(j<u)
	{
		c[k++]=right[j++];
	}
}
void merge_sort(in a[],in n)
{

	in i;
	in left[n],right[n];
	if(n<=1)
	{
		return;
	}
	for(i=0;i<n/2;i++)
	{
		left[i]=a[i];
	}
	for(i=n/2;i<n;i++)
	{
		right[i-n/2]=a[i];
	}
	merge_sort(left,n/2);
	merge_sort(right,n-n/2);
	merge(left,right,a,n/2,n-n/2);
}

int main(){
	in test,i;
	scanf("%lld",&test);
	for(i=0;i<test;i++){
		char arr[100000],n,z;
		scanf("%s",arr);
		n=strlen(arr);
		in add[100000]={0};
		for(z=0;z<n;z++){
			if(z==0){
				if(arr[z]=='J')
					add[z]=-20002;
				if(arr[z]=='M')
					add[z]=10003;
				if(arr[z]=='R')
					add[z]=9999;
			}
			else{
				if(arr[z]=='J')
					add[z]=add[z-1]-20002;
				if(arr[z]=='M')
					add[z]=add[z-1]+10003;
				if(arr[z]=='R')
					add[z]=add[z-1]+9999;
			}
		}
		merge_sort(add,n);
		in zero=0,count=1,ans=0;
		for(z=0;z<n;z++){
			if(add[z]==0)
				zero++;
			if(z!=0){
				if(add[z]==add[z-1])
					count++;
				if(add[z]!=add[z-1]||z==n-1){
					ans=ans+(((count)*(count-1))/2);
					count=1;
				}
			}
		}
		ans=ans+zero;
		printf("%lld\n",ans);
	}
	return 0;
}
