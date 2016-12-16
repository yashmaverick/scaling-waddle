#include<stdio.h>
int main(){
	long long int max1,a[100000],max,min,i,j,k,l,t,n;
	scanf("%lld",&t);
	while(t--){
		max=0;
		max1=0;
		scanf("%lld",&n);
		for(i=0;i<n;i++)
			scanf("%lld",&a[i]);
		max=a[n-1];
		max1=0;
		for(i=n-2;i>=0;i--){
			if(a[i]<=max){
				if(max-a[i]>max1)
					max1=max-a[i];		
			}
			else{
				max=a[i];
			}
		}
		printf("%lld\n",max1);
	}
	return 0;
}