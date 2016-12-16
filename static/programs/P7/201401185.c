#include<stdio.h>

void hash(long int a[],long int b[],long int max,long int size){
	long int i,j;
	for(i=0;i<size;i++){
		j=max-a[i];
		b[j]=b[j]+1;
	}
	return;
}



int main()
{
	int t;
	long int n,i,max;
	scanf("%d",&t);
	while(t--){
		long long int pc=0;
		scanf("%ld",&n);
		long int a[n],bucket[1000001];
		for(i=0;i<1000001;i++)
			bucket[i]=0;
		for(i=0;i<n;i++)
			scanf("%ld",&a[i]);
		max=a[0];
		for(i=1;i<n;i++)
			if(a[i]>max)
				max=a[i];
		hash(a,bucket,max,n);
		for(i=0;i<1000001;i++){
			if(bucket[i]>1){
				long int j=bucket[i];
				pc=pc+(j*(j-1))/2;
			}
		}
		printf("%lld\n",pc);
	}
	return 0;
}
