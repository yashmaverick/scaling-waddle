#include<stdio.h>
#include<stdlib.h>
void answer(long long * hash,int i,long long int ans)
{
	for(i=0;i<1000001;i++)
	{
		ans=ans+(hash[i]*(hash[i]-1)/2);
	}
		printf("%lld\n" ,ans);
	return ;			
}

int main()
{
	long long int i,n,min,ans,testcases;
	long long * A;
	long long * hash;
	A=malloc(sizeof(long long)*1000005);
	hash=malloc(sizeof(long long)*1000005);
	scanf("%lld" ,&testcases);
	while(testcases--){
		scanf("%lld" ,&n);
		min=10000000;
		for(i=0;i<n;i++){
			scanf("%lld" ,&A[i]);
			if(min>A[i])
				min=A[i];
		}
		for(i=0;i<1000005;i++)
			hash[i]=0;
		for(i=0;i<n;i++)
			hash[A[i]-min]++;
		answer(hash,i,ans);
	}
	return 0;


}
