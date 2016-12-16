#include<stdio.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,k,min=0,a[100000],i,j,l;
		scanf("%d %d",&n,&k);
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		for(i=1;i<k;i++)
			if(a[i]<a[min])
				min=i;
		if(k==n)
			printf("%d",a[min]);
		else
			printf("%d ",a[min]);
		for(i=1,j=k;j<n;i++,j++)
		{
			if(a[j]<a[min])
				min=j;
			else if(min<i)
			{
				min=i;
				for(l=i;l<=j;l++)
					if(a[l]<a[min])
						min=l;
			}
			if(j==n-1)
				printf("%d",a[min]);
			else
				printf("%d ",a[min]);
		}
		printf("\n");
	}
	return 0;
}
