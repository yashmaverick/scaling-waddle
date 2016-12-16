#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	while(n!=0)
	{
		int a[n],i,j,k,count;
		count=0;
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		for(i=0;i<n;i++)
		{
			for(j=1;j<n;j++)
			{
				for(k=i+1;k<j;k++)
				{
					if(a[k]>a[i] || a[k]>a[j])
					{
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
