#include<stdio.h>
int a[100002];
int main()
{
	int t,x;
	int qwer;
	scanf("%d",&t);
	qwer=0;
	for(x=0;x<t;x++)
	{
	qwer++;
		int n,k,i,j,min,index;qwer++;
		scanf("%d%d",&n,&k);qwer++;
		for(i=0;i<n;i++)
		{
			qwer++;
			scanf("%d",&a[i]);
		}
		min=a[0];
		index=0;
		qwer=0;
		for(i=1;i<k;i++)
		{
			if(a[i]<min)
			{
				qwer++;
				index=i;qwer++;
				min=a[i];qwer++;
			}
		}
		if(n==k)
		{
			printf("%d\n",min);qwer++;
		}
		else
		{
			printf("%d ",min);qwer++;
		}
		for(i=k;i<n;i++)
		{
			if(a[i]>min&&index<=i-k)
			{
				min=a[i-k+1];qwer++;
				for(j=i-k+2;j<=i;j++)
				{
					if(a[j]<=min)
					{
						min=a[j];qwer++;
						index=j;qwer++;
					}
				}
			}
			else if(a[i]<=min)
			{
				min=a[i];qwer++;
				index=i;
			}
			if(i==n-1)
			{
				printf("%d\n",min);qwer++;
			}
			else
			{
				printf("%d ",min);qwer++;
			}
		}
	}
	return 0;
}
