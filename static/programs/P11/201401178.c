#include<stdio.h>
int main(){
	while(1){
		long long int total,i=0,j=0;
		scanf("%lld",&total);
		long long int hgt[total];
		long long int maxarea=0;
		if(total==0){
			break;
		}
		else{
			for(i=0;i<total;i++){
				scanf("%lld",&hgt[i]);
			}
			long long int lftminprev=0,rgtminprev=0,area;
			for(i=0;i<total;i++){
				long long int lftmin,rgtmin;
				if(i==0){
					if(i==0){
						lftmin=0;
						for(j=0;j<total;j++){
							if(hgt[i]>hgt[j]){
								rgtmin=j-1;
								break;
							}
							if(j==total-1)
								rgtmin=total-1;
						}
					}
					/*	if(i==total-1){
						rgtmin=total-1;
						for(j=total-1;j>=0;j--){
						if(hgt[i]>hgt[j]){
						lftmin=j+1;
						break;
						}
						if(j==0)
						lftmin=0;
						}
						}*/
				}
				else{
					if(hgt[i]<hgt[i-1]){
						for(j=lftminprev;j>=0;j--){
							if(hgt[i]>hgt[j]){
								lftmin=j+1;
								break;
							}
							if(j==0){
								lftmin=0;
							}
						}
						for(j=i+1;j<total;j++){
							if(hgt[i]>hgt[j]){
								rgtmin=j-1;
								break;
							}
							if(j==total-1)
								rgtmin=total-1;
						}

					}
					if(hgt[i]>hgt[i-1]){
						for(j=i+1;j<total;j++){
							if(hgt[i]>hgt[j]){
								rgtmin=j-1;
								break;
							}
							if(j==total-1)
								rgtmin=total-1;
						}
						lftmin=i;
					}
					/*	if(hgt[i]==hgt[i-1]){
						lftmin=lftminprev;
						rgtmin=rgtminprev;
						}*/
				}
				area=(rgtmin-lftmin+1)*hgt[i];
				if(area>maxarea)
					maxarea=area;
				lftminprev=lftmin;
			}
		}
		if(total!=0)
			printf("%lld\n",maxarea);
	}
	return 0;
}
