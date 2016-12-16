#include<stdio.h>
#define size 100005

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		long long int a[size]={0},a1[size]={0},b[size]={0},b1[size]={0},c[size]={0};
		long long int i,j;
		long long int n1,n2,n3;
		for(i=0;i<size;i++){
			a[i]=0;
			b[i]=0;
			c[i]=0;
			a1[i]=0;
			b1[i]=0;
		}
		scanf("%lld",&n1);
		for(i=0;i<n1;i++)
			scanf("%lld",&a[i]);
		scanf("%lld",&n2);
		for(i=0;i<n2;i++)
			scanf("%lld",&b[i]);
		scanf("%lld",&n3);
		for(i=0;i<n3;i++){
			scanf("%lld",&c[i]);
		}
		long long int start=(n2<=n3)?n2:n3;
		long long int temp;
		temp=n3-1;
		for(j=start-1;j>=0;j--){
			i=temp;
			while(i>=j && b[j]<=c[i])
				i--;
			temp=i;
			if(j==start-1)
				b1[j]=n3-i-1;
			else
				b1[j]=b1[j+1]+n3-i-1;
		}
		start=(n1<=n2)?n1:n2;
		temp=n2-1;
		for(j=start-1;j>=0;j--){
			i=temp;
			while(i>=j && a[j]<=b[i])
				i--;
			temp=i;
			if(j==start-1)
				a1[j]=b1[i+1];
			else
				a1[j]=a1[j+1]+b1[i+1];
		}
		/*
		printf("\na\n");
		for(i=0;i<n1;i++)
			printf("%lld ",a[i]);
		printf("\nb\n");
		for(i=0;i<n2;i++)
			printf("%lld ",b[i]);
		printf("\nc\n");
		for(i=0;i<n3;i++)
			printf("%lld ",c[i]);
		printf("\na1\n");
		for(i=0;i<n1;i++)
			printf("%lld ",a1[i]);
		printf("\nb1\n");
		for(i=0;i<n2;i++)
			printf("%lld ",b1[i]);
*/
		printf("%lld\n",a1[0]);
	}
	return 0;
}
