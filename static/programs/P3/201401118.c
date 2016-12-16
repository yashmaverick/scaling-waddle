#include<stdio.h>
int diff(int a[], int end)
{
	int dif,max=0;
	while(0<=end)
	{
		int b=1000000000,c,d=0,e,i;
		for(i=0;i<=end;i++)
		{
			if(b>a[i])
			{
				b=a[i];
				c=i;
			}
		}
		for(i=c;i<=end;i++)
		{
			if(d<a[i])
			{
				d=a[i];
				e=i;
			}
		}
		dif=d-b;
		if(dif>max)
			max=dif;
		end=c-1;
	}
	return max;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		int a[n],i,ans;
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		ans=diff(a,n-1);
		printf("%d\n",ans);
	}
	return 0;
}
