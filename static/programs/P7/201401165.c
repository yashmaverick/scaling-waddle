#include<stdio.h>
long long int b[1000001];
int main()
{
	int t;
	scanf("%d",&t);
	while(t>0)
	{
                long long int a[1000000],e;   
		long long int n,i,max,m,ans,min,y;
		ans=0;
                scanf("%lld",&n);
		scanf("%lld",&a[0]);
                max=a[0];
		min=a[0];		
                for(i=1;i<n;i++)
		{
			scanf("%lld",&a[i]);
			if(a[i]>max)
			{
				max=a[i];
			}
			if(a[i]<min)
			{
				min=a[i];
			}
		}
		for(e=0;e<n;e++)
		{
			b[a[e]-min]++;
		}
		for(m=0;m<1000001;m++)
		{
			ans=ans+((b[m])*(b[m]-1))/2;
		}
		printf("%lld\n",ans);
		for(y=0;y<1000001;y++)
		{
			b[y]=0;
		}
		t--;
	}
	return 0;
}
