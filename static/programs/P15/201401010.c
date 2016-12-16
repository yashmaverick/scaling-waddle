#include<stdio.h>
#include<stdlib.h>

int min(int a[],int start,int end){
	int i,j;
	int min=start;
	for(i=start;i<=end;i++){
		if(a[i]<=a[min])min=i;
	}
	return min;
}
int main(){
	int t,n,i,j,k,*a,m;
	scanf("%d",&t);
	for(i=0;i<t;i++){
		m=0;
		scanf("%d%d",&n,&k);
		a=(int*)malloc(n*sizeof(int));
		for(j=0;j<n;j++)scanf("%d",&a[j]);
		for(j=0;j<n-k+1;j++){
			if(j==0 || m<j){
				m=min(a,j,j+k-1);
			}
			else if(a[m]>=a[j+k-1]){
				m=min(a,j,j+k-1);
			}
			if(j<n-k)printf("%d ",a[m]);
			else{printf("%d",a[m]);}
		}
		printf("\n");
		free(a);
	}
	return 0;
}