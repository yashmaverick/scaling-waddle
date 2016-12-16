#include<stdio.h>
int mi(int a,int b)
{
	if(a>b)
		return b;
	else
		return a;
}
int main()
{
	int jaa,test;
	scanf("%d",&test);
	for(jaa=0;jaa<test;jaa++)
	{
		int i,n,j,a[10000],k,count=0;
		scanf("%d%d",&n,&k);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
		}
		int min=a[1];
		for(i=1;i<=n-k+1;i++)
		{	
			if (min==a[i-1] || i==1)
			{
				min=a[i];
				for(j=i;j<=i+k-1;j++)
				{
					if(a[j]<min)
						min=a[j];
				}
			}
			else
			{
				min=mi(min,a[i+k-1]);
			}
			if(i<=n-k)
				printf("%d ",min);
			else 
				printf("%d",min);
			count++;
		}
		printf("\n");
	}
	return 0;
}
