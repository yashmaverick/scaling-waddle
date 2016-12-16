#include<stdio.h>
int main()
{
	int t,i,j,k,n,p;
	long long int a[100001],min,max,ans,tempmin,tempmax,tempans;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		scanf("%d",&n);
		if(n>0)
			scanf("%lld",&a[0]);
		min=a[0];
		max=a[0];
		p=0;
		tempmax=max;
		tempmin=min;
		ans=0;
		tempans=0;
		if(n>1)
			for(j=1;j<n;j++)
			{
				scanf("%lld",&a[j]);
				if(a[j]>a[j-1] && p==0)//increase
				{
					p=1;
					tempmin=a[j-1];
					tempmax=a[j];
					tempans=tempmax-tempmin;
				}
				if(p==1 && a[j]>a[j-1])
				{
					tempmax=a[j];
					tempans=tempmax-tempmin;
				}
				if(tempans>ans)
					ans=tempans;
				if(p==1 && a[j]<a[j-1])
				{
					p=2;
					min=tempmin;
					//tempmax=0;
				}
				if(p==2 && a[j]>a[j-1] )
				{
					if(min<a[j-1])
						tempmin=min;
					else
						tempmin=a[j-1];
					tempmax=a[j];
					tempans=tempmax-tempmin;
					p=1;
					//printf("did  tempmin=%lld j=%d\n ",tempmin,j);
				}
				if(tempans>ans)
					ans=tempans;
			}
		printf("%lld\n",ans);
	}
	return 0;
}
