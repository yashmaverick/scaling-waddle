#include<stdio.h>
#define size 100005

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
	int n,i,ref;
	long long int p[size],diff,ans;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	    scanf("%lld",&p[i]);

	ref=n-1;
	ans=0;

	for(i=n-1;i>=0;i--)
	{
//	    printf("p[%d] - p[%d] = %lld-%lld\n",ref,i,p[ref],p[i]);
	    diff=p[ref]-p[i];
//	    printf("diff = %lld\n",diff);
	    if(diff>ans)
		ans=diff;
//	    printf("ans to %lld\n",ans);
	    if(diff<0)
	    {
//		printf("ref from %d --> ",ref);
		ref=i;
//		printf("%d\n",ref);
	    }
	}
//	printf("ans = %lld\n",ans);
	printf("%lld\n",ans);
    }
    return 0;
}
