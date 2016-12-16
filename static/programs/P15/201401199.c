#include<stdio.h>
typedef long long int lli;
#define size 10004
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
	lli n,k,i,j;
	lli a[size],min=-1,in=-1,ans[size],at=-1;
	scanf("%lld%lld",&n,&k);
	for(i=0;i<n;i++)
	    scanf("%lld",&a[i]);
//	printf("searching for new\n");
	i=0;
	min=a[i];
	in=i;
	for(j=i+1;j<=i+k-1;j++)
	{
	    if(a[j]<min)
	    {   
		min=a[j];
		in=j;
	    }
	}
	//		printf("%lld",min);
	ans[++at]=min;
//	printf("before begin min=%lld in=%lld\n",min,in);

	for(i=k;i<n;i++)
	{
//	    printf("i=%lld a[i]=%lld\n",i,a[i]);
//	    printf("min=%lld in=%lld\n",min,in);
	    if(a[i]<=min)
	    {
		//		printf("%lld",a[i]);
		ans[++at]=a[i];
		min=a[i];
		in=i;
//		printf("found new min\n");
	    }
	    else if(in>=i-k+1)
	    {
		//		printf("%lld",min);
		ans[++at]=min;
//		printf("old min lies in range\n");
	    }
	    else
	    {
//		printf("searching for new\n");
		min=a[i];
		in=i;
		for(j=i-k+1;j<=i;j++)
		{
		    if(a[j]<min)
		    {   
			min=a[j];
			in=j;
		    }
		}
		//		printf("%lld",min);
		ans[++at]=min;
	    }
//	    printf("end min=%lld in=%lld\n",min,in);
//	    printf("\n");
	}
	for(i=0;i<=at;i++)
	{
	    printf("%lld",ans[i]);
	    if(i!=at)
		printf(" ");
	}
	printf("\n");
    }
    return 0;
}
