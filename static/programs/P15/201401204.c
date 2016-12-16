#include<stdio.h>
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int a[10005];
		int j,i,n,k,min,inmin;
		scanf("%d %d",&n,&k);
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		min=a[0];
		inmin=0;
		for(i=1;i<k;i++)
			if(min>=a[i]){
				min=a[i];
				inmin=i;
			}
		int c=1;
		if(c==n-k+1)
		printf("%d",min);
		else
		printf("%d ",min);
		c++;
		i=k;
		while(i<n){
			if(inmin>=i-k+1){
				if(min<a[i]){
					if(c==n-k+1){
					printf("%d",min);
					c++;
					}
					else{
					printf("%d ",min);
					c++;
					}
				}
				else{
					min=a[i];
					inmin=i;
					if(c==n-k+1){
					printf("%d",min);
					c++;
					}
					else{
					printf("%d ",min);
					c++;
					}
				}
			}
			else{
				min=a[i];
				for(j=i;j>=i-k+1;j--){
					if(min>=a[j]){
						min=a[j];
						inmin=j;
					}
				}
				if(c==n-k+1){
				printf("%d",min);
				c++;
				}
				else{
					printf("%d ",min);
					c++;
				}
			}
			i++;
		}
		printf("\n");
	}
	return 0;
}
