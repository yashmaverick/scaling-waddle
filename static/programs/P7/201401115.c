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
		long long int count=1,i,A[1000007],n;
		scanf("%lld",&n);
		for(i=0;i<n;i++)
			scanf("%lld",&A[i]);
		qsort(A,n,sizeof(long long int),cmpfunc);
		long long int ans=0;
		for(i=1;i<n;i++)
		{
			if(A[i]==A[i-1])
				count++;
			else
			{
				ans+=(count*(count-1))/2;
				count=1;
			}
		}
		if(count != 1)
			ans += (count*(count-1))/2;
		printf("%lld\n",ans);
	}
	return 0;
}