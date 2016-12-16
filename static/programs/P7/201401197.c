#include<stdio.h>
int main(){
	int ar[1000000],hash[1000001],i,n,min,t;
	long long ans;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		scanf("%d",ar);
		min=ar[0];
		for(i=1;i<n;i++){
			scanf("%d",ar+i);
			if(ar[i]<min){
				min=ar[i];
			}
		}
		for(i=0;i<1000001;i++){
			hash[i]=0;
		}
		for(i=0;i<n;i++){
			hash[ar[i]-min]++;
		}
		for(ans=0,i=0;i<1000001;i++){
			if(hash[i]>1){
				ans+=((long long)hash[i]*(long long)(hash[i]-1))/2;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
