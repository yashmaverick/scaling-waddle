#include <stdio.h>
int main(){
	int test;
	scanf("%d", &test);
	while(test--){
	long long int n,a,i,j,min,diff;
	scanf("%lld", &n);
	scanf("%lld", &a);
	min=a;
	diff=a;
	long long int max=0;
	for (i = 1; i < n; i++)
	{
		scanf("%lld",&a);
		diff=a-min;
		if(diff>max)
			max=diff;
		if(a<min)
			min=a;
			/* code */
	}
	printf("%lld\n",max);
	}
}