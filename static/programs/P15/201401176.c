#include<stdio.h>
int main()
{
	int i,j;
	int n,k,t,a[10005],min,p;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		min=a[0];
		for(i=0;i<k;i++)
			if(a[i]<min)
				min=a[i];
		printf("%d",min);
		if(n-k==0)
			printf("\n");
		else
			printf(" ");
		for(i=1;i<n-k+1;i++)
		{
			if(min==a[i-1])
			{
				min=a[i];
				for(j=i,p=0;p<k;p++,j++)
				{
					if(min>a[j])
						min=a[j];
				}
			}
			else if(min>a[k+i-1])
				min=a[k+i-1];
			if(i!=n-k)
				printf("%d ",min);
			else
				printf("%d\n",min);
		}
	}
	return 0;
}

