#include<stdio.h>
int main()
{
	int n,i,a[100000],b[100000],r1;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++)
	{
		scanf("%d",&b[i]);
	}
	int t,jaa;
	scanf("%d",&t);
	for(jaa=0;jaa<t;jaa++)
	{
		int t1,t2,e1,e2,k1,k2,j;
		scanf("%d%d",&t1,&t2);
		for(i=0;i<n;i++)
		{
			if(b[i]==t1)
				e1=i;
			if(b[i]==t2)
				e2=i;
		}
		if(e1>e2)
		{
			k1=e2;
			k2=e1;
		}
		else
		{
			k1=e1;
			k2=e2;
		}
		int flag=0;
		for(j=0;j<n;j++)
		{
			for(i=k1;i<=k2;i++)
			{
				if(a[j]==b[i])
				{
					printf("%d\n",a[j]);
					flag=1;
					break;
				}
			}
			if(flag==1)
				break;
		}
		flag=0;
	}
	return 0;
}

