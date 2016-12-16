#include<stdio.h>
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int a[10010],n,k,min,i,j;
		scanf("%d%d",&n,&k);
		a[0]=1000000001;
		min=0;
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
			if(i<=k && a[i]<a[min]){
				min = i;
			}
		}
		if (n==k){
			printf("%d\n",a[min]);
		}
		else
			printf("%d ",a[min]);
		for(i=k+1;i<=n;i++){
			if(min>(i-k)){
				if(a[i]<a[min]){
					min = i;
				}
			}
			else{
				min=0;
				for(j=i-k+1;j<=i;j++){
					if(a[j]<a[min]){
						min=j;
					}
				}
			}
			if(i<n){
				printf("%d ",a[min]);
			}
			else{
				printf("%d\n",a[min]);
			}
		}
		//printf("\n");
	}
	return 0;
}