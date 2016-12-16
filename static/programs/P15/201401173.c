#define MIN(a,b) ((a)<(b)?(a):(b))
#define loop(a,b) for(i=a;i<b;i++)
#define si(n) scanf("%d",&n)
#include<stdio.h>
int minimum(int l,int r,int a[]){
	int k;
	int ans=a[l];
	for(k=l;k<=r;k++){
		if(a[k]<ans)
			ans=a[k];
	}
	return ans;
}
int main(){
	int n,k,a[10001],t;
	int i,min;
	si(t);
	while(t--){
	si(n);
	si(k);
	loop(0,n) si(a[i]);
	int j;
	for(j=0;j<n-k+1;j++){
		if(j!=0&&min!=a[j-1]){
			min=MIN(min,a[j+k-1]);
			printf("%d",min);
			//continue;
		}
		else{
			//printf("j:%d",j);
			min=minimum(j,j+k-1,a);
			printf("%d",min);
		}
		if(j!=n-k)
			printf(" ");
	}
	printf("\n");
	}
	return 0;
}

