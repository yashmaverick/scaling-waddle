#include<stdio.h>
int main(){
	long long int x,sum,i,j,k,l,n,m,a[100000],b[50];
	b[0]=1;
	m=2;
	for(i=1;i<50;i++)
		b[i]=b[i-1]*2;
	scanf("%lld",&n);
	for(i=0;i<n;i++){
		scanf("%lld",&a[i]);
		j=0;
		sum=0;
		while(sum<a[i]){
			sum=sum+b[j];
			j++;
		}
//		printf("*%lld %lld %lld",sum,a[i],j);
		if(sum==a[i])
			printf("%lld\n",2*(j-1));
		else{
			j--;
			x = a[i]-sum+b[j];
//			printf(" %lld %lld\n",x,j);
			if(x <= b[j]/2)
				printf("%lld\n",2*j-1);
			else
				printf("%lld\n",2*j);
		}
	}
	return 0;
}
