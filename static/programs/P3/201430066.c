#include<stdio.h>
int main()
{
	int testcases,z;
	scanf("%d",&testcases);
	for(z=0;z<testcases;z++)
	{
		int n,i=0;
		scanf("%d",&n);
		int a[n];
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		int diff,maxdiff;
		int k,j;
		k=a[0];
		diff=maxdiff=0;
		for(j=0;j<n;j++)
		{
			if(k>a[j] )
				k=a[j];
			diff=a[j]-k;
			if(maxdiff<diff)
				maxdiff=diff;
		}
		printf("%d\n",maxdiff);
	}
	return 0;
}
