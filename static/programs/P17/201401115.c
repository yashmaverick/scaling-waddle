#include<stdio.h>
int main(){
	int n,i;
	int a[100000],b[100000],c[100000],d[100000];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		c[a[i]] = i;
	}
	for(i=0;i<n;i++){
		scanf("%d",&b[i]);
		d[b[i]] = i;
	}
	int test;
	scanf("%d",&test);
	while(test--){
		int q1,q2,min=100000000;
		scanf("%d%d",&q1,&q2);
		if(d[q1] < d[q2]){
			for(i=d[q1];i<=d[q2];i++){
				if(c[b[i]]<min)
					min = c[b[i]];
			}
		}
		else if(d[q1] > d[q2]){
			for(i=d[q2];i<=d[q1];i++){
				if(c[b[i]]<min)
					min = c[b[i]];
			}
		}
		else{
			min = c[q1];
		}
		printf("%d\n",a[min]);
	}
	return 0;
}