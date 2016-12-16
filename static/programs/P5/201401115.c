#include<stdio.h>
#include<stdlib.h>
int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int i,j,end,n,k,a[1000],flag=0;
		long long int current=0;
		char b[100];
		scanf("%d%d",&n,&k);
		for(i=0;i<n;i++){
			//printf("Night%d ",i+1);
			scanf("%s%d",b,&a[i]);
		}
		qsort(a,n,sizeof(int),cmpfunc);
		for(i=0;i<n-2;i++){
			j=i+1;
			end = n-1;
			while(j<end){
				current = a[i] + a[j] + a[end];
				if(current < k){
					j++;
				}
				else if(current > k){
					end--;
				}
				else{
					flag=1;
					break;
				}
			}
			if(flag==1)
				break;
		}
		if(flag==1)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
