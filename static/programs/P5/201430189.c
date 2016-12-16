#include<stdio.h>
#include<stdlib.h>

int cmpfunc (const void * a, const void * b)
{
		return ( *(int*)a - *(int*)b );
}
int main(){
		int testcases,n,sum,A[1000],i,j,k,done;
		char temp[100];
		scanf("%d" ,&testcases);
		while(testcases--){
				scanf("%d%d" ,&n,&sum);
				for(i=0;i<n;i++){
						scanf("%s%d" ,temp,A+i);
				}
				qsort(A,n,sizeof(int),cmpfunc);
				done=0;
				for(i=0;i<n-2 && done==0;i++){
						j=i+1;
						k=n-1;
						while(j<k){
								if(A[i]+A[j]+A[k]==sum){
										printf("YES\n");
										done=1;
										break;
								}
								else if(A[i]+A[j]+A[k]>sum)
										k--;
								else
										j++;
						}
				}
				if(done==0)
						printf("NO\n");
		}
		return 0;
}



