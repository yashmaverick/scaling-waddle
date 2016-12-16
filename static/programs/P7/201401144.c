#include <stdio.h>
#include <stdlib.h>
int selectq(int A[], int left, int right);
int find();
int main()
{
	int tt,tb;
	scanf("%d",&tt);
	for(tb=0;tt>tb;tb++){
		find();
	}
	return 0;
}
int find()
{
	int n;
	scanf("%d", &n);
	long long int a[n],b[1000000]={0};
	int i,j;
	for(i=0;i<n;i++){
		scanf("%lld",&a[i]);
	}
	int min=a[0];
	for(i=0;i<n;i++){
		if(min>a[i]){
			min=a[i];
		}
	}
	for(i=0;i<n;i++){
		b[a[i]-min]++;
	}
	long long int sum=0;
	for(i=0;i<1000000;i++){
		sum+=b[i]*(b[i]-1)/2;
	}
	printf("%lld\n",sum);
	return 0;
}
