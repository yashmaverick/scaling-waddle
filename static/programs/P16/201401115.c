#include<stdio.h>
long long int power(long long int a, long long int b){
	long long int x;
	if(b==0)
		return 1;
	else{
		if(b%2==0){
			x = power(a,b/2);
			return x*x;
		}
		else{
			x = power(a,b/2);
			return x*x*a;
		}
	}
}
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
	int n;
	scanf("%d",&n);
	while(n--){
		long long int a,lg=0,temp,x,y;
		scanf("%lld",&a);
		temp = a;
		while(temp!=1){
			temp=temp/2;
			lg++;
		}
		//x = power(2,lg-1);
		y = power(2,lg);
		x=y/2;
		if(a%y >= x)
			printf("%lld\n",(2*(lg)));
		else
			printf("%lld\n",((2*(lg))-1));
		//printf("%lld\n",modulo(a,b,m));
	}
	return 0;
}