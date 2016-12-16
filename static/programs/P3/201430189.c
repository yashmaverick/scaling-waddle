#include<stdio.h>
int main(){
		int A[1000000],pt,maxsum,diff[1000000],i,n,cumsum;
		int testcases;
		scanf("%d",&testcases);
		while(testcases--){
				scanf("%d" ,&n);
				scanf("%d",&A[0]);
				diff[0]=0;
				for(i=1;i<n;i++){
						scanf("%d" ,A+i);
						diff[i]=A[i]-A[i-1];
				}
				cumsum=maxsum=0;
				pt=1;
				while(pt<n){
						cumsum+=diff[pt];
						if(cumsum>maxsum)
								maxsum=cumsum;
						if(cumsum<0)
								cumsum=0;
						pt++;
				}
				printf("%d\n" ,maxsum);
		}
		return 0;
}


		
