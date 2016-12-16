#include<stdio.h>

void swap(int* a,int* b){
	int t;
	t=*a;
	*a=*b;
	*b=t;
	return;
}

int main(){
	int n,i,j,k,sum=0,dsum=0,ni,kite;
	long long int mod;
	scanf("%d %lld",&n,&mod);
	int a[1000001];
	int a1[n],a2[n];
	i=0;
	ni=0;
	kite=0;
	while(ni<n){
		scanf("%d",&a[i]);
		j=a[i];
		dsum+=j;
		a1[kite]=i;
		for(k=0,sum=0;k<j;k++){
			scanf("%d",&a[++i]);
			//a[++i]=t;
			sum=(sum%mod+a[i]%mod)%mod;
		}
		ni++;
		i++;
		a2[kite]=sum;
		kite++;
	}
	dsum+=n;
	/*for(i=0;i<dsum;i++)
		printf("%d ",a[i]);
	printf("\n");*/
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(a2[i]>a2[j]){
				swap(&a1[i],&a1[j]);
				swap(&a2[i],&a2[j]);
			}
		}
	}
/*	for(i=0;i<n;i++)
		printf("%d ",a2[i]);
	printf("\n");
	for(i=0;i<n;i++)
		printf("%d ",a1[i]);
	printf("\n");
*/
	for(i=0;i<n;i++){
		printf("%d\n",a2[i]);
		for(j=1;j<=a[a1[i]];j++)
			printf("%d\n",a[j+a1[i]]);
		printf("\n");
	}

	return 0;
}
