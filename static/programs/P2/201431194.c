#include<stdio.h>
int main(){
	long long int t,i,j,k,a[100000],b[100000],c[100000],n,m,l;
	scanf("%lld",&t);
	while(t--){
		long long int sum=0;
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
			scanf("%lld",&a[i]);
		scanf("%lld",&m);
		for(i=1;i<=m;i++)
			scanf("%lld",&b[i]);
		scanf("%lld",&l);
		for(i=1;i<=l;i++)
			scanf("%lld",&c[i]);
		i=1;
		k=1;
		for(j=1;j<=m;j++){
			k=j;
			while(a[i]<b[j] && i<j)
				i++;
			if(a[i]>b[j]){
				if(i>1)
					i=i-1;
				else
					i=1;
			}
			if(i>n)
				i=n;
			while(c[k]<b[j] && k<l)
				k++;
			if(j>l)
				break;
			if((a[i]<=b[j]) && (b[j]<=c[k]))
				sum=sum+(i*(l-k+1));
//			printf("%lld %lld %lld %lld\n",i,j,k,sum);
		}
		printf("%lld\n",sum);
	}
	return 0;
}
