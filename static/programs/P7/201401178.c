#include<stdio.h>
typedef long long int ll;
int main(){
	ll test,i;
	scanf("%lld",&test);
	for(i=0;i<test;i++){
		ll size,n;
		scanf("%lld",&size);
		ll arr[size],min=10000001,max=-10000001;
		for(n=0;n<size;n++){
			scanf("%lld",&arr[n]);
			if(arr[n]<=min)
				min=arr[n];
			if(arr[n]>=max)
				max=arr[n];
		}
		for(n=0;n<size;n++){
			arr[n]=arr[n]-min;
		}
		ll val,stor[1000000];
		for(n=0;n<1000000;n++){
			stor[n]=0;
		}
		for(val=0;val<size;val++){
			stor[arr[val]]++;
		}
		val=0;
		for(n=0;n<=(max-min);n++){
			val=((stor[n])*(stor[n]-1))/2+val;
		}
		printf("%lld\n",val);
	}
	return 0;
}

