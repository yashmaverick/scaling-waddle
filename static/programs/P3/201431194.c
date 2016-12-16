#include<stdio.h>
int main(){
	long long int max,max1,t,i,j,k,l,n,m,a[100000];
	scanf("%lld",&t);
	while(t--){
		max=0;
		max1=0;
		scanf("%lld",&n);
		for(i=0;i<n;i++)
			scanf("%lld",&a[i]);
		max=a[n-1];
		for(i=n-2;i>=0;i--){
			if(a[i]<=max){
				if(max-a[i]>max1){
					max1=max-a[i];
				}
			}
			else{
				max=a[i];
			}
		}
		printf("%lld\n",max1);
	}
	return 0;
}
