#include<stdio.h>

int main(){
	long long n,hist[100010];
	scanf("%lld",&n);
	while(n){
		long long i,a=1,max=0;
		long long stack[100010],l,m;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&hist[i]);
		}
		hist[0]=0;
		stack[0]=0;
		hist[++n]=0;
		for(i=1;i<=n;i++)
		{
				while(a>1 && hist[stack[a-1]] >= hist[i])
				{
					l=stack[a-1];
					m=stack[a-2];
					if(max < (long long)hist[l]*(long long)(i-m-1))
					{
						max=(long long)hist[l]*(long long)(i-m-1);
					}
					a--;
				}
			
			stack[a++]=i;
		}
		printf("%lld\n",max);

		scanf("%lld",&n);
	}
	return 0;
}
