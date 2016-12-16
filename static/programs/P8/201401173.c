#include<stdio.h>
#include<string.h>
long long int count(long long int x,long long int k,long long int n){
	if(k<n){
		if(x<=k)
			return 1;
		else
			return 0;}
	else if(x<=k)
		return ((k-x)/n)+1;
	return 0;
}
long long int modpow(long long int a,long long int b,long long int mod)
{
	long long product,pseq;
	product=1;
	pseq=a%mod;
	while(b>0)
	{
		if(b&1)
			product=(product*pseq)%mod;
		pseq=(pseq*pseq)%mod;
		b>>=1;
	}
	return product;
}
/*long long int counta(long long int x,int up,long long int n,long long int k,long long int d){
  long long int i,c=0;
  for(i=0;i<=up;i++){
  if(modpow(i,d,n)==x){
  c+=count(i,k,n);
  }
  }
  return c;
  }*/
int main(){
	typedef long long int lli;
	lli k,d,m,n;
	lli M=1000000000 + 7;
	int t;
	lli val[41];
	scanf("%d",&t);
	while(t--){
		scanf("%lld %lld %lld %lld",&k,&d,&m,&n);
		lli up,i,j,l;
		lli ans=1;
		if(k<n)
			up=k;
		else
			up=n-1;
		for(i=0;i<=up;i++){
			val[i]=modpow(i,d,n);
		}
		lli x,sum=0;
		for(i=0;i<=up;i++){
			for(j=0;j<=up;j++){
				for(l=0;l<=up;l++){
					if((val[i]+val[j]+val[l])%n==m){
						//printf("%lld %lld %lld\n",i,j,l);
						//ans+=(((count(i,k,n)%M)*(count(j,k,n)%M)%M)*(count(l,k,n)%M))%M;
						//	ans+=(((((k-i)/n)+1)*(((k-j)/n)+1))%M)*(((k-l)/n)+1)%M;
						x=((k-i)/n)+1;
						  if(x<0)
						  x=0;
						  ans=x;
						  ans%=M;
						  x=((k-j)/n)+1;
						  if(x<0)
						  x=0;
						  ans*=x;
						  ans%=M;
						  x=((k-l)/n)+1;
						  if(x<0)
						  x=0;
						  ans*=x;
						  ans%=M;
						  //printf("%lld\n",ans);
						  sum+=ans;
						  sum%=M;
					}
				}
			}
		}
		/*if(m+n<=3*(n-1)){
		  for(i=0;i<n;i++){
		  for(j=0;j<n;j++){
		  for(l=0;l<n;l++){
		  if(i+j+l==m+n){
		  ans+=((counta(i,up,n,k,d)%M)*(counta(j,up,n,k,d)%M)*(counta(l,up,n,k,d)%M))%M;
		  }
		  }
		  }
		  }
		  }
		  if(m+(2*n)<=3*(n-1)){
		  for(i=0;i<n;i++){
		  for(j=0;j<n;j++){
		  for(l=0;l<n;l++){
		  if(i+j+l==m+(2*n)){
		  ans+=((counta(i,up,n,k,d)%M)*(counta(j,up,n,k,d)%M)*(counta(l,up,n,k,d)%M))%M;
		  }
		  }
		  }
		  }
		  }*/
		printf("%lld\n",sum%M);
	}
	return 0;
}
