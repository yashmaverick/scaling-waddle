#include<stdio.h>
#include<string.h>
int main(){
	long long int n,i,j;
	long long int a[1000000],b[1000000];
	//long long int b[1000000];
	long long int max,min;
	int test;
	scanf("%d",&test);
	while(test--){
	max=-100000000;
        min=100000000;
	scanf("%lld",&n);
	for(i=0;i<n;i++){
		scanf("%lld",&a[i]);
		if(a[i]>max)
			max=a[i];
		if(a[i]<min)
			min=a[i];
	}
	memset(b,0,sizeof(b));
	/*for(i=0;i<1000000;i++)
		b[i]=0;*/
	for(i=0;i<n;i++){
		b[max-a[i]]++;
	}
	long long int count=0;
	for(j=0;j<=max-min;j++){
		if(b[j]>1){
			count+=(b[j]*(b[j]-1))/2;
		}
	}
	printf("%lld\n",count);
	}
	return 0;
}
