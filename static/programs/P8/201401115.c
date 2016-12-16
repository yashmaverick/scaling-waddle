#include<stdio.h>
long long int modulo(long long int a, long long int b, long long int m){
	long long int x;
	if(b==0)
		return 1;
	else{	
		if(b%2==0){
			x = modulo(a,b/2,m);
			return ((x%m)*(x%m))%m;
		}
		else{
			x = modulo(a,b/2,m);
			return ((((x%m)*(x%m))%m)*(a%m))%m;
		}
	}
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		long long int x,y,z,ul,d,m,n,i,j,k,count=0,temp;
		scanf("%lld%lld%lld%lld",&ul,&d,&m,&n);
		/*if(ul>n)
			temp=n;
		else
			temp=ul;*/
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				for(k=0;k<n;k++){
					if((modulo(i,d,n) + modulo(j,d,n) + modulo(k,d,n))%n==m){
						//printf("i,d,n %lld j,d,n %lld k,d,n %lld\n i,j,k %lld %lld %lld\n",modulo(i,d,n),modulo(j,d,n),modulo(k,d,n),i,j,k);
						if((ul-i)<0 || (ul-j)<0 || (ul-k)<0)
							count+=0;
						else{
							x = ((ul-i)/n + 1)%1000000007;
							y = ((ul-j)/n + 1)%1000000007;
							z = ((ul-k)/n + 1)%1000000007;
						    count = (count%1000000007 + ((((x*y)%1000000007)*z)%1000000007))%1000000007;
						    //count += (((((ul-i)/n + 1)%1000000007)*((ul-j)/n + 1)%1000000007)*(((ul-k)/n + 1)%1000000007))%1000000007;
						}
						//printf("%lld\n", count);
					}
				}
			}
		}
		printf("%lld\n",count);
	}
	return 0;
}