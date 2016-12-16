#include<stdio.h>
int main()
{
	while(1)
	{
		long long int n,i;
		scanf("%lld",&n);
		if(n==0) break;
		long long int a[n];
		for(i=0;i<n;i++) scanf("%lld",&a[i]);
		long long int stack[n],sp=-1;
		long long int left[n];
		left[0]=-1;
		sp++;stack[sp]=0;
		for(i=1;i<n;i++)
		{
			while(1)
			{
				if(sp==-1) break;
				if(a[stack[sp]]>=a[i]) sp--;
				else break;
			}
			if(sp==-1) left[i]=-1;
			else left[i]=stack[sp];
			sp++; stack[sp]=i;
		}
		sp=-1;
		long long int right[n];
		right[n-1]=-1;
		sp++; stack[sp]=n-1;
		for(i=n-2;i>=0;i--)
		{
			while(1)
			{
				if(sp==-1) break;
				if(a[stack[sp]]>=a[i]) sp--;
				else break;
			}
			if(sp==-1) right[i]=-1;
			else right[i]=stack[sp];
			sp++; stack[sp]=i;
		}
		long long int ans=0,left1,right1;
		for(i=0;i<n;i++)
		{
			if(left[i]==-1) left1=i;
			else left1=i-left[i]-1;
			if(right[i]==-1) right1=n-1-i;
			else right1=right[i]-i-1;
			if(a[i]*(left1+right1+1)>ans) ans=a[i]*(left1+right1+1);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
