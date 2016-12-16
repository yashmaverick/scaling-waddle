#include <stdio.h>

int main()
{
	int i,j,n,a[1000000],count,k;

	scanf("%d",&n);

	while(n!=0)
	{
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);

		count=0;

		for(i=0;i<n-2;i++)
		{
			for(j=i+2;j<n;j++)
			{
				for(k=i+1;k<j;k++)
				{
					if(a[k]>a[i] || a[k]>a[j])
					{
						//printf("%d %d-%d %d\n",a[i],a[j],i,j);
						count++;
						break;
					}
				}
			}
		}
		printf("%d\n",count);
		
		scanf("%d",&n);
	}

	return 0;
}
