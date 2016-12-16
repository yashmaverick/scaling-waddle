#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	int a[n],b[n],i;
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++)
	{
		scanf("%d",&b[i]);
	}
	int p,c,d,ind1,ind2;
	scanf("%d",&p);
	while(p--)
	{
		scanf("%d%d",&c,&d);
		for(i=0;i<n;i++)
		{
			if(b[i]==c)
			{
				ind1=i;
				break;
			}
		}
		for(i=0;i<n;i++)
		{
			if(b[i]==d)
			{
				ind2=i;
				break;
			}
		}
		if(ind2<ind1)
		{
			int temp;
			temp=ind1;
			ind1=ind2;
			ind2=temp;
		}
		int j,ans,flag=0;
		for(j=0;j<n;j++)
		{
			for(i=ind1;i<=ind2;i++)
			{
				if(b[i]==a[j])
				{
					ans=b[i];
					flag=1;
					break;
				}
			}
			if(flag==1)
			{
				break;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
