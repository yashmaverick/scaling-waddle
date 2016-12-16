#include<stdio.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,a[100000],i,k,max=0;
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		k=a[0];
		for(i=1;i<n;i++)
		{
			if(a[i]-k<0)
				k=a[i];
			a[i]=a[i]-k;
		}
		for(i=1;i<n;i++)
			if(a[i]>max)
				max=a[i];
		printf("%d\n",max);
	}
	return 0;
}
