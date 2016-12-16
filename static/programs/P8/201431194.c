#include<stdio.h>
long long int powr(long long int x,long long int p,long long int n){
	long long int yes;
	if(p==0)
		return 1;
	yes=(powr(x,p/2,n))%n;
	if(p%2==0)
		return (yes*yes)%n;
	else
		return (yes*yes*x)%n;
}	
int main(){
	long long int x,i,j,k,l,n,m,t,d,u,b[100],r,f,v,ourans;
	scanf("%lld",&t);
	while(t--){
		for(i=0;i<100;i++)
			b[i]=0;
		ourans=0;
		scanf("%lld%lld%lld%lld",&u,&d,&m,&n);
		x=m%n;
		for(i=0;i<n;i++){
			b[i]=powr(i,d,n);
//			printf("%lld ",b[i]);
		}
//		printf("\n");
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				for(k=0;k<n;k++){
//				printf("%lld %lld %lld %lld %lld %lld %lld\n",i,j,k,b[i],b[j],b[k],x);
					if(((b[i]+b[j]+b[k])%n==x) && (i<=u) && (j<=u) && (k<=u)){
					//	if(b[i]<=u%n)
							r=(((u-i)/n)+1)%1000000007;
					//	else
							//r=(u/n)%1000000007;
					//	if(b[j]<=u%n)
							f=(((u-j)/n)+1)%1000000007;
					//	else
					//		f=(u/n)%1000000007;
					//	if(b[k]<=u%n)
							v=(((u-k)/n)+1)%1000000007;
					//	else
					//		v=(u/n)%1000000007;
						ourans=(ourans+((r*f)%1000000007*v))%1000000007;
//				printf("%lld %lld %lld %lld %lld %lld %lld %lld\n",b[i],b[j],b[k],r,f,v,u,n);
					}
				}
			}
		}
		printf("%lld\n",(ourans)%1000000007);
	}
	return 0;
}
