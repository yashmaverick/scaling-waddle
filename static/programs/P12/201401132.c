#include<stdio.h>
int main(){
	long long int n,i,C,l,k,j,flag,ag;
	while(1){
	scanf("%lld",&n);
	long long int a[n],b[n];
		if(n==0){
			break;
		}
		j=-1;C=0;
		for(i=0;i<n;i++){
			scanf("%lld",&a[i]);
		}
		i=0;
		while(i<n){
			flag=0;
			if((j==-1)||(a[i]<=b[j])){
				j++;
				b[j]=a[i];
				i++;
			}
			else
			{
				j--;
				C=C+(n-i-1);
			//	printf("#\n");
				flag=2;
			}
			l=j;
			while((l>1)&&(flag!=2))
			{
				//		printf("k\n");
				for(k=l-1;k>0;k--){
//					printf("l\n");
					//			printf("%d,%d,%d\n",b[l],b[k],j);
					if(b[l]<b[k]){
						C=C+k;
				//		printf("%lld,%lld,%lld\n",C,i,j);
						ag=1;
						break;

					}
				}
					if(ag==1){
						break;
				}
				l--;
			}
		}
		printf("%lld\n",C);
	}
	return 0;
}


