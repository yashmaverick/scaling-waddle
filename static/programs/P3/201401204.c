#include<stdio.h>
#include<stdlib.h>
int main(){
	long long int a[100005];
	int t;
	scanf("%d",&t);
	while(t--){
		int i;
		long long int n;
		scanf("%lld",&n);
		for(i=0;i<n;i++)
			scanf("%lld",&a[i]);
		long long int min=a[0];
		long long int max=a[0];
		long long int maxpro=0;
		long long int maxp=0;
		int index_min=0;
		int index_max=0;
		for(i=1;i<=n-1;i++){
			if(min>a[i]){
				min=a[i];
				index_min=i;
				index_max=i;
				max=a[i];
			//	printf("min %lld = index_min = %d\n",min,index_min);
			}
			if(max<a[i]){
				max=a[i];
				index_max=i;
			//	printf("max %lld = index_max = %d\n",max,index_max);
			}
			maxp=min-max;
			//printf("maxp = %lld\n",maxp);
			if(maxpro>=maxp && index_max>=index_min){
				maxpro=maxp;
			//	printf("maxpro = %lld\n",maxpro);
			}
		}
		printf("%lld\n",-1*maxpro);
	}
	return 0;
}
