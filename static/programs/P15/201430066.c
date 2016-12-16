#include<stdio.h>
int main()
{
	int t,l;
	scanf("%d",&t);
	for(l=0;l<t;l++)
	{
		int n,k,flag;
		scanf("%d",&n);
		scanf("%d",&k);
		int i=0,j,min,a[n];
		while(i<n)
		{
			scanf("%d",&a[i]);
			i++;
		}
		min=a[0];
		for(j=0;j<n-k+1;j++)
		{
			if(j!=0 && a[j-1]!=min)
			{
				if(a[k+j-1]<min)
					min=a[k+j-1];
				if(j!=n-k)
					printf("%d ",min);
				else
					printf("%d\n",min);
				continue;
			}
			min=a[j];
			for(i=j;i<k+j;i++)
			{
				if(a[i]<min)
					min=a[i];
			}
			if(j!=n-k)
				printf("%d ",min);
			else
				printf("%d\n",min);
		}
	}
	return 0;
}
