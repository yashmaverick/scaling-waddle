#include<stdio.h>
int main()
{
	int i,ans,a[100005],b[100005],t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		b[n-1]=a[n-1];
		for(i=n-2;i>=0;i--)
			b[i]=(a[i]>a[i+1]?a[i]:a[i+1]);
		for(i=1;i<n;i++)
			a[i]=(a[i]<a[i-1]?a[i]:a[i-1]);
		ans=0;
		for(i=0;i<n;i++)
		{
			b[i]=b[i]-a[i];
			ans=(ans>b[i]?ans:b[i]);
		}
		printf("%d\n",ans);
	}
	return 0;
}
