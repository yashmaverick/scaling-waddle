#include<stdio.h>
int main()
{
	long long int a[100005],b[100005],i,h,n,j,tmp,MA,area;
	while(1){
		scanf("%lld",&n);
		if(n==0){
			break;
		}
		else{
			area=0,MA=0;
			for(i=0;i<n;i++){
				scanf("%lld",&h);
				a[i]=h;
			}
			j=-1;
			i=0;
			while(i<n){
				if((j==-1)||(a[b[j]]<=a[i]))
				{
					j++;
					b[j]=i;
					i++;
				}
				else
				{
					tmp=b[j];
					j--;
					if(j==-1){
						area=a[tmp]*i;
					}
					else{
						area=a[tmp]*(i-b[j]-1);
					}
					if(MA<area){
						MA=area;
					}
				}
			}
			while(j>-1){
				tmp=b[j];
				j--;
				if(j==-1){
					area=a[tmp]*i;
				}
				else{
					area=a[tmp]*(i-b[j]-1);
				}
				if(MA<area){
					MA=area;
				}
			}
			printf("%lld\n",MA);
		}
	}
	return 0;
}







