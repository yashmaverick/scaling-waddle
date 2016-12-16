#include <stdio.h>
int main(){
	int tt,tb;
	scanf("%d",&tb);
	for(tt=0;tt<tb;tt++){
		find();
	}
	return 0;
}
int find()
{
	long long int min,i,n,max=0;
	scanf("%lld",&n);
	long long int a[100000];
	for(i=0;i<n;i++)	
		scanf("%lld",&a[i]);
	min=a[0];
	for(i=0;i<n;i++){
		if(a[i]-min>max){
			max=a[i]-min;
		}
		else if(a[i]<min){
			min=a[i];
		}
	}
	printf("%lld\n", max);
	return 0;
}
