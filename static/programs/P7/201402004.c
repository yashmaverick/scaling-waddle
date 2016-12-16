#include <stdio.h>
#include<stdlib.h>

long long int t,n,a[1000010],i,cnt=1;
long long int ans=0;
int compare (const void * a, const void * b)
{
  return ( *(long long int*)a - *(long long int*)b );
}
int main(void) {
	scanf("%lld",&t);
	//memset(h,0,sizeof(h));
	while(t--)
	{
		ans=0;
		scanf("%lld",&n);
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
		}
		qsort (a, n, sizeof(long long int), compare);
		//for(i=0;i<n;i++)printf("%lld",a[i]);
		cnt=1;
		for(i=1;i<n;i++)
		{
			if(a[i]==a[i-1])cnt++;
			else
			{
				if(cnt>=2)ans+=(cnt*(cnt-1)/2);
				cnt=1;
			}
		}
		if(cnt>=2)ans+=(cnt*(cnt-1)/2);
		printf("%lld\n",ans);
	}
	return 0;
}
 
