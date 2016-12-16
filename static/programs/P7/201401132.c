#include<stdio.h>
#define MAX 1000005
int main(){
	long long int b[MAX],i,n,min,t,r;
	scanf("%d",&t);
	while(t--){
		for(i=0;i<MAX;i++)
		{
			b[i]=0;
		}
		scanf("%lld",&n);
		long long int a[n];
		min=10000001;
		for(i=0;i<n;i++){
			scanf("%lld",&a[i]);
			if(a[i]< min){
				min=a[i];
			}
		}
		for(i=0;i<n;i++){
			a[i]-=min;
			b[a[i]]+=1;
		}
		r=0;
		for(i=0;i<MAX;i++){
			if(b[i]>1){
				r+=(b[i]*(b[i]-1))/2;
			}
		}
		printf("%lld\n",r);
	}
	return 0;
}

