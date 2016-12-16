#include<stdio.h>
int main(){
	long long int sum,i,j,k,min=100000000,l,a[1000002],b[1000002],t,n,m;
	scanf("%lld",&t);
	while(t--){
		min=100000000;
		for(i=0;i<1000002;i++)
			b[i]=0;
		sum=0;
		scanf("%lld",&n);
		for(i=0;i<n;i++){
			scanf("%lld",&a[i]);
			if(a[i]<min)
				min=a[i];
		}
		if(min<0){
			for(i=0;i<n;i++)
				a[i]=a[i]+(0-min);
		}
		for(i=0;i<n;i++)
			(b[a[i]%1000001])++;
		for(i=0;i<1000001;i++)
			sum=sum+((b[i])*((b[i])-1))/2;
		printf("%lld\n",sum);
	}
	return 0;
}
