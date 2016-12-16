#include<stdio.h>
int main()
{
	long long int cases;
	scanf("%lld",&cases);
	while(cases--)
	{
		long long int n,k,i,j;
		scanf("%lld %lld",&n,&k);
		long long int a[n],stack[n],ep=0,bp=0;
		for(i=0;i<n;i++) scanf("%lld",&a[i]);
		if(n==1)  { printf("%lld\n",a[0]); continue; }
		stack[ep]=0;
		for(i=1;i<k;i++)
		{
			if(a[stack[ep]]<=a[i]) {ep++; stack[ep]=i;}
			else 
			{
				while(ep>=bp && a[stack[ep]]>a[i]) ep--;
				ep++; stack[ep]=i;
			}
		}
		if(k==n)
		{
				printf("%lld\n",a[stack[bp]]);
		}
		else
		printf("%lld ",a[stack[bp]]);
		//printf("Initial quack is ");for(i=bp;i<=ep;i++) printf("%lld ",stack[i]); printf("\n");
		for(i=k;i<n;i++)
		{
			//printf("%lld %lld %lld %lld %lld\n",a[i],a[stack[bp]],i,bp,stack[bp]);
			//printf("Loop starts Quack is bp->>ep  ");
			if(a[i]<a[stack[bp]]) { stack[bp]=i ; ep=bp;}
			else if(a[stack[ep]]<=a[i]) {ep++; stack[ep]=i;}
			else 
			{
				while(a[stack[ep]]>a[i])
				{
					ep--;
				}
				ep++; stack[ep]=i;
			}
			while(stack[bp]<=(i-k)){ bp++;}
			if (i<(n-1))
				printf("%lld ",a[stack[bp]]);
			else if (i==n-1)
				printf("%lld\n",a[stack[bp]]);
		    //printf("Loop ends Quack is bp->>ep  ");
	//		for(j=bp;j<=ep;j++) printf("%lld ",stack[j]); printf("\n");
		}
		//printf("\n");
	}
	return 0;
}
