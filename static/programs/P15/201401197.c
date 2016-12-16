#include<stdio.h>
int main(){
	int t,n,k,a[10004],l[10004],r[10004],i,j,pl,pr;
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&n,&k);
		for(i=0;i<n;i++){
			scanf("%d",a+i);
		}
		for(i=0;i<n;i++){
			j=i-1;
			while(j>=0&&a[j]>=a[i]){
				j=l[j];
			}
			l[i]=j;
		}
		for(i=n-1;i>=0;i--){
			j=i+1;
			while(j<n&&a[j]>=a[i]){
				j=r[j];
			}
			r[i]=j;
		}
		for(i=0,pl=0;i<n-k+1;i++){
			if(pl<i)
				pl=i;
			pr=i+k-1;
			while(r[pl]<=(i+k-1)&&l[pr]>=i){
				pl=r[pl];
				pr=l[pr];
			}
			if(r[pl]>i+k-1){
				printf("%d",a[pl]);
				if(i!=n-k){
					printf(" ");
				}
			}
			else if(l[pr]<i){
				printf("%d",a[pr]);
				pl=pr;
				if(i!=n-k){
					printf(" ");
				}
			}
			else{
				printf("\nGone Bad %d %d\n\n",pl,pr);
			}
		}
		printf("\n");
	}
	return 0;
}
