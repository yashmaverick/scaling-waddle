#include<stdio.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,k;
		scanf("%d%d",&n,&k);
		int a[n],i,flag=0;
		char b[10000];
		for(i=0;i<n;i++)
		{	
			scanf("%s",b);
			scanf("%d",&a[i]);
		}
		int p,q,r,j;
		for(i=0;i<n;i++)
		{
			for(j=i+1;j<n;j++)
				if(a[i]>a[j])
				{	
					a[i]=a[i]+a[j];
					a[j]=a[i]-a[j];
					a[i]=a[i]-a[j];
				}
		}

		for(i=0;i<n-2;i++)
		{
			p=i+1,q=n-1;
			while(p<q)
			{

				if(a[i]+a[p]+a[q]==k)
				{
					printf("YES\n");
					flag=1;
					break;
				}
				if(a[i]+a[p]+a[q]>k)
					q--;
				else
					p++;
			}
			if(flag==1)
				break;
		}
		if(flag==0)
			printf("NO\n");
	}
	return 0;
}

