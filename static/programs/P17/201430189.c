#include<stdio.h>
#include<stdlib.h>

int main(){
		int *pre,*prerev,*in,*inrev,num,t,J,W,i,minpre,Win,Jin;
		scanf("%d" ,&num);
		pre=malloc((num+1)*sizeof(int));
		prerev=malloc((num+1)*sizeof(int));
		for(i=1;i<=num;i++){
				scanf("%d" ,pre+i);
				prerev[pre[i]]=i;
		}
		in=malloc((num+1)*sizeof(int));
		inrev=malloc((num+1)*sizeof(int));
		for(i=1;i<=num;i++){
				scanf("%d" ,in+i);
				inrev[in[i]]=i;
		}
		scanf("%d" ,&t);
		while(t--){
				scanf("%d %d" ,&J,&W);
				minpre=prerev[J];
				Jin=inrev[J];
				Win=inrev[W];
				if(prerev[J]>prerev[W]){
						minpre=prerev[W];
				}
				for(i=1;i<=minpre;i++){
						if((inrev[pre[i]]-Jin)*(inrev[pre[i]]-Win)<=0){
								printf("%d\n" ,pre[i]);
								break;
						}
				}
		}
		return 0;
}
