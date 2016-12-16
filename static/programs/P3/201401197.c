#include<stdio.h>
#include<stdlib.h>
int main(){
	int t,n,ans,max,i,*ar;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		ar=(int *)malloc(sizeof(int)*n);
		for(i=0;i<n;i++){
			scanf("%d",ar+i);
		}
		for(i=n-1,max=ar[n-1],ans=0;i>=0;i--){
			if(ar[i]<max){
				if(max-ar[i]>ans){
					ans=max-ar[i];
				}
			}
			else{
				max=ar[i];
			}
		}
		printf("%d\n",ans);
		free(ar);
	}
	return 0;
}
